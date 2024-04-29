#include "MenuOption.h"
#include <stdexcept>

/**
 * Default constructor for creating a new MenuOption object.
*/
MenuOption::MenuOption(){}

/**
 * Default destructor for destroying a MenuOption object.
*/
MenuOption::~MenuOption(){}

/**
 * A method which begins the program logic by reading in the file containing the dataset and
 * prompting and handling user input.
*/
void MenuOption::start(string filename) {
    // read in csv file
	ifstream inData;
	inData.open(filename);
	if (!inData) {
		cout << "File does not exist." << endl;
		return;
	}
	VectorAQT AQTVector;
	getData(inData, AQTVector);

	// get user choice while program is running
	int choice = 0;
	while (choice != -1) {
		choice = getChoice();
		if (choice == -1) {
			break;
		} else if (choice == 0) {
			cout << endl << "Enter a valid choice." << endl;
			continue;
		}
		int month, year;
		pair<int, int> p;
		VectorAQT monthData;
		if (choice != 4) {
			p = getMonthAndYear();
			month = p.first;
			year = p.second;
			monthData = getAQTsForMonth(month, year, AQTVector);
			if (monthData.size() == 0) {
				cout << endl;
				cout << "There is no data for the date: " << month << "/" << year << "." << endl;
				continue;
			}
		}
		Date day;
		Time time;
		pair<double, double> tempAndRH;
        VectorAQT allAboveAvgTemp;
        VectorAQT allAboveAvgRelHumidity;
        VectorAQT allAboveAvgAbsHumidity;
		switch (choice) {
		case 1:
			cout << endl << "The average temperature for " << month << "/" << year << " was: " << getAvgTemp(monthData) << endl;
			break;
		case 2:
			cout << endl << "The average relative humidity for " << month << "/" << year << " was: " << getAvgRelHumidity(monthData) << endl;
			break;
		case 3:
			cout << endl << "The average absolute humidity for " << month << "/" << year << " was: " << getAvgAbsHumidity(monthData) << endl;
			break;
		case 4:
			day = getDate();
			time = getTime();
			tempAndRH = getTempAndRelHumidity(day, time, AQTVector);
			if (tempAndRH.first == -1.0 && tempAndRH.second == -1.0) {
				cout << endl;
				cout << "There is no data for: " << day << ", " << time << "." << endl;
			} else {
				cout << endl << "The temperature at " << day << " " << time << " was: " << tempAndRH.first << endl;
				cout << endl << "The relative humidity at " << day << " " << time << " was: " << tempAndRH.second << endl;
			}
			break;
		case 5:
			cout << endl << "The highest temperature for " << month << "/" << year << " was: " << getHighTemp(monthData) << endl;
			break;
		case 6:
			cout << endl << "The highest relative humidity for " << month << "/" << year << " was: " << getHighRelHumidity(monthData) << endl;
			break;
		case 7:
			cout << endl << "The highest absolute humidity for " << month << "/" << year << " was: " << getHighAbsHumidity(monthData) << endl;
			break;
		case 8:
            allAboveAvgTemp = getAllAboveAvgTemp(monthData);
            if (checkSize(allAboveAvgTemp)) {
                cout << endl << "The dates and times for when the temperature was higher than the average temperature for " << month << "/" << year << " was: " << endl;
                displayDatesAndTimes(allAboveAvgTemp);
            } else {
                cout << endl << "There are no dates and times higher than the average temperature for " << month << "/" << year << endl;
            }
			break;
		case 9:
            allAboveAvgRelHumidity = getAllAboveAvgRelHumidity(monthData);
            if (checkSize(allAboveAvgRelHumidity)) {
                cout << endl << "The dates and times for when the relative humidity was higher than the average relative humidity for " << month << "/" << year << " was: " << endl;
                displayDatesAndTimes(allAboveAvgRelHumidity);
            } else {
                cout << endl << "There are no dates and times higher than the average relative humidity for " << month << "/" << year << endl;
            }
			break;
		case 10:
            allAboveAvgAbsHumidity = getAllAboveAvgAbsHumidity(monthData);
            if (checkSize(allAboveAvgAbsHumidity)) {
                cout << endl << "The dates and times for when the absolute humidity was higher than the average absolute humidity for " << month << "/" << year << " was: " << endl;
                displayDatesAndTimes(allAboveAvgAbsHumidity);
            } else {
                cout << endl << "There are no dates and times higher than the average absolute humidity for " << month << "/" << year << endl;
            }
			break;
		default:
			cout << endl << "Enter a valid choice." << endl;
		}
	}
	inData.close();
}

