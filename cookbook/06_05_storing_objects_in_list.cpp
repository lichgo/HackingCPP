#include <iostream>
#include <list>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

template<typename T>
struct printer {
	void operator()(const T& s) {
		cout << s << '\n';
	}
};

bool inline even(int n) {
	return n % 2 == 0;
}

printer<string> strPrinter;
printer<int> intPrinter;

int main_0605() {
	list<string> lst1;
	list<string> lst2;

	lst1.push_back("Red");
	lst1.push_back("Green");
	lst1.push_back("Blue");

	lst2.push_front("One");
	lst2.push_front("Two");
	lst2.push_front("Three");

	for_each(lst1.begin(), lst1.end(), strPrinter);

	lst1.sort();
	lst2.sort();

	lst1.merge(lst2);   // sorted
	for_each(lst1.begin(), lst1.end(), strPrinter);

	list<int> intLst;
	intLst.push_back(1);
	intLst.push_back(2);
	intLst.push_back(3);
	intLst.push_back(4);

	// Remove all elements greater than 2
	//intLst.remove_if( bind2nd(greater<int>(), 2) );

	for_each(intLst.begin(), intLst.end(), intPrinter);

	intLst.remove_if(even);
    
    for_each(intLst.begin(), intLst.end(), intPrinter);

	return 0;
}