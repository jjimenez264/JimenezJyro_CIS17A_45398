/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   retail.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 3:05 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "retail.h"

RetailItem::RetailItem() {
    cout << "This Program Inputs Items in a store." << endl;
    cout << "Input Necessary Fields..." << endl;
    cout << "Input How many items: ";
    cin >> size;
    a = fill();
}

RetailItem::~RetailItem() {
    delete [] a;
}

void RetailItem::display() {
    cout << "Item Descriptions..." << endl;
    for(int i = 0; i < size; i++) {
        cout << "Item #" << i + 1 << "..." << endl;
        cout << "Description: " << a[i].desc << endl;
        cout << "Units Available: " << a[i].unit << endl;
        cout << "Unit Price: $" << a[i].price << endl << endl;
    }
}

items *RetailItem::fill() {
    //Allocate Memory
    items *copy = new items[size];
    
    for(int i = 0; i < size; i++ ){
        cout << "Input item: ";
        cin.ignore();
        getline(cin, copy[i].desc);
        cout << "Input Units: ";
        cin >> copy[i].unit;
        cout << "Input Price: ";
        cin >> copy[i].price;
        cout << endl;
    }
    
    return copy;
    delete [] copy;
}