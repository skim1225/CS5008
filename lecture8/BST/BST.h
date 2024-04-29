#pragma once
#include <iostream>
struct nodeType {
	int info;
	nodeType* lLink;
	nodeType* rLink;
};
class BST
{
public:
	BST();
	~BST();
	bool search(const int searchItem) const;
	void insert(const int intsertItem);
	void deleteNode(const int deleteItem);
	bool isEmpty() const;
	void inOrderTraversal() const;
	void preOrderTraversal() const;
	void postOrderTraversal() const;
	void destroy(nodeType*& p);
private:
	void inorder(nodeType* p) const;
	void preorder(nodeType* p) const;
	void postorder(nodeType* p) const;
	nodeType* root;
};

