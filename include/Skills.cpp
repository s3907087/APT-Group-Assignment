#include "Skills.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#include "Skills.h"

Skills::Skills(const std::string& Skills)
{
    std::istringstream ss(Skills);
    std::string skill;
    while (std::getline(ss, skill, ',')) {
        skills.push_back(skill);
    }
}

void Skills::addSkill(const std::string& skill)
{
    skills.push_back(skill);
}

void Skills::removeSkill(const std::string& skill)
{
    for(int i = 0; i < skills.size(); ++i){
        if(skills[i] == skill){
            skills.erase(skills.begin() + i);
        }
    }
}

bool Skills::hasSkill(const std::string& skill) const
{
    char currentSkill;

    for (int i = 0; i < skill.size(); ++i){
        if (skill[i] == currentSkill){
            return true;
        }
    }
    return false;
}

const std::vector<std::string>& Skills::getSkills() const
{
    return skills;
}