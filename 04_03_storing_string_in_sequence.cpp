#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

void write(const string& s) {
    cout << s << '\n';
}

void main_0403() {
    
    // vector
    vector<string> v;
    
    string s = "one";
    v.push_back(s);
    s = "two";
    v.push_back(s);
    s = "three";
    v.push_back(s);
    
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << '\n';
    }
    
    
    // list
    list<string> l;
    
    l.push_front("knife");
    l.push_front("spoon");
    l.push_front("fork");
    
    for_each(l.begin(), l.end(), write);
}