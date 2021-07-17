/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 16 2021
 * Purpose:Midterm Problem 6: NASA Conversions
 */

//System Libraries
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    
    //Output results
    cout << "Problem 6: Outputs results for NASA Float conversion problems" << endl << endl;
    cout << "Convert to binary, octal, hex, then to NASA float:" << endl;
    cout << "A.) 1. 51.1875 base 10    = .1100110011 base 2 x 2^6  = 1100 1100 | 1100 0000 | 0000 0000 | 0000 0110 = CCC00006" << endl;
    cout << "       51.1875 base 10    = (HEX) 33.3 base 16   = (OCTAL) 63.14 base 8     = (BINARY) 110011.0011 base 2" << endl;
    cout << "    2. 3.19921875 base 10 = .1100110011 base 2 x 2^2  = 1100 1100 | 1100 0000 | 0000 0000 | 0000 0010 = CCC00002" << endl;
    cout << "       3.19921875 base 10 = (HEX) 3.33 base 16   = (OCTAL) 3.146 base 8     = (BINARY) 11.00110011 base 2" << endl;
    cout << "    3. 0.2 base 10        = .11..0011.. base 2 x 2^-1 = 1100 1100 | 1100 1100 | 1100 1100 | 1111 1110 = CCCCCCFE" << endl;
    cout << "       0.2 base 10        = (HEX) 0.3... base 16 = (OCTAL) 0.1463... base 8 = (BINARY) 0.0011... base 2" << endl << endl;
    cout << "Convert the same numbers to NASA float but they are negative:" << endl;
    cout << "B.) 1. -51.1875 base 10    = -.1100110011 base 2 x 2^6  = 0011 0011 | 0100 0000 | 0000 0000 | 0000 0110 = 33400006" << endl;
    cout << "    2. -3.19921875 base 10 = -.1100110011 base 2 x 2^2  = 0011 0011 | 0100 0000 | 0000 0000 | 0000 0010 = 33400002" << endl;
    cout << "    3. -0.2 base 10        = -.11..0011.. base 2 x 2^-1 = 0011 0011 | 0011 0011 | 0011 0100 | 1111 1110 = 333334FE" << endl << endl;
    cout << "Convert NASA Float to decimal numbers: " << endl;
    cout << "C.) 1. 69999902 = 1.10...1001... base 2 OR .0110...1001... base 2 x 2^2" << endl;
    cout << "    2. 69999902 = 11.0...1001... base 2 OR .0110...1001... base 2 x 2^3" << endl;
    cout << "    3. 966667FF = .0100101100110011001100111 base 2 OR .100101100110011001100111 base 2 x 2^-1";
    
    //Exit stage right!
    return 0;
}