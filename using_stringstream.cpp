//
//  using_stringstream.cpp
//  HackingCPP
//
//  Created by lichgo on 11/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_stringstream.h"
#include <sstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;

int main_stringstream()
{
    string line, word;
    while (getline(cin, line))
    {
        if (line == "done") break;
        
        istringstream stream(line);     // bind line to a stringstream
        
        while (stream >> word)
        {
            cout << word << endl;
        }
    }
    
    int val1 = 12, val2 = 23;
    ostringstream format;
    format << "val1: " << val1 << "\tval2: " << val2;
    
    istringstream from_format(format.str());
    int val3;   //0 by default
    int val4;
    string dump;
    from_format >> dump >> val3 >> dump >> val4;
    cout << val3 << " " << val4;
    
    return 0;
}