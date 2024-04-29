#include "doublyLinkedList.h"
#include <iostream>

using namespace std;

int main() {
	doublyLinkedList myList;
	// add an element
	for (int i = 1; i <= 5; i++) {
		myList.append(i);
	}
	// print the list
	cout << "My linked list: " << endl;
	myList.print();
	cout << endl;
	// remove an element
	nodeType* myHead = myList.front();
	myList.deleteNode(myHead);
	cout << "My linked list after removing the head: " << endl;
	myList.print();
	cout << endl;
	// seach for an elemnent
	cout << "Is 1 in my linked list? " << endl;
	cout << myList.search(1) << endl;
	cout << "Is 2 in my linked list? " << endl;
	cout << myList.search(2) << endl;
	return 0;
}