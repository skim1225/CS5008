#include "AirQualityType.h"

/**
 * Constructor for creating a new AirQualityType object with the given date, time, temperature,
 * relative humidity, and absolute humidity.
 */
AirQualityType::AirQualityType(Date d, Time t, double te, double relH, double absH) {
	date = d;
	time = t;
	temp = te;
	relHumidity = relH;
	absHumidity = absH;
}

/**
 * Default constructor for creating a new AirQualityType object.
*/
AirQualityType::AirQualityType() {}

/**
 * Default destructor for destroying an AirQualityType object.
*/
AirQualityType::~AirQualityType() {}

/**
 * Returns the Date of the AirQualityType, as a Date.
*/
Date AirQualityType::getDate() const {
	return date;
}

/**
 * Returns the Time of the AirQualityType, as a Time.
*/
Time AirQualityType::getTime() const {
	return time;
}

/**
 * Returns the temperature of the AirQualityType in degrees Celsius, as a Double.
*/
double AirQualityType::getTemp() const {
	return temp;
}

/**
 * Returns the relative humidity of the AirQualityType in percents, as a Double.
*/
double AirQualityType::getRelHumidity() const {
	return relHumidity;
}

/**
 * Returns the absolute humidity of the AirQualityType, as a Double.
*/
double AirQualityType::getAbsHumidity() const {
	return absHumidity;
}

/**
 * Overloads the cout << operator.
*/
ostream& operator<<(ostream& osObject, const AirQualityType& aqt1) {
	osObject << aqt1.getDate() << ", " << aqt1.getTemp() << ", " << aqt1.getAbsHumidity();
	return osObject;
}