#include <iostream>
#include <stdexcpt.h>

#include "Database.h"

using namespace std;
using namespace ERS;

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

	cin >> selection;

	return selection;
}

void doHire(Database& db) {
	string firstName;
	string lastName;

	cout << "First name: ";
	cin >> firstName;
	cout << endl << "Last name: ";
	cin >> lastName;

	try {
		db.addEmployee(firstName, lastName);
		cout << "Employee " << firstName << " " << lastName << " has been hired." << endl;
	}
	catch (exception ex) {
		cerr << "Unable to add new employee!" << endl;
	}
}

void doFire(Database& db) {
	int employeeNumber;

	cout << "Employee number: ";
	cin >> employeeNumber;

	try {
		db.getEmployee(employeeNumber).fire();
		cout << "Employee " << employeeNumber << " has been fired." << endl;
	}
	catch (exception ex) {
		cerr << "Unable to fire employee." << endl;
	}
}

void doPromote(Database& db) {
	int employeeNumber;
	int raiseAmount;

	cout << "Employee number: ";
	cin >> employeeNumber;
	cout << endl << "Raise amount: ";
	cin >> raiseAmount;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
		cout << "Employee " << employeeNumber << " has been promoted by $" << raiseAmount << endl;
	}
	catch (exception ex) {
		cerr << "Unable to promote the employee." << endl;
	}
}

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