#ifndef BOOKING_H
#define BOOKING_H

#include "Member.h"
#include "Time.h"
#include "Skills.h"
#include <string>
#include <vector>

using namespace std;

class Booking{
    private:
        //vector<string> Period;
        Time timeSlot;
        string Username;
        double MinimumRating;
        Skills skills;
        string Status;
        int ConsumePoint;
    public:
        // Booking( Time& timeSlot, Member& Username, Member& MinimumRating,  vector<Skills>& skills);
        Booking(Time timeSlot, string Username, double MinimumRating,  Skills skills, int ConsumePoint, string Status);
        Booking();
        //  Time getTimeSlot();
        Time getTimeSlot();
        string getUsername() ;
        double getMinimumRating() ;
        Skills getSkills() ;
        // bool listSelf();
        // bool UnListSelf();
        string getStatus();
        int getConsumePoint();

        void setStatus(string Status);
        void setConsumePoint(int newConsumePoint);
        void setTimeSlot( Time newTimeSlot);
        //void addTimeSLot( string timeSlot,Time Start,Time End);
        //void removeTimeSLot( string timeSlot,Time Start,Time End);
         void setUsername( string newUserName) ;
         void setMinimumRating(double newMinimumRating) ; 
        void showInfo();
};

#endif //BOOKING_H