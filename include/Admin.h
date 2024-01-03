#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <iostream> // Để sử dụng std::cout

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password, bool isAdmin);

    void resetPassword(User& user, const std::string& newPassword);
    bool isAdministrator() const; // Phương thức để kiểm tra quyền Admin
    static bool adminLogin(const std::string& username, const std::string& password);
    static void adminMenu(){}

private:
    bool isAdmin; // Trường để xác định quyền Admin
    static std::string adminUsername;
    static std::string adminPassword;
};

#endif // ADMIN_H
