//
//  using_string.cpp
//  HackingCPP
//
//  Created by lichgo on 6/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_string.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main_string()
{
    string s;
    cin >> s;
    cout << s << endl;
    
    int count = 1;
    // read word by word seperated by space
    string word;
    while (cin >> word)         // text: a b c done d => output: a\n b\n c\n
    {
        cout << count++;
        if (word == "done")
            break;
        cout << word << endl;
    }
    
    // read line by line
    string line;
    while (getline(cin, line))
    {
        if (line == "done") break;
        cout << line << endl;
    }
    
    // string s1 = "hello" + "world"; error, not a string object
    string s1 = "hello";
    string s2 = s1 + "2world" + "3haha";  // after +, return a string object, so chaining+ is ok
    
    // string::size_type
    int count_digits = 0;
    for (string::size_type i = 0; i != s2.size(); ++i)
    {
        cout << s2[i] << endl;
        if (isdigit(s2[i])) count_digits++;
        s2[i]++;
    }
    cout << s2 << endl;
    cout << "The number of digits in s2: " << count_digits << endl;
    
    return 0;
}