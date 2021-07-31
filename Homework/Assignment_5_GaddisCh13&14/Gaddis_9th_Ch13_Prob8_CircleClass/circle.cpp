/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   circle.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 4:33 PM
 */

#include <iostream>
using namespace std;

#include "circle.h"

Circle::Circle() {
    cout << "This Program Inputs the radius of a circle and outputs its Diameter, Area, and Circumference." << endl;
    cout << "Input Each Field to Calculate Output..." << endl;
    cout << "Input Radius: ";
    cin >> radius;
    //Calculate by calling functions
    getDiam();
    getArea();
    getCirc();
}

float Circle::getArea() {
    area = pi * radius * radius;
}

float Circle::getDiam() {
    diameter = radius * 2;
}

float Circle::getCirc() {
    circum = pi * diameter;
}

void Circle::display() {
    cout << endl << "The Calculations are..." << endl;
    cout << "Radius        = " << radius << endl;
    cout << "Diameter      = " << diameter << endl;
    cout << "Area          = " << area << endl;
    cout << "Circumference = " << circum << endl;
}