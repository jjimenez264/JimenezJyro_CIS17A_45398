/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   circle.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 4:33 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    float radius, area, diameter, circum;
public: 
    Circle();
    float pi = 3.14159;
    float getArea();
    float getDiam();
    float getCirc();
    void display();
};

#endif /* CIRCLE_H */

