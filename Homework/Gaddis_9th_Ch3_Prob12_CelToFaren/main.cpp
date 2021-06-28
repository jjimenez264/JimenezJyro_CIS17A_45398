/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   June 21, 2021 5:20pm
    Purpose:Gadis Chapter 3 problem 12: Celsius to Fahrenheit
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float cel, fahren;
    
    //Initialize variables
    cout << "This is a program that converts Celsius to Fahrenheit." << endl
         << "Enter the Celsius to convert: ";
    cin >> cel;
    
    //Process, map inputs to outputs
    fahren = (cel * 9)/5 + 32;
    
    //Display your initial conditions as well as outputs.
    cout << "The converted Celsius, is " << fahren << " degrees Fahrenheit." << endl;
    
    //Exit stage right
    return 0;
}