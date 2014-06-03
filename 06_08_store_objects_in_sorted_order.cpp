#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// set and map both have sorted order
int main_0608() {
    set<string> setStr;
    
    string s = "bill";
    setStr.insert(s);
    s = "jason";
    setStr.insert(s);
    s = "eric";
    setStr.insert(s);
    
    for (set<string>::const_iterator iter = setStr.begin(); iter != setStr.end(); ++iter) {
        cout << *iter << endl;
    }
    
    // bill, eric, jason: see they have been sorted.
    
    return 0;
}