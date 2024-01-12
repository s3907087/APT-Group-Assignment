#include "Member.h"
#include <iostream>
#include "Skills.h"
#include "Request.h"
#include <fstream>
#include <sstream>
using namespace std;

Member::Member(const std::string& username, const std::string& password)
    : User(username, password, "", "", "", "", 0), isAvailable(false), minimumRating(0) {
    // Khởi tạo dữ liệu thành viên
}

void Member::registerMember(const std::string& fullName, const std::string& phoneNumber,
                            const std::string& email, const std::string& homeAddress) {
    this->fullName = fullName;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->homeAddress = homeAddress;
    // Lưu thông tin thành viên vào cơ sở dữ liệu hoặc tệp tin
}

void Member::viewInformation() const {
    // Hiển thị thông tin thành viên
    std::cout << "Username: " << getUsername() << std::endl;
    std::cout << "Full Name: " << getFullName() << std::endl;
    std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    std::cout << "Home Address: " << getAddress() << std::endl;
    // Hiển thị các thông tin khác của thành viên
}

void Member::listAvailable(const std::vector<Skills>& skills, int minimumRating) {
    // Lưu danh sách kỹ năng và minimumRating vào thành viên
    this->skills = skills;
    this->minimumRating = minimumRating;
    isAvailable = true;
}

void Member::viewRequests(Request& request) const {
    // Duyệt qua danh sách các yêu cầu và hiển thị thông tin của mỗi yêu cầu
    std::cout << "Request ID: " << request.getRequestID() << std::endl;
    std::cout << "Requestor: " << request.getRequestorName() << std::endl;
    std::cout << "Requested Skill: " << request.getRequestedSkill() << std::endl;
    std::cout << "Request Status: " << (request.isAccepted() ? "Accepted" : "Pending") << std::endl;
    std::cout << "--------------------------" << std::endl;
}

void Member::acceptRequest(int requestId, Request& request) {
    // Tìm yêu cầu cụ thể trong danh sách yêu cầu của thành viên
    
    if (request.getRequestID() == requestId) {
    // Đánh dấu yêu cầu là đã chấp nhận
    request.isAccepted() == true;
    std::cout << "Request " << requestId << " has been accepted." << std::endl;
    return; // Kết thúc khi đã tìm thấy yêu cầu
    }
    // Nếu không tìm thấy yêu cầu
    std::cout << "Request " << requestId << " not found or already accepted." << std::endl;
}


void Member::rejectRequest(int requestId,Request& request) {
    // Tìm yêu cầu cụ thể trong danh sách yêu cầu của thành viên
    if (request.getRequestID() == requestId) {
        // Đánh dấu yêu cầu là đã từ chối
        request.isAccepted() == false;
        std::cout << "Request " << requestId << " has been rejected." << std::endl;
        return; // Kết thúc khi đã tìm thấy yêu cầu
    }
    // Nếu không tìm thấy yêu cầu
    std::cout << "Request " << requestId << " not found or already rejected." << std::endl;
}


void Member::rateSupporter(int supporterId, int skillRating, int overallRating, const std::string& comment) {
    // Đánh giá người hỗ trợ
    // Implement logic để đánh giá người hỗ trợ
}

void Member::rateHost(int hostId, int rating, const std::string& comment) {
    // Đánh giá chủ nhà
    // Implement logic để đánh giá chủ nhà
}

void Member::saveDataToFile(const std::string& filename, Skills& skills) {
    std::ofstream file(filename);

    if (file.is_open()) {
        // Ghi thông tin thành viên vào tệp tin
        file << "Username: " << getUsername() << std::endl;

        // Ghi danh sách các kỹ năng của thành viên vào tệp tin
        file << "Skills: ";
        const std::vector<std::string>& memberSkills = skills.getSkills();
        for (const std::string& skill : memberSkills) {
            file << skill << ", ";
        }
        file << std::endl;

        // Ghi các thông tin khác của thành viên (ví dụ: minimumRating, isAvailable) vào tệp tin
        // ...

        file.close();
    } else {
        // Xử lý lỗi mở tệp tin
        std::cerr << "Failed to open file for saving data: " << filename << std::endl;
    }
}

void Member::loadDataFromFile(const std::string& filename, vector<Skills>& skills) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string key, value;
            if (std::getline(iss, key, ':') && std::getline(iss, value)) {
                // Xử lý từng cặp key và value từ tệp tin
                if (key == "Username") {
                    // Gán giá trị vào trường username của thành viên
                    setUsername() == value;
                } else if (key == "Skills") {
                    // Gán giá trị vào trường skills của thành viên
                    // Đảm bảo bạn xử lý dữ liệu kỹ năng ở đây
                    std::istringstream skillStream(value);
                    string skill;
                    while (std::getline(skillStream, skill, ',')) {
                        skills.push_back(skill);
                    }
                } else if (key == "MinimumRating") {
                    // Gán giá trị vào trường minimumRating của thành viên
                    // Đảm bảo bạn xử lý dữ liệu minimumRating ở đây
                    minimumRating = std::stoi(value);
                    
                } else if (key == "IsAvailable") {
                    // Gán giá trị vào trường isAvailable của thành viên
                    // Đảm bảo bạn xử lý dữ liệu isAvailable ở đây
                    isAvailable = (value == "true");
                }
                // Các trường khác có thể được xử lý tương tự
            }
        }
        file.close();
    } else {
        // Xử lý lỗi mở tệp tin
        std::cerr << "Failed to open file for loading data: " << filename << std::endl;
    }
}

