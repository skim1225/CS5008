#include <string>
#include <iostream>

using namespace std;

class Address
{
	friend ostream& operator << (ostream&, const Address&);

private:
	int block;
	int unit;
	int floor;
	string street;
	string city;
	string country;
	int postalCode;

public:

	// constructor and destructor
	Address(int b, int u, int f, string s, string c, string co, int p);
	~Address();

	// getters
	int getBlock() const;
	int getUnit() const;
	int getFloor() const;
	string getStreet() const;
	string getCity() const;
	string getCountry() const;
	int getPostalCode() const;

	// setters
	void setBlock(int b);
	void setUnit(int u);
	void setFloor(int f);
	void setStreet(string s);
	void setCity(string c);
	void setCountry(string c);
	void setPostalCode(int p);
	void setWholeAddress(int b, int u, int f, string s, string c, string co, int p);
};

