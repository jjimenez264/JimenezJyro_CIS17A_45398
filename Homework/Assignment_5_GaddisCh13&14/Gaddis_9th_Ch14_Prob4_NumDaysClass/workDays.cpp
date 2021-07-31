/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   workDays.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 9:20 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "workDays.h"

numDays::numDays() {
    cout << "This Program counts how much Days work hours amount to." << endl;
    cout << "Would you like to input Hours for today? (y/n): ";
    cin >> choice;
    //Initialize days and hours
    day = hour = 0;
    //Loop hour input
    while(choice == 'y') {
        cout << "How Many Hours did you do?" << endl;
        cout << "Input Hours: ";
        cin >> hour;
        countDays();
        //Ask if there are more days
        cout << endl << "Would you like to input another day? (y/n): ";
        cin >> choice;
        cout << endl;
    }
}

float numDays::countDays() {
    //Calculate amount of days
    day += hour / 8;
    cout << "You have " << setprecision(2) << fixed << day << " day(s) right now..." << endl;
}

void numDays::display() {
    cout << "The total amount of days accumulated is " << setprecision(2) << fixed << day << " day(s).";
}

