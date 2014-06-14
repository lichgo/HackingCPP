#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

// All char changed to upper case
inline bool caseInsCharCompSingle(char a, char b) {
	return (toupper(a) == b);
}

string::const_iterator caseInsFind(string& s, const string& p) {
	string tmp;

	transform(p.begin(), p.end(), back_inserter(tmp), toupper);

	return (search(s.begin(), s.end(), tmp.begin(), tmp.end(), caseInsCharCompSingle));
}

void main_0414() {
	string s = "row, row, row, your boat";
	string p = "YOUR";
	string::const_iterator it = caseInsFind(s, p);

	if (it != s.end()) {
		cout << "FOUNT IT!" << endl;
	}
}