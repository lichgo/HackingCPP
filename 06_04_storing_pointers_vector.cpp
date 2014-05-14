#include <iostream>
#include <vector>

using namespace std;

static const int NUM_OBJECTS = 10;

class MyClass { };

int main() {
	vector<MyClass*> vecPtr;

	MyClass* p = NULL;

	for (int i = 0; i < NUM_OBJECTS; i++) {
		p = new MyClass();
		vecPtr.push_back(p);
	}

	for (vector<MyClass*>::iterator iter = vecPtr.begin(); iter != vecPtr.end(); ++iter) {
		delete *iter;	// *iter still a pointer, delete the objects
	}

	vecPtr.clear();

	return 0;
}