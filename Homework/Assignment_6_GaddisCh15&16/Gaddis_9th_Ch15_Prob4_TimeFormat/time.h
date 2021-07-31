/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   time.h
 * Author: jyroj
 *
 * Created on July 26, 2021, 12:31 AM
 */

#ifndef TIME_H
#define TIME_H

//Base class
class time {
protected:
    int hour, min, sec;
    char day;
public:
    time();
};
//Derived Class
class milTime: public time{
private:
    int milHour, milSec;
public:
    milTime();
    void display();
};

#endif /* TIME_H */

