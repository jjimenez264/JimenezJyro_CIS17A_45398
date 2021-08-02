/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on August 1 2021
 * Purpose:Final Problem 6: Conversions
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    cout << "Problem 6: Conversions" << endl;
    //Output results for question 1
    cout << "1.) a.) 5.75 Base 10 --> 5.C         Base 16 --> 0101.1100              Base 2 --> 5.6                Base 8" << endl
         << "    b.) 0.9  Base 10 --> 0.E...6...  Base 16 --> 0.1110...0110...       Base 2 --> 0.7...1463...      Base 8" << endl
         << "    c.) 99.7 Base 10 --> 63.B...3... Base 16 --> 1100011.1011...0011... Base 2 --> 143.5463...1463... Base 8" << endl << endl;
    //Output results for question 2
    cout << "2.) a.) 0.1011100 x 2^3               = 0101 1100 | 0000 0000 | 0000 0000 | 0000 0011 = 5C000003" << endl
         << "    b.) 0.1110...0110... x 2^0        = 0111 0011 | 0011 0011 | 0011 0011 | 0000 0000 = 73333300" << endl
         << "    c.) 0.11000111011...0011... x 2^7 = 0110 0011 | 1011 0011 | 0011 0011 | 0000 0111 = 63B33307" << endl << endl;
    //Output results for question 3
    cout << "3.) a.) 5.C Base 16         --> 5C x 16^-1    = 8WD 4BP" << endl
         << "    b.) 0.E...6... Base 16  --> E666 x 16^4   = 16WD 16BP" << endl
         << "    c.) 63.B...3... Base 16 --> 63B333 x 16^4 = 24WD 16BP" << endl << endl;
    //Output results for question 4
    cout << "4.) a.) 8WD 4BP   * 4WD 0BP = 12WD 4BP" << endl
         << "    b.) 16WD 16BP * 4WD 0BP = 20WD 16BP" << endl
         << "    c.) 24WD 16BP * 4WD 0BP = 28WD 16BP" << endl << endl;
    //Output results for question 5
    cout << "5.) a.) 1.011100 x 2^2               = 0(100 0000 | 1)011 1000 | 0000 0000 | 0000 0000 = 40B80000" << endl
         << "    b.) 1.110...0110... x 2^-1       = 0(011 1111 | 0)110 0110 | 0110 0110 | 0110 0110 = 3F666666" << endl
         << "    c.) 1.1000111011...0011... x 2^6 = 0(100 0010 | 0)110 0111 | 0110 0110 | 0110 0110 = 42C76666" << endl << endl;
    
    
    //Exit stage right!
    return 0;
}