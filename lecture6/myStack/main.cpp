// Sooji Kim
// CS5008 Lecture 6
// 11 March 2024

#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
	// testing my stack
	Stack myStack;
	myStack = Stack();
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	while (!myStack.empty()) {
		cout << myStack.top() << endl;
		myStack.pop();
	}

	return 0;
}