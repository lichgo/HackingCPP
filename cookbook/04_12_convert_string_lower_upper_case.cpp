#include <string>
#include <iostream>
#include <cctype>

using namespace std;

void toUpper(string& s) {
    for (basic_string<char>::iterator p = s.begin(); p != s.end(); ++p) {
        *p = toupper(*p);
    }
}

void main_0412() {
    //string s = toUpper("123"); error
    //string s = toUpper( string("123") ); error
    string t = string("cap");
    toUpper(t);
    cout << t;
}