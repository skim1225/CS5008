// Sooji Kim
// CS5008 lab 5
// 6 March 2024

#include <iostream>

using namespace std;

void selectionSort(int list[], int len);
void printList(int list[], int len);

int main() {
    int intList[] = {16, 30, 24, 7, 62, 45, 5, 55};
    cout << "Before sorting: " << endl;
    printList(intList, 8);
    selectionSort(intList, 8);
    cout << "After sorting with selection sort: " << endl;
    printList(intList, 8);
	return 0;
}

void selectionSort(int list[], int len) {
    for (int i = 0; i < len; i++) {
        int min = list[i];
        int minIndex = i;
        for (int j = i; j < len; j++) {
            // find min in unsorted list
            if (list[j] < min) {
                min = list[j];
                minIndex = j;
            }
        }
        // swap min and start of unsorted list
        if (minIndex != i) {
            int temp = list[minIndex];
            list[minIndex] = list[i];
            list[i] = temp;
        }
    }
}

// helper method for displaying the list
void printList(int list[], int len) {
    for (int i = 0; i < len; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}