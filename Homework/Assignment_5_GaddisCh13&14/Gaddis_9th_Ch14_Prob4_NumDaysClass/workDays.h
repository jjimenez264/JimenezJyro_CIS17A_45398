/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   workDays.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 9:20 PM
 */

#ifndef WORKDAYS_H
#define WORKDAYS_H

class numDays {
private:
    float day, hour;
    char choice;
public: 
    numDays();
    float countDays();
    void display();
};

#endif /* WORKDAYS_H */

