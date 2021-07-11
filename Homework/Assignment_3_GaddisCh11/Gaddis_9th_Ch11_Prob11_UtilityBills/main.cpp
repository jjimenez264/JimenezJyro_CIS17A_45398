/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 8 2021
 * Purpose:Gaddis Chapter 11 Problem 11 - Utility Bills
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Structure
struct MonthlyBudget {
    float bills;
};

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int size = 10;
    MonthlyBudget budget[size] = {500, 150, 65, 50, 250, 30, 100, 150, 75, 50};
    MonthlyBudget expenses[size]; 
    float expTot, budgTot, diff;
    expTot = 0;
    budgTot = 0;
    
    //Process or map Inputs to Outputs
    //Input expenses
    cout << "Enter housing cost for the month:$" << endl;
    cout << "Enter utilities cost for the month:$" << endl;
    cout << "Enter household expenses cost for the month:$" << endl;
    cout << "Enter transportation cost for the month:$" << endl;
    cout << "Enter food cost for the month:$" << endl;
    cout << "Enter medical cost for the month:$" << endl;
    cout << "Enter insurance cost for the month:$" << endl;
    cout << "Enter entertainment cost for the month:$" << endl;
    cout << "Enter clothing cost for the month:$" << endl;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    //Input all expenses and add them
    for(int i = 0; i < size; i++) {
        //Input All expenses
        cin >> expenses[i].bills;
        //Add total budget
        budgTot += budget[i].bills;
        //Add total expenses
        expTot += expenses[i].bills;
    }
    
    //Process input if it is over, under, or even of budget and output
    for(int i = 0; i < size; i++) {
        switch(i) {
            case 0:
                cout << "Housing ";
                break;
            case 1:
                cout << "Utilities ";
                break;
            case 2:
                cout << "Household Expenses ";
                break;
            case 3:
                cout << "Transportation ";
                break;
            case 4:
                cout << "Food ";
                break;
            case 5:
                cout << "Medical ";
                break;
            case 6:
                cout << "Insurance ";
                break;
            case 7:
                cout << "Entertainment ";
                break;
            case 8:
                cout << "Clothing ";
                break;
            case 9:
                cout << "Miscellaneous ";
                break;
        }
        if(expenses[i].bills > budget[i].bills) {
            cout << "Over";
        }
        else if(expenses[i].bills < budget[i].bills) {
            cout << "Under";
        }
        else {
            cout << "Even";
        }
        
        cout << endl;
    }
    
    if(budgTot > expTot) {
        diff = budgTot - expTot;
        cout << "You were $" << setprecision(2) << fixed << diff << " under budget";
    }
    else {
        diff = expTot - budgTot;
        cout << "You were $" << setprecision(2) << fixed << diff << " over budget";
    }

    //Exit stage right!
    return 0;
}