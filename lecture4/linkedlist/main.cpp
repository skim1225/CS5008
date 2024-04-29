#include <iostream>
using namespace std;

struct nodeType {
	int info;
	nodeType* link;
};

// create a new linked list containing user-provided data
int main() {
	nodeType *head, *last, *newNode, *curr, *first, *trailCurr;
	head = nullptr;
	last = nullptr;
	curr = nullptr;
	first = nullptr;
	trailCurr = nullptr;
	bool found;
	int delnum;
	int num;

	cout << "Enter a list of integers ending with -999." << endl;
	cin >> num;
	while (num != -999) {
		newNode = new nodeType;
		newNode->info = num;
		newNode->link = nullptr;
		if (head == nullptr) {
			head = newNode;
			last = newNode;
		}
		else {
			last->link = newNode;
			last = newNode;
		}
		cout << "Enter the next number: " << endl;
		cin >> num;
	}
	// print linked list
	curr = head;
	while (curr != nullptr) {
		cout << curr->info << endl;
		curr = curr->link;
	}

	// delete the second node in the list
	nodeType* temp;
	temp = head->link;
	head->link = temp->link;
	delete temp;

	// print linkedlist after deletion
	cout << "After deleting 2nd node: " << endl;
	curr = head;
	while (curr != nullptr) {
		cout << curr->info << endl;
		curr = curr->link;
	}

	// delete a specific node
	int delnum;
	cout << "Enter a value to delete: " << endl;
	cin >> delnum;
	// case 1: list is empty
	if (head == nullptr) {
		cout << "Cannot delete from empty list." << endl;
	}
	// case 2: list is not empty
	else if (head->info == delnum) {
		// case 2a: head is only node in list
		if (head->link == nullptr) {
			delete head;
		}
		// case 2b: head is not only node in list
		else {
			curr = head;
			head = head->link;
			delete curr;
		}
	}
	// else, search list for delnum
	else {
		found = false;
		trailCurr = head;
		curr = head->link;
		while (curr != nullptr && !found) {
			if (curr->info != delnum) {
				curr = curr->link;
			}
		}
		// case 3: list is not empty and delnum is not head
		if (found) {
			trailCurr -> link = curr->link;
			if (last == curr) {

			}
		}
		// case 4: delnum is not in list
		else {
			cout << "The number to delete is not in the list. " << endl;
		}
	}
	return 0;
}
