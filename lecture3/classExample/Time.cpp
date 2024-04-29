#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

Time::Time() {
	hours = 0;
	mins = 0;
	secs = 0;
}

Time::Time(int h, int m, int s) {
	hours = h;
	mins = m;
	secs = s;
}

Time::~Time() {}

void Time::setHours(int h) {
	hours = h;
}

void Time::setMins(int m) {
	mins = m;
}

void Time::setSecs(int s) {
	secs = s;
}

void Time::setFullTime(int h, int m, int s) {
	hours = h;
	mins = m;
	secs = s;
}

int Time::getHours() const {
	return hours;
}

int Time::getMins() const {
	return mins;
}

int Time::getSecs() const {
	return secs;
}

string Time::getTime() const {
	return to_string(hours) + ":" + to_string(mins) + ":" + to_string(secs);
}

void Time::print() const {
	cout << "Time is " << hours << ":" << mins << ":" << secs << endl;
}

bool Time::operator==(const Time& otherTime) const {
	return (hours == otherTime.hours && mins == otherTime.mins && secs == otherTime.secs);
}