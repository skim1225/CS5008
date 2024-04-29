#include "BST.h"
#include <iostream>
using namespace std;
int main() {
	BST Btree;
	Btree.insert(10);
	Btree.insert(2);
	Btree.insert(4);
	Btree.insert(100);
	Btree.insert(28);

	// traversals 
	cout << "in order: " << endl;
	Btree.inOrderTraversal();
	cout << endl;
	cout << "pre order: " << endl;
	Btree.preOrderTraversal();
	cout << endl;
	cout << "post order: " << endl;
	Btree.postOrderTraversal();
	cout << endl;

	// search
	cout << "Enter a number to search: " << endl;
	int num;
	cin >> num;
	int found;
	found = Btree.search(num);
	if (found) {
		cout << "Element found" << endl;
	}
	else {
		cout << "Element not found" << endl;
	}

	return 0;
}