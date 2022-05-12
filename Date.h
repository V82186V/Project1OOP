#ifndef PROJECT1_DATE_H
#define PROJECT1_DATE_H

#include <iostream>

const unsigned int DATE_SIZE=11;

class Date{
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
public:
    Date(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    bool Compare(const Date& other);
    bool operator<(Date date);
    bool operator>(Date date);
    friend int diff(Date from, Date to);

};

#endif //PROJECT1_DATE_H
