/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   date.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 1:22 AM
 */

#ifndef DATE_H
#define DATE_H

class Date {
    private:
        int day, month, year;
    public:
        Date();
        void numDate();
        void monthDate();
        void dayDate();
};

#endif /* DATE_H */

