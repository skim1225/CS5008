#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

// class name :: method name 
// implements deafult constructor
Person::Person() {
	firstName = "John";
	middleName = "Jill";
	lastName = "Jane";
}

// implement specific constructor
Person::Person(string fn, string mn, string ln) {
	firstName = fn;
	middleName = mn;
	lastName = ln;
}

// destructor
Person::~Person() {}

// setters
void Person::setFirstName(string fn) {
	firstName = fn;
}

void Person::setMiddleName(string mn) {
	middleName = mn;
}

void Person::setLastName(string ln) {
	lastName = ln;
}

void Person::setFullName(string fn, string mn, string ln) {
	firstName = fn;
	middleName = mn;
	lastName = ln;
}

// getters 
string Person::getFirstName() const {
	return firstName;
}

string Person::getMiddleName() const {
	return middleName;
}

string Person::getLastName() const {
	return lastName;
}

string Person::getFullName() const {
	return firstName + " " + middleName + " " + lastName;
}

// print
void Person::print() const {
	cout << "Name is " << firstName << " " << middleName << " " << lastName << endl;
}

void Person::read_input() {
	cout << "Please enter first, middle, last name: " << endl;
	cin >> firstName >> middleName >> lastName;
}

// overloading cout to print the object
ostream& operator<<(ostream& osObject, const Person& person1) {
	osObject << person1.firstName << " " << person1.middleName << " " << person1.lastName;
	return osObject;
}

// overloading cin to read data in
istream& operator >> (istream& isObject, Person& person1) {
	isObject >> person1.firstName >> person1.middleName >> person1.lastName;
	return isObject;
}