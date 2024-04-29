// Sooji Kim
// CS5008 Lecture 6
// 11 March 2024

class Stack
{
public:

	Stack();
	~Stack();
	void push(int i);
	bool pop();
	int top() const;
	int length() const;
	bool empty() const;
	bool full() const;

private:
	int list[10];
	int len;
};

