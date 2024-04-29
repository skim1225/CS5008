#include <iostream>

using namespace std;

int main() {

	// init constant list of primes
	const int PRIMES[11] = {2,3,5,7,11,13,17,19,23,29,31};
	// init number to be tested
	int num;
	bool isPrime = true;

	// get number from user
	cout << "Enter a positive integer between 1 and 1000 (inclusive): " << endl;
	cin >> num;

	// check if number can be divided by a prime in our list. if so, prints out the prime and sets isPrime to false
	for (int i = 0; i < sizeof(PRIMES)/sizeof(int); i++) {
		if (num % PRIMES[i] == 0) {
			isPrime = false;
			cout << PRIMES[i] << endl;
		}
	}

	// outputs whether or not the number is prime. 
	if (isPrime) {
		cout << num << " is prime." << endl;
	}
	else {
		cout << num << " is not prime. All of the numbers above divide your number." << endl;
	}

	return 0;
}