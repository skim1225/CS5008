#include "DVD.h"
#include <iostream>

using namespace std;

// constructor/destructor
DVD::DVD(string t, vector<string> s, string p, string d, string pc, int n) {
	title = t;
	stars = s;
	producer = p;
	director = d;
	productionCompany = pc;
	numCopies = n;
}

DVD::~DVD() {}

// setters
void DVD::setTitle(string t) {
	title = t;
}
void DVD::setStars(vector<string> s) {
	stars = s;
}
void DVD::setProducer(string p) {
	producer = p;
}
void DVD::setDirector(string d) {
	director = d;
}
void DVD::setProductionCompany(string pc) {
	productionCompany = pc;
}
void DVD::setNumCopies(int n) {
	numCopies = n;
}

// getters
string DVD::getTitle() const {
	return title;
}
vector<string> DVD::getStars() const {
	return stars;
}
string DVD::getProducer() const {
	return producer;
}
string DVD::getDirector() const {
	return director;
}
string DVD::getProductionCompany() const {
	return productionCompany;
}
int DVD::getNumCopies() const {
	return numCopies;
}

// overloading comparison
bool DVD::operator==(const DVD& otherDVD) const {
	return title == otherDVD.title;
}
bool DVD::operator<(const DVD& otherDVD) const {
	return title < otherDVD.title;
}
bool DVD::operator>(const DVD& otherDVD) const {
	return title > otherDVD.title;
}