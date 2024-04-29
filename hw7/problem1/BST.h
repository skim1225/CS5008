#include "dateType.h"
#include <iostream>
using namespace std;
struct nodeType
{
    dateType info;
    nodeType* lLink;
    nodeType* rLink;
};
class BST
{
public:
    BST();
    ~BST();
    nodeType* getRoot();
    bool search(const dateType searchItem) const;
    void insert(const dateType insertItem);
    nodeType* deleteNode(nodeType* curr, const dateType deleteItem);
    nodeType* minValueNode(nodeType* node);
    bool isEmpty() const;
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    void destroy(nodeType*& p);
private:
    void inorder(nodeType* p) const;
    void preorder(nodeType* p) const;
    void postorder(nodeType* p) const;
    nodeType* root;
};
