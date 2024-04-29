#include <iostream>

using namespace std;

int binarySearch(int list[], int len, int num);

int main() {

	int list[10];
	int num;
	int pos;
	
	for (int i = 0; i < 10; i++) {
		cout << "Enter an integer (must be unique and in ascending order): " << endl;
		cin >> list[i];
	}
	cout << "Enter the number to search for: " << endl;
	cin >> num;
	pos = binarySearch(list, 10, num);
	cout << "Your number is at index " << pos << endl;

	return 0;
}

/*
* Returns the index of the number to be found in the list. If the number is not in the list, returns -1.
*/
int binarySearch(int list[], int len, int num) {
	int start = 0;
	int end = len - 1;
	int mid;
	bool found = false;
	while (start <= end && !found) {
		mid = (start + end) / 2;
		if (list[mid] == num) {
			found = true;
		}
		else if (list[mid] > num) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	if (found) {
		return mid;
	}
	else {
		return -1;
	}
}