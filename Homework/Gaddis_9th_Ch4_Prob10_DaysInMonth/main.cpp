/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   June 21, 2021 6:00pm
    Purpose:Gadis Chapter 4 problem 10: Days in a Month
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int month, year, leap;
    
    //Initialize variables
    cout << "This program outputs the days in a month." << endl
         << "Enter the month: ";
    cin >> month;
    cout << "Enter the year : ";
    cin >> year;
    
    //Process, map inputs to outputs
    if(month == 2) {
        leap = year % 100;
        if(leap != 0) {
            leap = year % 4;
            if(leap == 0) {
                cout << "29 days";
            }
            else if(leap != 0) {
                cout << "28 days";
            }
        }
        else if(leap == 0) {
            leap = year % 400;
            if(leap == 0) {
                cout << "29 days";
            }
            else if(leap != 0) {
                cout << "28 days";
            }
        }
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        cout << "31 days";
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11) {
        cout << "30 days";
    }
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}