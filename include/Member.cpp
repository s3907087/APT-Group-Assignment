#include "Member.h"
#include <iostream>
#include "Skills.h"
#include "Request.h"
#include <fstream>
#include <sstream>
#include "User.h"
#include <vector>

// Function to trim leading and trailing whitespaces from a string
std::string Member::trimm(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

Member::Member() : User("", "", "", "", "", "", 0),skillRating(5), supporterRating(5), hostRating(5), isAvailable(false), minimumRating(0) {
    // Initialize member-specific data
}

Member::Member(const std::string& username, const std::string& password)
    : User(username, password, "", "", "", "", 0),skillRating(5), supporterRating(5), hostRating(5), isAvailable(false), minimumRating(0) {
    // Khởi tạo dữ liệu thành viên
}

int Member::getSkillRating() const{
    return skillRating;
}

void Member::setSkillRating(int newSkillRating){
    skillRating = newSkillRating;
}

int Member::getSupporterRating() const{
    return supporterRating;
}

void Member::setSupporterRating(int newSupporterRating){
    supporterRating = newSupporterRating;
}

int Member::getHostRating() const{
    return hostRating;
}

void Member::setHostRating(int newHostRating){
    hostRating = newHostRating;
}

std::vector<Comment> Member::getComments() const {
    return comments;
}

void Member::registerMember(const std::string& fullName, const std::string& phoneNumber,
                            const std::string& email, const std::string& homeAddress, const int& CP) {
    this->fullName = fullName;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->homeAddress = homeAddress;
    // Lưu thông tin thành viên vào cơ sở dữ liệu hoặc tệp tin
}

void Member::viewInformation() {
    // Load data from the file
    // std::vector<Skills> skills;  // Assuming you need to pass skills to Member
    // loadDataFromFile(getUsername() + ".dat", skills);

    // Display additional information specific to Member
    std::cout << "Username: " << getUsername() << std::endl;
    std::cout << "Full Name: " << getFullName() << std::endl;
    std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    std::cout << "Home Address: " << getAddress() << std::endl;
    std::cout << "Credit points: " << getCreditPoints() << std::endl;
    std::cout << "Skill Rating: " << getSkillRating() << std::endl;
    std::cout << "Supporter Rating: " << getSupporterRating() << std::endl;
    std::cout << "Host Rating: " << getHostRating() << std::endl;
    // Display saved comments
    std::ifstream file(getUsername() + ".dat");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Failed to open file for loading comments: " << getUsername() << ".dat" << std::endl;
    }
    // Display any other member-specific information
}

void Member::listAvailable(const std::vector<Skills>& skills, int minimumRating) {
    // Lưu danh sách kỹ năng và minimumRating vào thành viên
    this->skills = skills;
    this->minimumRating = minimumRating;
    isAvailable = true;
}

void Member::topUp(){
    int amount;
    std::cout << "Your total credit: " << getCreditPoints() << "\n";
    std::cout << "How much do you want to top up? ";
    std::cin >> amount;
    setCreditPoints(amount);
    std::cout << "You have successfully topped up: " << amount << ". Thank you for choosing our service!\n"; 
}

// void Member::viewRequests() const {
//     // Duyệt qua danh sách các yêu cầu và hiển thị thông tin của mỗi yêu cầu
//     for (const Request& request : requests) {
//         std::cout << "Request ID: " << request.getRequestID() << std::endl;
//         std::cout << "Requestor: " << request.getRequestorName() << std::endl;
//         std::cout << "Requested Skill: " << request.getRequestedSkill() << std::endl;
//         std::cout << "Request Status: " << (request.isAccepted() ? "Accepted" : "Pending") << std::endl;
//         std::cout << "--------------------------" << std::endl;
//     }
// }

// void Member::acceptRequest(int requestId) {
//     // Tìm yêu cầu cụ thể trong danh sách yêu cầu của thành viên
//     for (Request& request : requests) {
//         if (request.getRequestID() == requestId) {
//             // Đánh dấu yêu cầu là đã chấp nhận
//             request.setAccepted(true);
//             std::cout << "Request " << requestId << " has been accepted." << std::endl;
//             return; // Kết thúc khi đã tìm thấy yêu cầu
//         }
//     }
//     // Nếu không tìm thấy yêu cầu
//     std::cout << "Request " << requestId << " not found or already accepted." << std::endl;
// }


// void Member::rejectRequest(int requestId) {
//     // Tìm yêu cầu cụ thể trong danh sách yêu cầu của thành viên
//     for (Request& request : requests) {
//         if (request.getRequestID() == requestId) {
//             // Đánh dấu yêu cầu là đã từ chối
//             request.setAccepted(false);
//             std::cout << "Request " << requestId << " has been rejected." << std::endl;
//             return; // Kết thúc khi đã tìm thấy yêu cầu
//         }
//     }
//     // Nếu không tìm thấy yêu cầu
//     std::cout << "Request " << requestId << " not found or already rejected." << std::endl;
// }


