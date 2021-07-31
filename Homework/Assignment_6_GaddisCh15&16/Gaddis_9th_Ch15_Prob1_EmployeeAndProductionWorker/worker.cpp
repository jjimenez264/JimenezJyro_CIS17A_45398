/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   worker.cpp
 * Author: jyroj
 * 
 * Created on July 25, 2021, 10:16 PM
 */

#include <iostream>
using namespace std;

#include "worker.h"

employee::employee() {
    cout << "This Program inputs an employee and their work shifts." << endl;
    cout << "Enter the specific fields..." << endl;
    cout << "Enter Employee's Name  : ";
    cin.clear();
    getline(cin, empName);
    cout << "Enter Full Phone Number: ";
    getline(cin, phoneNum);
    cout << "Enter Hire Date (M/D/Y): ";
    getline(cin, hireDate);
}

productionWorker::productionWorker() {
    cout << "Enter the Production Worker's information..." << endl;
    cout << "Enter what shift they have..." << endl;
    cout << "(Day = 1 or Night = 2)" << endl;
    cout << "Input Shift: ";
    cin >> shift;
    cout << "Input Hourly Pay Rate: $";
    cin >> hourPay;
}

void productionWorker::display() {
    cout << endl << "The Employee's Information is..." << endl;
    cout << "Name     : " << empName << endl;
    cout << "Phone Num: " << phoneNum << endl;
    cout << "Hire Date: " << hireDate << endl;
    cout << "Shift    : ";
    //If day or night
    if(shift == 1) {
        cout << "Day" << endl;
    }
    else {
        cout << "Night" << endl;
    }
    cout << "Pay Rate : $" << hourPay << endl;
}