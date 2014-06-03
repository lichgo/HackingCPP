#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cwctype>

using namespace std;

inline bool caseInsCharCompare(char a, char b) {
	return (toupper(a) == toupper(b));
}

bool caseInsStrCompare(const string& s1, const string& s2) {
	return (s1.size() == s2.size() && equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompare));
}

