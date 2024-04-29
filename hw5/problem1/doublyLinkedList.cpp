// Sooji Kim
// CS5008 HW5
// 6 March 2024

#include <iostream>
#include <cassert>
#include "doublyLinkedList.h"

using namespace std;

// constructor
doublyLinkedList::doublyLinkedList() {
	head = nullptr;
	tail = nullptr;
	len = 0;
}

// destructor
doublyLinkedList::~doublyLinkedList() {}

// return first element
nodeType* doublyLinkedList::front() const {
	assert(head != nullptr);
	return head;
}

// return last element
nodeType* doublyLinkedList::back() const {
	assert(tail != nullptr);
	return tail;
}

// gets the length of the list
int doublyLinkedList::getLength() const {
	return len;
}

// return if node with given info exists
bool doublyLinkedList::search(int searchItem) const {
	nodeType* curr = head;
	while (curr->next != nullptr) {
		if (curr->info == searchItem) {
			return true;
		}
		curr = curr->next;
	}
	return false;
}

// adds node with given info to the end of the list
void doublyLinkedList::append(int addItem) {
	nodeType* newNode;
	newNode = new nodeType;
	newNode->info = addItem;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	newNode->next = nullptr;
	if (head == nullptr) {
		newNode->prev = nullptr;
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}


// adds node with given info to the start of the list
void doublyLinkedList::prepend(int addItem) {
	nodeType* newNode;
	newNode = new nodeType;
	newNode->info = addItem;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	newNode->next = nullptr;
	if (head == nullptr) {
		newNode->prev = nullptr;
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

// insert node with given info after the given node
void doublyLinkedList::insertAfter(int insertItem, nodeType* currNode) {
	if (search(currNode->info)) {
		nodeType* curr;
		nodeType* trailCurr;
		nodeType* newNode;
		bool found;
		newNode = new nodeType;
		newNode->info = insertItem;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		// case 1: list empty
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		// case 2: insert after tail
		else if (currNode == tail) {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		else {
			nodeType* next = currNode->next;
			newNode->next = next;
			newNode->prev = currNode;
			currNode->next = newNode;
			next->prev = newNode;
		}
		len += 1;
	}
}

// delete node with given info
void doublyLinkedList::deleteNode(nodeType* curr) {
	if (search(curr->info)) {
		nodeType* next = curr->next;
		nodeType* prev = curr->prev;
		if (next != nullptr) {
			next->prev = prev;
		}
		if (prev != nullptr) {
			prev->next = next;
		}
		if (curr == head) {
			head = next;
		}
		if (curr == tail) {
			tail = prev;
		}
		len -= 1;
	}
}

// prints the linkedlist
void doublyLinkedList::print() const {
	nodeType* curr = head;
	while (curr != nullptr) {
		cout << curr->info;
		curr = curr->next;
	}
}

// prints the linkedlist in reverse
void doublyLinkedList::printR() const {
	nodeType* curr = tail;
	while (curr->prev != nullptr) {
		cout << curr->info;
		curr = curr->prev;
	}
}