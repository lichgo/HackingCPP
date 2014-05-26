#include <iostream>
#include <fstream>

using namespace std;

int main_0415(int argc, char* infile, char* outfile) {
	if (argc < 3)
		return EXIT_FAILURE;

	ifstream in(infile);
	ofstream out(outfile);

	if (!in || !out)
		return EXIT_FAILURE;

	char c;
	while (in.get(c)) {
		if (c == '\t')
			out << "   ";
		else
			out << c;

		cout << c;
	}

	out.close();
	in.close();

	if (out)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}