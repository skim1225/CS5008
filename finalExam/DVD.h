#include <string>
#include <vector>

using namespace std;
class DVD
{
public:
	// constructor and destructor
	DVD(string t, vector <string> s, string p, string d, string pc, int n);
	~DVD();

	// setters
	void setTitle(string t);
	void setStars(vector <string> s);
	void setProducer(string p);
	void setDirector(string d);
	void setProductionCompany(string pC);
	void setNumCopies(int n);

	// getters
	string getTitle() const;
	vector<string> getStars() const;
	string getProducer() const;
	string getDirector() const;
	string getProductionCompany() const;
	int getNumCopies() const;

	// overloading comparison operators
	bool operator==(const DVD& otherDVD) const;
	bool operator<(const DVD& otherDVD) const;
	bool operator>(const DVD& otherDVD) const;

private:
	string title;
	vector <string> stars;
	string producer;
	string director;
	string productionCompany;
	int numCopies;
};