#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

class MyClass {
protected:
    int value_;
public:
    static list<MyClass*> instances_;
    MyClass(int val);
    ~MyClass();
    static void show_list();
};

// Essential: Init a static member
list<MyClass*> MyClass::instances_;

MyClass::MyClass(int val) {
    cout << "Creating a myclass..." << value_ << endl;
    instances_.push_back(this);
    value_ = val;
}

// Constructing order is the opposite of deconstructing
MyClass::~MyClass() {
    cout << "Destroying a myclass...." << value_ << endl;
    list<MyClass*>::iterator p = find(instances_.begin(), instances_.end(), this);
    if (p != instances_.end())
        instances_.erase(p);
}

void MyClass::show_list() {
    for (list<MyClass*>::const_iterator p = instances_.begin(); p != instances_.end(); ++p) {
        cout << (*p)->value_ << endl;
    }
}

void main_0804() {
    MyClass a(1), b(10), c(100);
    MyClass::show_list();
}