/**
 * Returns whether the given VectorAQT is not empty.
*/
bool MenuOption::checkSize(VectorAQT v) {
    return v.size() != 0;
}

/**
 * Method for reading the given ifstream and parsing the data to create AirQualityType objects.
 * Puts the valid AirQualityType objects in the given VectorAQT.
*/
void MenuOption::getData(ifstream& inData, VectorAQT &AQTVector) {
	// discard the 1st line which has headers
	string discard;
	getline(inData, discard);
	while (inData.peek() != ',' && inData.peek() != EOF) {
		// read in the file line by line
		string data;
		int day, month, year, hour, min, sec;
		double temp, relH, absH;

		// parse Date
		getline(inData, data, '/');
        month = stoi(data);
		getline(inData, data, '/');
		day = stoi(data);
		getline(inData, data, ',');
		year = stoi(data);
		Date d(day, month, year);

		// parse Time
		getline(inData, data, ':');
		hour = stoi(data);
		getline(inData, data, ':');
		min = stoi(data);
		getline(inData, data, ',');
		sec = stoi(data);
		Time t(hour, min, sec);

		// ignore irrelevant columns
		for (int i = 0; i < 10; i++) {
			getline(inData, discard, ',');
		}

		// parse temp, relH, and absH
		getline(inData, data, ',');
		temp = stod(data);
		getline(inData, data, ',');
		relH = stod(data);
		getline(inData, data, '\n');
		absH = stod(data);

		AirQualityType entry(d, t, temp, relH, absH);
		if (temp != -200) {
			AQTVector.push_back(entry);
		}
	}
}

/**
 * Displays the menu options to the user, gets their choice, and returns it as an int.
 */
int MenuOption::getChoice() {
	string choiceString;
	int choice;
	cout << endl;
    cout << "MENU----------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Enter 1 to get the average temperature of a month: " << endl;
	cout << "Enter 2 to get the average relative humidity for the month: " << endl;
	cout << "Enter 3 to get the average absolute humidity for a month: " << endl;
	cout << "Enter 4 to get the temperature and relative humidity for a valid date and time: " << endl;
	cout << "Enter 5 to get the highest temperature for a month: " << endl;
	cout << "Enter 6 to get the highest relative humidity for a month: " << endl;
	cout << "Enter 7 to get the highest absolute humidity for a month: " << endl;
	cout << "Enter 8 to get the dates and times for a month when the temperature is higher than the average temperature for that month: " << endl;
	cout << "Enter 9 to get the dates and times for a month when the relative humidity is higher than the average relatuve humidity for that month: " << endl;
	cout << "Enter 10 to get the dates and times for a month when the absolute humidity is higher than the average absolute humidity for that month: " << endl;
	cout << "Enter -1 to quit the program: " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	getline(cin, choiceString);
	if (isNumber(choiceString)) {
		choice = stoi(choiceString);
		if (((choice >= 1) && (choice <= 10)) || choice == -1) {
			return choice;
		}
	}
	return 0;
}

/**
 * Gets a month and year from the user as a pair of ints.
 */
pair<int, int> MenuOption::getMonthAndYear() {
	string monthString, yearString;
	int month, year;
	cout << "Enter the month: " << endl;
	getline(cin, monthString);
	month = getValidInt(monthString, "Month");
	cout << "Enter the year: " << endl;
	getline(cin, yearString);
	year = getValidInt(yearString, "Year");
	return make_pair(month, year);
}

