#include "BST.h"
#include <iostream>

using namespace std;

BST::BST() {
	root = NULL;
}

BST::~BST() {
	destroy(root);
}

void BST::insert(const int insertItem) {
	nodeType* curr;
	nodeType* trailCurr = NULL;
	nodeType* newNode;

	newNode = new nodeType;
	newNode->info = insertItem;
	newNode->lLink = NULL;
	newNode->rLink = NULL;

	if (root == NULL) {
		root = newNode;
	}
	else {
		curr = root;
		while (curr != NULL) {
			trailCurr = curr;
			if (insertItem == curr->info) {
				cout << "Duuplicates not allowed. Value: " << insertItem << endl;
			}
			else if (insertItem < curr->info) {
				curr = curr->lLink;
			}
			else {
				curr = curr->rLink;
			}
		}
		if (insertItem < trailCurr->info) {
			trailCurr->lLink = newNode;
		}
		else {
			trailCurr->rLink = newNode;
		}
	}
}

bool BST::isEmpty() const {
	return root == NULL;
}

bool BST::search(const int searchItem) const {
	nodeType* curr;
	bool found = false;
	if (root == NULL) {
		cout << "Cannot search an empty tree." << endl;
	}
	else {
		curr = root;
		while (curr != NULL && !found) {
			if (curr->info == searchItem) {
				found = true;
			}
			else if (curr->info > searchItem) {
				curr = curr->lLink;
			}
			else {
				curr = curr->rLink;
			}
		}
	}
	return found;
}

void BST::deleteNode(const int deleteItem) {
	
}

void BST::destroy(nodeType*& p) {
	if (p != NULL) {
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = NULL;
	}
}

void BST::preOrderTraversal() const {
	return preorder(root);
}

void BST::inOrderTraversal() const {
	return inorder(root);
}

void BST::postOrderTraversal() const {
	return postorder(root);
}

void BST::preorder(nodeType* p) const {
	if (p != NULL) {
		cout << p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}

void BST::inorder(nodeType* p) const {
	if (p != NULL) {
		inorder(p->lLink);
		cout << p->info << " ";
		inorder(p->rLink);
	}
}

void BST::postorder(nodeType* p) const {
	if (p != NULL) {
		postorder(p->lLink);
		postorder(p->rLink);
		cout << p->info << " ";
	}
}
