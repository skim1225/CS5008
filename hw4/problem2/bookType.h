#include <string>
#include <iostream>

using namespace std;

class bookType {

	// overload cout
	friend ostream& operator << (ostream& osObject, const bookType& book1);

public:

	// constructors
	bookType();
	bookType(string title_arg, string authors_arg[], string publisher_arg, string isbn_arg,
		double price_arg, int num_copies_arg, int num_authors_arg);

	// destructor
	~bookType();

	// getters
	string get_title() const;
	string* get_authors() const;
	string get_publisher() const;
	string get_isbn() const;
	double get_price() const;
	int get_num_copies() const;
	int get_num_authors() const;

	// setters
	void set_title(string title_arg);
	void set_authors(string authors_arg[]);
	void set_publisher(string publisher_arg);
	void set_isbn(string isbn_arg);
	void set_price(double price_arg);
	void set_num_copies(int num_copies_arg);
	void set_num_authors(int num_authors_arg);
	void setBookInfo(string title_arg, string isbn_arg, string publisher_arg, string author_arg[],
		double cost_arg, int num_copies_arg, int num_authors_arg);

	// updaters
	void update_num_copies(int change);

	// display
	void display_title() const;
	void display_authors() const;
	void display_publisher() const;
	void display_isbn() const;
	void display_price() const;
	void display_num_copies() const;
	void display_num_authors() const;
	void printInfo() const;

	// check
	bool isTitle(string s) const;
	bool isISBN(string s) const;
	bool isAuthor(string s) const;
	bool isInStock() const;

private:

	string title;
	string authors[4];
	string publisher;
	string isbn;
	double price;
	int num_copies;
	int num_authors;

};