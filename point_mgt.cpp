//
//  point_mgt.cpp
//  HackingCPP
//
//  Created by lichgo on 24/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

/*
 Sharing the same pointer among multiple classes
 */

#include "point_mgt.h"

#include <iostream>

using namespace std;

class UPtr {
    friend class HasPtr;
    int* ip;
    size_t use_count;     // count how many pointers referring to itself
    UPtr(int* p): ip(p), use_count(1) {}
    ~UPtr() { delete ip; }
};

class HasPtr {
public:
    // Set a new UPtr for couting use in copy constructor and operationr=
    HasPtr(int* p, int i): ptr(new UPtr(p)), val(i) {}
    
    HasPtr(const HasPtr& orig): ptr(orig.ptr), val(orig.val) {
        cout << "init " << this->val << endl;
        // point to one more HasPtr instance
        ++(ptr->use_count);
    }
    
    HasPtr& operator=(const HasPtr& another) {
        cout << "== " << this->val << endl;
        
        // reduce self, add another
        ++(another.ptr->use_count);
        
        if (--(ptr->use_count) == 0) delete ptr;
        
        ptr = another.ptr;
        val = another.val;
        
        return *this;
    }
    
    ~HasPtr() {
        if (--(ptr->use_count) == 0)
            delete ptr;
    }
    
    int getVal() {
        return this->val;
    }
    
private:
    UPtr* ptr;
    int val;
};

void main_ptrmgt() {
    int* p = new int(4);
    int* q = new int(4);
    
    HasPtr p1(p, 1);
    //HasPtr p2(p, 2);    // p has been released
    HasPtr p2(q, 2);
    HasPtr p3 = p1; // using copy constructor
    p3 = p2;        // using = operator (not initialization, without declaration)
    // p3 is not changed if nothing written in =
    cout << p3.getVal() << endl;    //still 1
}