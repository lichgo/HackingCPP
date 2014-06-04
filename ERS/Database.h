#ifndef ERS_DATABASE_H_

#define ERS_DATABASE_H_

#include <iostream>
#include "Employee.h"

namespace ERS {

	const int kMaxEmployee = 100;
	const int kFirstEmployeeNumber = 1000;

	class Database {

	public:
		Database();
		~Database();

		Employee& addEmployee(std::string inFirstName, std::string inLastName);
		Employee& getEmployee(int inEmployeeNumber);
		Employee& getEmployee(std::string inFirstName, std::string inLastName);

		void displayAll();
		void displayCurrent();
		void displayFormer();

	protected:
		Employee mEmployees[kMaxEmployee];
		int mNextSlot;
		int mNextEmployeeNumber;

	};
}

#endif