#include <iostream>
#include "dayType.h"

using namespace std;

int main() {
	int day;
	cout << "Enter a day of the week as a number. Sunday = 0 and Saturday = 6. " << endl;
	cin >> day;
	dayType myDay(day);
	myDay.print();
	int numDays;
	cout << "Enter the number of days to add: " << endl;
	cin >> numDays;
	cout << "Your new day is: " << myDay.calcDay(numDays) << endl;
	return 0;
}