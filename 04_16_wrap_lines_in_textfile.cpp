#include <iostream>
#include <fstream>

using namespace std;

void textWrap(istream& in, ostream& out, size_t width) {
	string tmp;
	char cur = '\0';
	char last = '\0';
	size_t i = 0;

	while (in.get(cur)) {
		if (++i == width) {
			
		}
	}
}