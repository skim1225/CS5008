#include <string>
#include <iostream>

using namespace std;

class dayType {

public:
	dayType();
	dayType(int input);

	~dayType();

	string getDay() const;
	string getNextDay() const;
	string getPreviousDay() const;

	void setDay(int day);
	
	void print() const;

	string calcDay(int numDays);

private:
	int day;
	const string DAYS[7] = {"sun", "mon", "tues", "wed", "thurs", "fri", "sat" };
};