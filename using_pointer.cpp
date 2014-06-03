//
//  using_pointer.cpp
//  HackingCPP
//
//  Created by lichgo on 7/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_pointer.h"

using std::cout;
using std::endl;
using std::string;

int main_pointer()
{
    int val = 23;
    
    // point to a value
    int *p1 = 0;
    int *pi = NULL; // same as above
    // int *p1 = 23; illegal
    
    // point to a var (its address)
    int *p2 = &val;
    
    // point to a const 0
    const int c = 0;
    ///int *p3 = c;
    
    cout << *p2;
    // cout << *p1; NULL POINTER, error
    
    // void*
    double d = 12;
    std::string s = "abc";
    void *p = &s;
    p = &d;
    // cout << *p << endl;  error
    p = &s;
    
    // pointer to pointer
    int **pp = &p1;
    
    
    // operations on pointer
    ptrdiff_t n = p2 - p1;
    
    // point to a const var
    const double dd = 21;
    int ii = 12;
    const double *dpt = &dd;
    const void *vpt = &dd;
    const int *ipt = &ii; // const pointer to a non-const var
    // const pointer
    int *const er = &ii;
    // const pointer to a const
    const double *const ddd = &dd;
    
    // using typedef
    string name = "jason";
    typedef string *ptr_to_string_type;
    const ptr_to_string_type const_ptr_to_string_type = &name;  // const pointer, same as: string *const ptr
    ptr_to_string_type const another = &name;                   // position of const is not a matter, both means const ptr
    
    
    
    // string in c: const pointer and with null ended
    const char *cp = "some value";
    while (*cp) {
        cout << *cp;
        cp++;
    }
    
    // new and delete: create arrays dynamically
    int *pii = new int[10];      //uninitialized
    int *pti = new int[10]();    //initialized to 0
    const string *pstr = new const string[10];  // empty string
    
    delete []pii;   //delete pii is error
    
    
    // multiple-dimensional array
    int ma[2][3] = {1,2,3,4,5,6};
    int mc[2][3] = {1,2};           // all others are 0
    int mb[2][3] = { {1}, {4} };    // others are 0
    
    //pointer
    int ia[3][4];
    int (*pia)[4] = ia; // point to an array with 4 elements
    pia = &ia[0];
    
    typedef int int_array[4];
    int_array *ptr_ia_4 = ia;
    
    
    
    return 0;
}