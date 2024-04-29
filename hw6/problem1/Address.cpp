#include "Address.h"
#include <iostream>
#include <string>

using namespace std;

Address::Address(int b, int u, int f, string s, string c, string co, int p) {
	block = b;
	unit = u;
	floor = f;
	street = s;
	city = c;
	country = co;
	postalCode = p;
}

Address::~Address() {}

// getters
int Address::getBlock() const {
	return block;
}
int Address::getUnit() const {
	return unit;
}
int Address::getFloor() const {
	return floor;
}
string Address::getStreet() const {
	return street;
}
string Address::getCity() const {
	return city;
}
string Address::getCountry() const {
	return country;
}
int Address::getPostalCode() const {
	return postalCode;
}

// setters
void Address::setBlock(int b) {
	block = b;
}
void Address::setUnit(int u) {
	unit = u;
}
void Address::setFloor(int f) {
	floor = f;
}
void Address::setStreet(string s) {
	street = s;
}
void Address::setCity(string c) {
	city = c;
}
void Address::setCountry(string c) {
	country = c;
}
void Address::setPostalCode(int p) {
	postalCode = p;
}
void Address::setWholeAddress(int b, int u, int f, string s, string c, string co, int p) {
	block = b;
	unit = u;
	floor = f;
	street = s;
	city = c;
	country = co;
	postalCode = p;
}

ostream& operator << (ostream& osObject, const Address& a1) {
	osObject << a1.block << " " << a1.unit << " " << a1.floor << " " << a1.street << " " << a1.city << " " << a1.country << " " << a1.postalCode;
	return osObject;
}
