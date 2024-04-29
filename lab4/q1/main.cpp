#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> myVector;
	int num;
	for (int i = 0; i < 6; i++) {
		cout << "Enter integer: " << endl;
		cin >> num;
		myVector.push_back(num);
	}
	vector<int>::iterator itr;
	cout << "Integers in the vector: " << endl;
	for (itr = myVector.begin(); itr != myVector.end(); ++itr) {
		cout << *itr << " ";
	}
	return 0;
}