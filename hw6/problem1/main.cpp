#include <map>
#include <string>
#include <iostream>
#include "Person.h"
#include "Address.h"

using namespace std;

int main() {

	map<Person, Address> addressBook;

	Person p1("Alice", "A", "Anne");
	Person p2("Bobbie", "Brown", "Butters");
	Person p3("Charlie", "C", "Can");
	Person p4("David", "Drussel", "Dan");
	Address a1(1,1,1,"First Street","Bellevue","USA",1);
	Address a2(2,2,2,"Second Street","Seattle","USA", 2);
	Address a3(3,3,3,"Third Street","Seoul","Korea",3);
	Address a4(4,4,4,"Fourth Ave","Paris","France",4);

	addressBook.insert(pair<Person, Address>(p1, a1));
	addressBook.insert(pair<Person, Address>(p2, a2));
	addressBook.insert(pair<Person, Address>(p3, a3));
	addressBook.insert(pair<Person, Address>(p4, a4));

	map<Person, Address>::iterator itr;

	cout << "My address book: " << endl;
	for (itr = addressBook.begin(); itr != addressBook.end(); ++itr) {
		cout << itr->first << ": " << itr->second << "\n";
	}

	return 0;
}