// getters

/**
 * Takes in a Vector containing all of the AQTs for a specific month and returns the average temp for that month, as a double.
 */
double MenuOption::getAvgTemp(VectorAQT& monthData) {
	double totalTemp = 0.0;
	int size = monthData.size();
	for (int i = 0; i < size; i++) {
		AirQualityType curr = monthData.at(i);
		totalTemp += curr.getTemp();
	}
	double avgTemp = totalTemp / size;
	return avgTemp;
}

/**
 * Takes in a Vector containing all of the AQTs for a specific month and returns the average relative humidity for that month, as a double.
 */
double MenuOption::getAvgRelHumidity(VectorAQT& monthData) {
	double totalRH = 0.0;
	int size = monthData.size();
	for (int i = 0; i < size; i++) {
		AirQualityType curr = monthData.at(i);
		totalRH += curr.getRelHumidity();
	}
	double avgRH = totalRH / size;
	return avgRH;
}

/**
 * Takes in a Vector containing all of the AQTs for a specific month and returns the average absolute humidity for that month, as a double.
 */
double MenuOption::getAvgAbsHumidity(VectorAQT& monthData) {
	double totalAH = 0.0;
	int size = monthData.size();
	for (int i = 0; i < size; i++) {
		AirQualityType curr = monthData.at(i);
		totalAH += curr.getAbsHumidity();
	}
	double avgAH = totalAH / size;
	return avgAH;
}

/**
 * Takes in a Date, Time, and Vector containing all AQT data and returns the temp and relative humidity at that date and time as a pair of doubles.
 * If the given Date and Time does not exist, returns <0.0, 0.0>
 */
pair<double, double> MenuOption::getTempAndRelHumidity(Date day, Time time, VectorAQT& AQTVector) {
	pair<double, double> tempAndRelHumidity = make_pair(-1.0, -1.0);
	for (int i = 0; i < AQTVector.size(); i++) {
		AirQualityType curr = AQTVector.at(i);
		if (curr.getDate() == day && curr.getTime() == time) {
			return make_pair(curr.getTemp(), curr.getRelHumidity());
		}
	}
	return tempAndRelHumidity;
}

/**
 * Takes in a Vector containing all of the AQTs for a specific month and returns the highest temperature for that month, as a double.
 */
double MenuOption::getHighTemp(VectorAQT& monthData) {
	double highTemp = 0.0;
	for (int i = 0; i < monthData.size(); i++) {
		AirQualityType curr = monthData.at(i);
		if (curr.getTemp() > highTemp) {
			highTemp = curr.getTemp();
		}
	}
	return highTemp;
}

/**
 * Takes in a Vector containing all of the AQTs for a specific month and returns the highest relative humidity for that month, as a double.
 */
double MenuOption::getHighRelHumidity(VectorAQT& monthData) {
	double highRH = 0.0;
	for (int i = 0; i < monthData.size(); i++) {
		AirQualityType curr = monthData.at(i);
		if (curr.getRelHumidity() > highRH) {
			highRH = curr.getRelHumidity();
		}
	}
	return highRH;
}

/**
 * Takes in a Vector containing all of the AQTs for a specific month and returns the highest absolute humidity for that month, as a double.
 */
double MenuOption::getHighAbsHumidity(VectorAQT& monthData) {
	double highAH = 0.0;
	for (int i = 0; i < monthData.size(); i++) {
		AirQualityType curr = monthData.at(i);
		if (curr.getAbsHumidity() > highAH) {
			highAH = curr.getAbsHumidity();
		}
	}
	return highAH;
}

/**
 * Returns a Vector containing all of the airQualityTypes of the specified month and year that have a higher temp than the average temp for that month
 */
VectorAQT MenuOption::getAllAboveAvgTemp(VectorAQT& monthData) {
	double avgTemp = getAvgTemp(monthData);
	VectorAQT aboveAvgTemp;
	for (int i = 0; i < monthData.size(); i++) {
		AirQualityType curr = monthData.at(i);
		if (curr.getTemp() > avgTemp) {
			aboveAvgTemp.push_back(curr);
		}
	}
	return aboveAvgTemp;
}

