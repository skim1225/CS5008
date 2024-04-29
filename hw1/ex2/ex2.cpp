#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	// init vars to store info about tree count and space requirements
	double const PI = 3.14159;
	int len;
	int rad;
	int space;
	int num_trees;
	double space_used;

	// set output to 2 sig figs
	cout << fixed << showpoint << setprecision(2);

	// get yard dimension from user
	cout << "Enter the length of the yard: " << endl;
	cin >> len;

	// get tree radius from user
	cout << "Enter the radius of a fully grown tree: " << endl;
	cin >> rad;

	// get tree space-between from user
	cout << "Enter the required space between fully grown trees: " << endl;
	cin >> space;

	// calculate the number of trees that can fit in yard
	num_trees = static_cast<int> ((len + space) / (2 * rad + space));
	// calculate total space used by trees
	space_used = PI * rad * rad * num_trees;

	// output number of trees and soace occcupied to user
	cout << "The number of trees that can be planted: " << num_trees << endl;
	cout << "The amount of space occupied by trees: " << space_used << endl;
	return 0;
}