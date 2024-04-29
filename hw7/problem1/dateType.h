#include <string>
#include <iostream>

using namespace std;

class dateType {

	friend ostream& operator << (ostream&, const dateType&);
	friend istream& operator >> (istream&, dateType&);

public:
	// Constructors
	dateType();
	dateType(int day, int month, int year);

	// Destructor
	~dateType();

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
	bool operator==(const dateType& otherDate) const;
	bool operator<(const dateType& otherDate) const;
	bool operator>(const dateType& otherDate) const;


private:
	int day;
	int month;
	int year;
};
