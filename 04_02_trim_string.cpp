#include <iostream>
#include <string>

using namespace std;

void trim(string& s, char c) {
    // from beginning
    string::iterator iter = s.begin();
    while (iter != s.end() && *iter == c) iter++;
    s.erase(s.begin(), iter);
    
    // from end
    iter = --s.end();
    while (iter != s.begin() && *iter == c) iter--;
    if (*iter != c) iter++;
    s.erase(iter, s.end());
}

int main_0402() {
    
    // first pointer == last pointer in erase, remove nothing
    string s = "hallo";
    s.erase(s.begin(), s.begin());
    cout << s << "|" << endl;
    
    trim(s, ' ');
    cout << s << "|" << endl;
    
    s = "hallo ";
    trim(s, ' ');
    cout << s << "|" << endl;
    
    s = "hallo***";
    trim(s, ' ');
    cout << s << "|" << endl;
    
    trim(s, '*');
    cout << s << "|" << endl;
    
    s = "**  *hallo***";
    trim(s, '*');
    cout << s << "|" << endl;
    
    return 0;
}