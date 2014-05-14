//
//  06_01_vectors_insteadof_arrays.cpp
//  HackingCPP
//
//  Created by lichgo on 14/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "06_01_vectors_insteadof_arrays.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main_0601() {
    vector<int> intVec;
    vector<string> strVec;
    
    intVec.push_back(3);
    intVec.push_back(6);
    intVec.push_back(9);
    
    strVec.push_back("hihi");
    string name = "jason";
    strVec.push_back(name);
    
    for (vector<string>::size_type i = 0; i < strVec.size(); ++i) {
        cout << strVec[i] << "\t";
    }
    
    for (vector<string>::iterator iter = strVec.begin(); iter != strVec.end(); ++iter) {
        cout << *iter << "\t";
    }
    
    try {
        intVec.at(3000) = 2;
    } catch (out_of_range& e) {
        cerr << "out of range: " << e.what() << endl;
    }
    
    return 0;
}