#include "User.h"
#include "Member.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

User::User(const std::string& username, const std::string& password, const std::string& fullName, const std::string& phoneNumber, const std::string& email, const std::string& address, int creditPoints)
    : username(username), password(password), fullName(fullName), phoneNumber(phoneNumber), email(email), address(address), creditPoints(creditPoints) {}

const std::string& User::getUsername() const {
    return username;
}

const std::string& User::getPassword() const{
    return password;
}

const std::string& User::getFullName() const {
    return fullName;
}

const std::string& User::getPhoneNumber() const {
    return phoneNumber;
}

const std::string& User::getEmail() const {
    return email;
}

const std::string& User::getAddress() const {
    return address;
}

int User::getCreditPoints() const {
    return creditPoints;
}

bool User::login(const std::string& username) {
    // std::string username, password, line, fileUsername, filePassword;
    // bool userFound = false;

    // // Get username and password from the user
    // std::cout << "Enter username: ";
    // std::cin >> username;
    // std::cout << "Enter password: ";
    // std::cin >> password;

    // // Open the .dat file to search for the user
    // std::ifstream file(username + ".dat");
    // if (file.is_open()) {
    //     while (getline(file, line)) {
    //         std::istringstream iss(line);
    //         getline(iss, fileUsername, ',');
    //         getline(iss, filePassword);

    //         // Trim leading and trailing spaces
    //         fileUsername.erase(0, fileUsername.find_first_not_of(' ')); 
    //         fileUsername.erase(fileUsername.find_last_not_of(' ')+1);
    //         filePassword.erase(0, filePassword.find_first_not_of(' ')); 
    //         filePassword.erase(filePassword.find_last_not_of(' ')+1);

    //         if (username == fileUsername && password == filePassword) {
    //             userFound = true;
    //             break;
    //         }
    //     }
    //     file.close();

    //     if (userFound) {
    //         std::cout << "Login successful!" << std::endl;
    //         return true;
    //     } else {
    //         std::cout << "Login failed: Invalid username or password." << std::endl;
    //     }
    // } else {
    //     std::cerr << "Unable to open file." << std::endl;
    // }

    // return false;
    std::string password;
    std::cout << "Enter password for " << username << ": ";
    std::cin >> password;

    // Here, add the logic to read from the file and check credentials
    // For example, open the file named username + ".dat"
    std::ifstream file(username + ".dat");
    if (!file.is_open()) {
        std::cerr << "Failed to open user data file." << std::endl;
        return false;
    }

    // Assuming the first line is the password, read and compare
    std::string line;
    std::string storedPassword;
    
    // Skip the first line
    getline(file, line);

    // // Read the second line for the password
    getline(file, storedPassword);
    file.close();

    if (password == storedPassword) {
        std::cout << "Login successful!" << std::endl;
        return true;
    } else {
        std::cout << "Invalid username or password." << std::endl;
        return false;
    }
}

void User::viewInformation() const {
    std::cout << "Username: " << username << std::endl;
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Credit Points: " << creditPoints << std::endl;
}

void User::registerAccount(const std::string& newUserName, const std::string& newPassword, const std::string& newFullName, const std::string& newPhoneNumber, const std::string& newEmail, const std::string& newAddress) {
    username = newUserName;
    password = newPassword;
    fullName = newFullName;
    phoneNumber = newPhoneNumber;
    email = newEmail;
    address = newAddress;
}

void User::resetPassword(const std::string& newPassword) {
    password = newPassword;
}
