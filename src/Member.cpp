#include "Member.h"
#include <string>

Member::Member(const std::string& username, const std::string& password)
    : User(username, password) {}

void Member::addSkill(const std::string& skill) {
    skills.push_back(skill);
}

const std::vector<std::string>& Member::getSkills() const {
    return skills;
}
