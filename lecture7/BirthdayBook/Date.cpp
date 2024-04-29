

#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

Date::~Date() {}

void Date::setDay(int d) {
    day = d;
}

void Date::setMonth(int m) {
    month = m;
}

void Date::setYear(int y) {
    year = y;
}

void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

string Date::getDate() const {
    string d1 = to_string(day);
    string m1 = to_string(month);
    string y1 = to_string(year);

    return d1 + "/" + m1 + "/" + y1;
}


void Date::print() const {
    string d1 = to_string(day);
    string m1 = to_string(month);
    string y1 = to_string(year);

    cout << "The date is: " << d1 + "/" + m1 + "/" + y1;
}

ostream& operator << (ostream& osObject, const Date& date1) {
    osObject << date1.day << " " << date1.month << " " << date1.year;
    return osObject;
}

// Overloading cin >> to read data into a new object
istream& operator >> (istream& isObject, Date& date1) {
    isObject >> date1.day >> date1.month >> date1.year;
    return isObject;
}

// Overloading ==
bool Date::operator==(const Date& otherDate) const {
    if (year == otherDate.year && month == otherDate.month &&
        day == otherDate.day)
        return true;
    else
        return false;
}