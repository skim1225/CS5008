#include "bookType.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// constructors
bookType::bookType() {
	title = "default title";
	authors[0] = "default author";
	publisher = "default publisher";
	isbn = "default isbn";
	price = 1.0;
	num_copies = 1;
	num_authors = 1;
}

bookType::bookType(string title_arg, string authors_arg[], string publisher_arg, string isbn_arg, double price_arg, int num_copies_arg, int num_authors_arg) {
	title = title_arg;
	copy(authors_arg[0], authors_arg[3], authors);
	publisher = publisher_arg;
	isbn = isbn_arg;
	price = price_arg;
	num_copies = num_copies_arg;
	num_authors = num_authors_arg;
}

// destructor
bookType::~bookType() {}

// getters
string bookType::get_title() const {
	return title;
}

string* bookType::get_authors() const {
	string* authorsCopy = new string[4];
	for (int i = 0; i < 4; i++) {
		authorsCopy[i] = authors[i];
	}
	return authorsCopy;
}
string bookType::get_publisher() const {
	return publisher;
}
string bookType::get_isbn() const {
	return isbn;
}
double bookType::get_price() const {
	return price;
}
int bookType::get_num_copies() const {
	return num_copies;
}
int bookType::get_num_authors() const {
	return num_authors;
}

// setters
void bookType::set_title(string title_arg) {
	title = title_arg;
}
void bookType::set_authors(string authors_arg[]) {
	copy(authors_arg[0], authors_arg[3], authors);
}
void bookType::set_publisher(string publisher_arg) {
	publisher = publisher_arg;
}
void bookType::set_isbn(string isbn_arg) {
	isbn = isbn_arg;
}
void bookType::set_price(double price_arg) {
	price = price_arg;
}
void bookType::set_num_copies(int num_copies_arg) {
	num_copies = num_copies_arg;
}
void bookType::set_num_authors(int num_authors_arg) {
	num_authors = num_authors_arg;
}
void bookType::setBookInfo(string title_arg, string isbn_arg, string publisher_arg, string authors_arg[],
	double price_arg, int num_copies_arg, int num_authors_arg) {
	title = title_arg;
	copy(authors_arg[0], authors_arg[3], authors);
	publisher = publisher_arg;
	isbn = isbn_arg;
	price = price_arg;
	num_copies = num_copies_arg;
	num_authors = num_authors_arg;
}


// updaters
void bookType::update_num_copies(int change) {
	num_copies += change;
}

// display
void bookType::display_title() const {
	cout << "Title: " << title << endl;
}
void bookType::display_authors() const {
	cout << "Authors: " << authors << endl;
}
void bookType::display_publisher() const {
	cout << "Publisher: " << publisher << endl;
}
void bookType::display_isbn() const {
	cout << "ISBN: " << isbn << endl;
}
void bookType::display_price() const {
	cout << "Price: " << price << endl;
}
void bookType::display_num_copies() const {
	cout << "Number of copies: " << num_copies << endl;
}
void bookType::display_num_authors() const {
	cout << "Number of authors: " << num_authors << endl;
}

void bookType::printInfo() const {
	display_title();
	display_authors();
	display_publisher();
	display_isbn();
	display_price();
	display_num_copies();
	display_num_authors();
}

ostream& operator << (ostream& osObject, const bookType& book1) {
	osObject << "Title: " << book1.title << "Author: " << book1.authors[0] << "Publisher: " << book1.publisher
		<< "ISBN: " << book1.isbn << "Price: " << book1.price << "Number of copies: " << book1.num_copies << "Number of authors: " << book1.num_authors;
}

// check
bool bookType::isTitle(string s) const {
	return s == title;
}
bool bookType::isISBN(string s) const {
	return s == isbn;
}
bool bookType::isAuthor(string s) const {
	for (int i = 0; i < 4; i++) {
		if (s == authors[i]) {
			return true;
		}
	}
	return false;
}

bool bookType::isInStock() const {
	return num_copies > 0;
}