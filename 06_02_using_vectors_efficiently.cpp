//
//  06_02_using_vectors_efficiently.cpp
//  HackingCPP
//
//  Created by lichgo on 14/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "06_02_using_vectors_efficiently.h"

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

void f(vector<string>& vec) {
    
}

int main() {
    vector<string> vec(500);
    vector<string> vec2;
    
    f(vec);
    
    vec2.reserve(500);
    
    return 0;
}