#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_CANDIDATES = 5;

struct candidate {
	string lastName;
	int votesReceived;
	double percentVotes;
};

void getData(candidate candidates[], int size);
void calcVotes(candidate candidates[], int size);
void printResults(const candidate candidates[], int size);
void getWinner(candidate candidates[], int size);

int main() {
	candidate candidates[NUM_CANDIDATES];
	getData(candidates, NUM_CANDIDATES);
	calcVotes(candidates, NUM_CANDIDATES);
	printResults(candidates, NUM_CANDIDATES);
	getWinner(candidates, NUM_CANDIDATES);
	return 0;
}

void getData(candidate candidates[], int size) {
	cout << "Enter 5 candidates' last names and votes: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> candidates[i].lastName >> candidates[i].votesReceived;
	}
}

void calcVotes(candidate candidates[], int size) {
	// calc total number of votes
	int total = 0;
	int max = 0;
	for (int i = 0; i < size; i++) {
		total += candidates[i].votesReceived;
	}
	// calc percentaged
	for (int i = 0; i < size; i++) {
		candidates[i].percentVotes = (double) candidates[i].votesReceived / total * 100;
	}
}

void printResults(const candidate candidates[], int size) {
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(15) << "Candidate" << setw(17) << "Votes Received" << setw(15) << "% of Total Votes" << endl;
	for (int i = 0; i < size; i++) {
		cout << left << setw(20) << candidates[i].lastName << setw(14) << candidates[i].votesReceived << setw(10) << candidates[i].percentVotes << endl;
	}
}

void getWinner(candidate candidates[], int size) {
	candidate winner;
	int maxVotes = candidates[0].votesReceived;
	for (int i = 1; i < size; i++) {
		if (candidates[i].votesReceived > maxVotes) {
			winner = candidates[i];
			maxVotes = candidates[i].votesReceived;
		}
	}
	cout << "The winner of the election is: " << winner.lastName;
}