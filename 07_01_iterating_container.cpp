#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

static const int ARRAY_SIZE = 5;

template<typename T, typename FwdIter>
FwdIter fixOutliersUBound(FwdIter p1, FwdIter p2, const T& oldVal, const T& newVal) {
    for (; p1 != p2; ++p1) {
        if (greater<T>(*p1, oldVal)) {
            *p1 = newVal;
        }
    }
}

int main_0701() {
    list<string> lstStr;
    
    lstStr.push_back("Please");
    lstStr.push_back("leave");
    lstStr.push_back("a");
    lstStr.push_back("message");
    
    for (list<string>::iterator p = lstStr.begin(); p != lstStr.end(); ++p) {
        cout << *p << endl;
    }
    // Reverse iterator
    for (list<string>::reverse_iterator p = lstStr.rbegin(); p != lstStr.rend(); ++p) {
        cout << *p << endl;
    }
    
    // Iterate thourgh a range
    string arrStr[ARRAY_SIZE] = { "MY", "WAY" };
    
    for (string* p = arrStr; p != &arrStr[ARRAY_SIZE]; ++p) {
        cout << *p << endl;
    }
    
    // Unique copy
    list<string> lstStr2;
    // back_inserter acts like push_back
    unique_copy(&arrStr[0], &arrStr[ARRAY_SIZE], back_inserter(lstStr2));
    
    for (list<string>::const_iterator iter = lstStr2.begin(); iter != lstStr2.end(); ++iter) {
        cout << *iter << endl;
    }
    
    return 0;
}