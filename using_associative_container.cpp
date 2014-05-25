//
//  using_associative_container.cpp
//  HackingCPP
//
//  Created by lichgo on 13/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_associative_container.h"
#include <map>
#include <string>

using namespace std;

int main_asso()
{
    // pair
    pair<string, string> author("jason", "lin");
    
    // typedef
    typedef pair<string, string> Author;
    Author a("eric", "lam");
    
    // make_pair
    pair<string, int> count = make_pair(a.second, 23);
    
    // map
    map<string, int> word_count;
    map<string, int>::iterator iter = word_count.begin();
    cout << iter->first << iter->second << endl;
    word_count["anna"] = 2;
    
    // map insert
    word_count.insert(map<string, int>::value_type("yy", 4));
    typedef map<string, int>::value_type valType;
    word_count.insert(valType("yy", 3));
    word_count.insert(make_pair("ss", 23));
    
    // map count and find
    int occur_count = -1;
    map<string, int>::iterator iter2 = word_count.find("eric");
    if (iter2 != word_count.end()) occur_count = iter2->second;
    
    return 0;
}