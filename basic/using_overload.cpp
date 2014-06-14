//
//  using_overload.cpp
//  HackingCPP
//
//  Created by lichgo on 18/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_overload.h"

#include <string>
#include <iostream>

using namespace std;

void print(const string& s) {
    cout << "Const" << endl;
}
void print(string& s) {
    cout << "NOT Const" << endl;
}

void main_override() {
    const string t = "const";
    string s = "hall";
    
    // const reference can point to a literal
    const string& ref = "yes";
    
    // Override by adding const
    print(s);       // NOT Const
    print(t);       // Const
    print("dd");    // Const
}