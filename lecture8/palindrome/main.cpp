#include <iostream>

using namespace std;

bool isPal(string s);

int main() {
	string s;
	cout << "Enter a string to test: " << endl;
	cin >> s;
	bool pal = isPal(s);
	if (pal) {
		cout << "Your string is a palindrome." << endl;
	}
	else {
		cout << "Your string is not a palindrome. " << endl;
	}
	return 0;
}

bool isPal(string s) {
	if (s.length() == 1) {
		return true;
	}
	else if (s.length() == 2) {
		return s[0] == s[1];
	}
	else {
		if (s[0] == s[s.length() - 1]) {
			return isPal(s.substr(1, s.length() - 2));
		}
		else {
			return false;
		}
	}
}