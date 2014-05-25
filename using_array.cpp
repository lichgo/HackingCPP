//
//  using_array.cpp
//  HackingCPP
//
//  Created by lichgo on 8/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_array.h"

using std::cout;
using std::endl;

int get_size() {
    int result = 5;
    
    std::cin >> result;
    
    return result;
}

int main_array()
{
    // The length should be a constant that can be known in compile time
    const unsigned buf_size = 52;
    int staff_size = 2;
    const int tree_size = get_size();
    
//    char a1[buf_size];
//    char a2[buf_size + 1];
//    
//    int a3[staff_size]; //error
//    a3[5] = 4;
//    
//    int a4[get_size()]; //normal
//    a4[9] = 10;
//    for (int *p_start = a4, *p_end = a4 + get_size(); p_start != p_end; p_start++)
//    {
//        cout << "Num" << *p_start << endl;
//        *p_start = 324;
//    }
    
    //int a5[tree_size];  //error
	int a5[12];
    a5[9] = 12;
    cout << "a5 " << a5[9] << endl;

//    cout << a1[0] << a3[7] << endl;;

    // array of chars as string
    char s1[] = { 'C' };
    char s2[] = { 'C', '\0' };
    char s3[] = "C";    // same as s2, with null at the end
    
    return 0;
}