/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bank.cpp
 * Author: jyroj
 * 
 * Created on August 1, 2021, 12:04 AM
 */

#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;

#include "bank.h"

SavingsAccount::SavingsAccount() {
    Balance = 0;
    FreqDeposit = 0;
    FreqWithDraw = 0;
}

void SavingsAccount::Transaction(float a) {
    if(a > 0) {
        Balance = Deposit(a);
    }
    else if(a < 0 && (Balance <= 0 || Balance < a)) {
        cout << "WithDraw not Allowed" << endl;
    }
    else if(a < 0 && Balance > 0) {
        Balance = Withdraw(a);
    }
    else {
        cout << "WithDraw not Allowed" << endl;
    }
}

float SavingsAccount::Deposit(float a) {
    Balance += a;
    FreqDeposit++;
    return Balance;
}

float SavingsAccount::Withdraw(float a) {
    Balance += a;
    FreqWithDraw++;
    return Balance;
}

void SavingsAccount::toString() {
    cout << "Balance=" << Balance << endl;
    cout << "WithDraws=" << FreqWithDraw << endl;
    cout << "Deposit=" << FreqDeposit << endl;
}

float SavingsAccount::Total(float savint, int time) {
    float result = Balance * (pow ((1+savint), time));
    return result;
}

float SavingsAccount::TotalRecursive(float savint, int time) {
    float result = Balance * (pow ((1+savint), time));
    return result;
}