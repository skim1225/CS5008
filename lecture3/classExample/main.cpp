#include <iostream>
#include <string>
#include "Person.h"
#include "Date.h"
#include "Time.h"

using namespace std;

int main() {
	Person p1;
	p1.print();
	Person p2("Soo", "Ji", "Kim");
	p2.print();
	p2.setLastName("Ling");
	p2.print();
	Person p3;
	cout << p3 << endl;
	Date d1;
	d1.print();
	Date d2(1, 29, 2024);
	d2.print();
	Time t1;
	t1.print();
	Time t2(16, 14, 0);
	t2.print();
	return 0;
}