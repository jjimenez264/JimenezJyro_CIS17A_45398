/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   July 26, 2021
    Purpose:Gaddis Chapter 16 Prob 1: Dates Exception
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
using namespace std;   //Library Name-space

//User Libraries
#include "date.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execute code
int main() {
    //Initialize class
    Date fields;
    //Output Class functions
    fields.numDate();
    fields.monthDate();
    fields.dayDate();
    return 0;
}