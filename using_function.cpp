//
//  using_function.cpp
//  HackingCPP
//
//  Created by lichgo on 11/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "using_function.h"

#include <vector>
#include <cstdlib>

using namespace std;

size_t count_calls()
{
    static size_t c = 0;
    return c++;
}

int main_usingfunction(int argc, char *argv[])    // int argc, char **argv
{
    for (int i = 0; i  != 10; i++)
    {
        cout << count_calls() << endl;
    }
    
    string s1 = "longer";
    string s2 = "hello";
    cout << longerString(s1, s2) << endl;
    
    int x = 1;
    int y = 2;
    // pointer
    swap(&x, &y);
    cout << x << y << endl;
    // reference
    swap(x, y);
    cout << x << y << endl;
    
    // pass an iterator
    void tranverse(vector<int>::iterator begin, vector<int>::iterator end);
    
    // array
    void printValues(int *);
    void printValues(int[]);
    void printValues(int[10]);
    void printValues(const int*);
    // reference to array
    void printValues(int (&arr)[10]);   // can only pass an array of 10 elements
    // multiple dimension
    int matrix[3][4];
    int print(int (*matrix)[10]);
    int print_(int matrix[][10]); // same as above
    
    // function pointer
    typedef bool (*pf_type)(const string &, const string &);
    bool fun(const string &, const string &);
    pf_type pf1 = 0;
//    pf_type pf2 = fun;
//    pf1 = fun;
//    cout << (pf1 == pf2) << endl;
//    fun(s1, s2);
    
    
    return x ? EXIT_FAILURE : EXIT_SUCCESS;
}

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() > s2.size() ? s2 : s1; //s1 is originally a reference, no need & symbol
}

void swap(int *px, int *py)
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

void swap(int &rx, int &ry)
{
    int tmp = rx;
    rx = ry;
    ry = tmp;
}

void swapPointer(int *&prx, int *&pry)
{
    int *tmp = prx;
    prx = pry;
    pry = tmp;
}