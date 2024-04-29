#ifndef MENUOPTION_H
#define MENUOPTION_H

#include "VectorAQT.h"
#include "VectorAQT.cpp"
#include "AirQualityType.h"
#include "AirQualityType.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

/**
 * Class MenuOption is a utility class for handling user input, retrieving, and performing
 * calculations on a CSV dataset.
*/

class MenuOption {

    public:
        MenuOption();
        ~MenuOption();
        void start(string filename);

    private:
        // input
        void getData(ifstream& inData, VectorAQT& AQTVector);
        int getChoice();
        pair<int, int> getMonthAndYear();

        // getters
        double getAvgTemp(VectorAQT& monthData);
        double getAvgRelHumidity(VectorAQT& monthData);
        double getAvgAbsHumidity(VectorAQT& monthData);
        pair<double, double> getTempAndRelHumidity(Date day, Time time, VectorAQT& AQTVector);
        double getHighTemp(VectorAQT& monthData);
        double getHighRelHumidity(VectorAQT& monthData);
        double getHighAbsHumidity(VectorAQT& monthData);
        VectorAQT getAllAboveAvgTemp(VectorAQT& monthData);
        VectorAQT getAllAboveAvgRelHumidity(VectorAQT& monthData);
        VectorAQT getAllAboveAvgAbsHumidity(VectorAQT& monthData);

        // helper funcs
        void displayDatesAndTimes(VectorAQT selectedAQTs);
        VectorAQT getAQTsForMonth(int month, int year, VectorAQT& AQTVector);
        Date getDate();
        Time getTime();
        bool checkSize(VectorAQT v);
        bool isNumber(string value);
        int getValidInt(string value, string type);
};

#endif