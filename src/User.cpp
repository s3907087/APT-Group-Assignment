#include "User.h"
#include <string>

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

const std::string& User::getUsername() const {
    return username;
}

const std::string& User::getPassword() const {
    return password;
}
