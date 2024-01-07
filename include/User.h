#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& username, const std::string& password, const std::string& fullName, const std::string& phoneNumber, const std::string& email, const std::string& address, int creditPoints);

    const std::string& getUsername() const;
    const std::string& getPassword() const;
    const std::string& getFullName() const;
    const std::string& getPhoneNumber() const;
    const std::string& getEmail() const;
    const std::string& getAddress() const;
    int getCreditPoints() const;
    const std::string& setUsername() const;
    const std::string& setFullName() const;
    const std::string& setPhoneNumber() const;
    const std::string& setEmail() const;
    int setCreditPoints() const;

    static bool login(const std::string& username);
    void viewInformation() const;
    void registerAccount(const std::string& newUserName, const std::string& newPassword, const std::string& newFullName, const std::string& newPhoneNumber, const std::string& newEmail, const std::string& newAddress);
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
