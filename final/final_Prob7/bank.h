/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bank.h
 * Author: jyroj
 *
 * Created on August 1, 2021, 12:04 AM
 */

#ifndef BANK_H
#define BANK_H

class SavingsAccount {
    private:
        float Withdraw(float);      //Utility Procedure
        float Deposit(float);       //Utility Procedure
        float Balance;              //Property
        int FreqWithDraw;           //Property
        int FreqDeposit;            //Property
    public:
        SavingsAccount();      //Constructor
        void Transaction(float);    //Procedure
        float Total(float=0,int=0); //Savings Procedure
        float TotalRecursive(float=0,int=0);
        void toString();            //Output Properties
};

#endif /* BANK_H */

