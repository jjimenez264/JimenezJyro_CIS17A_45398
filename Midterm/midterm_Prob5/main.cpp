/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 15 2021
 * Purpose:Midterm Problem 5: Factorials
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
    cout << "Problem 5: Outputing largest n for n! in each data type." << endl;
    cout << "Data Type" << setw(13) << "Largest n" << setw(10) << "Output" << endl;
    cout << "short" << setw(11) << "17!" << setw(16) << "-32768" << endl;
    cout << "Uns-short" << setw(7) << "17!" << setw(15) << "32768" << endl;
    cout << "int" << setw(13) << "33!" << setw(21) << "-2147483648" << endl;
    cout << "Uns-int" << setw(9) << "33!" << setw(20) << "2147483648" << endl;
    cout << "long" << setw(12) << "65!" << setw(30) << "-9223372036854775808" << endl;
    cout << "Uns-long" << setw(8) << "65!" << setw(29) << "-9223372036854775808" << endl;
    
    //Results from program
    //short 32767: 17! = -32768
    //unsigned short 65535: 17! = 32768
    //int 2147483647: 33! = -2147483648
    //unsigned int (4,294,967,295): 33! = 2147483648
    //long 2147483647: 65! = -9223372036854775808
    //unsigned long 4294967295: 65! = 9223372036854775808
    
    //Exit stage right!
    return 0;
}