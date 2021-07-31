/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   date.cpp
 * Author: jyroj
 * 
 * Created on July 26, 2021
 */

#include <iostream>
using namespace std;

#include "date.h"

Date::Date() {
    cout << "This Program Outputs the different forms of writing a date of a year." << endl
         << "Please Input the specific fields..." << endl;
    //Input What Day with an exception check
    try {
        day = invalidDay();
    }
    catch(int error) {
        cout << "Invalid Day inputed! " << error << " is not an option!" << endl;
        cout << "Input another day from 1-31: ";
        cin >> day;
    }
    //Input what Month with an Exception Check
    try {
        month = invalidMonth();
    }
    catch(int error) {
        cout << "Invalid Month inputed! " << error << " is not an option!" << endl;
        cout << "Input another Month from 1-12: ";
        cin >> month;
    }
    //Input what Year with an Exception Check
    try {
        year = invalidYear();
    }
    catch(int error) {
        cout << "Invalid Year inputed! " << error << " is not an option!" << endl;
        cout << "Input another Year >= 0: ";
        cin >> year;
    }
}

int Date::invalidDay() {
    cout << "Input day  (1-31) : ";
    cin >> day;
    if(day > 31 || day < 1) {
        throw day;
    }
    else {
        return day;
    }
}

int Date::invalidMonth() {
    cout << "Input month (1-12): ";
    cin >> month;
    if(month > 12 || month < 1) {
        throw month;
    }
    else {
        return month;
    }
}

int Date::invalidYear() {
    cout << "Input year (>= 0) : ";
    cin >> year;
    if(year < 0) {
        throw year;
    }
    else {
        return year;
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