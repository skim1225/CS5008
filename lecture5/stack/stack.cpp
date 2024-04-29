#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> myStack;
	int num;
	for (int i = 0; i < 10; i++) {
		cout << "Enter a number: " << endl;
		cin >> num;
		myStack.push(num);
	}
	while (!myStack.empty()) {
		cout << myStack.top() << endl;
		myStack.pop();
	}
	return 0;
}