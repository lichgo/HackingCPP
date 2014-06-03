//
//  classes.cpp
//  HackingCPP
//
//  Created by lichgo on 6/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "classes.h"
#include <string>

using namespace std;

class Sales
{
public:
    std::string title;
private:
    std::string isbn;
    unsigned units_sold;
    double revenue;
};

struct Sales_
{
    std::string title;
    // public by default
private:
    std::string isbn;
    unsigned units_sold;
    double revenue;
};

class MyClass {
public:
    MyClass(MyClass const &mc) {
        // do something
    }
    // constructor cannot be declared
//    MyClass(const MyClass& mc) {
//        
//    }
};

class Factory {
public:
    Factory() {
        cout << "Factory..." << endl;
    }
    
    int getId() {
        return 42123;
    }
};

static const Factory f();

class Pen {
public:
    Pen() {
        cout << "Creating pen instance......" << endl;
//        factory;
//        cout << "name length(): " << name.length() << endl;
//        name = "new name";
//        cout << "new length(): " << name.length() << endl;
    }
    void print() {
        //cout << factory.getId() << endl;
        cout << "----------------" << endl;
        cout << name << endl;
        cout << id << endl;
        cout << price << endl;
    }
private:
    Factory factory;
    string name;
    int id;
    float price;
};

int main_classes() {
//    string name;
//    int id;
//    float price;
//    
//    cout << name << "|" << id << "|" << price << endl;
    
    // using implicit (default) constructor
    Pen p3;
    Pen p4 = Pen();
    Pen* p1 = new Pen();
    cout << "three ways..." << endl;
    p1->print();
    
    if (true) {
        Pen *p2 = new Pen();
        p2->print();
    }
    
    Pen pens[10];
    
    return 0;
}