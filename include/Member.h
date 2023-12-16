#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include <vector>

class Member : public User {
public:
    Member(const std::string& username, const std::string& password);

    void addSkill(const std::string& skill);
    const std::vector<std::string>& getSkills() const;

private:
    std::vector<std::string> skills;
};

#endif // MEMBER_H
