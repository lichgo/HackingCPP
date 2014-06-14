#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void write(string& s) {
    cout << s << '\n';
}

void split(const string& s, const char delimiter, vector<string>& v) {
    string::size_type i = 0;
    string::size_type j = s.find(delimiter);
    
    while (j != string::npos) {
        v.push_back(s.substr(i, j - i));
        i = ++j;
        j = s.find(delimiter, j);
        
        if (j == string::npos) {
            v.push_back(s.substr(i, s.length()));
        }
    }
}

void main_0406() {
    string s = "hello";
    // const references and pointer can point to non-const
    string& s_ref = s;
    const string& s_const_ref = s;
    const string* s_const_ptr = &s;
    // *s_const_ptr = "new string"; error
    // string* ptr_to_literal = &"hihi";    error
    
    const string str = "test";
    // string& str_ref = str;   error
    
    
    vector<string> v;
    string columes = "Name|Telephone Number|Address|Company|City";
    split(columes, '|', v);
    
    for_each(v.begin(), v.end(), write);
}