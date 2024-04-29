#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int acc_number;
	char acc_type;
	double min_balance;
	double curr_balance;

	cout << "Enter the account number: " << endl;
	cin >> acc_number;
	cout << "Enter the account type (S for savings or C for checking): " << endl;
	cin >> acc_type;
	cout << "Enter the minimum balance that the account should maintain: " << endl;
	cin >> min_balance;
	cout << "Enter the current balance: " << endl;
	cin >> curr_balance;

	cout << fixed << showpoint << setprecision(2);

	if (curr_balance < min_balance) {
		if (acc_type == 'S' || acc_type == 's') {
			curr_balance -= 10;
			cout << "An overdraft fee of $10 has been charged." << endl;
		}
		else {
			curr_balance -= 25;
			cout << "An overdraft fee of $25 has been charged." << endl;
		}
	}
	else {
		if (acc_type == 'C' || acc_type == 'c') {
			curr_balance *= 1.04;
			cout << "4% interest has been added." << endl;
		}
		else {
			if (curr_balance <= (min_balance + 5000)) {
				curr_balance *= 1.03;
				cout << "3% interest has been added." << endl;
			}
			else {
				curr_balance *= 1.05;
				cout << "5% interest has been added." << endl;
			}
		}
	}

	cout << acc_number << " " << acc_type << " " << min_balance << " " << curr_balance;

	return 0;
}
