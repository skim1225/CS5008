// Sooji Kim
// CS5008 HW5
// 6 March 2024

struct nodeType {
	int info;
	nodeType* next;
	nodeType* prev;
};

class doublyLinkedList
{

public:
	// constructor
	doublyLinkedList();
	// destructor
	~doublyLinkedList();
	// return first element
	nodeType* front() const;
	// return last element
	nodeType* back() const;
	// return if node with given info exists
	bool search(int searchItem) const;
	// adds node with given info to the end of the list
	void append(int addItem);
	// adds node with given info to start of the list
	void prepend(int addItem);
	// insert node with given info after the given node
	void insertAfter(int insertItem, nodeType* currNode);
	// delete given node from the list
	void deleteNode(nodeType* curr);
	// prints the list
	void print() const;
	// prints the linkedlist in reverse
	void printR() const;
	// gets the length of the list
	int getLength() const;

private:
	nodeType* head;
	nodeType* tail;
	int len;

};

