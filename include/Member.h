#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include <vector>
#include <string>
#include "Skills.h"
#include "Comment.h"

class Member : public User {
public:
    Member();
    Member(const std::string& username, const std::string& password);

    int getSkillRating() const;

    void setSkillRating(int newSkillRating);

    int getSupporterRating() const;

    void setSupporterRating(int newSupporterRating);

    int getHostRating() const;

    void setHostRating(int newHostRating);

    std::vector<Comment> getComments() const;

    // Đăng ký thành viên
    void registerMember(const std::string& fullName, const std::string& phoneNumber,
                        const std::string& email, const std::string& homeAddress, const int& CP);

    // Hiển thị thông tin thành viên
    void viewInformation();

    // Liệt kê kỹ năng có thể thực hiện
    void listAvailable(const std::vector<Skills>& skills, int minimumRating);

    void topUp();


    // static Member getUserDataByUsername(const std::string& username);
    // // Xem danh sách các yêu cầu
    // void viewRequests();

    // // Chấp nhận yêu cầu cụ thể
    // void acceptRequest(int requestId);

    // // Từ chối yêu cầu cụ thể
    // void rejectRequest(int requestId);

    // Đánh giá người hỗ trợ
    void rateMember(Member& memberBeingRated, int skillRating, int supporterRating, int hostRating, Comment comment);

    // Lưu dữ liệu vào tệp
    void saveDataToFile(const std::string& filename);

    void saveRatingsToFile(const Member& memberBeingRated, const std::string& comment);

    // Tải dữ liệu từ tệp
    void loadDataFromFile(const std::string& filename, std::vector<Skills>& skills);

    static void memberMenu(const std::string& username);

    std::string trimm(const std::string& str);


private:
    std::string fullName;
    std::string phoneNumber;
    std::string email;
    std::string homeAddress;
    std::vector<Skills> skills;
    int skillRating;
    int supporterRating;
    int hostRating;
    bool isAvailable;
    int minimumRating;
    std::vector<Comment> comments;
    void loadDataFromFileHelper(const std::string& filename, std::vector<Skills>& skills);
    

    // Thêm các trường dữ liệu khác cần thiết cho thành viên
};

#endif // MEMBER_H