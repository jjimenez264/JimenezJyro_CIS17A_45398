/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   person.h
 * Author: jyroj
 *
 * Created on August 1, 2021, 1:43 AM
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Employee {
    private:
        float Tax(); //Utility Procedure
        string MyName;   //Property
        string JobTitle; //Property
        float HourlyRate;  //Property
        int HoursWorked;   //Property
        float GrossPay;    //Property
        float NetPay;      //Property
    public:
        Employee(string,string, int, float); //Constructor
        float CalculatePay(float,int); //Procedure
        float getGrossPay(float,int);  //Procedure
        float getNetPay(float);        //Procedure
        void toString();               //Procedure
        int setHoursWorked(int);       //Procedure
        float setHourlyRate(float);    //Procedure
};

#endif /* PERSON_H */

