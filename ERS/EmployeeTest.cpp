#include <iostream>
#include  "Employee.h"

using namespace std;
using namespace ERS;

int main_employee() {
	Employee emp;

	emp.setFirstName("Jason");
	emp.setLastName("Lin");
	emp.setEmployeeNumber(12);
	emp.setSalary(5000);
	emp.promote();
	emp.promote(5000);
	emp.hire();
	emp.display();

	return 0;
}