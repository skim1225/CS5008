#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_EMPLOYEES = 3;

struct employee {
	string firstName;
	string lastName;
	double salary;
	double increase;
	double newSalary;
};

void getData(ifstream& inData, employee employees[], int size);
void calcSalary(employee employees[], int size);
void printResults(ofstream& outData, const employee employees[], int size);

int main() {
	employee employees[NUM_EMPLOYEES];
	ifstream inData;
	ofstream outData;
	inData.open("input.txt");
	if (!inData) {
		cout << "File does not exist." << endl;
		return 1;
	}
	outData.open("output.txt");
	if (!outData) {
		cout << "Cannot create output file." << endl;
		return 1;
	}
	outData << fixed << showpoint << setprecision(2);
	getData(inData, employees, NUM_EMPLOYEES);
	calcSalary(employees, NUM_EMPLOYEES);
	printResults(outData, employees, NUM_EMPLOYEES);
	inData.close();
	outData.close();
	return 0;
}

void getData(ifstream& inData, employee employees[], int size) {
	for (int i = 0; i < size; i++) {
		inData >> employees[i].firstName >> employees[i].lastName >> employees[i].salary >> employees[i].increase;
	}
}

void calcSalary(employee employees[], int size) {
	for (int i = 0; i < size; i++) {
		employees[i].newSalary = employees[i].salary * employees[i].increase;
	}
}

void printResults(ofstream& outData, const employee employees[], int size) {
	for (int i = 0; i < size; i++) {
		outData << employees[i].firstName << " " << employees[i].lastName << " " << employees[i].newSalary << endl;
	}
}