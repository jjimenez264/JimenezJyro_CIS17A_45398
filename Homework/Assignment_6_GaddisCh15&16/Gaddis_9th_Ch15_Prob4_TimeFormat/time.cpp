/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   time.cpp
 * Author: jyroj
 * 
 * Created on July 26, 2021, 12:31 AM
 */

#include <iostream>
using namespace std;

#include "time.h"

time::time() {
    cout << "This Program inputs standard time and outputs both military and standard time." << endl;
    cout << "Input Each Field..." << endl;
    cout << "Input Hours  (1-12) : ";
    cin >> hour;
    //Validation
    if(hour > 12 || hour < 1) {
        cout << "Invalid Hour! Try again: ";
        cin >> hour;
    }
    cout << "Input Minutes (0-59): ";
    cin >> min;
    //Validation
    if(min > 59 || min < 1) {
        cout << "Invalid Minutes! Try again: ";
        cin >> min;
    }
    cout << "Input Seconds (0-59): ";
    cin >> sec;
    //Validation
    if(sec > 59 || sec < 1) {
        cout << "Invalid Seconds! Try again: ";
        cin >> sec;
    }
    cout << "Day or Night(a or p): ";
    cin >> day;
}

milTime::milTime() {
    if(day == 'a' && hour == 12) {
        milHour = min;
    }
    else if(day == 'p' && hour == 12) {
        milHour = (hour * 100) + min;
    }
    else if(day == 'a') {
        milHour = (hour * 100) + min;
    }
    else if(day == 'p') {
        milHour = (hour + 12) * 100;
        milHour += min;
    }
    milSec = sec;
}

void milTime::display() {
    cout << endl << "The Converted Times are..." << endl;
    cout << "Standard Time..." << endl;
    cout << hour << ":" << min << ":" << sec;
    //Output for am or pm
    if(day == 'a') {
        cout << " A.M." << endl << endl;
    }
    else {
        cout << " P.M." << endl << endl;
    }
    cout << "Military Time..." << endl;
    cout << milHour << " Hours and " << milSec << " Seconds";
}