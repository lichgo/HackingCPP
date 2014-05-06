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

int main()
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
    
    return 0;
}