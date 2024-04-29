#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
	map <string, int> myMap;
	myMap.insert(pair<string, int>("John", 200));
	myMap.insert(pair<string, int>("Jill", 300));
	myMap.insert(pair<string, int>("Tom", 50));
	myMap.insert(pair<string, int>("May", 10));

	map <string, int>::iterator itr;

	for (itr = myMap.begin(); itr != myMap.end(); ++itr) {
		cout << itr->first << " " << itr->second << '\n';
	}

	// finding keys value
	cout << myMap.find("Tom")->second << endl;
	cout << myMap.find("Alice")->second << endl;

	return 0;
}