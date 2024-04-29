#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack <string> mystack;
	string input;
	for (int i = 0; i < 5; i++) {
		cout << "Enter a flower name: " << endl;
		cin >> input;
		mystack.push(input);
	}
	cout << "Display in reverse order: " << endl;
	while (!mystack.empty()) {
		cout << mystack.top() << " ";
		mystack.pop();
	}
	return 0;
}