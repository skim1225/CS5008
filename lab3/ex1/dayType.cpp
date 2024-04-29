#include <string>
#include <iostream>
#include "dayType.h"

using namespace std;

dayType::dayType() {
	day = 0;
}

dayType::dayType(int input) {
	day = input;
}

dayType::~dayType() {}

string dayType::getDay() const {
	return DAYS[day];
}

string dayType::getNextDay() const {
	return DAYS[(day + 1) % 7];
}

string dayType::getPreviousDay() const {
	return DAYS[(day - 1) % 7];
}

void dayType::setDay(int input) {
	day = input;
}

void dayType::print() const {
	cout << "Your day is: " << DAYS[day] << endl;
}

string dayType::calcDay(int numDays) {
	return DAYS[(day + numDays) % 7];
}