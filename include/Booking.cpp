#include "Booking.h"
#include "Member.h"
#include "Time.h"
#include "Skills.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Booking::Booking( Time timeSlot,  Member Username,  Member MinimumRating,  vector<Skills> skills) 
// : timeSlot(timeSlot), Username(Username), MinimumRating(MinimumRating), skills(skills) {}

Booking::Booking( vector<string> Period,  Member Username, double  MinimumRating,  vector<Skills> skills, int ConsumePoint) 
: Period(Period), Username(Username), MinimumRating(MinimumRating), skills(skills),isListed(false), ConsumePoint(ConsumePoint){}

//  Time Booking::getTimeSlot() {
    // return timeSlot;
// }
 vector<string> Booking::getPeriod(){
    return Period;
}

 Member Booking::getUsername() {
    return Username;
}

double Booking::getMinimumRating() {
    return MinimumRating;
}
vector<Skills> Booking::getSkills(){
    return skills;
}


int Booking::getConsumePoint(){
    return ConsumePoint;
}

 void Booking::setConsumePoint(int newConsumePoint){
    ConsumePoint = newConsumePoint;
}
//  void Booking::setTimeSlot( Time newTimeSlot) {
//     timeSlot = newTimeSlot;
// }
 void Booking::addTimeSLot( string timeSlot,Time Start,Time End){
    timeSlot == Start.getStartTime() + "->" + End.getEndTime();
    Period.push_back(timeSlot);
}

 void Booking::removeTimeSLot( string timeSlot,Time Start,Time End){
    timeSlot == Start.getStartTime() + "->" + End.getEndTime();
    
    for (int i=0;i<Period.size();i++){
        if (Period[i]==timeSlot){
            Period.erase(Period.begin()+i);
        }
    }
}

 bool Booking::listSelf(){
    isListed = true;
}

 bool Booking::UnListSelf(){
    isListed = false;
}

 void Booking::setUsername( Member newUsername) {
    Username = newUsername;
}

 void Booking::setMinimumRating(double newMinimumRating) {
    MinimumRating = newMinimumRating;
}

void Booking::showInfo(Booking booking, Member member, Skills skills) {
    cout << "Period: ";
    for ( auto period : booking.getPeriod()) {
        cout << period << " ";
    }
    cout << endl;
    cout << "\nUsername: " << member.getUsername() << endl;    
    cout << "\nMinimum Rating: " << booking.getMinimumRating() << endl;
    cout << "\nSkills: " ;
    for (auto skill : skills.getSkills()) {
        cout << skill << " ";
    }
    cout << endl;

    cout << "\nIs Listed: " << (booking.listSelf() ? "Yes" : "No") << endl;
    cout << "\nConsume Point: " << booking.getConsumePoint() << endl;
}