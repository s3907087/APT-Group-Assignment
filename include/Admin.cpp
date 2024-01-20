#include "Admin.h"
#include "Member.h" 
#include "Skills.h" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem> 
#include <vector> 

// Initialize static member variables
std::string Admin::adminUsername = "admin"; // Placeholder username
std::string Admin::adminPassword = "adminpass"; // Placeholder password

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


Admin::Admin(const std::string& username, const std::string& password, bool isAdmin)
    : User(username, password, "", "", "", "", 0), isAdmin(isAdmin) {}

void Admin::resetPassword(User& user, const std::string& newPassword) {
    Member& member = dynamic_cast<Member&>(user);
    if (isAdmin) {
        // Call the resetPassword method of User to reset the password
        member.resetPassword(newPassword);
        std::cout << "The password of user " << member.getUsername() << " has been reset." << std::endl;

        // Save the updated user data back to the .dat file
        std::string filename = member.getUsername() + ".dat";
        member.saveDataToFile(filename);
    } else {
        std::cout << "You do not have permission to perform this operation." << std::endl;
    }
}

bool Admin::adminLogin(const std::string& username, const std::string& password) {
    return username == adminUsername && password == adminPassword;
}

void Admin::adminMenu(const std::string& username) {
    char repeat = 'y';
    while (repeat == 'y' || repeat == 'Y') {
        std::string userToReset;
        bool userFound = false;
        while (!userFound) {
            std::cout << "Enter the username of the user you want to reset the password for: ";
            std::cin >> userToReset;

            userToReset = trim(userToReset); //Trim out whitespaces

            std::string filename = userToReset + ".dat";
            if (std::filesystem::exists(filename)) {
                userFound = true;
                Member userToResetObj(userToReset, ""); // Create a Member object with the provided username
                std::vector<Skills> skills; // Create a vector to hold the skills
                userToResetObj.loadDataFromFile(filename, skills); // Load the data from the file
                std::string newPassword;
                std::cout << "Enter the new password for " << userToReset << ": ";
                std::cin >> newPassword;
                Admin adminObj(username, "", true); // Create an Admin object
                adminObj.resetPassword(userToResetObj, newPassword); // Call resetPassword on the Admin object
            } else {
                std::cout << "User not found, please enter an existing username." << std::endl;
            }
        }

        std::cout << "1. Reset another password\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> repeat;
        if (repeat == '2') {
            std::cout << "Exiting the application." << std::endl;
            exit(0);
        }
    }
}
