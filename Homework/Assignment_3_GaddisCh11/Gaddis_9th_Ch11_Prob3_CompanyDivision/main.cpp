/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 7 2021
 * Purpose:  Gaddis Chapter 11 Problem 3 - Company Division
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Structure for each division
struct divsn {
    float first, second, third, fourth, total, avg;
};

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    divsn north;
    divsn west;
    divsn east;
    divsn south;
    
    //Display Outputs and initialize
    cout << setprecision(2) << fixed;
    // North Division
    cout << "North" << endl
         << "Enter first-quarter sales:" << endl
         << "Enter second-quarter sales:" << endl
         << "Enter third-quarter sales:" << endl
         << "Enter fourth-quarter sales:" << endl;
    // Input sales for this divison
    cin >> north.first >> north.second >> north.third >> north.fourth;
    // Add Sales from this division and output
    north.total = north.first + north.second + north.third + north.fourth;
    cout << "Total Annual sales:$" << north.total << endl;
    // Find Average quarterly sale
    north.avg = north.total / 4;
    cout << "Average Quarterly Sales:$" << north.avg << endl;
    
    // West Division
    cout << "West" << endl
         << "Enter first-quarter sales:" << endl
         << "Enter second-quarter sales:" << endl
         << "Enter third-quarter sales:" << endl
         << "Enter fourth-quarter sales:" << endl;
    // Input sales for this divison
    cin >> west.first >> west.second >> west.third >> west.fourth;
    // Add Sales from this division and output
    west.total = west.first + west.second + west.third + west.fourth;
    cout << "Total Annual sales:$" << west.total << endl;
    // Find Average quarterly sale
    west.avg = west.total / 4;
    cout << "Average Quarterly Sales:$" << west.avg << endl;
    
    // East Division
    cout << "East" << endl
         << "Enter first-quarter sales:" << endl
         << "Enter second-quarter sales:" << endl
         << "Enter third-quarter sales:" << endl
         << "Enter fourth-quarter sales:" << endl;
    // Input sales for this divison
    cin >> east.first >> east.second >> east.third >> east.fourth;
    // Add Sales from this division and output
    east.total = east.first + east.second + east.third + east.fourth;
    cout << "Total Annual sales:$" << east.total << endl;
    // Find Average quarterly sale
    east.avg = east.total / 4;
    cout << "Average Quarterly Sales:$" << east.avg << endl;
    
    // South Division
    cout << "South" << endl
         << "Enter first-quarter sales:" << endl
         << "Enter second-quarter sales:" << endl
         << "Enter third-quarter sales:" << endl
         << "Enter fourth-quarter sales:" << endl;
    // Input sales for this divison
    cin >> south.first >> south.second >> south.third >> south.fourth;
    // Add Sales from this division and output
    south.total = south.first + south.second + south.third + south.fourth;
    cout << "Total Annual sales:$" << south.total << endl;
    // Find Average quarterly sale
    south.avg = south.total / 4;
    cout << "Average Quarterly Sales:$" << south.avg;

    //Exit stage right!
    return 0;
}