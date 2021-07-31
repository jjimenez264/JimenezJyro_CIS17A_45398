/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dates.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 7:10 PM
 */

#ifndef DATES_H
#define DATES_H

class DayOfYear {
private:
    int input, day, month;
public:
    DayOfYear();
    int convert();
    void display();
};

#endif /* DATES_H */

