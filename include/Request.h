#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request {
public:
    Request(int requestID, const std::string& requestorName, const std::string& requestedSkill, bool accepted,  int duration);

    int getRequestID() const;
    const std::string& getRequestorName() const;
    const std::string& getRequestedSkill() const;
    bool isAccepted() const;
    int getDuration() const;

private:
    int requestID;
    std::string requestorName;
    std::string requestedSkill;
    bool accepted;
    int duration;
};

#endif // REQUEST_H
