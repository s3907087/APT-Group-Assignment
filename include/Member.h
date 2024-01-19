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

    int getSkillRating();

    void setSkillRating(int newSkillRating);

    int getSupporterRating();

    void setSupporterRating(int newSupporterRating);

    int getHostRating();

    void setHostRating(int newHostRating);

    std::vector<Comment> getComments() const;

    Skills getSkills();

    void setSkills(Skills newSkills);


    // Hiển thị thông tin thành viên
    void viewInformation();

    // Liệt kê kỹ năng có thể thực hiện
    void listAvailable(const Skills skills, int minimumRating);

    void topUp();

    // // Chấp nhận yêu cầu cụ thể
    // void acceptRequest(int requestId);

    // // Từ chối yêu cầu cụ thể
    // void rejectRequest(int requestId);

    // Đánh giá người hỗ trợ
    void rateMember(Member& memberBeingRated);

    // //Save username list
    // void saveListUS(const std::string& filename, const std::vector<std::string>& usernames);

    // //load username list
    // std::vector<std::string> loadListUS(const std::string& filename);

    // Lưu dữ liệu vào tệp
    void saveDataToFile(const std::string& filename);


    // Tải dữ liệu từ tệp
    bool loadDataFromFile(const std::string& filename, std::vector<Skills>& skills); //

    static void memberMenu(const std::string& username);

    std::string trimm(const std::string& str);


private:
    Skills skills;
    int skillRating;
    int supporterRating;
    int hostRating;
    bool isAvailable;
    int minimumRating;
    std::vector<Comment> comments;
    void loadDataFromFileHelper(const std::string& filename); //, std::vector<Skills>& skills
    

    // Thêm các trường dữ liệu khác cần thiết cho thành viên
};

#endif // MEMBER_H