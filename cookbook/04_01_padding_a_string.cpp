#include <iostream>
#include <string>

#include "stdio.h"

using namespace std;

// string is a typedef of basic_string<char>, wstring is a typedef of basic_string<wchar_t>
template<typename T>
void pad(basic_string<T>& s, typename basic_string<T>::size_type n, T c) {
    if (n > s.length()) {
        s.append(n - s.length(), c);
    }
}

int main_0401() {
    string s = "chapter 1";
    string::size_type length = s.length();
    
    // append
    s.append(20 - length, '.');
    cout << s << endl;
    
    s.erase(s.begin() + length, s.end());
    cout << s << endl;
    
    // insert(starting_pointer, length, char)
    s.insert(s.end(), 20 - length, '.');
    cout << s << endl;
    
    // using template function pad
    string ss = "hello world";
    wstring ws = L"你好世界";
    
    pad(ss, 20, '*');
    cout << ss << endl;
    
    pad(ws, 20, L'哈');
    //wcout << ws << endl;    // using wcout but failed
    //wprintf(ws);
    
    return 0;
}