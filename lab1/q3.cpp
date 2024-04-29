#include <iostream>

using namespace std;

int main() {

	double const TAX = 0.14;
	double hourly_rate;
	int hours_worked = 0;
	int curr_hours;
	double income;
	double net_income;
	double clothes;
	double supplies;
	double remaining_income;
	double bonds;
	double addl_bonds;

	cout << "Enter the pay rate for an hour: " << endl;
	cin >> hourly_rate;
	cout << "Enter the number of hours worked week 1: " << endl;
	cin >> curr_hours;
	hours_worked += curr_hours;
	cout << "Enter the number of hours worked week 2: " << endl;
	cin >> curr_hours;
	hours_worked += curr_hours;
	cout << "Enter the number of hours worked week 3: " << endl;
	cin >> curr_hours;
	hours_worked += curr_hours;
	cout << "Enter the number of hours worked week 4: " << endl;
	cin >> curr_hours;
	hours_worked += curr_hours;
	cout << "Enter the number of hours worked week 5: " << endl;
	cin >> curr_hours;
	hours_worked += curr_hours;

	income = hourly_rate * hours_worked;
	cout << "Your income before taxes: $" << income << endl;

	net_income = (1 - TAX) * income;
	cout << "Your income after taxes: $" << net_income << endl;

	clothes = 0.1 * net_income;
	supplies = 0.01 * net_income;
	cout << "The amount you spent on clothes and other accessories: $" << clothes << endl;
	cout << "The amount you spent on school supplies: $" << supplies << endl;

	remaining_income = net_income - (clothes + supplies);
	bonds = 0.25 * remaining_income;
	cout << "The amount you spent on savings bonds: $" << bonds << endl;

	addl_bonds = static_cast<int> (bonds) * .5;
	cout << "The money your parents spent to buy additional bonds: $" << addl_bonds << endl;

	return 0;
}
