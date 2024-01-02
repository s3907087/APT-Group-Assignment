#include "Member.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool login() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Here, add the logic to read from the file and check credentials
    // For example, open the file named username + ".dat"
    std::ifstream file(username + ".dat");
    if (!file.is_open()) {
        std::cerr << "Failed to open user data file." << std::endl;
        return false;
    }

    // Assuming the first line is the password, read and compare
    std::string storedPassword;
    getline(file, storedPassword);  // Modify based on your file format
    file.close();

    if (password == storedPassword) {
        std::cout << "Login successful!" << std::endl;
        return true;
    } else {
        std::cout << "Invalid username or password." << std::endl;
        return false;
    }
}

int main() {
    // Creating an instance of Member
    Member member("john_doe", "password123");
    Member member1("john doe 2", "123");

    // Setting up member's data
    member.registerMember("John Doe", "123456789", "john@example.com", "123 Main St");
    member1.registerMember("John Doe 2", "123", "john@example.com", "123 Main St");
    // Add other necessary member setup here

    // Saving member's data to a file
    member.saveDataToFile("member.dat");
    member.saveDataToFile(member.getUsername() +".dat");

    bool loggedIn = login();

    return 0;
}

