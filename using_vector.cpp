//
//  using_vector.cpp
//  HackingCPP
//
//  Created by lichgo on 7/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_vector.h"

#include <vector>
using std::vector;
using std::string;

int m()
{
    // initialization
    vector<int> v1;
    vector<int> v2(v1);
    vector<int> v3(10, 'a');
    vector<int> v4(100);    //100 0s
    vector<string> v5(5);   //5 empty strings
    
    // iterator
    for (vector<int>::iterator iter = v3.begin(); iter != v3.end(); ++iter)
    {
        *iter = 'b';
    }
    std::cout << (char)v3[5] << std::endl;
    
    // const_iterator
    vector<int>::const_iterator c_iter = v3.begin();
    //*c_iter = 'a';  //error, the pointed ele is read-only
    c_iter++;       //ok
    
    // compared with const iterator
    const vector<int>::iterator C_ITER = v3.begin();
    *C_ITER = 'c';  //ok
    //*C_ITER++;  // error
    
    return 0;
}