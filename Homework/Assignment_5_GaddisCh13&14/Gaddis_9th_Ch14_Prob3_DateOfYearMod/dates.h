/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dates.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 8:40 PM
 */

#ifndef DATES_H
#define DATES_H

class DateOfYear {
private:
    string inputMonth;
    int totDays, inputDay, monthNum;
public:
    DateOfYear();
    int countMonths();
    int countDays();
    void display();
};

#endif /* DATES_H */

