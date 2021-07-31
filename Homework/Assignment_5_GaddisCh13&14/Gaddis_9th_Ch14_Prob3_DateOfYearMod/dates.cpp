/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dates.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 8:40 PM
 */

#include <iostream>
using namespace std;

#include "dates.h"

DateOfYear::DateOfYear() {
    cout << "This Program Inputs a date and converts it to its corresponding number of days." << endl;
    cout << "Enter a Date (Month) (Day): ";
    cin >> inputMonth >> inputDay;
    //Initialize totDays
    totDays = 0;
    //Count Months and totDays
    countMonths();
    countDays();
}

int DateOfYear::countMonths() {
    if(inputMonth == "January") {
        monthNum = 1;
    }
    else if(inputMonth == "February") {
        monthNum = 2;
    }
    else if(inputMonth == "March") {
        monthNum = 3;
    }
    else if(inputMonth == "April") {
        monthNum = 4;
    }
    else if(inputMonth == "May") {
        monthNum = 5;
    }
    else if(inputMonth == "June") {
        monthNum = 6;
    }
    else if(inputMonth == "July") {
        monthNum = 7;
    }
    else if(inputMonth == "August") {
        monthNum = 8;
    }
    else if(inputMonth == "September") {
        monthNum = 9;
    }
    else if(inputMonth == "October") {
        monthNum = 10;
    }
    else if(inputMonth == "November") {
        monthNum = 11;
    }
    else if(inputMonth == "December") {
        monthNum = 12;
    }
}

int DateOfYear::countDays() {
    for(int i = 0; i < monthNum; i++) {
        //Subtract to get exact day in month
        if(i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
            totDays += 31;
        }
        else if(i == 3 || i == 5 || i == 8 || i == 10) {
            totDays += 30;
        }
        else if(i == 1){
            totDays += 28;
        }
    }
    totDays += inputDay;
}

void DateOfYear::display() {
    cout << endl << "The Converted Date amounts to " << totDays << " Day(s)";
}
