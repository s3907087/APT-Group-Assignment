#include "User.h"
#include <iostream>

User::User(const std::string& username, const std::string& password, const std::string& fullName, const std::string& phoneNumber, const std::string& email, const std::string& address, int creditPoints)
    : username(username), password(password), fullName(fullName), phoneNumber(phoneNumber), email(email), address(address), creditPoints(creditPoints) {}

const std::string& User::getUsername() const {
    return username;
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

bool User::login(const std::string& enteredPassword) const {
    return password == enteredPassword;
}

void User::viewInformation() const {
    std::cout << "Username: " << username << std::endl;
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Credit Points: " << creditPoints << std::endl;
}

void User::registerAccount(const std::string& newPassword, const std::string& newFullName, const std::string& newPhoneNumber, const std::string& newEmail, const std::string& newAddress) {
    password = newPassword;
    fullName = newFullName;
    phoneNumber = newPhoneNumber;
    email = newEmail;
    address = newAddress;
}

void User::resetPassword(const std::string& newPassword) {
    password = newPassword;
}
