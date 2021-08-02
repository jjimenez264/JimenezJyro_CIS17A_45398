/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   July 31, 2021
    Purpose:Final Problem 4: Savings Account Class
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;   //Library Name-space

//User Libraries
#include "bank.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execute code
int main() {
    //Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    //Driver Code
    SavingsAccount mine;
    for(int i=1;i<=10;i++){
        mine.Transaction((rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout << setprecision(2) << fixed;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total(0.10,7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive(0.10,7)
        <<" Recursive Calculation "<<endl;
    return 0;
}