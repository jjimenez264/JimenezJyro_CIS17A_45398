/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 7 2021
 * Purpose:  Gaddis Chapter 11 Problem 5 - Weather Statistic
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Structure
struct weather {
    float rain, high, low;
};

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int size = 6;
    weather months[size];
    float max, min, avgTemp, avgRain;
    int count = 0;
    
    //Display Outputs
    while(cin >> months[count].rain >> months[count].high >> months[count].low) {
        cout << "Enter the total rainfall for the month:" << endl
             << "Enter the high temp:" << endl
             << "Enter the low temp:" << endl;
        count += 1;
    }
    
    //find average monthly rainfall
    avgRain = 0;
    for(int i = 0; i < count; i++) {
        avgRain += months[i].rain;
    }
    avgRain = avgRain / count;
    
    //find highest temperature
    max = months[0].high;
    for(int i = 1; i < count; i++) {
        if(months[i].high > months[i - 1].high) {
            max = months[i].high;
        }
    }
    
    //find lowest temperature
    min = months[0].low;
    for(int i = 1; i < count; i++) {
        if(months[i].low < months[i - 1].low) {
            min = months[i].low;
        }
    }
    
    //find average temperature
    avgTemp = 0;
    for(int i = 0; i < count; i++) {
        avgTemp += (months[i].high + months[i].low);
    }
    avgTemp = avgTemp / (count*2);
    
    //Output results
    cout << setprecision(2) << fixed;
    cout << "Average monthly rainfall:" << avgRain << endl;
    cout << setprecision(0) << fixed;
    cout << "High Temp:" << max << endl;
    cout << "Low Temp:" << min << endl;
    cout << setprecision(1) << fixed;
    cout << "Average Temp:" << avgTemp;

    //Exit stage right!
    return 0;
}