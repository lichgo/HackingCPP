//
//  using_array.cpp
//  HackingCPP
//
//  Created by lichgo on 8/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_array.h"

using std::cout;

int get_size() {
    return 4;
}

int main()
{
    const unsigned buf_size = 52;
    int staff_size = 12;
    const int tree_size = get_size();
    
    char a1[buf_size];
    char a2[buf_size + 1];
    int a3[staff_size];
    int a4[get_size()];
    int a5[tree_size];
    
    cout << a1[0] << a3[7];
    
    for (int *p = a4; )
    
    
    return 0;
}