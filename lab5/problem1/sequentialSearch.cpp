#include <iostream>

using namespace std;

int seqSearch(int list[], int len, int num);

int main() {

	int list[10];
	int num;
	int pos;
	for (int i = 0; i < 10; i++) {
		cout << "Enter an integer (must be unique): " << endl;
		cin >> list[i];
	}
	cout << "Enter the number to search for: " << endl;
	cin >> num;
	pos = seqSearch(list, 10, num);
	cout << "Your number is at index " << pos << endl;

	return 0;
}

/*
* Returns the index of the number to be found in the list.
* If the number is not in the list, returns -1.
*/
int seqSearch(int list[], int len, int num) {
	for (int i = 0; i < len; i++) {
		if (list[i] == num) {
			return i;
		}
	}
	return -1;
}