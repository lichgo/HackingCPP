//
//  using_fileio.cpp
//  HackingCPP
//
//  Created by lichgo on 11/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_fileio.h"

#include <iostream>

using namespace std;

int main()
{
    string in_file_dir = "README.md";
    string out_file_dir = "cpy_README.md";
    
//    ifstream infile(in_file_dir.c_str());
//    ofstream outfile(out_file_dir.c_str());
    
    ifstream infile;
    ofstream outfile;
    
    infile.open(in_file_dir.c_str());
    outfile.open(out_file_dir.c_str());
}