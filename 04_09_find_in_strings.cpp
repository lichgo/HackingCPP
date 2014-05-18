#include <string>
#include <iostream>

using namespace std;

template<typename T>
int countUnique(const basic_string<T>& s) {
    
    basic_string<T> chars;
    
    for (typename basic_string<T>::const_iterator p = s.begin(); p != s.end(); ++p) {
        if (chars.find(*p) == basic_string<T>::npos)
            chars += *p;
    }
    
    cout << chars << endl;
    
    return chars.length();
}

void main_0409() {
    string s = "Charles Darwin";
    
    cout << s.find("ar") << endl;   //2
    cout << s.rfind("ni") << endl;  //string::npos
    cout << s.find_first_of("swi") << endl;    //6
    cout << s.find_first_not_of("Charles ") << endl;    //8
    cout << s.find_last_of("abg") << endl;  //9
    cout << s.find_last_not_of("aDinrw") << endl;   //7
    
    cout << countUnique(s) << endl;
}