#include <iostream>

using namespace std;

class HTable {
public:
	explicit HTable(int id): _id(id) {
		cout << "Creating HTable..." << _id << endl;
	}
	~HTable() {
		cout << "Destroying HTable..." << _id << endl;
	}
	int getId() {
		return _id;
	}
private:
	int _id;
};

void main_using_explicit() {
	HTable ht(13);
	ht = 5;							// Creating HTable...5
									// Destroying HTable...5
	cout << ht.getId() << endl;		// 5
									// Destroying HTable...5
}

int main() {
	main_using_explicit();
}