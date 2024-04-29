// Sooji Kim
// CS5008 Lec6
// 11 March 2024

class Queue
{
private:
	int list[10];
	int len;
	int first;
	int last;

public:
	Queue();
	~Queue();
	void enqueue(int i);
	bool dequeue();
	int front() const;
	int back() const;
	bool empty() const;
	bool full() const;
};

