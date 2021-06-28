/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   June 22, 2021 8:00pm
    Purpose:Gadis Chapter 7 problem 6: Rain or Shine
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
#include <fstream>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only
const int cols = 30;

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    short rain1, rain2, rain3, rainTot,
          cloudy1, cloudy2, cloudy3, cloudyTot,
          sunny1, sunny2, sunny3, sunnyTot;
    
    //char arrays
    const int rows = 3;
    char input[rows][cols];
    const int size = 90;
    char line[90];
    
    //IO files
    fstream inFile;
    
    //Initialize variables
    cout << "This is a program that organizes weather data during the months of summer." << endl;
    
    //Process, map inputs to outputs
    //See if file is opened or not
    inFile.open("RainOrShine.txt");
    if (!inFile) {
        cout << "File open failure!" << endl;
    }
    
    //Read data
    for(int i = 0; i < size; i++) {
        inFile >> line[i];
    }   
    
    //Transfer input data to program data
    int i = 0;
    for(int j = 0; j < rows; j++) {
        for(int k = 0; k < cols; k++) {
            input[j][k] = line[i];
            i += 1;
        }
    }
    
    //weather for first month
    rain1 = 0;
    cloudy1 = 0;
    sunny1 = 0;
    for(int i = 0; i < cols; i++) {
        if(input[0][i] == 'R') {
            rain1 += 1;
        }
        if(input[0][i] == 'C') {
            cloudy1 += 1;
        }
        if(input[0][i] == 'S') {
            sunny1 += 1;
        }
    }
    
    //weather second month
    rain2 = 0;
    cloudy2 = 0;
    sunny2 = 0;
    for(int i = 0; i < cols; i++) {
        if(input[1][i] == 'R') {
            rain2 += 1;
        }
        if(input[1][i] == 'C') {
            cloudy2 += 1;
        }
        if(input[1][i] == 'S') {
            sunny2 += 1;
        }
    }
    
    //weather third month
    rain3 = 0;
    cloudy3 = 0;
    sunny3 = 0;
    for(int i = 0; i < cols; i++) {
        if(input[2][i] == 'R') {
            rain3 += 1;
        }
        if(input[2][i] == 'C') {
            cloudy3 += 1;
        }
        if(input[2][i] == 'S') {
            sunny3 += 1;
        }
    }
    
    
    //Display your initial conditions as well as outputs.
    cout << "Month of June:" << endl
         << "Rainy  = " << rain1 << endl
         << "Cloudy = " << cloudy1 << endl
         << "Sunny  = " << sunny1 << endl << endl;
    
    cout << "Month of July:" << endl
         << "Rainy  = " << rain2 << endl
         << "Cloudy = " << cloudy2 << endl
         << "Sunny  = " << sunny2 << endl << endl;
    
    cout << "Month of August:" << endl
         << "Rainy  = " << rain3 << endl
         << "Cloudy = " << cloudy3 << endl
         << "Sunny  = " << sunny3 << endl << endl;
    
    //Rainy month
    if(rain1 > rain2 || rain1 > rain3) {
        cout << "With this information, the month of June had the most rain this season.";
    }
    else if(rain2 > rain1 || rain2 > rain3) {
        cout << "With this information, the month of July had the most rain this season.";
    }
    else {
        cout << "With this information, the month of August had the most rain this season.";
    }
    
    //Exit stage right
    return 0;
}