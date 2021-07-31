/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   price.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 9:36 PM
 */

#include <iostream>
using namespace std;

#include "price.h"

Carpet::Carpet() {
    cout << "This program calculates the total price of setting up a carpet depending on its price per foot." << endl;
    cout << "Enter the specific fields..." << endl;
    cout << "Input length of carpet: ";
    cin >> length;
    cout << "Input Width of carpet : ";
    cin >> width;
    cout << "Input price per foot  : $";
    cin >> perFoot;
    //Initialize totPrice
    totPrice = 0;
    //Calculate total;
    calc();
}

float Carpet::calc() {
    totPrice = length * width * perFoot;
}

void Carpet::display() {
    cout << endl << "The total Price for setting up the carpet has been calculated..." << endl;
    cout << "The total amounts to: $" << totPrice << endl;
}