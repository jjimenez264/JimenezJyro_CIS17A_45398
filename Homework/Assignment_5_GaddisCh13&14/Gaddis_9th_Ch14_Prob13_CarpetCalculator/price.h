/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   price.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 9:36 PM
 */

#ifndef PRICE_H
#define PRICE_H

class Carpet {
private:
    float length, width, perFoot, totPrice;
public:
    Carpet();
    float calc();
    void display();
};

#endif /* PRICE_H */

