#include <iostream>
#include <iomanip>
using namespace std;

void initialize(double alpha[], int size);
void print(double alpha[], int size);

int main() {
	double alpha[50];
	initialize(alpha, 50);
	print(alpha, 50);
	return 0;
}

void initialize(double alpha[], int size) {
	for (int i = 0; i < size/2; i++) {
		alpha[i] = i * i;
	}
	for (int i = size/2; i < size; i++) {
		alpha[i] = 3 * i;
	}
}

void print(double alpha[], int size) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			int index = 10 * i + j;
			cout << setw(4) << alpha[index] << ' ';
		}
		cout << endl;
	}
}
