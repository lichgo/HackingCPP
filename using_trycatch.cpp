//
//  using_trycatch.cpp
//  HackingCPP
//
//  Created by lichgo on 11/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_trycatch.h"

using namespace std;

void throw_error()
{
    throw runtime_error("RUNTIME ERROR FROM function.");
}

int main()
{
    int i = 0;
    if (i != 0)
        throw runtime_error("RUNTIME ERROR: i == 0.");
    
    try
    {
        throw_error();
        cout << "HIHI" << endl;
    }
    catch (runtime_error err)
    {
        cout << err.what();
    }
    
    // return 0; this is neglectable
}