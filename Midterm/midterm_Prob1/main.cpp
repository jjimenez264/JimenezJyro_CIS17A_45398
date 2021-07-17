/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 13 2021
 * Purpose:Midterm Problem 1: Checking Account Balance
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "account.h"

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
bank *fillAcc(int &, int &);
float calcTot(bank *, int, int, float &, float &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    bank *account;
    int numChk, numDepo;
    float totChks, totDepo;
    
    //Initialize
    totChks = totDepo = 0;
    
    //input all fields
    cout << "This program determines the banking Account's balance." << endl;
    account = fillAcc(numChk, numDepo);
    
    //Calculate Deposits and Checks
    calcTot(account, numChk, numDepo, totChks, totDepo);
    
    //Calculate Balance
    account->bal = account->bal + totDepo - totChks;
    
    //Output Account's transactions
    cout << endl << "Account No." << account->num <<" Summary..." << endl;
    cout << "The Account's Total Checks amount to : $" << totChks << endl;
    cout << "The Account's Total Deposit amount to: $" << totDepo << endl;
    
    
    //If account is overdraw or not
    if(account->bal >= 0) {
        cout << "The Account's Total Balance amount to: $" << account->bal;
    }
    else if(account->bal < 0) {
        cout << "The Account's Total Balance amount to:-$" << account->bal*-1 <<endl;
        cout << "The Account's Balance is Overdrawn..." << endl
             << "A Debit of $50 is now needed..." << endl;
        account->bal -= 50;
        cout << "The New Account Balance is: -$" << account->bal*-1;
    }
    
    //Output End of program
    cout << endl << endl << "Thank you for choosing us " << account->name << "! Good Bye!";
    
    //Deallocate memory
    delete [] account->checks;
    delete [] account->depo;
    delete [] account->address;
    delete [] account;
    
    //Exit stage right!
    return 0;
}

bank *fillAcc(int &numChk, int &numDepo) {
    //Initialize dynamic array
    bank *a = new bank;
    a->checks = new float;
    a->depo = new float;
    
    //Input fields
    cout << "Please input the given fields for the program..." << endl;
    cout << "Account Number (5-Digit Num.): ";
    cin >> a->num;
    //Input Account name
    cout << "Account Holder's Name        : ";
    cin.ignore();
    getline(cin, a->name);
    //Allocate data for char array
    int size = 120; //Size for name and address
    a->address = new char[size];
    cout << "Account Holder's Address     : ";
    cin.getline(a->address, size  - 1);
    //Input Account Balance
    cout << "Account's Starting Balance   : $";
    cin >> a->bal;
    //Input No. of checks and the amount of each check
    cout << "Total No. of Checks Written  : ";
    cin >> numChk;
    cout << "Input Amount of Each Check Written..." << endl;
    for(int i = 0; i < numChk; i++) {
        cout << "Check " << i + 1 << ": $";
        cin >> a->checks[i];
    }
    //Input No. of deposits and the amount of deposit check
    cout << "Total No. of Deposits Written: ";
    cin >> numDepo;
    cout << "Input Amount of Each Check Written..." << endl;
    for(int i = 0; i < numDepo; i++) {
        cout << "Check " << i + 1 << ": $";
        cin >> a->depo[i];
    }
    
    //Return Value
    return a;
}

float calcTot(bank *a, int numChk, int numDepo, float &totChks, float &totDepo) {
    //Calculate total checks
    for(int i = 0; i < numChk; i++) {
        totChks += a->checks[i];
    }
    //Calculate total Deposits
    for(int i = 0; i < numDepo; i++) {
        totDepo += a->depo[i];
    }
}