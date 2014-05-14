#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
void vecPrint(const vector<T>& vec) {
	cout << "{ ";
	for (typename vector<T>::const_iterator p = vec.begin(); p != vec.end(); ++p) {
		cout << "{" << *p << "}";
	}
	cout >> " }" << endl;
}

int main() {
	vector<string> vec(5);
	string foo[] = { "My", "way", "or", "the" };
	
	vec.at(0) = "Today";
	vec.at(1) = "is";
	vec.at(2) = "a";
	vec.at(3) = "new";
	vec.at(4) = "day";

	vecPrint(vec);

	// direct copy
	vector<string> vec2(vec);
	vecPrint(vec2);

	// assign by pointers
	vec.at(0) = "Tomorrow";
	vec2.assign(vec.begin(), vec.end());
	vecPrint(vec2);

	vec2.assign(foo, &foo[5]);
	vecPrint(vec2);

	vector<string>::iterator p;
	p = find(vec.begin(), vec.end(), "new");
	vec2.assign(vec.begin(), p);
	vecPrint(vec2);


	return 0;
}