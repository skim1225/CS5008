#ifndef AIRQUALITYTYPE_H
#define AIRQUALITYTYPE_H

#include "Date.h"
#include "Date.cpp"
#include "Time.h"
#include "Time.cpp"

/**
 * A class representing an air quality measurement.
 *
 * Class AirQualityType encapsulates information about an air quality measurement as the date and
 * time it was collected as well as the temperature, relative, and absolute humidity at the time
 * of recording.
*/

class AirQualityType {
	friend ostream& operator << (ostream&, const AirQualityType&);

	private:
		Date date;
		Time time;
		double temp;
		double relHumidity;
		double absHumidity;

	public:
		AirQualityType(Date d, Time t, double temp, double relH, double absH);
		AirQualityType();
		~AirQualityType();
		Date getDate() const;
		Time getTime() const;
		double getTemp() const;
		double getRelHumidity() const;
		double getAbsHumidity() const;
};

#endif