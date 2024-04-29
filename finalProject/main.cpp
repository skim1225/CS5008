#include "MenuOption.h"
#include "MenuOption.cpp"

using namespace std;

const string FILE_NAME = "AirQualityUCI.csv";

/**
 * Main meothod which runs the program.
*/
int main() {
	MenuOption menuOption;
	menuOption.start(FILE_NAME);
	return  0;
}