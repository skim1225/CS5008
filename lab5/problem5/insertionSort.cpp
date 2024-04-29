// Sooji Kim
// CS 5008 Lab 5
// 6 March 2024

#include <iostream>
using namespace std;

void insertionSort(int list[], int length);
void printList(int list[], int length);

int main() {
    int intList[] = { 10, 18, 25, 30, 23, 17, 45, 35 };
    cout << "Before sorting:" << endl;
    printList(intList, 8);
    insertionSort(intList, 8);
    cout << "After sorting with insertion sort:" << endl;
    printList(intList, 8);
    return 0;
}

void printList(int list[], int length) {
    for (int i = 0; i < length; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

void insertionSort(int list[], int length) {
    int curr, prev;
    for (int i = 1; i < length; i++) {
        curr = list[i];
        prev = i - 1;
        while (prev >= 0 && list[prev] > curr) {
            list[prev + 1] = list[prev];
            prev = prev - 1;
        }
        list[prev + 1] = curr;
    }
}