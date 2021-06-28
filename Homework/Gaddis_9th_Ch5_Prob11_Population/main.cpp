/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   June 22, 2021 4:20pm
    Purpose:Gadis Chapter 5 problem 11: Population
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
    float perc, total;
    int start, days;
    total = 0;
    
    //Initialize variables
    cout << "This program predicts the size of a population of organisms." << endl
         << "Enter the starting population (not < 2)      : ";
    cin >> start;
    
    if(start < 2) {
        cout << "The starting population is less than 2 choose again..." << endl;
        cin >> start;
    }
    
    cout << "Enter the increase in population (terms of %): ";
    cin >> perc;
    
    if(perc <= 0) {
        cout << "The increase percentage is less than zero, try again..." << endl;
        cin >> perc;
    }
    
    perc = perc * .01;
    
    cout << "Enter the number of days (days > 1)          : ";
    cin >> days;
    
    if(days < 1) {
        cout << "Days entered are less than one, try again..." << endl;
        cin >> days;
    }
    
    //Process, map inputs to outputs
    total = start;
    for(int i = 0; i < days; i++) {
        total = start * perc + total;
        cout << "The population at day " << i + 1 << " is " << total << endl;
    }
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}