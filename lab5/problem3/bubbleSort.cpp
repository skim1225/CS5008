#include <iostream>

using namespace std;

void bubbleSort(int list[], int len);
void printArr(int list[], int len);

int main() {
	int list[10];
	for (int i = 0; i < 10; i++) {
		cout << "Enter an int: ";
		cin >> list[i];
		cout << endl;
	}
	bubbleSort(list, 10);
	return 0;
}

void bubbleSort(int list[], int len) {
	// after each sorting step, print the list
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			if (list[j] > list[j + 1]) {
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
		printArr(list, len);
	}
}

void printArr(int list[], int len) {
	for (int i = 0; i < len; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}