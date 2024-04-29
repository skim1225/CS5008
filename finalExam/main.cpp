#include <iostream>
#include "DVD.h"

// function declarations 
void addDVD(vector <DVD> &v);
void removeDVD(string title, vector <DVD> &v);
void findDVD(string title, vector <DVD> &v);
void listTitles(vector <DVD> &v);
void updateDetails(string title, vector <DVD> &v);
void displayDetails(DVD dvd);
int search(string title, vector <DVD> &v);
void sort(vector <DVD> &v);
int getChoice();
int getUpdateChoice();
vector<string> getStars();

using namespace std;

int main() {
	vector <DVD> v;
	int choice = 0;
	string input;
	while (choice != -1) {
		choice = getChoice();
		switch (choice) {
		case -1:
			// quit program
			break;
		case 1:
			addDVD(v);
			break;
		case 2:
			cout << "Enter the title of the DVD to remove: " << endl;
			cin.ignore(256, '\n');
			getline(cin, input);
			removeDVD(input, v);
			break;
		case 3:
			cout << "Enter the title of the DVD to search and display: " << endl;
			cin.ignore(256, '\n');
			getline(cin, input);
			findDVD(input, v);
			break;
		case 4:
			listTitles(v);
			break;
		case 5:
			cout << "Enter the title of the DVD to update: " << endl;
			cin.ignore(256, '\n');
			getline(cin, input);
			updateDetails(input, v);
			break;
		default:
			cout << "Not a valid option.";
			break;
		}
	}
	return 0;
}

// returns the user's menu option choice
int getChoice() {
	int choice;
	cout << "Enter 1 to add a new DVD to the list of DVDS." << endl;
	cout << "Enter 2 to remove a DVD from the list of DVDs." << endl;
	cout << "Enter 3 to search for a DVD by title and display its information." << endl;
	cout << "Enter 4 to list all of the titles of the DVDs in the store in alphabetical order." << endl;
	cout << "Enter 5 to update the details of a particular of a DVD." << endl;
	cout << "Enter -1 to quit the program." << endl;
	cin >> choice;
	return choice;
}

// prompts the user to enter information about a DVD then adds the DVD to the collection, maintaining a sorted order
// DVDs with duplicate titles are not allowed in the collection
void addDVD(vector <DVD> &v) {
	string title;
	vector<string> stars;
	string producer;
	string director;
	string productionCompany;
	string input;
	int numCopies;
	cout << "Enter the title of the DVD: " << endl;
	cin.ignore(256, '\n');
	getline(cin, title);
	stars = getStars();
	cout << "Enter the producer: " << endl;
	getline(cin, producer);
	cout << "Enter the director: " << endl;
	getline(cin, director);
	cout << "Enter the production company: " << endl;
	getline(cin, productionCompany);
	cout << "Enter the number of copies: " << endl;
	cin >> input;
	numCopies = stoi(input);
	if (search(title, v) == -1) {
		DVD dvd(title, stars, producer, director, productionCompany, numCopies);
		v.push_back(dvd);
		sort(v);
	}
}

// removes a DVD with the given title from the given vector
void removeDVD(string title, vector <DVD> &v) {
	vector<DVD>::iterator itr;
	for (itr = v.begin(); itr != v.end();) {
		if ((*itr).getTitle() == title) {
			v.erase(itr);
			break;
		}
		else {
			++itr;
		}
	}
}

// displays the details a the DVD with the given title
void findDVD(string title, vector <DVD> &v) {
	int result = search(title, v);
	if (result != -1) {
		displayDetails(v.at(result));
	}
	else {
		cout << "The DVD you are searching for does not exist." << endl;
	}
}

// returns the index of the DVD with the given title, or -1 if it is not found
int search(string title, vector <DVD> &v) {
	int index = -1;
	vector<DVD>::iterator itr;
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i).getTitle() == title) {
			return i;
		}
	}
	return index;
}

// displays the titles of all of the DVDs in the collection in alphabetical order
void listTitles(vector <DVD> &v) {
	vector<DVD>::iterator itr;
	for (itr = v.begin(); itr != v.end(); ++itr) {
		cout << (*itr).getTitle() << endl;
	}
}

// sort vector by title of DVD alphabetically using bubble sort
void sort(vector <DVD> &v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (v[j] > v[j + 1]) {
				DVD temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

// prompts the user to update the field of the given DVD in the given vector
void updateDetails(string title, vector <DVD> &v) {
	int choice = getUpdateChoice();
	DVD &dvd = v.at(search(title, v));
	string input;
	switch (choice) {
	case 1:
		cout << "Enter the new title: " << endl;
		cin.ignore();
		getline(cin, input);
		dvd.setTitle(input);
		break;
	case 2:
		cout << "Enter the new stars when prompted: " << endl;
		dvd.setStars(getStars());
		break;
	case 3:
		cout << "Enter the new producer: " << endl;
		cin.ignore();
		getline(cin, input);
		dvd.setProducer(input);
		break;
	case 4:
		cout << "Enter the new director: " << endl;
		cin.ignore();
		getline(cin, input);
		dvd.setDirector(input);
		break;
	case 5:
		cout << "Enter the new production company: " << endl;
		cin.ignore();
		getline(cin, input);
		dvd.setProductionCompany(input);
		break;
	case 6:
		cout << "Enter the new number of copies: " << endl;
		cin.ignore();
		getline(cin, input);
		dvd.setNumCopies(stoi(input));
		break;
	default:
		cout << "Not a valid option. " << endl;
	}
}

// displays the details of the given DVD
void displayDetails(DVD dvd) {
	cout << "Title: " << dvd.getTitle() << endl;
	cout << "Stars: ";
	vector<string>::iterator itr;
	vector<string> stars = dvd.getStars();
	for (itr = stars.begin(); itr != stars.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	cout << "Producer: " << dvd.getProducer() << endl;
	cout << "Director: " << dvd.getDirector() << endl;
	cout << "Production company: " << dvd.getProductionCompany() << endl;
	cout << "Number of copies: " << dvd.getNumCopies() << endl;
}

// gets the user's choice for updating the details of a DVD
int getUpdateChoice() {
	int choice;
	cout << "Enter which detail you wish to change: " << endl;
	cout << "Enter 1 to change the title: " << endl;
	cout << "Enter 2 to change the stars: " << endl;
	cout << "Enter 3 to change the producer: " << endl;
	cout << "Enter 4 to change the director: " << endl;
	cout << "Enter 5 to change the production company: " << endl;
	cout << "Enter 6 to change the number of copies: " << endl;
	cin >> choice;
	return choice;
}

// helper method to get stars from the user as strings and return them in a vector
vector<string> getStars() {
	int numStars;
	string input;
	vector <string> stars;
	cout << "Enter the number of stars: " << endl;
	cin >> numStars;
	cin.ignore(256, '\n');
	for (int i = 0; i < numStars; i++) {
		cout << "Enter a star: ";
		getline(cin, input);
		stars.push_back(input);
	}
	return stars;
}