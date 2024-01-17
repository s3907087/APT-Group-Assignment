#include "Booking.h"
#include "Time.h"
#include "Member.h"
#include "Skills.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    Booking book;
    Time time;
    string start;
    string end;
    cout << "Enter your start time: ";
    getline(cin,start);
    cout << "Enter your end time: ";
    getline(cin,end);

    if(time.isValidDateFormat(start) == false){
        cout << "Wrong date format for start time";
    } else {
        time.setStartTime(start);
    }

    if (time.isValidDateFormat(end) == false){
        cout << "Wrong date format for end time";
    } else{
        time.setEndTime(end);
    }

    cout << time.getStartTime();
    cout << time.getEndTime();


    return 0;
}