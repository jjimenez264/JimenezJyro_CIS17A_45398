/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   proced.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 3:48 AM
 */

#include "proced.h"
#include <iostream>
#include <string>
using namespace std;

Proced::Proced() {
    cout << endl << "Input The number of Procedures for the patient: ";
    cin >> size;
    a = fill();
}

Proced::~Proced() {
    delete [] a;
}

void Proced::display() {
    for(int i = 0; i < size; i++) {
        cout << endl << "Procedure #" << i + 1 << ":" << endl;
        cout << "Procedure Name: " << a[i].namePro << endl;
        cout << "Date: " << a[i].datePro << endl;
        cout << "Practitioner: " << a[i].doctr << endl;
        cout << "Charge: " << a[i].chrg << endl;
    }
}

procedures *Proced::fill() {
    //Allocate Memory
    procedures *copy = new procedures[size];
    
    for(int i = 0; i < size; i++) {
        cout << "Input Procedure: ";
        cin.ignore();
        getline(cin, copy[i].namePro);
        cout << "Input Date of Procedure: ";
        getline(cin, copy[i].datePro);
        cout << "Input Name of Doctor: ";
        getline(cin, copy[i].doctr);
        cout << "Input Charge for Procedure: ";
        cin >> copy[i].chrg;
    }
    
    return copy;
    delete [] copy;
}