#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <iostream> // Để sử dụng std::cout

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password, bool isAdmin);

    void resetPassword(User& user, const std::string& newPassword);
    bool isAdministrator() const; // Phương thức để kiểm tra quyền Admin

private:
    bool isAdmin; // Trường để xác định quyền Admin
};

#endif // ADMIN_H
