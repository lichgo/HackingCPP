#include <string>
#include <iostream>

using namespace std;

void main_0411() {
    string t = "Banana Republic";
    string sub = "nana";
    
    string::size_type first_occurence = t.find(sub);
    if (first_occurence != string::npos)
        t.erase(first_occurence, sub.length());
    
    cout << t;
}