// Sooji Kim
// CS5008 Lecture 6
// 11 March 2024

#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
	len = 0;
}

Stack::~Stack() {}

void Stack::push(int i) {
	if (!full()) {
		list[len] = i;
		len++;
	}
	else {
		cout << "The stack is full." << endl;
	}
}

bool Stack::pop() {
	if (empty()) {
		cout << "The stack is empty. " << endl;
		return false;
	}
	else {
		len--;
		return true;
	}
}

int Stack::top() const {
	if (empty()) {
		cout << "The stack is empty. " << endl;
		return -1;
	}
	else {
		return list[len - 1];
	}
}

int Stack::length() const {
	return len;
}

bool Stack::empty() const {
	return len == 0;
}

bool Stack::full() const {
	return len == 10;
}