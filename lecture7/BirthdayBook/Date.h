

#ifndef CLASS_EXAMPLE_DATE_H
#define CLASS_EXAMPLE_DATE_H

#include <iostream>
#include <string>
using namespace std;


class Date {
    friend ostream& operator << (ostream&, const Date&);
    friend istream& operator >> (istream&, Date&);
public:
    Date();
    Date(int d, int m, int y);
    ~Date();

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    void setDate(int d, int m, int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    string getDate() const;

    void print() const;

    bool operator==(const Date& otherDate) const;

private:
    int day;
    int month;
    int year;
};


#endif //CLASS_EXAMPLE_DATE_H
