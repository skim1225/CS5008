#include <string>
#include <iostream>

using namespace std;

class Date {

	friend ostream& operator << (ostream&, const Date&);
	friend istream& operator >> (istream&, Date&);

public:
	// Constructors
	Date();
	Date(int day, int month, int year);

	// Destructor
	~Date();

	// Getters 
	int getDay() const;
	int getMonth() const;
	int getyear() const;
	string getDate() const;

	// Setters
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setFullDate(int day, int month, int year);

	// Print
	void print() const;

	// ==
	bool operator==(const Date& otherDate) const;


private:
	int day;
	int month;
	int year;
};

