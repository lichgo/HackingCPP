#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char* npt;	// NULL pointer


/*
long int strtol (const char* str, char** endptr, int base);
*/

void main_0310() {
	char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
	char* end;

	long int li1, li2, li3, li4;

	li1 = strtol(szNumbers, &end, 10);
	li2 = strtol(end, &end, 16);
	li3 = strtol(end, &end, 2);
	li4 = strtol(end, NULL, 0);

	printf("The decimal numbers are: %ld, %ld, %ld, %ld.", li1, li2, li3, li4);
}