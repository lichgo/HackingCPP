#include <iostream>
#include <fstream>

using namespace std;

void main_0415(int argc, char** argv) {
	if (argc < 3)
		return EXIT_FAILURE;

	ifstream in(argv[1]);
	ofsteam out(argv[2]);

	if (!in || !out)
		return EXIT_FAILURE;

	char c;
	while (in.get(c)) {
		if (c == '\t')
			out << "   ";
		else
			out << c;
	}

	out.close();
	in.close();

	if (out)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}

int main() {
	main_0415();
}