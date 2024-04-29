#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	// method 1
	/* set<int> mySet;
	set<int>::iterator itr;
	int num;
	for (int i = 1; i <= 5; i++) {
		cout << "Enter a number: ";
		cin >> num;
		mySet.insert(num);
		cout << endl;
	}
	for (itr = mySet.begin(); itr != mySet.end(); ++itr) {
		cout << *itr << endl;
	}
	*/
	// method 2
	vector<int> v(10);
	vector<int>::iterator itr3;
	set<int> mySet1;
	set<int> mySet2;
	set<int>::iterator itr1;
	set<int>::iterator itr2;
	for (int i = 1; i <= 5; i++) {
		mySet1.insert(i * 2);
		mySet2.insert(i + 1);
	}
	set_intersection(mySet1.begin(), mySet1.end(), mySet2.begin(), mySet2.end(), v.begin());
	for (itr3 = v.begin(); itr3 != v.end(); ++itr3) {
		cout << *itr3 << endl;
	}
	system("PAUSE");
	return 0;
}