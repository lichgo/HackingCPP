#include <utility>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
	return out << "[" << p.first << ", " << p.second << "]";
}


class Foo {
public:
	Foo(tuple<int, float>) {
		cout << "tuple" << endl;
	}
	template<typename... Args>
	Foo(Args... args) {
		cout << "Args" << endl;
	}
};

void f(pair<int, const char*>);
void g(pair<int, string>);

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

	// using tuple to pass values to constructor
	tuple<int, float> t(1, 2.34);
	pair<int, Foo> pif(2, t);		// implicit conversion
	pair<int, Foo> pif2(piecewise_construct, make_tuple(42), t);

}

//int main() {
//	main_pair();
//}