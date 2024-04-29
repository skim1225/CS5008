#include "Date.h"
#include <iostream>

using namespace std;

/**
 * Default constructor for creating a Date object.
*/
Date::Date() {
	day = 1;
	month = 1;
	year = 1;
}

/**
 * Default destructor for destroying a Date object.
*/
Date::~Date() {}

/**
 * Constructor for creating a Date object with the given date, month, and year.
*/
Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

/**
 * Sets the day of the Date to the given integer.
*/
void Date::setDay(int d) {
	day = d;
}

/**
 * Sets the month of the Date to the given integer.
*/
void Date::setMonth(int m) {
	month = m;
}

/**
 * Sets the year of the Date to the given integer.
*/
void Date::setYear(int y) {
	year = y;
}

/**
 * Sets the day, month, and year of the Date to the given integers.
*/
void Date::setFullDate(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

/**
 * Returns the day of the Date, as an int.
*/
int Date::getDay() const {
	return day;
}

/**
 * Returns the month of the Date, as an int.
*/
int Date::getMonth() const {
	return month;
}

/**
 * Returns the year of the Date, as an int.
*/
int Date::getyear() const {
	return year;
}

/**
 * Returns a String representation of the Date.
*/
string Date::getDate() const {
	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

/**
 * Prints the Date to the console in a readable format.
*/
void Date::print() const {
	cout << "Date is " << day << "-" << month << "-" << year << endl;
}

/**
 * Overloads the cout << operator.
*/
ostream& operator<<(ostream& osObject, const Date& date1) {
	osObject << date1.month << "-" << date1.day << "-" << date1.year;
	return osObject;
}

/**
 * Overloads the cin >> operator.
*/
istream& operator >> (istream& isObject, Date& date1) {
	isObject >> date1.day >> date1.month >> date1.year;
	return isObject;
}

/**
 * Overloads the comparison == operator.
*/
bool Date::operator==(const Date& otherDate) const {
	return (day == otherDate.day && month == otherDate.month && year == otherDate.year);
}