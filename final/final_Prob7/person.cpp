/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   person.cpp
 * Author: jyroj
 * 
 * Created on August 1, 2021, 1:43 AM
 */

#include <string>
#include <iostream>
using namespace std;

#include "person.h"

Employee::Employee(string name, string job, int hours, float rate) {
    MyName = name;
    JobTitle = job;
    HourlyRate = setHourlyRate(rate);
    HoursWorked = setHoursWorked(hours);
    GrossPay = 0;
    NetPay = 0;
}

int Employee::setHoursWorked(int hours) {
    return hours;
}

float Employee::setHourlyRate(float rate) {
    return rate;
}

float Employee::CalculatePay(float rate, int hours) {
    GrossPay = getGrossPay(rate, hours);
    float tax = Tax();
    NetPay = getNetPay(tax);
    return NetPay;
}

float Employee::getGrossPay(float rate, int hours) {
    float total;
    if(hours < 40) {
        total = rate * hours;
    }
    else if(hours >= 40 && hours < 50) {
        total = rate * 40;
        total += (rate * ((hours - 40) * 1.5));
    }
    else if(hours >= 50) {
        total = rate * 40;
        total += (rate * ((hours - 40) * 1.5));
        total -= (rate * ((hours - 50) * 1.5));
        total += (rate * ((hours - 50) * 2));
    }
    return total;
}

float Employee::Tax() {
    float tax = 0;
    if(GrossPay < 500) {
        tax = .1;
    }
    else if(GrossPay < 1000 && GrossPay >= 500) {
        tax = .2;
    }
    else {
        tax = .3;
    }
    return tax;
}

float Employee::getNetPay(float tax) {
    float total = 0;
    total = GrossPay * tax;
    total = GrossPay - total;
    return total;
}

 void Employee::toString() {
     cout << "Name = " << MyName << " Job Title = " << JobTitle << endl;
     cout << " Hourly Rate = " << HourlyRate << " Hours Worked = " << HoursWorked << " Gross Pay = $" << GrossPay << " Net Pay = $" << NetPay << endl;
 }