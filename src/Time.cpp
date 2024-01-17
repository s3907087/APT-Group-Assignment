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
Time::Time(string StartTime, string EndTime): StartTime(StartTime),EndTime(EndTime){}

string Time::getStartTime(){
    return StartTime;
}

string Time::getEndTime(){
    return EndTime;
}

void Time::setStartTime(string StartTime){
    this->StartTime == StartTime;
}

void Time::setEndTime(string EndTime){
    this->EndTime == EndTime;
}

void Time::showDuration(){
    cout << "Start Time: " << StartTime << "\nEnd Time: " << EndTime << "\n";
}

bool Time::isValidDateFormat(string date){
    stringstream ss(date);
    tm time;
    ss >> get_time(&time, "%d/%B/%Y");

    if (ss.fail()) {
       cout << "Wrong date format" << "\n";
    }
    return true;
}