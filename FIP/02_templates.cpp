#include <vector>
#include <string>
#include <iostream>

#include "Range.h"

using namespace std;
using namespace FinMath;

namespace FinMath {

template<class T>
class EuropeanOption {
	T interestRate;
	T volatility;
	T strikePrice;
	T expireDate;
	T currentUnderlyingPrice;
	T costOfCarry;

	string optionType;
};

template<class Name = string, class Type = double>
class MyProperty {
private:
	Name name;
	Type type;
public:
	MyProperty();
	MyProperty(const Name& n, const Type& t);
};

// Template functions
template<class T>
void swap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template<class T>
T normalPDF(const T& x) const {
	T a = 1.0 / sqrt(2.0 * 3.1415);
	return a * exp(-x * x * 0.5);
}

typedef int Length;
typedef MyProperty<> StandardProperty;

}

int main() {
	Range<int> range1(1, 4);
	Range<int> range2(range1);

	MyProperty<string> p1;
	MyProperty<> p2;
}