#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double const CARTON_SIZE = 3.78;
	double const UNIT_COST = 0.38;
	double const UNIT_PROFIT = 0.27;

	int total_milk;
	int num_cartons;
	double cost;
	double profit;

	cout << "Enter the total amount of milk purchased in liters." << endl;
	cin >> total_milk;

	num_cartons = ceil(total_milk / CARTON_SIZE);
	cost = total_milk * UNIT_COST;
	profit = UNIT_PROFIT * num_cartons;

	cout << "The number of milk cartons needed: " << num_cartons << endl;
	cout << "The cost of producing milk: $" << cost << endl;
	cout << "The profit for producing milk: $" << profit << endl;

	return 0;
}