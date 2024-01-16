#ifndef TIME_H
#define TIME_H

#include <string>
#include <sstream>
using namespace std;

class Time{
    private:
        
        string StartTime;
        string EndTime;

    public:
        Time();
        Time(string StartTime, string EndTime);

        string getStartTime();
        string getEndTime(); 
        
        void setStartTime(string StartTime);
        void setEndTime(string EndTime);

        void showDuration();
        bool isValidDateFormat(string date);
};

#endif //TIME_H