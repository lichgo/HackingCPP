//
//  using_expression.cpp
//  HackingCPP
//
//  Created by lichgo on 11/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_expression.h"

using std::cout;
using std::endl;
using std::string;

int main_e()
{
    int i = 23;
    int *p = &i;
    int a[4];
    // sizeof
    cout << sizeof(i) << endl;  //4
    cout << sizeof(p) << endl;  //8
    cout << sizeof(a) << endl;  //16
    
    // default init of dynamic creation
    int *pi = new int(120); // return a pointer when using new
    
    // create const dynamically
    const int *cpi = new const int(12);
    // cannot change but can delete
    delete cpi;
    
    string *ps1 = new string;   //empty str
    int *pi1 = new int;         //uninit
    string *ps2 = new string(); //empty str
    int *pi2 = new int();       //0
    
    // delete: to avoid memory leak
    delete pi1;
    delete ps1;
    
    return 0;
}