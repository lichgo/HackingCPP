#include <utility>
#include <iostream>
#include <string>

using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
	return out << "[" << p.first << ", " << p.second << "]";
}

void main_pair() {
	typedef pair<int, float> IntFloatPair;
	IntFloatPair p(1, 2.3);

	cout << p << endl;

	cout << get<0>(p) << endl;							//p.first
	cout << get<1>(p) << endl;							//p.second
	cout << tuple_size<IntFloatPair>::value << endl;	//2
	tuple_element<0, IntFloatPair>::type i;				
	cout << typeid(i).name() << endl;					//int

	pair<int, float> q;		//<0, 0.0> by default
	cout << q << endl;

	pair<int, const char*> s(12, "abc");
	f(s);	//legal, implicit type conversion
	g(s);	//legal, implicit type conversion
}

void f(pair<int, const char*>);
void g(pair<int, string>);

int main() {
	main_pair();
}