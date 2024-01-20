#include "Member.h"
#include "User.h"
#include "Admin.h"
#include "Skills.h" // Include this to use Skills
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem> // Include this to use std::filesystem

// bool login() {
//     std::string username, password;
//     std::cout << "Enter username: ";
//     std::cin >> username;
//     std::cout << "Enter password: ";
//     std::cin >> password;

//     // Here, add the logic to read from the file and check credentials
//     // For example, open the file named username + ".dat"
//     std::ifstream file(username + ".dat");
//     if (!file.is_open()) {
//         std::cerr << "Failed to open user data file." << std::endl;
//         return false;
//     }

//     // Assuming the first line is the password, read and compare
//     std::string storedPassword;
//     std::string line;
//     // Skip the first line
//     getline(file, line);

//     // // Read the second line for the password
//     getline(file, storedPassword);
//     file.close();

//     if (password == storedPassword) {
//         std::cout << "Login successful!" << std::endl;
//         return true;
//     } else {
//         std::cout << "Invalid username or password." << std::endl;
//         return false;
//     }
// }
void registerMember() {
    std::string username, password, fullName, phone, email, address, choice, enteredSkill;
    Skills skills;

    bool registrationSuccessful = false;
    std::cout << "Welcome to the Time Bank!\n";
    std::cout << "To register, please enter the following information:\n";

    while (!registrationSuccessful) {
        std::cout << "Enter your username: ";
        std::getline(std::cin, username);

        // Check if the file exists
        std::string filename = username + ".dat";
        if (std::filesystem::exists(filename)) {
            std::cout << "Username already exists. Please choose a different username.\n";
        } else {
            // Proceed with the registration process
            std::cout << "Enter your password: ";
            std::getline(std::cin, password);
            std::cout << "Your full name: ";
            std::getline(std::cin, fullName);
            std::cout << "Your phone: ";
            std::getline(std::cin, phone);
            std::cout << "Your email: ";
            std::getline(std::cin, email);
            std::cout << "Your address: ";
            std::getline(std::cin, address);
    
            std::string choice;
            std::cout << "Enter your skill: ";
            std::getline(std::cin >> std::ws, enteredSkill);
            enteredSkill = enteredSkill + ", ";
            skills.addSkill(enteredSkill);
            std::cout << "Do you want to add another skill? (Y/N)";
            std::getline(std::cin >> std::ws, choice);
            while (choice == "y" || choice == "Y"){
                std::cout << "Enter your skill: ";
                std::getline(std::cin >> std::ws, enteredSkill);
                enteredSkill = enteredSkill + ", ";
                skills.addSkill(enteredSkill);
                std::cout << "Do you want to add another skill? (Y/N)";
                std::getline(std::cin >> std::ws, choice);
            }
            

            Member newMember(username, password); // Assume Member constructor takes username and password
            newMember.registerAccount(username, password, fullName, phone, email, address); // Register account
            newMember.setSkills(skills);
            newMember.saveDataToFile(filename);


            std::cout << "Registration successful!\n";
            registrationSuccessful = true;
        }
    }
}

void viewAsGuest() {
    std::vector<Skills> skill;
    std::ifstream userListFile("userlist.dat");

    if (userListFile.is_open()) {
        std::string username;
        while (std::getline(userListFile, username)) {
            // For each username in userlist.dat, retrieve and display member information
            Member temp;
            std::string filename = username + ".dat";

            if (temp.loadDataFromFile(filename, skill)) {
                std::cout << "Member Information for Username: " << username << "\n";
                temp.viewInformationAsGuest();
                std::cout << "--------------------------------------\n";
            } else {
                std::cerr << "Failed to load data for username: " << username << "\n";
            }
        }

        userListFile.close();
    } else {
        std::cerr << "Failed to open userlist file for viewing as guest.\n";
    }
}

void guestMenu() {
    int choice;
    std::cout << "1. Register\n";
    std::cout << "2. View as Guest\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << "--------------------------------------\n";

    std::cin.ignore(); // Clear the input buffer

    switch (choice) {
        case 1:
            registerMember();
            break;
        case 2:
            viewAsGuest();
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }
}



void welcomeScreen() {
    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n";
    std::cout << "\"TIME BANK\" APPLICATION\n";
    std::cout << "Instructor: Mr. Tran Duc Linh\n";
    std::cout << "Group: 25\n";
    std::cout << "s3907087, Tran Khanh Duc\n";
    std::cout << "sXXXXXXX, Student Name\n";
    std::cout << "--------------------------" << std::endl;

    // Add more student details as needed
    int roleChoice = -1;
    while (roleChoice!= 0){
        int roleChoice;
        std::cout << "Use the app as 1. Guest 2. Member 3. Admin\n";
        std::cout << "Enter your choice: ";
        std::cin >> roleChoice;
        std::string username, password;
        
            switch (roleChoice) {
                case 1:
                    guestMenu();
                    break;
                case 2:
                    std::cout << "Enter username (or 0 to go back): ";
                    std::cin >> username;
                    if (username == "0") {
                        std::cout << "Going back to Role Selection.\n";
                        break;  // Break out of the switch statement
                    }
                    Member::memberMenu(username);
                    break;
                case 3:
                    std::cout << "Enter admin username: "; 
                    std::cin >> username;
                    std::cout << "Enter admin password: ";
                    std::cin >> password;

                    if (Admin::adminLogin(username, password)) {
                        Admin adminObj(username, password, true); // Create an Admin object with the provided username and password
                        adminObj.adminMenu(username);
                    } else {
                        std::cout << "Invalid admin credentials." << std::endl;
                    }
                    break;

                // Add more cases as needed
            }
    }
}

int main() {
    welcomeScreen();
    

    return 0;
}
