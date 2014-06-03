//
//  using_io.cpp
//  HackingCPP
//
//  Created by lichgo on 11/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_io.h"

#include <iostream>

using namespace std;

int main_io()
{
    int i = 0;
    while (i < 3, false)        // condition is only on the second expression after comma
    {
        cout << i++ << endl;
    }
    
    // stream status and control
    int ival;
    while (cin >> ival, !cin.eof())
    {
        if (cin.bad())
        {
            throw runtime_error("bad");
        }
        
        if (cin.fail())
        {
            cerr << "bad data, try again.";
            cin.clear(istream::failbit);
            continue;
        }
        
        cout << ival << endl;
    }
    
    return 0;
}