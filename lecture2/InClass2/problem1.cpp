#include <iostream>
using namespace std;

struct fruitType {
	string name;
	string color;
	int fat;
	int sugar;
	int carbs;
};

int main() {
	fruitType fruits[5];
	for (int i = 0; i < 5; i++) {
		cout << "Enter the name of a fruit: " << endl;
		cin >> fruits[i].name;
		cout << "Enter the color of the fruit: " << endl;
		cin >> fruits[i].color;
		cout << "Enter the fat in the fruit: " << endl;
		cin >> fruits[i].fat;
		cout << "Enter the sugar in the fruit: " << endl;
		cin >> fruits[i].sugar;
		cout << "Enter the carbs in the fruit: " << endl;
		cin >> fruits[i].carbs;
		cout << endl;
	}

	for (int i = 0; i < 5; i++) {
		cout << "Fruit name: " << fruits[i].name << endl;
		cout << "Fruit color: " << fruits[i].color << endl;
		cout << "Fruit fat: " << fruits[i].fat << endl;
		cout << "Fruit sugar: " << fruits[i].sugar << endl;
		cout << "Fruit carbs:  " << fruits[i].carbs << endl;
	}
	
}

