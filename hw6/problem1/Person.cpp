#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person() {
    firstName = "John";
    middleName = "Jill";
    lastName = "James";
}

Person::Person(string fn, string mn, string ln) {
    firstName = fn;
    middleName = mn;
    lastName = ln;
}

// Destructor
Person::~Person() {}

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

void Person::print() const {
    cout << "Name is " << firstName + " " + middleName + " " + lastName << endl;
}

void Person::read_input() {
    cout << "Please enter first name, middle name, and last name: " << endl;
    cin >> firstName >> middleName >> lastName;
    //    setFullName(firstName, middleName, lastName);

}

// Overloading cout << to print the object
ostream& operator << (ostream& osObject, const Person& person1) {
    osObject << person1.firstName << " " << person1.middleName << " " << person1.lastName;
    return osObject;
}

// Overloading cin >> to read data into a new object
istream& operator >> (istream& isObject, Person& person1) {
    isObject >> person1.firstName >> person1.middleName >> person1.lastName;
    return isObject;
}

// Overloading ==
bool Person::operator==(const Person& otherPerson) const {
    if (firstName == otherPerson.firstName && middleName == otherPerson.middleName &&
        lastName == otherPerson.lastName)
        return true;
    else
        return false;
}

bool Person::operator<(const Person& otherPerson) const {
    if ((lastName < otherPerson.lastName) ||
        (lastName == otherPerson.lastName && middleName < otherPerson.middleName) ||
        (lastName == otherPerson.lastName && middleName == otherPerson.middleName && firstName < otherPerson.firstName)
        )
        return true;
    else
        return false;
};

bool Person::operator!=(const Person& otherPerson) const {
    return !(*this == otherPerson);
};

bool Person::operator>=(const Person& otherPerson) const {
    return !(*this < otherPerson);
};


bool Person::operator<=(const Person& otherPerson) const {
    return (*this < otherPerson || *this == otherPerson);
};


bool Person::operator>(const Person& otherPerson) const {
    return !(*this <= otherPerson);
};

