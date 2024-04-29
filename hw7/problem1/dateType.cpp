#include "dateType.h"
#include <iostream>
#include <string>

using namespace std;

dateType::dateType() {
	day = 1;
	month = 1;
	year = 1;
}

dateType::dateType(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

dateType::~dateType() {}

void dateType::setDay(int d) {
	day = d;
}

void dateType::setMonth(int m) {
	month = m;
}

void dateType::setYear(int y) {
	year = y;
}

void dateType::setFullDate(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

int dateType::getDay() const {
	return day;
}

int dateType::getMonth() const {
	return month;
}

int dateType::getyear() const {
	return year;
}

string dateType::getDate() const {
	return to_string(day) + "-" + to_string(month) + "-" + to_string(year);
}

void dateType::print() const {
	cout << "Date is " << day << "-" << month << "-" << year << endl;
}

ostream& operator<<(ostream& osObject, const dateType& date1) {
	osObject << date1.day << "-" << date1.month << "-" << date1.year;
	cout << endl;
	return osObject;
}

// overloading cin to read data in
istream& operator >> (istream& isObject, dateType& date1) {
	isObject >> date1.day >> date1.month >> date1.year;
	return isObject;
}

// overloading comparison operators
bool dateType::operator==(const dateType& otherDate) const {
	return (day == otherDate.day && month == otherDate.month && year == otherDate.year);
}

bool dateType::operator<(const dateType& otherDate) const {
	if (year < otherDate.year) {
		return true;
	}
	else if (year > otherDate.year) {
		return false;
	}
	// years are equal
	else {
		if (month < otherDate.month) {
			return true;
		}
		else if (month > otherDate.month) {
			return false;
		}
		// months are equal
		else {
			if (day < otherDate.day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
bool dateType::operator>(const dateType& otherDate) const {
	if (year > otherDate.year) {
		return true;
	}
	else if (year < otherDate.year) {
		return false;
	}
	// years are equal
	else {
		if (month > otherDate.month) {
			return true;
		}
		else if (month < otherDate.month) {
			return false;
		}
		// months are equal
		else {
			if (day > otherDate.day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}