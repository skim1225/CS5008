#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_STUDENTS = 20;

struct studentType {
	string firstName;
	string lastName;
	int testScore;
	char grade;
};

void getData(ifstream& inData, studentType students[], int size);
void calcGrades(studentType students[], int size);
int maxScore(const studentType students[], int size);
void printResults(ofstream& outData, const studentType students[], int size);

int main() {
	studentType students[NUM_STUDENTS];
	ifstream inData;
	ofstream outData;
	inData.open("textinput.txt");
	if (!inData) {
		cout << "File does not exist." << endl;
		return 1;
	}
	outData.open("output.txt");
	if (!outData) {
		cout << "Cannot create output file." << endl;
		return 1;
	}
	getData(inData, students, NUM_STUDENTS);
	calcGrades(students, NUM_STUDENTS);
	printResults(outData, students, NUM_STUDENTS);
	inData.close();
	outData.close();
	return 0;
}

void getData(ifstream& inData, studentType students[], int size) {
	for (int i = 0; i < size; i++) {
		inData >> students[i].firstName >> students[i].lastName >> students[i].testScore;
	}
}

void calcGrades(studentType students[], int size) {
	for (int i = 0; i < size; i++) {
		switch (students[i].testScore / 10) {
			case 10:
				students[i].grade = 'A';
				break;
			case 9:
				students[i].grade = 'B';
				break;
			case 8:
				students[i].grade = 'C';
				break;
			case 7:
				students[i].grade = 'D';
				break;
			default:
				students[i].grade = 'F';

		}
	}
}

int maxScore(const studentType students[], int size) {
	int maxScore = 0;
	for (int i = 0; i < size; i++) {
		if (students[i].testScore > maxScore) {
			maxScore = students[i].testScore;
		}
	}
	return maxScore;
}

void printResults(ofstream& outData, const studentType students[], int size) {
	int max = maxScore(students, size);
	outData << setw(15) << "Student Name " << setw(10) << "Test Score"
		<< setw(7) << "Grade" << endl;
	for (int i = 0; i < size; i++)
		outData << left << setw(25) << students[i].lastName + ", " +
		students[i].firstName << right << " " << setw(5) << students[i].testScore
		<< setw(6) << " " << students[i].grade << endl;
	outData << endl << "Highest Test Score: " << max << endl;
	outData << "Students having the highest test score:" << endl;
	for (int i = 0; i < size; i++)
		if (students[i].testScore == max)
			outData << students[i].lastName + ", " + students[i].firstName << endl;
}
