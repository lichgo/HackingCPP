//
//  main.cpp
//  HackingCPP
//
//  Created by lichgo on 5/5/14.
//  Copyright (c) 2014 lichgo. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{

    // iostream
    std::cout << "Hello, World!\n";
    
    std::cout << "Enter two numbers:" << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << "." << std::endl;
    
    int sum = 0, value;
    while (std::cin >> value)   // Unix: Control+d; Windows: ctrl+z to stop the loop
        sum += value;
    std::cout << "Sum is " << sum << std::endl;
    
    // directly initialisation
    int v3(1024);
    v3 = 24;
    
    // init a sting
    std::string s1("abc");
    std::string s2 = "ABC";
    std::string s3(10, '9');    //9999999999
    
    // declare and define
    extern int i;   // declare but not define
    int j;  // declare and define
    j = 23;
    //int i = 3;  // error
    i = 23;
    // extern int pi = 3;  // declare and define, legal but should be outside a function
    
    return 0;
}

