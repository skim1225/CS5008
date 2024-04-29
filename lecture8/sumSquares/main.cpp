#include <iostream>
using namespace std;

int sumSquares(int num);

int main() {
	int num;
	cout << "Enter a number to find the sum of squares up to that number: " << endl;
	cin >> num;
	cout << "Answer: " << sumSquares(num);
	return 0;
}

int sumSquares(int num) {
	if (num == 0) {
		return 0;
	}
	else {
		return num * num + sumSquares(num - 1);
	}
}