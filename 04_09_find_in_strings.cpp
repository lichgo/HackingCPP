#include <string>
#include <iostream>

using namespace std;

void main_0409() {
    string s = "Charles Darwin";
    
    cout << s.find("ar") << endl;   //2
    cout << s.rfind("ni") << endl;  //string::npos
    cout << s.find_first_of("swi") << endl;    //6
    cout << s.find_first_not_of("Charles ") << endl;    //8
    cout << s.find_last_of("abg") << endl;  //9
    cout << s.find_last_not_of("aDinrw") << endl;   //7
    
    
}