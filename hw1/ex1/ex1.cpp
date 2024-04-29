#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	// init vars to store dimensions of cylinder and cube
	double const PI = 3.14159;
	int radius;
	int height;
	double side;
	double volume;

	// get cylinder dimensions from user
	cout << fixed << showpoint << setprecision(2);
	cout << "Enter the radius of the cylinder: " << endl;
	cin >> radius;
	cout << "Enter the height of the cylinder: " << endl;
	cin >> height;

	// calculate volume of cylinder
	volume = PI * radius * radius * height;
	// calculate side length of cube with equivalent volune
	side = std::cbrt(volume);

	// output side length to user
	cout << "The side length of a cube with the same volume as your cylidner: " << side << endl;

	return 0;
}