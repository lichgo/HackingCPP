#include <iostream>
#include <vector>

using namespace std;

static const int NUM_OBJECTS = 10;

class MyClass {
public:
    int id = 1;
};

int main_0604() {
	vector<MyClass*> vecPtr;

	MyClass *p = NULL;

	for (int i = 0; i < NUM_OBJECTS; i++) {
		p = new MyClass();      // new class returns a pointer
		vecPtr.push_back(p);
	}

    cout << p->id << endl;
	for (vector<MyClass*>::iterator iter = vecPtr.begin(); iter != vecPtr.end(); ++iter) {
		delete *iter;	// *iter still a pointer, delete the objects
	}
    p->id = 23;     // unknown exception
    cout << p->id << endl;

	vecPtr.clear();
    
//    p = new MyClass();
//    
//    delete p;
//    
//    p->id = 12;
//    
//    cout << p->id;

	return 0;
}