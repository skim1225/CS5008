# include <string>
# include <iostream>

using namespace std;


class Person {
    friend ostream& operator << (ostream&, const Person&);
    friend istream& operator >> (istream&, Person&);
public:
    Person();
    Person(string fn, string md, string ln);
    ~Person();
    void setFirstName(string fn);
    void setMiddleName(string md);
    void setLastName(string ln);
    void setFullName(string fn, string mn, string ln);

    // getters
    string getFirstName() const;
    string getMiddleName() const;
    string getLastName() const;
    string getFullName() const;

    // IO
    void print() const;

    void read_input();

    // Overloading the == operator
    bool operator==(const Person& otherPerson) const;
    bool operator<(const Person& otherPerson) const;
    bool operator>(const Person& otherPerson) const;
    bool operator<=(const Person& otherPerson) const;
    bool operator>=(const Person& otherPerson) const;
    bool operator!=(const Person& otherPerson) const;

private:
    string firstName;
    string middleName;
    string lastName;
};
