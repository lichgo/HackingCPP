#include <iostream>

int main() {

	// Declaration
	extern int x;	// declare an integer

	std::size_t numDigits(int number);	// declare a function

	class Widget;	// declare a class

	template<typename T>	// declare a template
	class GraphNode;


	// Some undefined behaviros
	int* p = 0;			// p is a null pointer
	std::cout << *p;	// undefined behavior: dereferencing a NULL pointer

	char name[] = "Darla";
	char c = name[10];	// undefined bahavior

}