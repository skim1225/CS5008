#include "VectorAQT.h"

/**
 * Default constructor for creating a VectorAQT.
*/
VectorAQT::VectorAQT() {
	length = 0;
	capacity = 1;
	data = new AirQualityType[1];
}

/**
 * Default destructor for destroying a VectorAQT.
*/
VectorAQT::~VectorAQT() {}

/**
 * Helper method for doubling the size of the VectorAQT array once it reaches capacity.
*/
void VectorAQT::resize() {
	capacity *= 2;
	AirQualityType *newArray = new AirQualityType[capacity];
	copy(data, newArray, length);
	delete[] data;
	data = newArray;
}

/**
 * Helper method for aiding in the resizing of the VectorAQT.
*/
void VectorAQT::copy(AirQualityType fromArray[], AirQualityType toArray[], int length) {
	for (int i = 0; i < length; i++) {
		toArray[i] = fromArray[i];
	}
}

// returns the index of the first AQT with the given month and year, or -1 if it does not exist
int VectorAQT::find(int month, int year) const {
	int l = 0;
    int r = length - 1;
    int result = -1;

    while (l <= r) {
        int middle = l + (r - l) / 2;

        int currentYear = data[middle].getDate().getyear();
        int currentMonth = data[middle].getDate().getMonth();

        if (currentYear == year && currentMonth == month) {
            result = middle;
            r = middle - 1;
        } else if (currentYear > year || (currentYear == year && currentMonth > month)) {
            r = middle - 1;
        } else {
            l = middle + 1;
        }
    }

    return result;
}

/**
 * Returns the size of the VectorAQT, as an int.
*/
int VectorAQT::size() const {
	return length;
}

/**
 * Returns the capacity of the VectorAQT, as an int.
*/
int VectorAQT::getCapacity() const {
	return capacity;
}

/**
 * Returns whether the VectorAQT is empty, as a boolean.
*/
bool VectorAQT::isEmpty() const {
	return length == 0;
}

/**
 * Adds the given AirQualityType to the rear of the VectorAQT.
*/
void VectorAQT::push_back(AirQualityType aqt) {
	if (length == capacity) {
		resize();
	}
	data[length] = aqt;
	length++;
}

/**
 * Removes the last AirQualityType in the VectorAQT.
*/
void VectorAQT::pop_back() {
	if (length > 0) {
		length--;
	} else {
		return;
	}
}

/**
 * Returns the AirQualityType at the given index in the VectorAQT.
*/
AirQualityType VectorAQT::at(int index) const {
	return data[index];
}

/**
 * Returns the first AirQualityType in the VectorAQT.
*/
AirQualityType VectorAQT::front() const {
	return data[0];
}

/**
 * Returns the last AirQualityType in the VectorAQT.
*/
AirQualityType VectorAQT::back() const {
	return data[length - 1];
}