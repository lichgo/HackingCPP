//
//  using_function.h
//  HackingCPP
//
//  Created by lichgo on 11/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#ifndef __HackingCPP__using_function__
#define __HackingCPP__using_function__

#include <iostream>
using namespace std;

#endif /* defined(__HackingCPP__using_function__) */

void swap(int *, int *);
void swap(int &, int &);

inline const string &longerString(string &s1, string &s2)
{
    return s1.size() < s2.size() ? s2 : s1;
}