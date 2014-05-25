#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton* getInstance() {
		if (!instance) {
			instance = new Singleton();
		}
		return instance;
	}

	void setVal(int v) {
		val = v;
	}

	int getVal() {
		return val;
	}

protected:
	int val = 1;	// OK

private:
	// private all constructors (default, copy, =)
	Singleton(): val(123) {}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

	static Singleton* instance;
};

// Assign
Singleton* Singleton::instance = NULL;

void main_0809() {
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();

	cout << s1->getVal() << endl;
	s2->setVal(4);
	cout << s2->getVal() << endl;
}