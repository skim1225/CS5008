#include <iostream>
#include <iomanip>
using namespace std;

double getBillingAmount(double rate, int totalTime, bool lowIncome);

// constants
double const LOW_INCOME_RATIO = 0.4;
int const LOW_INCOME_TIME_LIMIT = 30;
double const NORMAL_INCOME_RATIO = 0.7;
int const NORMAL_INCOME_TIME_LIMIT = 20;
int const LOW_INCOME_THRESHOLD = 25000;
int const MINS_TO_HOURS = 60;

int main() {
	double hourlyRate;
	int totalTime;
	int yearlyIncome;
	bool lowIncome;
	double billingAmount;

	// get info from user
	cout << "Enter yearly income: " << endl;
	cin >> yearlyIncome;
	cout << "Enter the hourly rate: " << endl;
	cin >> hourlyRate;
	cout << "Enter consulting time in minutes: " << endl;
	cin >> totalTime;

	// determine whether user is low income
	lowIncome = yearlyIncome <= LOW_INCOME_THRESHOLD;

	// calculate billing amount
	billingAmount = getBillingAmount(hourlyRate, totalTime, lowIncome);

	// output formatted billing amount to user
	cout << fixed << showpoint << setprecision(2);
	cout << "The billing amount is: " << billingAmount << endl;

	return 0;
}


// helper method to calculate billing amountgiti
double getBillingAmount(double rate, int totalTime, bool lowIncome) {
	double billingAmount;
	double hours;

	// calculates rate for low income clients
	if (lowIncome) {
		if (totalTime <= LOW_INCOME_TIME_LIMIT) {
			billingAmount = 0;
		}
		else {
			hours = (double)(totalTime - LOW_INCOME_TIME_LIMIT) / MINS_TO_HOURS;
			billingAmount = LOW_INCOME_RATIO * hours * rate;
		}
	}

	// calculates rate for non-low income clients
	else {
		if (totalTime <= NORMAL_INCOME_TIME_LIMIT) {
			billingAmount = 0;
		}
		else {
			hours = (double)(totalTime - NORMAL_INCOME_TIME_LIMIT) / 60;
			billingAmount = NORMAL_INCOME_RATIO * hours * rate;
		}
	}
	return billingAmount;
}