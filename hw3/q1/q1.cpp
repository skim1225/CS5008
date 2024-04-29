#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int MENU_SIZE = 8;
const double TAX_RATE = 0.05;

struct menuItemType {
	string menuItem;
	double menuPrice;
};

void getData(ifstream& inData, menuItemType menuList[], int size);
void showMenu(menuItemType menuList[], int size);
void printCheck(menuItemType menuList[], int itemsPurchased[], int size);

int main() {
	menuItemType menuList[MENU_SIZE];
	// an array which keeps track of the items the customer purchased. the index matches the index of the item in the menuList
	// and the number at an index is the quantity of that item purchased.
	ifstream inData;
	inData.open("Menu_Data.txt");
	if (!inData) {
		cout << "File does not exist." << endl;
		return 1;
	}
	getData(inData, menuList, MENU_SIZE);
	showMenu(menuList, MENU_SIZE);
	int input = 0;
	int itemsPurchased[MENU_SIZE] = {0};
	cout << "Enter a number to order an item from 0-7. Enter -1 to calculate your total." << endl;
	cin >> input;
	while (input != -1) {
		if (input >= 0 && input < MENU_SIZE) {
			itemsPurchased[input] += 1;
		}
		cin >> input;
	}
	printCheck(menuList, itemsPurchased, MENU_SIZE);
	inData.close();
	return 0;
}

// read in menu information from text file
void getData(ifstream& inData, menuItemType menuList[], int size) {
	for (int i = 0; i < size; i++) {
		string name;
		string price;
		getline(inData, name);
		menuList[i].menuItem = name;
		getline(inData, price);
		menuList[i].menuPrice = stof(price);
	}
}

// format and display the menu to the customer
// inform the customer how to selct menu items
void showMenu(menuItemType menuList[], int size) {
	cout << "Welcome to Sooji's Restaurant" << endl;
	for (int i = 0; i < size; i++) {
		cout << fixed << showpoint << setprecision(2);
		cout << i << ": " << left << setw(15) << menuList[i].menuItem << right << "$" << menuList[i].menuPrice << endl;
	}
}

// display the items, quantities, and prices of the items purchased
void printCheck(menuItemType menuList[], int itemsPurchased[], int size) {
	double total = 0.0;
	double subtotal = 0.0;
	double tax;
	cout << "Welcome to Sooji's Restaurant" << endl;
	for (int i = 0; i < size; i++) {
		int qty = itemsPurchased[i];
		if (qty > 0) {
			subtotal = qty * menuList[i].menuPrice;
			cout << qty << " " << left << setw(17) << menuList[i].menuItem << " $" << subtotal << endl;
			total += subtotal;
		}
	}
	tax = total * TAX_RATE;
	total += tax;
	cout << "  Tax:" << right << setw(15) << "$" << tax << endl;
	cout << "  Amount due:" << right << setw(8) << "$" << total<< endl;
}