void Member::saveDataToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        // Ghi thông tin thành viên vào tệp tin
        file << "Username: " << getUsername() << std::endl;
        file << "Password: " << getPassword() << std::endl;
        file << "Fullname: " << getFullName() << std::endl;
        file << "Phone: " << getPhoneNumber()<< std::endl;
        file << "Email: " << getEmail() << std::endl;
        file << "Address: " << getAddress() << std::endl;
        file << "Credit points: " << getCreditPoints() << std::endl;
        // Append ratings and comments to the file
        file << "Skill Rating: " << getSkillRating() << std::endl;
        file << "Supporter Rating: " << getSupporterRating() << std::endl;
        file << "Host Rating: " << getHostRating() << std::endl;
        file << "Comments: \n";
        getComments();
        for (const Comment& comment : comments) {
            file << comment.content << std::endl;
        }
        file << "--------------------------" << std::endl;

        // Ghi danh sách các kỹ năng của thành viên vào tệp tin
        // file << "Skills: ";
        // const std::vector<std::string>& memberSkills = getSkills();
        // for (const std::string& skill : memberSkills) {
        //     file << skill << ", ";
        // }
        file << std::endl;

        // Ghi các thông tin khác của thành viên (ví dụ: minimumRating, isAvailable) vào tệp tin
        // ...

        file.close();
    } else {
        // Xử lý lỗi mở tệp tin
        std::cerr << "Failed to open file for saving data: " << filename << std::endl;
    }
}

void Member::loadDataFromFile(const std::string& filename, std::vector<Skills>& skills) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string key, value;
            if (std::getline(iss, key, ':') && std::getline(iss, value)) {
                value = trimm(value); // Trim the value
                if (key == "Username") {
                    setUsername(value);
                } else if (key == "Password") {
                    setPassword(value);
                } else if (key == "Fullname") {
                    setFullName(value);
                } else if (key == "Phone") {
                    setPhoneNumber(value);
                } else if (key == "Email") {
                    setEmail(value);
                } else if (key == "Address") {
                    setAddress(value);
                } else if (key == "Credit points") {
                    // Convert the value to an integer and assign it to creditPoints
                    setCreditPoints(std::stoi(value));
                } else if (key == "Skills") {
                    std::istringstream skillStream(value);
                    std::string skill;
                    while (std::getline(skillStream, skill, ',')) {
                        // Handle skills as needed
                        // For example, you can add each skill to the skills vector
                        skills.push_back(skill);
                    }
                }
                // Add more conditions for other member-specific data
            }
        }
        file.close();
    } else {
        std::cerr << "Failed to open file for loading data: " << filename << std::endl;
    }
}namespace name
{
    
} // namespace name
void Member::rateMember(Member& memberBeingRated, int skillRating, int supporterRating, int hostRating, Comment comment) {
    // Update skill rating and supporter rating based on the new ratings
    skillRating = (skillRating + memberBeingRated.getSkillRating()) / 2;
    supporterRating = (supporterRating + memberBeingRated.getSupporterRating()) / 2;

    // Update host rating based on the new rating
    hostRating = (hostRating + memberBeingRated.getHostRating()) / 2;

    comment.content = getUsername() + ": " + comment.content;

    // Update member's ratings
    memberBeingRated.setSkillRating(skillRating);
    memberBeingRated.setSupporterRating(supporterRating);
    memberBeingRated.setHostRating(hostRating);
    memberBeingRated.comments.push_back(comment);

    // Save ratings and comments to file
    std::string filename = memberBeingRated.getUsername() + ".dat";
    memberBeingRated.saveDataToFile(filename);
}

void Member::memberMenu(const std::string& username) {
    // Use the login function to check if the login is successful
    std::pair<bool, Member> loginResult = User::login(username);
    
    if (loginResult.first) {
        int choice;
        do {
            std::cout << "This is your menu:\n";
            std::cout << "0. Exit\n";
            std::cout << "1. View Information\n";
            std::cout << "2. Rate Another Member\n";
            std::cout << "3. Top up\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    loginResult.second.viewInformation();
                    break;
                case 2:
                    int enteredSkillRating;
                    int enteredSupporterRating;
                    int enteredHostRating;
                    Comment comment;
                    std::string username;
                    std::cout << "Enter the username you would like to rate: ";
                    std::cin >> username;
                    Member userData(username, "");
                    std::string filename = username + ".dat";
                    std::vector<Skills> skills; // Create a vector to hold the skills
                    userData.loadDataFromFile(filename, skills);
                    std::cout << "How much would you rate their skill? (1-5): ";
                    std::cin >> enteredSkillRating;

                    // Check if the entered rating is within the valid range (1-5)
                    if (enteredSkillRating < 1 || enteredSkillRating > 5) {
                        std::cout << "Invalid rating. Please enter a number between 1 and 5." << std::endl;
                        // You might want to handle this situation, for example, asking the user to enter the rating again.
                        // Add appropriate logic based on your requirements.
                        return;  // Exiting the function or taking necessary actions
                    }

                    std::cout << "How much would you rate them as a supporter? (1-5): ";
                    std::cin >> enteredSupporterRating;

                    // Check if the entered rating is within the valid range (1-5)
                    if (enteredSupporterRating < 1 || enteredSupporterRating > 5) {
                        std::cout << "Invalid rating. Please enter a number between 1 and 5." << std::endl;
                        // Handle this situation, for example, asking the user to enter the rating again.
                        return;  // Exiting the function or taking necessary actions
                    }

                    std::cout << "How much would you rate them as a host? (1-5): ";
                    std::cin >> enteredHostRating;

                    // Check if the entered rating is within the valid range (1-5)
                    if (enteredHostRating < 1 || enteredHostRating > 5) {
                        std::cout << "Invalid rating. Please enter a number between 1 and 5." << std::endl;
                        // Handle this situation, for example, asking the user to enter the rating again.
                        return;  // Exiting the function or taking necessary actions
                    }
                    std::cout << "Add a comment: ";
                    std::getline(std::cin >> std::ws, comment.content);
                    loginResult.second.rateMember(userData, enteredSkillRating, enteredSupporterRating, enteredHostRating, comment);  // Call a function to simulate rating another member
                    break;
                
            }
        } while (choice != 0);
    } else {
        std::cout << "Invalid username or password" << std::endl;
    }
}



