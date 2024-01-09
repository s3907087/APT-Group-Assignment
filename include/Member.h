#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include <vector>
#include <string>
#include "Skills.h"

class Member : public User {
public:
    Member();
    Member(const std::string& username, const std::string& password);

    // Đăng ký thành viên
    void registerMember(const std::string& fullName, const std::string& phoneNumber,
                        const std::string& email, const std::string& homeAddress, const int& CP);

    // Hiển thị thông tin thành viên
    void viewInformation();

    // Liệt kê kỹ năng có thể thực hiện
    void listAvailable(const std::vector<Skills>& skills, int minimumRating);

    // // Xem danh sách các yêu cầu
    // void viewRequests();

    // // Chấp nhận yêu cầu cụ thể
    // void acceptRequest(int requestId);

    // // Từ chối yêu cầu cụ thể
    // void rejectRequest(int requestId);

    // Đánh giá người hỗ trợ
    void rateSupporter(int supporterId, int skillRating, int overallRating, const std::string& comment);

    // Đánh giá chủ nhà
    void rateHost(int hostId, int rating, const std::string& comment);

    // Lưu dữ liệu vào tệp
    void saveDataToFile(const std::string& filename);

    // Tải dữ liệu từ tệp
    void loadDataFromFile(const std::string& filename, std::vector<Skills>& skills);

    static void memberMenu(const std::string& username);

private:
    std::string fullName;
    std::string phoneNumber;
    std::string email;
    std::string homeAddress;
    std::vector<Skills> skills;
    bool isAvailable;
    int minimumRating;
    void loadDataFromFileHelper(const std::string& filename, std::vector<Skills>& skills);

    // Thêm các trường dữ liệu khác cần thiết cho thành viên
};

#endif // MEMBER_H
