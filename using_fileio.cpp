//
//  using_fileio.cpp
//  HackingCPP
//
//  Created by lichgo on 11/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_fileio.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main_usingfileio()
{
    string in_file_dir = "README.md";
    string out_file_dir = "cpy_README.md";
    
    ifstream infile(in_file_dir.c_str());
    ofstream outfile(out_file_dir.c_str());
    
//    ifstream infile;
//    ofstream outfile;
//    infile.open(in_file_dir.c_str());
//    outfile.open(out_file_dir.c_str());
    
    vector<string> files(3, "README.md");
    ifstream in_file;
    string s;
    vector<string>::const_iterator beg = files.begin();
    while (beg != files.end())
    {
        in_file.open(beg->c_str());
        
        if (!in_file)
            break;
        
        while (in_file >> s)
        {
            cout << s << endl;
        }
        in_file.close();
        in_file.clear();    //without this, stream cannot be reset
        
        beg++;
    }
    
    return 0;
}

ifstream &open_file(ifstream &in, const string &file)
{
    in.close();
    in.clear();
    in.open(file.c_str());
    return in;
}