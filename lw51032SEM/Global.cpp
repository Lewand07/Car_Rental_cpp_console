#include "Global.h"

size_t randomNumber(size_t begin, size_t end) {
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<size_t> uniformDist(begin, end);
    return uniformDist(engine);
}

std::string randomPESEL() {
    std::string pesel;
    for (size_t i = 0; i < 11; i++) {
        pesel += randomNumber(0, 9) + '0';
    }
    return pesel;
}
Date::Date() {
    currentTime();
}

void Date::set(size_t day, size_t month, size_t year, size_t hour, size_t minute){
    this->day = day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->minute = minute;
}
Date::Date(size_t d, size_t m, size_t yr, size_t hr, size_t mins) {
    day = d;
    month = m;
    year = yr;
    hour = hr;
    minute = mins;
}

bool Date::isValid(const Date date) {
    
    if (hour == 24) {
        hour = 0;
    }

    if (hour > 24 || minute > 60) {
        return false;
    }
    else {
        bool leap = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
        bool valid = false;

        if (month == 2){
            if (leap)
                valid = (day <= 29);
            else
                valid = (day <= 28);
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            valid = (day <= 30);
        else
            valid = (day <= 31);

        if (valid == false) {
            return false;
        }
    }
   
    if ((day == date.day && month <= date.month && year <= date.year && hour <= date.hour && minute <= date.minute) || (day > date.day && month <= date.month && year <= date.year) || (year < date.year)) {
        return false;
    }
    else {
        return true;
    }
}

void Date::currentTime()
{
    //Current time
    std::time_t t = std::time(0);
    struct tm now;
    localtime_s(&now, &t);

    day = now.tm_mday;
    month = now.tm_mon + 1;
    year = now.tm_year + 1900;
    hour = now.tm_hour;
    minute = now.tm_min;
}

std::ostream& operator<<(std::ostream& output, Date*& date) {
    output << date->day << "." << date->month << "." << date->year << "  " << date->hour << ":" << date->minute << std::endl;
    return output;
}

std::ostream& operator<<(std::ostream& output, Date& date) {
    output << date.day << "." << date.month << "." << date.year << "  " << date.hour << ":" << date.minute << std::endl;
    return output;
}