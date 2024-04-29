// Sooji Kim
// CS5008 HW6
// 15 March 2024

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// create 2 sets
	set<int> set1;
	set<int> set2;
	set<int>::iterator itr;
	for (int i = 1; i <= 8; i++) {
		set1.insert(i);
	}
	for (int i = 6; i <= 11; i++) {
		set2.insert(i);
	}
	// print the sets
	cout << "Set 1: " << endl;
	for (itr = set1.begin(); itr != set1.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	cout << "Set 2: " << endl;
	for (itr = set2.begin(); itr != set2.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	// print the set difference
	cout << "Set1 -- Set2: " << endl;
	vector<int> v(5);
	vector<int>::iterator vitr;
	set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), v.begin());
	for (vitr = v.begin(); vitr != v.end(); ++vitr) {
		cout << *vitr << " ";
	}
	cout << endl;
	// print the set union
	cout << "The union of set 1 and set 2: " << endl;
	vector<int> v1(11);
	vector<int>::iterator vitr1;
	set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), v1.begin());
	for (vitr1 = v1.begin(); vitr1 != v1.end(); ++vitr1) {
		cout << *vitr1 << " ";
	}
	cout << endl;
	// print the set intersection
	cout << "The intersection of set1 and set 2: " << endl;
	vector<int> v2(3);
	vector<int>::iterator vitr2;
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), v2.begin());
	for (vitr2 = v2.begin(); vitr2 != v2.end(); ++vitr2) {
		cout << *vitr2 << " ";
	}
	cout << endl;
	return 0;
}
