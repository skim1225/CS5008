#include <iostream>

using namespace std;

int main() {

	// init vars for populaation and growth rate for 2 towns, and years
	double pop_a;
	double pop_b;
	double growth_a;
	double growth_b;
	int years = 0;

	// get population and grwoth rate info for 2 towns from user
	cout << "Enter the current population of town A: " << endl;
	cin >> pop_a;
	cout << "Enter the current population of town B (must be greater than town A's): " << endl;
	cin >> pop_b;
	cout << "Enter the growth rate of town A: " << endl;
	cin >> growth_a;
	cout << "Enter the growth rate of town B (must be less than town A's.)" << endl;
	cin >> growth_b;

	// convert given growth rate into a decimal representing a percentage
	growth_a = growth_a / 100 + 1;
	growth_b = growth_b / 100 + 1;

	// simulate pop growth for both towns until pop a >= pop b and keep track of the years
	while (pop_a < pop_b) {
		pop_a *= growth_a;
		pop_b *= growth_b;
		years++;
	}

	// output the years until pop a >= pop b and the populations of each town at that time
	cout << "After " << years << " year(s) the population of town A will be greater than or equal to the population of town B." << endl;
	cout << "After " << years << " years, population of town A: " << static_cast<int> (pop_a) << endl;
	cout << "After " << years << " years, population of town B: " << static_cast<int> (pop_b) << endl;

	return 0;
}
