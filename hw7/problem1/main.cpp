#include "BST.h"
#include <iostream>

using namespace std;

dateType getDate();
void addDate(BST &Btree);
void removeDate(BST &Btree);
void searchDate(BST &Btree);

int main() {
	int option = 0;
	BST Btree;

	while (option != -1) {
		cout << "Enter 1 to add a date, 2 to remove a date, 3 to search for a date, 4 to display all dates in ascending order, or -1 to quit." << endl;
		cin >> option;
		switch (option) {
		case 1:
			addDate(Btree);
			break;
		case 2:
			removeDate(Btree);
			break;
		case 3:
			searchDate(Btree);
			break;
		case 4:
			cout << "In order traversal of the tree: " << endl;
			Btree.inorderTraversal();
			break;
		case -1:
			break;
		default:
			cout << "Enter a valid option!" << endl;
		}
	}
	return 0;
}

void addDate(BST& Btree) {
	dateType dateToAdd = getDate();
	Btree.insert(dateToAdd);
}

void removeDate(BST& Btree) {
	dateType dateToRemove = getDate();
	Btree.deleteNode(Btree.getRoot(), dateToRemove);
}

void searchDate(BST& Btree) {
	dateType dateToSearch = getDate();
	bool ans;
	ans = Btree.search(dateToSearch);
	if (ans) {
		cout << "Element found" << endl;
	}
	else {
		cout << "Element not found" << endl;
	}
}

dateType getDate() {
	int d;
	int m;
	int y;
	cout << "Enter the day of the date: ";
	cin >> d;
	cout << "Enter the month of the date: ";
	cin >> m;
	cout << "Enter the year of the date: ";
	cin >> y;
	dateType date(d, m, y);
	return date;
}