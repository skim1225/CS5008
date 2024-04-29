#ifndef VECTORAQT_H
#define VECTORAQT_H

#include "AirQualityType.h"

/**
 * Class VectorAQT represents a Vector which stores AirQualityType objects. It supports operations
 * such as getting the size of the VectorAQT, getting the AirQualityType at a specific index,
 * and getting the index of the certain AirQualityType.
*/

class VectorAQT {
	public:
		VectorAQT();
		~VectorAQT();

		int size() const;
		int getCapacity() const;
		bool isEmpty() const;
		void push_back(AirQualityType aqt);
		void pop_back();
		AirQualityType at(int index) const;
		AirQualityType front() const;
		AirQualityType back() const;
		int find(int month, int year) const;

	private:
		int length;
		int capacity;
		AirQualityType *data;
		void resize();
		void copy(AirQualityType fromArray[], AirQualityType toArray[], int length);
};

#endif