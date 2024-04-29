#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}

	vector<int>::iterator itr;
	for (itr = v.begin(); itr != v.end(); ++itr) {
		cout << " " << *itr << endl;
	}
}