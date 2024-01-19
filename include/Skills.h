#ifndef SKILLS_H
#define SKILLS_H

#include <string>
#include <vector>

class Skills {
public:
    Skills(const std::string& Skills);
    Skills();
    void addSkill(const std::string& skill);
    void removeSkill(const std::string& skill);
    bool hasSkill(const std::string& skill) const;
    const std::vector<std::string> getSkills() const;

    friend class Booking;
private:
    std::vector<std::string> skills;
};

#endif // SKILLS_H