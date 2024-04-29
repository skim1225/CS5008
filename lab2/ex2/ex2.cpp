#include <iostream>
using namespace std;
int reverseDigit(int num);

int main() {
	int num;
	cout << "Enter a number to reverse: " << endl;
	cin >> num;
	cout << reverseDigit(num);
	return 0;
}

int reverseDigit(int num) {
	bool isNeg = num < 0;
	if (isNeg) {
		num *= -1;
	}
	int reversed = 0;
	while (num > 0) {
		reversed *= 10;
		int temp = num % 10;
		reversed += temp;
		num /= 10;
	}
	if (isNeg) {
		reversed *= -1;
	}
	return reversed;
}
