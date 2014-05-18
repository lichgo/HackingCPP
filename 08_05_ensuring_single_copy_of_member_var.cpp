#include "08_08_static.h"
#include <iostream>

using namespace std;

// Static member needs to be initialized globally
int OneStatic::count = 0;

OneStatic::OneStatic() {
    count++;
}

void main_0805() {
    OneStatic a, b, c;
    
    cout << a.getCount() << endl;
    cout << b.getCount() << endl;
    cout << c.getCount() << endl;
}

int main() {
    main_0805();
}