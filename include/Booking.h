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
        vector<string> Period;
        // Time timeSlot;
        Member Username;
        double MinimumRating;
        vector<Skills> skills;
        bool isListed;
        int ConsumePoint;
    public:
        // Booking( Time& timeSlot, Member& Username, Member& MinimumRating,  vector<Skills>& skills);
        Booking(vector<string> Period, Member Username, double MinimumRating,  vector<Skills> skills, int ConsumePoint);

        //  Time getTimeSlot();
         vector<string> getPeriod();
         Member getUsername() ;
        double getMinimumRating() ;
        vector<Skills> getSkills() ;
         bool listSelf();
         bool UnListSelf();
        int getConsumePoint();

         void setConsumePoint(int newConsumePoint);
        //  void setTimeSlot( Time newTimeSlot);
         void addTimeSLot( string timeSlot,Time Start,Time End);
         void removeTimeSLot( string timeSlot,Time Start,Time End);
         void setUsername( Member newUserName) ;
         void setMinimumRating(double newMinimumRating) ; 
        void showInfo(Booking booking, Member member, Skills skills);
};

#endif //BOOKING_H