#ifndef USER_H
#define USER_H

#include <string>
// Forward declaration
class Member;

class User {
public:
    User(const std::string& username, const std::string& password, const std::string& fullName, const std::string& phoneNumber, const std::string& email, const std::string& address, int creditPoints);

    virtual ~User() {}


    const std::string& getUsername() const;
    const std::string& getPassword() const;
    const std::string& getFullName() const;
    const std::string& getPhoneNumber() const;
    const std::string& getEmail() const;
    const std::string& getAddress() const;
    int getCreditPoints() const;
    void setUsername(const std::string& newUsername);
    void setPassword(const std::string& newPass);
    void setFullName(const std::string& newFullName);
    void setPhoneNumber(const std::string& newPhoneNumber);
    void setEmail(const std::string& newEmail);
    void setAddress(const std::string& newAddress);
    void setCreditPoints(int newCreditPoints);

    static std::pair<bool, Member> login(const std::string& username);   
    void registerAccount(const std::string& newUserName, const std::string& newPassword, const std::string& newFullName, const std::string& newPhoneNumber, const std::string& newEmail, const std::string& newAddress);
    void saveToUserList(const std::string& newUserName);
    void resetPassword(const std::string& newPassword);

private:
    std::string username;
    std::string password;
    std::string fullName;
    std::string phoneNumber;
    std::string email;
    std::string address;
    int creditPoints;
};

#endif // USER_H