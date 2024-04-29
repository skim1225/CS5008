#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char toUpper(char c);

int main() {
	char str[50];
	cout << "Enter a string: " << endl;
	cin >> str;
	cout << "String in upper case letters is: " << endl;
	int i = 0;
	while (str[i] != NULL) {
		cout << (char)toupper(str[i]);
		i++;
	}
}