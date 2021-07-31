/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemInventory.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 3:54 PM
 */

#ifndef ITEMINVENTORY_H
#define ITEMINVENTORY_H

struct items {
    int itemNum, unit;
    float price, totPrice;
};

class Inventory {
private:
    items *a;
    int size;
public:
    Inventory();
    ~Inventory();
    void display();
    items *fill();
    float calcTot();
};

#endif /* ITEMINVENTORY_H */

