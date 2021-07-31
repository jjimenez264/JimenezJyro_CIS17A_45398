/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   date.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 1:22 AM
 */

#include <iostream>
using namespace std;

#include "date.h"

Date::Date() {
    cout << "This Program Outputs the different forms of writing a date of a year." << endl
         << "Please Input the specific fields..." << endl;
    cout << "Input day  (1-31) : ";
    cin >> day;
    //INVALID
    if(day > 31 || day <= 0) {
        cout << "Day is invalid! Input Again: ";
        cin >> day;
    }
    cout << "Input month (1-12): ";
    cin >> month;
    //INVALID
    if(month > 12 || month <= 0) {
        cout << "Month is invalid! Input Again: ";
        cin >> month;
    }
    cout << "Input year (>= 0) : ";
    cin >> year;
    //INVALID
    if(year < 0) {
        cout << "Year is invalid! Input Again: ";
        cin >> year;
    }
}

void Date::numDate() {
    cout << month << "/" << day << "/" << year << endl;
}

void Date::monthDate() {
    switch(month) {
        case 1:
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case 8:
            cout << "August ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << "October ";
            break;
        case 11:
            cout << "November ";
            break;
        default:
            cout << "December ";
    }
    cout << day << ", " << year << endl;
}

void Date::dayDate() {
    cout << day << " ";
    switch(month) {
        case 1:
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case 8:
            cout << "August ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << "October ";
            break;
        case 11:
            cout << "November ";
            break;
        default:
            cout << "December ";
    }
    cout << year << endl;
}