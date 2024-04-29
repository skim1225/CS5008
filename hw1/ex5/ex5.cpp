#include <iostream>

using namespace std;

int main() {

	// init constants for various royalty rates
	double const RATE1 = .125;
	double const RATE2 = .1;
	double const RATE3 = .14;
	int const ROYALTY1 = 25000;

	// init vars for info on books sold
	int num_sold;
	double net_price;
	double royalty2;
	double royalty3;

	// get price and number of books sold from user
	cout << "Enter the net price of the novel: " << endl;
	cin >> net_price;
	cout << "Enter the number of copies sold: " << endl;
	cin >> num_sold;

	// calculate royalties for option 2
	royalty2 = RATE1 * num_sold * net_price;

	// calculate royalties for option 3
	if (num_sold > 4000) {
		royalty3 = (RATE2 * 4000 * net_price) + (RATE3 * (num_sold - 4000) * net_price);
	}
	else {
		royalty3 = RATE2 * num_sold * net_price;
	}
	
	// output all royalty options to user
	cout << "O1:  " << ROYALTY1 << ", O2: " << royalty2 << ", O3: " << royalty3 << endl;

	// compare and output most profitable royalty option to user
	if (ROYALTY1 > royalty2 && ROYALTY1 > royalty3) {
		cout << "Best: O1" << endl;
	}
	else if (royalty2 > ROYALTY1 && royalty2 > royalty3) {
		cout << "Best: O2" << endl;
	}
	else {
		cout << "Best: O3" << endl;
	}

	return 0;
}
