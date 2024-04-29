#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date() {
	day = 1;
	month = 1;
	year = 1;
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

void Date::setFullDate(int d, int m, int y) {
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

int Date::getyear() const {
	return year;
}

string Date::getDate() const {
	return to_string(day) + "-" + to_string(month) + "-" + to_string(year);
}

void Date::print() const {
	cout << "Date is " << day << "-" << month << "-" << year << endl;
}

ostream& operator<<(ostream& osObject, const Date& date1) {
	osObject << date1.day << "-" << date1.month << "-" << date1.year;
	return osObject;
}

// overloading cin to read data in
istream& operator >> (istream& isObject, Date& date1) {
	isObject >> date1.day >> date1.month >> date1.year;
	return isObject;
}

bool Date::operator==(const Date& otherDate) const {
	return (day == otherDate.day && month == otherDate.month && year == otherDate.year);
}