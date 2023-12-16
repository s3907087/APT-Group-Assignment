#include "TimeBank.h"
#include <string>

TimeBank::TimeBank() {}

void TimeBank::registerUser(const std::string& username, const std::string& password) {
    users.push_back(new User(username, password));
}

User* TimeBank::findUser(const std::string& username) const {
    for (User* user : users) {
        if (user->getUsername() == username) {
            return user;
        }
    }
    return nullptr;
}
