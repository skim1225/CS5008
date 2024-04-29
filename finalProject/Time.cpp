#include "Time.h"
#include <iostream>

using namespace std;

/**
 * Default constructor for creating a new Time object.
*/
Time::Time() {
	hours = 0;
	mins = 0;
	secs = 0;
}

/**
 * Constructor for creating a new Time object with the given hours, minutes, and seconds.
*/
Time::Time(int h, int m, int s) {
	hours = h;
	mins = m;
	secs = s;
}

/**
 * Default destructor for destroying a Time object.
*/
Time::~Time() {}

/**
 * Sets the hours of the Time to the given int.
*/
void Time::setHours(int h) {
	hours = h;
}

/**
 * Sets the minutes of the Time to the given int.
*/
void Time::setMins(int m) {
	mins = m;
}

/**
 * Sets the seconds of the Time to the given int.
*/
void Time::setSecs(int s) {
	secs = s;
}

/**
 * Sets the hours, minutes, and seconds of the Time to the given ints.
*/
void Time::setFullTime(int h, int m, int s) {
	hours = h;
	mins = m;
	secs = s;
}

/**
 * Returns the hours of the Time, as an int.
*/
int Time::getHours() const {
	return hours;
}

/**
 * Returns the minutes of the Time, as an int.
*/
int Time::getMins() const {
	return mins;
}

/**
 * Returns the seconds of the Time, as an int.
*/
int Time::getSecs() const {
	return secs;
}

/**
 * Returns a string representation of the Time.
*/
string Time::getTime() const {
	return to_string(hours) + ":" + to_string(mins) + ":" + to_string(secs);
}

/**
 * Prints a string representaition of the Time to the console.
*/
void Time::print() const {
	cout << "Time is " << hours << ":" << mins << ":" << secs << endl;
}

/**
 * Overloads the comparison == operator.
*/
bool Time::operator==(const Time& otherTime) const {
	return (hours == otherTime.hours && mins == otherTime.mins && secs == otherTime.secs);
}

/**
 * Overloads the cout << operator.
*/
ostream& operator<<(ostream& osObject, const Time& time1) {
	osObject << time1.hours << ":" << time1.mins << ":" << time1.secs;
	return osObject;
}

/**
 * Overloads the cin >> operator.
*/
istream& operator >> (istream& isObject, Time& time1) {
	isObject >> time1.hours >> time1.mins >> time1.secs;
	return isObject;
}