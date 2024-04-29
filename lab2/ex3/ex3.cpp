#include <iostream>
using namespace std;

void removeVowels(string& str);
bool isVowel(char ch);

int main() {
	string input;
	cout << "Enter a string: " << endl;
	cin >> input;
	removeVowels(input);
	cout << "Your string with vowels removed: " << input;
	return 0;
}

void removeVowels(string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (isVowel(str[i])) {
			str = str.substr(0,i) + str.substr(i + 1, str.length());
			i--;
		}
	}
}

bool isVowel(char ch) {
	switch (ch) {
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}