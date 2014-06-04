#ifndef ERS_EMPLOYEE_H_

#define ERS_EMPLOYEE_H_

#include <iostream>
#include <string>

namespace ERS {

const int kDefaultStartingSalary = 30000;

	class Employee {

	public:
		Employee();

		void			promote(int inRaiseAmount = 1000);
		void			demote(int inDemeritAmount = 1000);
		void			hire();
		void			fire();
		void			display();

		// Accessors and Setters
		void			setFirstName(std::string inFirstName);
		std::string		getFirstName();
		void			setLastName(std::string inLastName);
		std::string		getLastName();
		void			setEmployeeNumber(int inEmployeeNumber);
		int				getEmployeeNumer();
		void			setSalary(int inNewSalary);
		int				getSalary();
		bool			getIsHired();

	private:
		std::string		mFirstName;
		std::string		mLastName;
		int				mEmployeeNumber;
		int				mSalary;
		bool			fHired;

	};

}

#endif