#include "Date.h"

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

unsigned int Date::getYear() const {
    return this->year;
}

unsigned int Date::getMonth() const {
    return this->month;
}

unsigned int Date::getDay() const {
    return this->day;
}

bool Date::Compare(const Date &other) {
    return (year == other.year && month == other.month && day == other.day);
}

bool Date::operator<(Date date) {
    if(year<date.year) return true;
    else if(year == date.year)
    {
        if(month<date.month) return true;
        else if(month==date.month)
        {
            if(day<=date.day) return true;
            return false;
        }
        return false;
    }
    return false;
}

bool Date::operator>(Date date) {
    return !operator<(date);
}

int diff(Date from, Date to){
    return (to.getYear()*365 + to.getMonth()*31 + to.getDay()) - (from.getYear()*365 + from.getMonth()*31 + from.getDay());
}