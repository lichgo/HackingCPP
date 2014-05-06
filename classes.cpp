//
//  classes.cpp
//  HackingCPP
//
//  Created by lichgo on 6/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include "classes.h"

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