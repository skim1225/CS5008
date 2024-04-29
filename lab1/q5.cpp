#include <iostream>

using namespace std;

int main() {
	int evenSum = 0;
	int oddSum = 0;
	char curr;

	cout << "Enter an integer or press 'x' to quit." << endl;
	cin >> curr;

	while (curr != 'x') {
		curr = int(curr) - 48;
		if (curr % 2 == 0) {
			evenSum += curr;
		}
		else {
			oddSum += curr;
		}
		cin >> curr;
	}

	cout << "The sum of even integers: " << evenSum << endl;
	cout << "The sum of odd integers: " << oddSum << endl;

	return 0;
}
