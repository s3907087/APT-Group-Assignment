#include "TimeBank.h"
#include <iostream>

int main() {
    TimeBank timeBank;

    timeBank.registerUser("user1", "password1");
    timeBank.registerUser("user2", "password2");

    User* foundUser = timeBank.findUser("user1");
    if (foundUser) {
        std::cout << "User found: " << foundUser->getUsername() << std::endl;
    } else {
        std::cout << "User not found." << std::endl;
    }

    return 0;
}
