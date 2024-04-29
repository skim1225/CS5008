#include <string>
#include <iostream>

using namespace std;

class Time {

public:
	Time();
	Time(int hours, int mins, int secs);

	~Time();

	// getters
	int getHours() const;
	int getMins() const;
	int getSecs() const;
	string getTime() const;

	// setters
	void setHours(int h);
	void setMins(int m);
	void setSecs(int s);
	void setFullTime(int h, int m, int s);

	// overloaded
	void print() const;
	bool operator ==(const Time& otherTime) const;

private:
	int hours;
	int mins;
	int secs;
};


