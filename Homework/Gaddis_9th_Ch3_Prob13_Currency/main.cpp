/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   June 21, 2021 5:30pm
    Purpose:Gadis Chapter 3 problem 13: Currency
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
    float yen, euro, dollar;
    
    //Initialize variables
    cout << "This program converts dollars to Yen and Euros." << endl
         << "Enter the Dollar value to convert: ";
    cin >> dollar;
    
    //Process, map inputs to outputs
    yen = dollar * 98.93;
    euro = dollar * 0.74;
    
    //Display your initial conditions as well as outputs.
    cout << setprecision(2) << fixed;
    cout << "The converted Dollar value amounts to: " << endl 
         << dollar << " Dollars is " << yen << " Yen." << endl
         << dollar << " Dollars is " << euro << " Euros." << endl;
    
    //Exit stage right
    return 0;
}