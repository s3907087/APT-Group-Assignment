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
        Time(const string& StartTime, const string& EndTime);

        string getStartTime();
        string getEndTime(); 
        
        void setStartTime(const string& StartTime);
        void setEndTime(const string& EndTime);

        void showDuration();
        bool isValidDateFormat(const string& date);
};

#endif //TIME_H