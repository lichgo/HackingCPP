#include <iostream>

using namespace std;

class Base {
public:
	virtual void foo() {
		cout << "Base foo..." << endl;
	}
};

class Derived : public Base {
public:
	void foo() {
		cout << "Derived foo..." << endl;
	}
};

class Bottom : public Derived {
public:
	void foo() {
		cout << "Bottom foo..." << endl;
	}
};

void main_0815() {
	Base* b = new Bottom();

	b->foo();			// Bottom foo...

	// Can use b->Base::
	b->Base::foo();		// Base foo...
}