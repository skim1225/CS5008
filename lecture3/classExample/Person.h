#include <string>
#include <iostream>

using namespace std;

class Person {

	friend ostream& operator << (ostream&, const Person&);
	friend istream& operator >> (istream&, Person&);

public:
	// Constructors
	Person();
	Person(string fn, string mn, string ln);

	// Destructor
	~Person();

	// Getters 
	string getFirstName() const;
	string getMiddleName() const;
	string getLastName() const;
	string getFullName() const;

	// Setters
	void setFirstName(string fn);
	void setMiddleName(string mn);
	void setLastName(string ln);
	void setFullName(string fn, string mn, string ln);

	// Print
	void print() const;
	void read_input();

	// ==
	bool operator==(const Person& otherPerson) const;


private:
	string firstName;
	string middleName;
	string lastName;
};
