/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   July 22, 2021
    Purpose:Gaddis Chapter 13 Prob 4: Patient Charges
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
#include <cstring>
using namespace std;   //Library Name-space

//User Libraries
#include "info.h"
#include "proced.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execute code
int main() {
    cout << "This Program inputs a patient's name and the procedures they will experience." << endl;
    
    //Initialize class
    int size;
    procedures *pro;
    
    //Input Patient info
    Info patient;
    
    //Input Procedure info
    Proced list;

    //Output Data
    patient.display();
    list.display();
   
    //End code
    return 0;
}