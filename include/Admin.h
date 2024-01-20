#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <iostream> // Để sử dụng std::cout

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password, bool isAdmin);

    void resetPassword(User& user, const std::string& newPassword);
    static bool adminLogin(const std::string& username, const std::string& password);
    static void adminMenu(const std::string& username);

private:
    bool isAdmin; 
    static std::string adminUsername;
    static std::string adminPassword;
};

#endif // ADMIN_H