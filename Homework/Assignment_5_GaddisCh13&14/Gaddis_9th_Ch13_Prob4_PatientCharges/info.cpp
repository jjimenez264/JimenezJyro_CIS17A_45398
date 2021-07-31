/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   info.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 3:25 AM
 */

#include "info.h"
#include<iostream>
#include <string>
using namespace std;

Info::Info() {
    //Input for Patient
    cout << "Input Each Necessary field..." << endl;
    cout << "Patient's Full Legal Name..." << endl;
    cout << "Input first name: ";
    cin.clear();
    getline(cin, first);
    cout << "Input middle name: ";
    getline(cin, middle);
    cout << "Input last name: ";
    getline(cin, last);
    cout << "Patient's Legal Address..." << endl;
    cout << "Input first line: ";
    getline(cin, address);
    cout << "Input City: ";
    getline(cin, city);
    cout << "Input State: ";
    getline(cin, state);
    cout << "Input ZIP code: ";
    getline(cin, zip);
    cout << "Patient's Emergency Contact Information..." << endl;
    cout << "Input Phone number: ";
    getline(cin, phone);
    cout << "Input Emergency contact: ";
    getline(cin, emgName);
    cout << "Input Emergency number: ";
    getline(cin, emgPhone);
}

void Info::display() {
    //Output patient info
    cout << endl << endl;
    cout << "Patient's Information..." << endl;
    cout << "Name: " << first << " " << middle << " " << last << endl;
    cout << "Address : " << address << ", " << city << endl
         << "          " << state << " " << zip << endl;
    cout << "Phone Number: " << phone << endl;
    cout << "Emergency Contact Info... " << endl;
    cout << "Name: " << emgName << endl;
    cout << "Phone Number: " << emgPhone << endl;
}