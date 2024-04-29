#include <iostream>
#include <fstream> // reading files
#include <iomanip> // formatting input output
using namespace std;

int main() {
	ifstream inData; // variable of type ifstream needed to read data from the file
	ofstream outData; // variable for writing data to output file
	int ticketPrice;
	int ticketsSold;
	int totalSales = 0;
	int totalTicketsSold = 0;

	// open input file
	inData.open("ticketinfo.txt");

	if (!inData) {
		cout << "Input file does not exist. Program terminates." << endl;
		return 1;
	}

	// open output file
	outData.open("outputData.txt");

	// formatting
	outData << fixed << showpoint << setprecision(2);

	cout << "Processing data" << endl;

	// loop over lines in test file
	while (inData) {
		// get data from input file
		inData >> ticketPrice >> ticketsSold;
		totalTicketsSold += ticketsSold;
		totalSales += ticketPrice * ticketsSold;
	}

	// write data to output file
	outData << "Number of tickets sold: " << totalTicketsSold << endl;
	outData << "Sale amount = $" << totalSales << endl;

	// close input and output files
	inData.close();
	outData.close();
	return 0;
}