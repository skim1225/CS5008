// write a c++ program that reads in 2 intgers and returns the larger
#include <iostream>
using namespace std;

int larger(int& num1, int& num2);

int main() {
	int num1;
	int num2;
	cout << "Enter a number: " << endl;
	cin >> num1;
	cout << "Enter a number: " << endl;
	cin >> num2;
	int largerNum = larger(num1, num2);
	cout << "The larger number is: " << largerNum;
	return 0;
}

int larger(int& num1, int& num2) {
	if (num1 > num2) {
		return num1;
	}
	else {
		return num2;
	}
}