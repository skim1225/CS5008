#include <iostream>
#include <vector>
#include <string>
#include "Person.h"

using namespace std;

int main() {
	vector <int> list1;
	vector <string> list2;
	vector <Person> list3;

	Person p1("A","B","C");
	Person p2("D", "E", "F");
	Person p3("G", "H", "I");

	list1.push_back(31);
	list2.push_back("Andy");
	list3.push_back(p1);

	list1.push_back(25);
	list2.push_back("Jim");
	list3.push_back(p2);

	list1.push_back(35);
	list2.push_back("Tom");
	list3.push_back(p3);

	for (int i = 0; i < 3; i++) {
		cout << list1[i] << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << list2[i] << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << list3[i] << endl;
	}

	return 0;
}