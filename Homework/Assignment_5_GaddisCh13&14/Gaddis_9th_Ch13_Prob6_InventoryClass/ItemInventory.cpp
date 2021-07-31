/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemInventory.cpp
 * Author: jyroj
 * 
 * Created on July 23, 2021, 3:54 PM
 */

#include <iostream>
using namespace std;

#include "ItemInventory.h"

Inventory::Inventory() {
    cout << "This Program Inputs Items in a store and calculates the cost of each item." << endl;
    cout << "Input Necessary Fields..." << endl;
    cout << "Input How many items: ";
    cin >> size;
    a = fill();
    //Call function to calculate total
    calcTot();
}

Inventory::~Inventory() {
    delete [] a;
}

void Inventory::display() {
    cout << "Item Inventory List..." << endl;
    for(int i = 0; i < size; i++) {
        cout << "Item Number    : " << a[i].itemNum << endl;
        cout << "Units Available: " << a[i].unit << endl;
        cout << "Price per Unit : $" << a[i].price << endl;
        cout << "Total Price    : $" << a[i].totPrice << endl << endl;
    }
}

items *Inventory::fill() {
    //Allocate Memory
    items *copy = new items[size];
    //Input each number
    for(int i = 0; i < size; i++ ){
        cout << "Input item number: ";
        cin >> copy[i].itemNum;
        cout << "Input quantity   : ";
        cin >> copy[i].unit;
        cout << "Input Item Price : ";
        cin >> copy[i].price;
        cout << endl;
    }
    //Return Value
    return copy;
    delete [] copy;
}

float Inventory::calcTot() {
    for(int i = 0; i < size; i++) {
        a[i].totPrice = a[i].price * a[i].unit;
    }
}