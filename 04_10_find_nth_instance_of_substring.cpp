#include <iostream>
#include <string>

using namespace std;

int nthSubstr(int nth, const string& s, const string& sub) {
    
    string::size_type i = s.find(sub);
    
    
    int j;
    for (j = 1; j < nth && i != string::npos; ++j) {
        i = s.find(sub, i + 1);     // the second arg means the searching starting palce
    }
   
    return (j == nth) ? i : -1;
}

void main_0410() {
    string s = "the wind, the sea, the sky";
    string sub = "the";
    
    cout << nthSubstr(1, s, sub) << '\n';
    cout << nthSubstr(3, s, sub) << '\n';
    cout << nthSubstr(6, s, sub) << '\n';
}