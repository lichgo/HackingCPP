#include <string>
#include <iostream>

using namespace std;

void main_0404() {
    string s = "hello world";
    cout << s.length() << endl;
    
    string str = "";
    cout << &str << endl;
    str.reserve(2); //capacity is over 2 now
    cout << &str << endl;
    str += 'c';
    str += 'c';
    str += 'c';
    cout << &str << endl;
    
    str.reserve(9000);  // capacity is over 9000. without this, capacity will increase automatically
    
    cout << "length: " << str.length() << '\n';
    cout << "capcity: " << str.capacity() << '\n';
    cout << "max_size: " << str.max_size() << '\n';
    
    // capacity increases when buffer is full (length == capacity);
    
    for (int i = 0; i < 10000; ++i) {
        if (s.length() == s.capacity()) {
            cout << "s length/capacity: " << s.capacity() << endl;
        }
        if (str.length() == str.capacity()) {
            cout << "str length/capacity: " << str.capacity() << endl;
        }
        s += 'x';
        str += 'y';
    }
}