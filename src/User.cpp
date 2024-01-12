#include "User.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

User:: User(const std::string& username, const std::string& password, const std::string& fullName, const std::string& phoneNumber, const std::string& email, const std::string& address, int creditPoints){
    this->username = username;
    this->fullName = fullName;
    this->password = password;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->address = address;
    this->creditPoints = creditPoints;
}

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

const std::string& setUsername(const std::string& username){
    username == username;
}
const std::string& setFullName(const std::string& fullname){
    fullname == fullname;
}

const std::string& setPhoneNumber(const std::string& phoneNumber){
    phoneNumber == phoneNumber;
}

const std::string& setEmail(const std::string& email){
    email == email;
}

const std::string& setAddress(const std::string& address){
    address == address;
}

int setCreditPoints(int creditPoints){
    creditPoints = creditPoints;
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
