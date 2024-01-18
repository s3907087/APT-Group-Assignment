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

void User::setUsername(const std::string& newUsername) {
    username = newUsername;
}

void User::setPassword(const std::string& newPassword){
    password = newPassword;
}

void User::setFullName(const std::string& newFullName) {
    fullName = newFullName;
}

void User::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void User::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void User::setAddress(const std::string& newAddress) {
    address = newAddress;
}

void User::setCreditPoints(int newCreditPoints) {
    creditPoints = newCreditPoints;
}

std::pair<bool, Member> User::login(const std::string& username) {
    std::string password;
    std::cout << "Enter password for " << username << ": ";
    std::cin >> password;

    // Use loadDataFromFile to load user data
    std::vector<Skills> skills;  // Assuming you need to pass skills to Member
    Member member(username, password);
    member.loadDataFromFile(username + ".dat", skills);

    if (!member.loadDataFromFile(username + ".dat", skills)) {
        return std::make_pair(false, Member());  // Return a default-constructed Member for invalid login
    }

    // Access member data as needed
    std::string storedPassword = member.getPassword();

    // Trim leading and trailing whitespaces from entered and stored passwords
    password.erase(0, password.find_first_not_of(' '));
    password.erase(password.find_last_not_of(' ')+1);
    storedPassword.erase(0, storedPassword.find_first_not_of(' '));
    storedPassword.erase(storedPassword.find_last_not_of(' ')+1);

    if (password == storedPassword) {
        std::cout << "Login successful!\n" << std::endl;
        return std::make_pair(true, member);
    } else {
        std::cout << "Invalid username or password.\n" << std::endl;
        return std::make_pair(false, Member());  // Return a default-constructed Member for invalid login
    }
}

void User::registerAccount(const std::string& newUserName, const std::string& newPassword, const std::string& newFullName, const std::string& newPhoneNumber, const std::string& newEmail, const std::string& newAddress) {
    username = newUserName;
    password = newPassword;
    fullName = newFullName;
    phoneNumber = newPhoneNumber;
    email = newEmail;
    address = newAddress;
    creditPoints = 20;
    // Save the user information to userlist.dat
    saveToUserList(newUserName);
}

void User::saveToUserList(const std::string& newUserName) {
    std::ofstream userListFile("userlist.dat", std::ios::app);  // Open the file in append mode

    if (userListFile.is_open()) {
        // Save the new user's username to the file
        userListFile << newUserName << std::endl;

        userListFile.close();
    } else {
        // Handle the error if the file cannot be opened
        std::cerr << "Failed to open userlist.dat for saving data." << std::endl;
    }
}

void User::resetPassword(const std::string& newPassword) {
    password = newPassword;
}