#include <iostream>
#include "BST.h"

using namespace std;

BST::BST()
{
    root = NULL;
}
bool BST::search(const dateType searchItem) const
{
    nodeType* current;
    bool found = false;
    if (root == NULL)
        cout << "Cannot search an empty tree." << endl;
    else
    {
        current = root;
        while (current != NULL && !found)
        {
            if (searchItem == current->info)
                found = true;
            else if (searchItem < current->info)
                current = current->lLink;
            else
                current = current->rLink;
        }
    }
    return found;
}

nodeType* BST::getRoot() {
    return root;
}

void BST::insert(const dateType insertItem)
{
    nodeType* current;
    nodeType* trailCurrent = NULL;
    nodeType* newNode;
    newNode = new nodeType;
    newNode->info = insertItem;
    newNode->lLink = NULL;
    newNode->rLink = NULL;
    if (root == NULL)
        root = newNode;
    else
    {
        current = root;
        while (current != NULL)
        {
            trailCurrent = current;
            if (insertItem == current->info)
            {
                cout << "Duplicates are not "
                    << "allowed. Value: " << insertItem << endl;
                return;
            }
            else
                if (insertItem < current->info)
                    current = current->lLink;
                else
                    current = current->rLink;
        }
        if (insertItem < trailCurrent->info)
            trailCurrent->lLink = newNode;
        else
            trailCurrent->rLink = newNode;
    }
}

nodeType* BST::deleteNode(nodeType* curr, const dateType deleteItem) {
    if (curr == nullptr) {
        return curr;
    }
    if (deleteItem < root->info) {
        root->lLink = deleteNode(root->lLink, deleteItem);
    }
    else if (deleteItem > root->info) {
        root->rLink = deleteNode(root->rLink, deleteItem);
    }
    else {
        if (root->lLink == nullptr) {
            nodeType* temp = root->rLink;
            delete root;
            return temp;
        } else if (root->rLink == nullptr) {
            nodeType* temp = root->lLink;
            delete root;
            return temp;
        }
        nodeType* temp = minValueNode(root->rLink);
        root->info = temp->info;
        root->rLink = deleteNode(root->rLink, temp->info);
    }
    return root;
}

nodeType* BST::minValueNode(nodeType* node) {
    nodeType* curr = node;
    while (curr && curr->lLink != nullptr) {
        curr = curr->lLink;
    }
    return curr;
}

bool BST::isEmpty() const
{
    return (root == NULL);
}
void BST::preorderTraversal() const
{
    preorder(root);
}
void BST::inorderTraversal() const
{
    inorder(root);
}
void BST::postorderTraversal() const
{
    postorder(root);
}
void BST::preorder(nodeType* p) const
{
    if (p != NULL)
    {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}
void BST::postorder(nodeType* p) const
{
    if (p != NULL)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}
void BST::inorder(nodeType* p) const
{
    if (p != NULL)
    {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}
void BST::destroy(nodeType*& p)
{
    if (p != NULL)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = NULL;
    }
}
BST::~BST()
{
    destroy(root);
}
