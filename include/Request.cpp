#include "Request.h"

Request::Request(int requestID, const std::string& requestorName, const std::string& requestedSkill, bool accepted, int duration)
    : requestID(requestID), requestorName(requestorName), requestedSkill(requestedSkill), accepted(accepted), duration(duration) {}

int Request::getRequestID() const {
    return requestID;
}

const std::string& Request::getRequestorName() const {
    return requestorName;
}

const std::string& Request::getRequestedSkill() const {
    return requestedSkill;
}

bool Request::isAccepted() const {
    return accepted;
}

int Request::getDuration() const {
    return duration;
}

