#include <iostream>
#include <map>
#include <string>
#include "Person.h"
#include "Date.h"

using namespace std;

int main() {
    map<Person, Date>myMap;

    Person p1("Htet", "htet", "Win");
    Person p2("ang", "Wan", "Xin");
    Person p3("A", "B", "C");
    Person p4("E", "F", "G");

    Date d1(1, 2, 4);
    Date d2(2, 12, 6);
    Date d3(3, 4, 5);
    Date d4(4, 5, 6);

    myMap.insert(pair<Person, Date>(p1, d1));
    myMap.insert(pair<Person, Date>(p2, d2));
    myMap.insert(pair<Person, Date>(p3, d3));
    myMap.insert(pair<Person, Date>(p4, d4));

    map<Person, Date>::iterator it;

    for (it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << ": " << it->second << "\n";
    }

    return 0;
}
