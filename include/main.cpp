#include "Member.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "Admin.h"


void guestMenu() {
    int choice;
    std::cout << "1. Register\n";
    std::cout << "2. View as Guest\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cin.ignore(); // Clear the input buffer

    std::string username, password, fullName, phone, email, address;

    bool registrationSuccessful = false;
    std::cout << "Welcome to the Time Bank!\n";
    std::cout << "To register please enter as following!\n";
    while (!registrationSuccessful) {
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    // Check if the file exists
    std::string filename = username + ".dat";
    if (std::filesystem::exists(filename)) {
        std::cout << "Username already exists. Please choose a different username.\n";
        // Handle the situation accordingly, e.g., ask the user to enter a different username
    } else {
        // Proceed with the registration process
        std::cout << "Enter your password: ";
        std::getline(std::cin, password);
        std::cout << "Your fullname: ";
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


void welcomeScreen() {
    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n";
    std::cout << "\"TIME BANK\" APPLICATION\n";
    std::cout << "Instructor: Mr. Tran Duc Linh\n";
    std::cout << "Group: 25\n";
    std::cout << "s3907087, Tran Khanh Duc\n";
    std::cout << "sXXXXXXX, Student Name\n";
    // Add more student details as needed

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
            std::cin.ignore(); // Clear the input buffer
            std::cout << "Username: ";
            std::getline(std::cin, username);
            Member::memberMenu(username);
            break;
        case 3:
            std::cout << "Enter admin username: ";
            std::cin >> username;
            std::cout << "Enter admin password: ";
            std::cin >> password;

            if (Admin::adminLogin(username, password)) {
                Admin::adminMenu(username);
            } else {
                std::cout << "Invalid admin credentials." << std::endl;
            }
            break;
        // Add more cases as needed
    }
}

int main() {

    welcomeScreen();
    

    return 0;
}

