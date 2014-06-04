#include <iostream>
#include <stdexcpt>

#include "Database.h"

using namespace std;
using namespace ERS;

int main() {
	Database db;
	bool done = false;

	while (!done) {
		int selection = displayMenu();

		switch (selection) {
		case 1:
			doHire(db);
			break;
		case 2:
			doFire(db);
			break;
		case 3:
			doPromote(db);
			break;
		case 4:
			db.displayAll();
			break;
		case 5:
			db.displayCurrent();
			break;
		case 6:
			db.displayFormer();
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "Unknown command." << endl;
		}
	}

	cout << "Program exit." << endl;

	return 0;
}

int displayMenu() {
	int selection;

	cout << "----------------------" << endl;
	cout << "1 hire" << endl;
	cout << "2 fire" << endl;
	cout << "3 promote" << endl;
	cout << "4 all" << endl;
	cout << "5 current" << endl;
	cout << "6 former" << endl;
	cout << "0 quit" << endl;
	cout << "----------------------" << endl;
}

void doFire(Database& db) {

}