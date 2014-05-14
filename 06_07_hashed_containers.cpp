#include <iostream>
#include <string>
#include <hash_set>

int main() {
	hash_set<std::string> hsString;
	string s = "bravo";

	hsString.insert(s);
	s = "alpha";
	hsString.insert(s);

	for (hash_set<string>::const_iterator p = hsString.begin(); p != hsString.end() ++p) {
		cout << *p << endl;
	}
}