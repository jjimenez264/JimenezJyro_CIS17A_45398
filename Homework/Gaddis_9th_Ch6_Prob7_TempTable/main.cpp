/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   June 22, 2021 6:00pm
    Purpose:Gadis Chapter 6 problem 7: Celsius Temperature Table
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
float convert(float, float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float cel, fahren;
    
    //Initialize variables
    cout << "This is a program that converts Fahrenheit to Celsius." << endl;
    
    //Process, map inputs to outputs
    cout << "Fahrenheit | Celsius" << endl;
    for(int i = 0; i < 21; i++) {
        fahren = i;
        cel = convert(cel, fahren);
        cout << setprecision(2) << fixed;
        cout << setw(10) << fahren << " | " << cel << endl;
    }
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

float convert(float cel, float fahren) {
    cel = 5 * (fahren - 32) / 9;
    return cel;
}