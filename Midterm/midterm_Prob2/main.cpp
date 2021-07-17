/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 14 2021
 * Purpose:Midterm Problem 2: Employee Checks
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "company.h"

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
employee *inField(int);
void checkOut(employee *, int, string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    employee *indiv;
    int numEmpl;
    string compName;
    
    //Initialize
    cout << "This Program determines the gross pay for any number of employees." << endl;
    
    //Ask For company name and input it
    cout << "What is the name of the Company?" << endl;
    cout << "Input name: ";
    cin.clear();
    getline(cin, compName);
    
    //Ask for the number of employees
    cout << "Please input the number of employees: ";
    cin >> numEmpl;
    
    //Initialize the structure array
    indiv = inField(numEmpl);
    
    //Output
    cout << endl;
    checkOut(indiv, numEmpl, compName);
    
    //Deallocate memory
    delete [] indiv;
    
    //Exit stage right!
    return 0;
}

employee *inField(int numEmpl) {
    //Initialize dynamic array
    employee *a = new employee[numEmpl];
    
    //Fill Each field
    for(int i = 0; i < numEmpl; i++) {
        cout << "Enter each field for Employee No." << i+1 << "..." << endl;
        cout << "Employee Name   : ";
        cin.ignore();
        getline(cin, a[i].name);
        cout << "No. Hours Worked: ";
        cin >> a[i].hours;
        cout << "Pay Rate in $/hr: ";
        cin >> a[i].payRate;
        //Validate User input for negatives
        if(a[i].hours < 0 || a[i].payRate < 0) {
            cout << "These are invalid inputs, and will not count" << endl;
            numEmpl = i;
        }
    }
    
    //Calculate total pay for each employee
    for(int i = 0; i < numEmpl; i++) {
        if(a[i].hours <= 20){
            a[i].totPay = a[i].payRate * a[i].hours;
        }
        else if(a[i].hours > 20 && a[i].hours <= 40) {
            a[i].totPay = a[i].payRate * 20;
            a[i].totPay += (a[i].payRate * ((a[i].hours - 20) * 2));
        }
        else if(a[i].hours > 40) {
            a[i].totPay = a[i].payRate * 20;
            a[i].totPay += (a[i].payRate * ((a[i].hours - 20) * 2));
            a[i].totPay -= (a[i].payRate * ((a[i].hours - 40) * 2));
            a[i].totPay += (a[i].payRate * ((a[i].hours - 40) * 3));
        }
    }
    
    //Return array
    return a;
}

void checkOut(employee *a, int numEmpl, string compName) {
    //Initialize numbers
    int num1, num2, num3, num4;
    cout << "Printing out Employee Checks..." << endl << endl;
    //Output employee checks
    for(int i = 0; i < numEmpl; i++) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Company: " << compName << endl;
        cout << "Name: " << a[i].name << "    Amount: $" << a[i].totPay << endl;
        cout << "Amount: ";
        //Calculate the 1000's, 100's, 10's and 1's
        //Had to take modulus in second step cause it wouldn't compile
        num1 = a[i].totPay;
        num1 = num1 % 10;
        num2 = a[i].totPay / 10;
        num2 = num2 % 10;
        num3 = a[i].totPay / 100;
        num3 = num3 % 10;
        num4 = a[i].totPay / 1000;
        num4 = num4 % 10;
        //Convert to English numerical Value
        //Thousands Place
        switch(num4) {
            case 1:
                cout << "One Thousand ";
                break;
            case 2:
                cout << "Two Thousand ";
                break;
            case 3:
                cout << "Three Thousand ";
                break;
            case 4:
                cout << "Four Thousand ";
                break;
            case 5:
                cout << "Five Thousand ";
                break;
            case 6:
                cout << "Six Thousand ";
                break;
            case 7:
                cout << "Seven Thousand ";
                break;
            case 8:
                cout << "Eight Thousand ";
                break;
            case 9:
                cout << "Nine Thousand ";
                break;
        }
        //Hundreths place
        switch(num3) {
            case 1:
                cout << "One Hundred ";
                break;
            case 2:
                cout << "Two Hundred ";
                break;
            case 3:
                cout << "Three Hundred ";
                break;
            case 4:
                cout << "Four Hundred ";
                break;
            case 5:
                cout << "Five Hundred ";
                break;
            case 6:
                cout << "Six Hundred ";
                break;
            case 7:
                cout << "Seven Hundred ";
                break;
            case 8:
                cout << "Eight Hundred ";
                break;
            case 9:
                cout << "Nine Hundred ";
                break;
        }
        //Tenths place depending on teen or not
        if (num2 == 1) {
            switch(num1) {
                case 0:
                    cout << "Ten ";
                    break;
                case 1:
                    cout << "Eleven ";
                    break;
                case 2:
                    cout << "Twelve ";
                    break;
                case 3:
                    cout << "Thirteen ";
                    break;
                case 4:
                    cout << "Fourteen ";
                    break;
                case 5:
                    cout << "Fifteen ";
                    break;
                case 6:
                    cout << "Sixteen ";
                    break;
                case 7:
                    cout << "Seventeen ";
                    break;
                case 8:
                    cout << "Eighteen ";
                    break;
                case 9:
                    cout << "Nineteen ";
                    break;
            }
        }
        else {
            switch(num2) {
                case 2:
                    cout << "Twenty ";
                    break;
                case 3:
                    cout << "Thirty ";
                    break;
                case 4:
                    cout << "Forty ";
                    break;
                case 5:
                    cout << "Fifty ";
                    break;
                case 6:
                    cout << "Sixty ";
                    break;
                case 7:
                    cout << "Seventy ";
                    break;
                case 8:
                    cout << "Eighty ";
                    break;
                case 9:
                    cout << "Ninety ";
                    break;
            }
            //Ones place
            switch(num1) {
                case 0:
                    cout << "";
                    break;
                case 1:
                    cout << "One ";
                    break;
                case 2:
                    cout << "Two ";
                    break;
                case 3:
                    cout << "Three ";
                    break;
                case 4:
                    cout << "Fourt ";
                    break;
                case 5:
                    cout << "Five ";
                    break;
                case 6:
                    cout << "Six ";
                    break;
                case 7:
                    cout << "Seven ";
                    break;
                case 8:
                    cout << "Eight ";
                    break;
                case 9:
                    cout << "Nine ";
                    break;
            }
        }
        //Output Signature line
        cout << "Dollars." << endl;
        cout << "Signature Line:__________________________________" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    }
}