/**
 * Returns a Vector containing all of the airQualityTypes of the specified month and year that have a higher relative humidity than the average for that month
 */
VectorAQT MenuOption::getAllAboveAvgRelHumidity(VectorAQT& monthData) {
	double avgRH = getAvgRelHumidity(monthData);
	VectorAQT aboveAvgRH;
	for (int i = 0; i < monthData.size(); i++) {
		AirQualityType curr = monthData.at(i);
		if (curr.getRelHumidity() > avgRH) {
			aboveAvgRH.push_back(curr);
		}
	}
	return aboveAvgRH;
}


/**
 * Returns a Vector containing all of the airQualityTypes of the specified month and year that have a higher absolute humiditythan the average for that month
 */
VectorAQT MenuOption::getAllAboveAvgAbsHumidity(VectorAQT& monthData) {
	double avgAH = getAvgAbsHumidity(monthData);
	VectorAQT aboveAvgAH;
	for (int i = 0; i < monthData.size(); i++) {
		AirQualityType curr = monthData.at(i);
		if (curr.getAbsHumidity() > avgAH) {
			aboveAvgAH.push_back(curr);
		}
	}
	return aboveAvgAH;
}

/**
 * Helper method to display the dates and times of the airQualityTypes in the given vector
 */
void MenuOption::displayDatesAndTimes(VectorAQT selectedAQTs) {
	for (int i = 0; i < selectedAQTs.size(); i++) {
		AirQualityType curr = selectedAQTs.at(i);
		cout << curr.getDate() << " " << curr.getTime() << endl;
	}
}

/**
 * Helper method to return a vector containing all of the AQTs for a given month
 */
VectorAQT MenuOption::getAQTsForMonth(int month, int year, VectorAQT& v) {
	VectorAQT selectedAQTs;
	int index = v.find(month, year);
	if (index != -1) {
		while (v.at(index).getDate().getMonth() == month) {
			selectedAQTs.push_back(v.at(index));
			index++;
		}
	}
	return selectedAQTs;
}

/**
 * Helper method to get a date from the user and return it as a Date object
 */
Date MenuOption::getDate() {
	string monthString, dayString, yearString;
	int month, day, year;

	cout << "Enter the month of the date: " << endl;
	getline(cin, monthString);
	month = getValidInt(monthString, "Month");

	cout << "Enter the day of the date: " << endl;
	getline(cin, dayString);
	day = getValidInt(dayString, "Day");

	cout << "Enter the year of the date: " << endl;
	getline(cin, yearString);
	year = getValidInt(yearString, "Year");

	return Date(day, month, year);
}

/**
 * Helper method to get a time from the user and return it as a Time object
 */
Time MenuOption::getTime() {
	string hourString, minutesString, secondsString;
	int h, m, s;

	cout << "Enter the hours of the time: " << endl;
	getline(cin, hourString);
	h = getValidInt(hourString, "Hours");

	cout << "Enter the minutes of the time: " << endl;
	getline(cin, minutesString);
	m = getValidInt(minutesString, "Minutes");

	cout << "Enter the seconds of the time: " << endl;
	getline(cin, secondsString);
	s = getValidInt(secondsString, "Seconds");

	return Time(h, m, s);
}

/**
 * Helper method to check whether the value of a string is an integer
 */
bool MenuOption::isNumber(string value) {
    try {
        stoi(value);
    } catch (const invalid_argument& e) {
        return false;
    }
    return true;
}

/**
 * Helper method to check whether the value of a string is an integer
 */
int MenuOption::getValidInt(string value, string type) {
	while (!isNumber(value)) {
		cout << endl << type << " must be an integer." << endl;
		cout << endl << "Re-enter the " << type << ": " << endl;
		getline(cin, value);
	}
	return stoi(value);
}