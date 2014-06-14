#include <typeinfo>
#include <iostream>

using namespace std;

class Base {};
class Derived : public Base {};

void main_0806() {
    Base b, bb;
    Derived d;
    
    cout << typeid(b).name() << endl;
    cout << typeid(Base).name() << endl;
    cout << typeid(d).name() << endl;
    cout << typeid(Derived).name() << endl;
    
    cout << ( typeid(b) == typeid(bb) ) << endl;
    cout << ( typeid(b) == typeid(d) ) << endl;
    cout << ( typeid(d) == typeid(Derived) ) << endl;
}