#include "Member.h"
#include "User.h"
#include "Admin.h"
#include "Skills.h" // Include this to use Skills
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem> // Include this to use std::filesystem
#include <conio.h>

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

void infoPanel() {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n";
    std::cout << "\"TIME BANK\" APPLICATION\n";
    std::cout << "Instructor: Mr. Tran Duc Linh\n";
    std::cout << "Group: 25\n";
    std::cout << "s3907087, Tran Khanh Duc\n";
    std::cout << "sXXXXXXX, Student Name\n";
    std::cout << "--------------------------\n" << std::endl;
}

void registerMember() {
    std::string username, password, fullName, phone, email, address;

    bool registrationSuccessful = false;
    infoPanel();
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

            Member newMember(username, password); // Assume Member constructor takes username and password
            newMember.registerAccount(username, password, fullName, phone, email, address); // Register account
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
                temp.viewInformation();
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
    std::cout << "0. Exit\n";
    std::cout << "1. Register\n";
    std::cout << "2. View as Guest\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cin.ignore(); // Clear the input buffer

    switch (choice) {
        case 0:
            return;
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
    
    // Add more student details as needed
    int roleChoice = -1;
    while (roleChoice!= 0){
        int roleChoice;
        infoPanel();
        std::cout << "Use the app as 1. Guest 2. Member 3. Admin\n";
        std::cout << "Enter your choice: ";
        std::cin >> roleChoice;
        std::string username, password;
        
            switch (roleChoice) {
                case 1:
                    infoPanel();
                    guestMenu();
                    break;
                case 2:
                    std::cout << "Enter username (or 0 to go back): ";
                    std::cin >> username;
                    if (username == "0") {
                        std::cout << "Going back to Role Selection.\n";
                        break;  // Break out of the switch statement
                    }
                    infoPanel();
                    Member::memberMenu(username);
                    break;
                case 3:
                    bool isAdminLogin = false;
                    while (isAdminLogin != true) {
                        std::cout << "Enter admin username: "; 
                        std::cin >> username;
                        std::cout << "Enter admin password: ";
                        std::cin >> password;

                        if (Admin::adminLogin(username, password)) {
                            Admin adminObj(username, password, true); // Create an Admin object with the provided username and password
                            infoPanel();
                            adminObj.adminMenu(username);
                            isAdminLogin = true;
                        } else {
                            std::cout << "Invalid admin credentials." << std::endl;
                        }
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
