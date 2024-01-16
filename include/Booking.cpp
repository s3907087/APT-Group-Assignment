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

Booking::Booking(Time timeSlot, string Username, double MinimumRating,  Skills skills, int ConsumePoint, string Status)
: timeSlot(timeSlot), Username(Username), MinimumRating(MinimumRating), skills(skills),Status(Status), ConsumePoint(ConsumePoint){}

Booking::Booking(){
}
//  Time Booking::getTimeSlot() {
    // return timeSlot;
// }
Time Booking::getTimeSlot(){
    return timeSlot;
}

string Booking::getUsername() {
    return Username;
}

double Booking::getMinimumRating() {
    return MinimumRating;
}
Skills Booking::getSkills(){
    return skills;
}


int Booking::getConsumePoint(){
    return ConsumePoint;
}

 void Booking::setConsumePoint(int newConsumePoint){
    ConsumePoint = newConsumePoint;
}

void Booking::setTimeSlot( Time newTimeSlot) {
     timeSlot = newTimeSlot;
}

string Booking::getStatus(){
    return Status;
}
//  void Booking::addTimeSLot( string timeSlot,Time Start,Time End){
//     timeSlot == Start.getStartTime() + "->" + End.getEndTime();
//     Period.push_back(timeSlot);
// }

// //  void Booking::removeTimeSLot( string timeSlot,Time Start,Time End){
// //     timeSlot == Start.getStartTime() + "->" + End.getEndTime();
    
//     for (int i=0;i<Period.size();i++){
//         if (Period[i]==timeSlot){
//             Period.erase(Period.begin()+i);
//         }
//     }
// }

//  bool Booking::listSelf(){
//     isListed = true;
// }

//  bool Booking::UnListSelf(){
//     isListed = false;
// }

void Booking::setStatus(string Status){
    this->Status = Status;
}

 void Booking::setUsername( string newUsername) {
    this->Username = newUsername;
}

 void Booking::setMinimumRating(double newMinimumRating) {
    MinimumRating = newMinimumRating;
}

void Booking::showInfo() {
    cout << "Username: " << Username;
    cout << "\nMinimum rating: " << to_string(MinimumRating);
    cout << "\nStart time: " << timeSlot.getStartTime() << "-->" << " End time: " << timeSlot.getEndTime();
    cout << "Skills: ";
    for (string skill : skills.getSkills()){
        cout << skill << "\n"; 
    }
    cout << "\nStatus: " << Status;
}