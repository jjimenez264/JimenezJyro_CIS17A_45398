/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 9 2021
 * Purpose:Structure Weather Statistics
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Structure
struct weather {
    string month;
    int rain, high, low; 
};

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int size = 12;
    weather months[size];
    float avg, avgTemp;
    int min, max, minAdd = 0, maxAdd = 0;
    
    //Initialize variables
    for(int i = 0; i < size; i++) {
        cin >> months[i].month >> months[i].rain >> months[i].low >> months[i].high;
    }
    
    //Process inputs
    // Find average rain fall
    avg = 0;
    for(int i = 0; i < size; i++) {
        avg += months[i].rain;
    }
    avg = avg / 12;
    //Find Lowest and highest temp
    min = months[0].low;
    max = months[0].high;
    for(int i = 1; i < size; i++) {
        // Lowest temp
        if(months[i].low <= min) {
            min = months[i].low;
            minAdd = i;
        }
        // Highest Temp
        if(months[i].high >= max) {
            max = months[i].high;
            maxAdd = i;
        }
    }
    //Find Average Tmep for the year
    avgTemp = 0;
    for(int i = 0; i < size; i++) {
        avgTemp += (months[i].low + months[i].high);
    }
    avgTemp = avgTemp / (size*2);
    
    //Cout Results
    cout << setprecision(1) << fixed;
    cout << "Average Rainfall " << avg << " inches/month" << endl;
    cout << setprecision(0) << fixed;
    cout << "Lowest  Temperature " << months[minAdd].month << "  " << min << " Degrees Fahrenheit" << endl
         << "Highest Temperature " << months[maxAdd].month << "  " << max << " Degrees Fahrenheit" << endl
         << "Average Temperature for the year " << avgTemp << " Degrees Fahrenheit" << endl;
         
    // end code
    return 0;
}