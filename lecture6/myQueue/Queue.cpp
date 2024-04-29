// Sooji Kim
// CS5008 Lec6
// 11 March 2024

#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
	len = 0;
	first = 0;
	last = -1;
}

Queue::~Queue() {}

void Queue::enqueue(int i) {
	if (!full()) {
		len++;
		last = (last + 1) % 10;
		list[last] = i;
	}
	else {
		cout << "Queue is full. " << endl;
	}
}

bool Queue::dequeue() {
	int val;
	if (!empty()) {
		val = list[first];
		first = (first + 1) % 10;
		len--;
		if (empty()) {
			first = 0;
			last = -1;
		}
		return true;
	}
	else {
		cout << "Queue is empty." << endl;
		return false;
	}
}

int Queue::front() const {
	if (empty()) {
		cout << "Queue is empty. " << endl;
		return -1;
	} 
	return list[first];
}

int Queue::back() const {
	if (empty()) {
		cout << "Queue is empty. " << endl;
		return -1;
	}
	return list[last];
}

bool Queue::empty() const {
	return len == 0;
}

bool Queue::full() const {
	return len == 10;
}
