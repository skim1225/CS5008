#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack <double> stack_cal;
	double num1;
	double num2;
	string s;

	while (s != "q") {
		cout << "Enter a number, operator, or q to quit: " << endl;
		cin >> s;

		switch (s[0]) {
			case 'q':
				break;
			case '+':
				// check for at least 2 operands
				if (stack_cal.size() < 2) {
					cout << "Number of operands must be at least 2. " << endl;
				}
				else {
					num2 = stack_cal.top();
					stack_cal.pop();
					num1 = stack_cal.top();
					stack_cal.pop();
					cout << "Current result: " << num1 + num2 << endl;
					stack_cal.push(num1 + num2);
				}
				break;
			case '-':
				if (s.size() != 1) {
					stack_cal.push(stod(s));
				}
				else {
					// check for at least 2 operands
					if (stack_cal.size() < 2) {
						cout << "Number of operands must be at least 2. " << endl;
					}
					else {
						num2 = stack_cal.top();
						stack_cal.pop();
						num1 = stack_cal.top();
						stack_cal.pop();
						cout << "Current result: " << num1 - num2 << endl;
						stack_cal.push(num1 - num2);
					}
				}
				break;
			case '*':
				// check for at least 2 operands
				if (stack_cal.size() < 2) {
					cout << "Number of operands must be at least 2. " << endl;
				}
				else {
					num2 = stack_cal.top();
					stack_cal.pop();
					num1 = stack_cal.top();
					stack_cal.pop();
					cout << "Current result: " << num1 * num2 << endl;
					stack_cal.push(num1 * num2);
				}
				break;
			case '/':
				// check for at least 2 operands
				if (stack_cal.size() < 2) {
					cout << "Number of operands must be at least 2. " << endl;
				}
				else {
					num2 = stack_cal.top();
					stack_cal.pop();
					num1 = stack_cal.top();
					stack_cal.pop();
					cout << "Current result: " << num1 / num2 << endl;
					stack_cal.push(num1 / num2);
				}
				break;
			default:
				stack_cal.push(stod(s));
		}
	}
	return 0;
}