#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "bookType.h"

using namespace std;

int main() {
	// problem 1:
	// declare array of 100 components of booktype
	bookType myLibrary[100];
	string authors1[] = { "Anna Wiener" };
	bookType book1("Uncanny Valley", authors1, "MCD", "978-0-374-27801-4", 27.00, 1, 1);
	string authors2[] = { "James Clear" };
	bookType book2("Atomic Habits", authors2, "Penguin Random House", "978-0-7352-1129-2", 27.00, 1, 1);
	string authors3[] = { "Nick Lane" };
	bookType book3("The Vital Question", authors3, "W W Norton", "978-0-393-35297-9", 17.95, 1, 1);
	myLibrary[0] = book1;
	myLibrary[1] = book2;
	myLibrary[3] = book3;
	// search for a book by title
	cout << "Enter the title of a book to find out whether it exists in the library: " << endl;
	string title;
	cin >> title;
	for (int i = 0; i < 100; i++) {
		if (myLibrary[i].isTitle(title)) {
			cout << "Your book exists in the collection." << endl;
		}
	}
	// search for book by isbn
	cout << "Enter the isbn of a book to find out whether it exists in the library: " << endl;
	string isbn;
	cin >> isbn;
	for (int i = 0; i < 100; i++) {
		if (myLibrary[i].isISBN(isbn)) {
			cout << "Your book exists in the collection." << endl;
		}
	}
	// update num copies by isbn
	cout << "Enter the isbn of the book in the library you wish to update: " << endl;
	cin >> isbn;
	cout << "Enter the number of copies you wish to update the book by: " << endl;
	int num;
	cin >> num;
	for (int i = 0; i < 100; i++) {
		if (myLibrary[i].isISBN(isbn)) {
			myLibrary[i].update_num_copies(num);
		}
	}

	return 0;
}