#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double const A = 35.74;
double const B = 0.6215;
double const C = 35.75;
double const D = 0.16;
double const E = 0.4275;

double calcWindchill(double windSpeed, double temp);
void getInfo(double& windspeed, double& temp );

int main() {
	double windSpeed;
	double temp;
	double windchill;

	getInfo(windSpeed, temp);
	windchill = calcWindchill(windSpeed, temp);

	cout << fixed << showpoint << setprecision(2);
	cout << "The windchill factor is: " << windchill << endl;

	return 0;
}

void getInfo(double& windSpeed, double& temp) {
	cout << "Enter the wind speed in miles per hour: " << endl;
	cin >> windSpeed;
	cout << "Enter the temperature in degrees farenheit: " << endl;
	cin >> temp;
}

double calcWindchill(double windSpeed, double temp) {
	return A + (B * temp) - (C * pow(windSpeed, D)) + E * temp * pow(windSpeed, D);
}