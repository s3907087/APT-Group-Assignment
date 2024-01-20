#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include <vector>
#include <string>
#include "Skills.h"

class Member : public User {
public:
    //Constructors
    Member();
    Member(const std::string& username, const std::string& password);

    //Getters & setters
    int getSkillRating();

    void setSkillRating(int newSkillRating);

    int getSupporterRating();

    void setSupporterRating(int newSupporterRating);

    int getHostRating();

    void setHostRating(int newHostRating);

    std::vector<std::string> getComments() const;

    Skills getSkills();

    void setSkills(Skills newSkills);


    // View information of a member
    void viewInformation();
    void viewInformationAsGuest();

    // List availability
    void listAvailable(const Skills skills, int minimumRating);

    void topUp();

    // // Accept a request
    // void acceptRequest(int requestId);

    // // Reject a request
    // void rejectRequest(int requestId);

    // Rate other members
    void rateMember(Member& memberBeingRated);

    // Save data to file
    void saveDataToFile(const std::string& filename);


    // Load data from file
    bool loadDataFromFile(const std::string& filename, std::vector<Skills>& skills); //

    //UI for member
    static void memberMenu(const std::string& username);

    //trim the excess spaces when user input
    std::string trimm(const std::string& str);


private:
    Skills skills;
    int skillRating;
    int supporterRating;
    int hostRating;
    bool isAvailable;
    int minimumRating;
    std::vector<std::string> comments;    

    // Thêm các trường dữ liệu khác cần thiết cho thành viên
};

#endif // MEMBER_H