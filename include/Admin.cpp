#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, bool isAdmin)
    : User(username, password, "", "", "", "", 0), isAdmin(isAdmin) {}

void Admin::resetPassword(User& user, const std::string& newPassword) {
    if (isAdmin) {
        // Gọi phương thức resetPassword của User để đặt lại mật khẩu
        user.resetPassword(newPassword);
        std::cout << "Mật khẩu của người dùng " << user.getUsername() << " đã được đặt lại." << std::endl;
    } else {
        std::cout << "Bạn không có quyền thực hiện hoạt động này." << std::endl;
    }
}

bool Admin::isAdministrator() const {
    return isAdmin;
}
