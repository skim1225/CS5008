// Sooji Kim
// CS5008 Lec6
// 11 March 2024

#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
	Queue q;
	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}
	q.dequeue();
	q.enqueue(11);
	for (int i = 0; i < 10; i++) {
		cout << q.front() << endl;
		q.dequeue();
	}
	return 0;
}