#include "Time.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

Time::Time(){
    this->StartTime = "";
    this->EndTime = "";
}
Time::Time(const string& StartTime, const string& EndTime): StartTime(StartTime),EndTime(EndTime){}

string Time::getStartTime(){
    return StartTime;
}

string Time::getEndTime(){
    return EndTime;
}

void Time::setStartTime(const string& StartTime){
    StartTime == StartTime;
}

void Time::setEndTime(const string& EndTime){
    EndTime == EndTime;
}

void Time::showDuration(){
    cout << "Start Time: " << StartTime << "\nEnd Time: " << EndTime << "\n";
}

bool Time::isValidDateFormat(const string& date){
    stringstream ss(date);
    tm time;
    ss >> get_time(&time, "%d/%B/%Y");

    if (ss.fail()) {
       cout << "Wrong date format" << "\n";
    }
    return true;
}

