#include "Member.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Admin.h"

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
    std::string line;
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

void guestMenu() {
    // Implement guest-specific functionalities
}

void welcomeScreen() {
    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n";
    std::cout << "\"TIME BANK\" APPLICATION\n";
    std::cout << "Instructor: Mr. Tran Duc Linh\n";
    std::cout << "Group: Group No.\n";
    std::cout << "sXXXXXXX, Student Name\n";
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
            std::cout << "Enter username: ";
            std::cin >> username;
            if (User::login(username)) {
                Member::memberMenu(username);
            }
            break;
        case 3:
            std::cout << "Enter admin username: ";
            std::cin >> username;
            std::cout << "Enter admin password: ";
            std::cin >> password;

            if (Admin::adminLogin(username, password)) {
                Admin::adminMenu();
            } else {
                std::cout << "Invalid admin credentials." << std::endl;
            }
            break;
        // Add more cases as needed
    }
}

int main() {
    // Creating an instance of Member
    Member member("john_doe", "password123");
    Member member1("john_doe_2", "123");

    //Creating instance of Admin
    Admin admin1("admin", "adminpass", true);

    // Setting up member's data
    member.registerMember("John Doe", "123456789", "john@example.com", "123 Main St");
    member1.registerMember("John Doe 2", "123", "john@example.com", "123 Main St");
    // Add other necessary member setup here

    // Saving member's data to a file
    member.saveDataToFile(member.getUsername() +".dat");
    std::cout << "member's pass " << member.getPassword() << std::endl;
    member1.saveDataToFile(member1.getUsername() +".dat");
    std::cout << "member1's pass " << member1.getPassword() << std::endl;

    welcomeScreen();
    

    return 0;
}

