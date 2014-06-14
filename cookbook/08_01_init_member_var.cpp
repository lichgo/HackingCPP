#include <string>
#include <iostream>

using namespace std;

// Members are initialized in the order they are declared,
// NOT the order in the initializer list

// Every member field needs be initialized in the constructor

class Pen {
public:
    Pen(int id) {
        cout << "Creating a pen by id: " << id << endl;
    }
};

static int counter = 0;

class Foo {
public:
    Foo(): pen_(++counter), ref_("123") {}
    Foo(int c, string* p): counter_(c), str_(p), pen_(++counter), ref_(*p) {}
    void print() {
        cout << counter_ << '\n';
        cout << str_ << '\n';
//        cout << pen_ << '\n';
    }
private:
    int counter_;
    string* str_;
    Pen pen_;
    const string& ref_;
};

int main_0801() {
    Foo foo;
    Foo foo2 = Foo();
    return 0;
}