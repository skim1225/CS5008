#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "bookType.h"

using namespace std;

int main() {
	string authors1[] = { "Anna Wiener" };
	bookType book1("Uncanny Valley", authors1, "MCD", "978-0-374-27801-4", 27.00, 1, 1);
	string authors2[] = { "James Clear" };
	bookType book2("Atomic Habits", authors2, "Penguin Random House", "978-0-7352-1129-2", 27.00, 1, 1);
	string authors3[] = { "Nick Lane" };
	bookType book3("The Vital Question", authors3, "W W Norton", "978-0-393-35297-9", 17.95, 1, 1);
	// store booktype objs in vector
	vector <bookType> booksVector;
	vector <bookType>::iterator itr1;
	// use 5 methods of vector class: push_back, pop_back, insert, size, at
	booksVector.push_back(book1);
	booksVector.push_back(book2);
	cout << "Size of books vector after adding 2 books: " << booksVector.size() << endl;
	cout << "Books vector after adding 2 books: " << endl;
	for (itr1 = booksVector.begin(); itr1 != booksVector.end(); ++itr1) {
		cout << " " << *itr1 << endl;
	}
	booksVector.insert(booksVector.begin() + 1, book3);
	cout << "Books vector after inserting book 3: " << endl;
	for (itr1 = booksVector.begin(); itr1 != booksVector.end(); ++itr1) {
		cout << " " << *itr1 << endl;
	}
	while (!booksVector.empty()) {
		booksVector.pop_back();
	}

	// stack: push, pop, top, size, empty
	stack<bookType> bookStack;
	bookStack.push(book1);
	bookStack.push(book2);
	bookStack.push(book3);
	cout << "The size of book stack after pushing 3 books: " << bookStack.size() << endl;
	cout << "The books in the reverse order they were added: " << endl;
	while (!bookStack.empty()) {
		cout << bookStack.top() << endl;
		bookStack.pop();
	}

	// queue: push, pop, size, front, empty
	queue<bookType> bookQ;
	bookQ.push(book1);
	bookQ.push(book2);
	bookQ.push(book3);
	cout << "The size of book queue after pushing 3 books: " << bookQ.size() << endl;
	cout << "The books in the order they were added: " << endl;
	while (!bookQ.empty()) {
		cout << bookQ.front();
		bookQ.pop();
	}
	return 0;
}