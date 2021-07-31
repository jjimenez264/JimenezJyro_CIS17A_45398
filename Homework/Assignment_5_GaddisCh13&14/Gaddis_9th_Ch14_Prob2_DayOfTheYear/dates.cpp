/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dates.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 7:10 PM
 */

#include <iostream>
using namespace std;

#include "dates.h"

DayOfYear::DayOfYear() {
    cout << "This Program Converts the day of a year to its corresponding date." << endl;
    cout << "Enter a day (1 - 365): ";
    cin >> input;
    //Initialize month as 12 for loop and day as input
    month = 12;
    day = input;
    //calculate what day and month
    convert();
}

int DayOfYear::convert() {
    for(int i = 0; i < month; i++) {
        //Subtract to get exact day in month
        if((i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) && day > 31) {
            day -= 31;
        }
        else if((i == 3 || i == 5 || i == 8 || i == 10) && day > 30) {
            day -= 30;
        }
        else if(i == 1 && day > 28){
            day -= 28;
        }
        else {
            month = i;
        }
    }
}

void DayOfYear::display() {
    cout << "The converted day is calculated..." << endl;
    cout << "Day " << input << " would be ";
    switch(month) {
        case 0:
            cout << "January ";
            break;
        case 1:
            cout << "February ";
            break;
        case 2:
            cout << "March ";
            break;
        case 3:
            cout << "April ";
            break;
        case 4:
            cout << "May ";
            break;
        case 5:
            cout << "June ";
            break;
        case 6:
            cout << "July ";
            break;
        case 7:
            cout << "August ";
            break;
        case 8:
            cout << "September ";
            break;
        case 9:
            cout << "October ";
            break;
        case 10:
            cout << "November ";
            break;
        case 11:
            cout << "December ";
            break;
    }
    cout << day << ".";
}