/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   retail.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 3:05 PM
 */

#ifndef RETAIL_H
#define RETAIL_H
#include <string>
using namespace std;

struct items {
    string desc;
    int unit, price;
};

class RetailItem {
private:
    items *a;
    int size;
public:
    RetailItem();
    ~RetailItem();
    void display();
    items *fill();
};

#endif /* RETAIL_H */

