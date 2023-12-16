#ifndef TIMEBANK_H
#define TIMEBANK_H

#include "User.h"
#include <vector>

class TimeBank {
public:
    TimeBank();

    void registerUser(const std::string& username, const std::string& password);
    User* findUser(const std::string& username) const;

private:
    std::vector<User*> users;
};

#endif // TIMEBANK_H
