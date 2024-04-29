#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<char> v;
	vector<char>::iterator itr;
	itr = v.begin();

	itr = v.insert(itr, 'A');
	itr = v.insert(itr, 'B');
	v.insert(itr, 'C');

	cout << "Contents of v: " << endl;
	for (v.begin(); itr != v.end(); ++itr) {
		cout << *itr << endl;
	}

	vector<char>::reverse_iterator ritr;

	cout << "Here is v in reverse: " << endl;
	for (ritr = v.rbegin(); ritr != v.rend(); ++ritr) {
		cout << *ritr << endl;
	}

	vector<char> v2(v);
	vector<char>::iterator itr2;
	itr2 = v2.begin();
	cout << "Contents of v2: " << endl;
	for (v2.begin(); itr2 != v2.end(); ++itr) {
		cout << *itr2 << endl;
	}

	cout << "Size of v is: " << v.size() << endl;

	if (v == v2) {
		cout << "v and v2 are equivalent" << endl;
	}

	cout << "Insert more chars into v and v2." << endl;

	v.insert(v.end(), 'D');
	v.insert(v.end(), 'E');
	v2.insert(v2.end(), 'X');

	cout << "Contents of v: " << endl;
	for (v.begin(); itr != v.end(); ++itr) {
		cout << *itr << endl;
	}
	cout << "Contents of v2: " << endl;
	for (v2.begin(); itr2 != v2.end(); ++itr) {
		cout << *itr2 << endl;
	}


	if (v < v2) {
		cout << "v is less than v2" << endl;
	}

	cout << "insert z at start of v" << endl;
	v.insert(v.begin(), 'Z');

	cout << "Contents of v: " << endl;
	for (v.begin(); itr != v.end(); ++itr) {
		cout << *itr << endl;
	}

	if (v > v2) {
		cout << "Now v is greater than v2" << endl;
	}

	v2.erase(v2.begin());
	cout << "Contents of v2 after removing 1st element: " << endl;
	for (v2.begin(); itr2 != v2.end(); ++itr) {
		cout << *itr2 << endl;
	}

	vector<char> v3;
	vector<char>::iterator itr3;
	itr3 = v3.begin();
	v3.insert(v3.end(), 'X');
	v3.insert(v3.end(), 'Y');
	v3.insert(v3.end(), 'Z');
	

	cout << "Exchange v and v3: " << endl;
	v.swap(v3);
	cout << "Contents of v: " << endl;
	for (v.begin(); itr != v.end(); ++itr) {
		cout << *itr << endl;
	}
	cout << "Contents of v3: " << endl;
	for (v3.begin(); itr3 != v3.end(); ++itr) {
		cout << *itr3 << endl;
	}

	v.clear();
	if (v.empty()) {
		cout << "v is now empty." << endl;
	}

	return 0;
}