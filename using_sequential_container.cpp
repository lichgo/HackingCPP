//
//  using_sequential_container.cpp
//  HackingCPP
//
//  Created by lichgo on 13/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_sequential_container.h"
#include "classes.h"

#include <vector>
#include <list>
#include <deque>

namespace std {

int main_seqctr()
{
    vector<string> svec;
    list<int> ilist;
    deque<SalesItem> sdeque;
    
    // Init by copying another container
    vector<string> svec2(svec);
    
    // Init from an array
    char *words[] = { "one", "two", "three", "four" };
    size_t words_size = sizeof(words) / sizeof(char *);
    list<string> lword(words, words + words_size);
    
    // Init with length
    const list<int>::size_type list_size = 64;
    list<string> leh(list_size, "eh?");
    
    // Init with iterator
    list<string> leh2(leh.begin(), leh.end());
    
    
    // Container in container
    vector< vector<int> > vv;
    
    // iterator
    vector< vector<int> >::iterator iter = vv.begin() + vv.size() / 2;
    vv.begin() + vv.size() / 2;
    
    //list<string>::difference_type diff = leh.begin() - leh.end();
    
    // push_back and push_front
    svec.push_back("hihi");
    //svec.push_front("yes"); there is no push_front for vector
    leh.push_front("front");
    
    // insert
    string geek("eric");
    leh.insert(leh.begin(), geek);
    leh.insert(leh.end(), 10, "end");
    string w[] = { "one", "two" };
    leh.insert(leh.end(), w, w + 2);
    
    vector<string>::iterator first = svec.begin(), last = svec.end();
    while (first != svec.end())
    {
        first = svec.insert(first, "inserted");
        first++;
    }
    
    // front(), back(), and [] return references
    list<string>::reference front1 = leh.front();
    list<string>::reference front2 = *leh.begin();
    
    list<string>::reference back1 = leh.back();
    list<string>::reference back2 = *(--leh.end());
    
    // leh[3] = "changed"; onlu vector and deque have subscript
    svec[3] = "change";
    svec.at(3) = "changed again";
    
    // erase
    svec.clear();
    svec.erase(svec.begin(), svec.end());
    
    // =
    vector<string> sv(10);
    sv = svec;
    
    // assign
    sv.assign(svec.begin(), svec.end());
    sv.assign(10, "hi");    // reset to a vector with 10 "hi"
    
    // swap
    swap(sv, svec);
    
    
    return 0;
    
}

}