/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   July 31, 2021
    Purpose:Final Problem 5: Employee Class
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
using namespace std;   //Library Name-space

//User Libraries
#include "person.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
int expRate();
int expHour();

//Execute code
int main() {
    cout << "Problem 5: Employee Class" << endl;
    cout << "Extra Credit to discuss making code better..." << endl;
    cout << "I changed the character properties to strings so that the user can input name and job title." << endl
         << "This is better in a way, as the user manually inputs the properties rather than pre-inputed properties." << endl
         << "In addition to this, I added exception handling for the hours and work rate inputed by the user." << endl
         << "I also changed the doable property for Tax(), cause no doubles and wasn't needed." << endl;
    //Declare
    string name, job;
    float rate;
    int hours;
    //Ask Questions
    cout << "What is the name of the employee: ";
    cin.clear();
    getline(cin, name);
    cout << "What is their Job title?: ";
    getline(cin, job);
    //Exception Handling for Rate
    try {
        rate = expRate();
    }
    catch(int error) {
        cout << "The Inputed Hourly Rate " << rate << " is Invalid! Try Again..." <<endl;
        rate = expRate();
    }
    //Exception Handling for Hours
    try {
        hours = expHour();
    }
    catch(int error) {
        cout << "The Inputed Hours Worked " << rate << " is Invalid! Try Again..." <<endl;
        hours = expHour();
    }
    //Declare Class
    Employee person(name, job, hours, rate);
    //Calculate pay rate
    person.CalculatePay(rate, hours);
    cout << endl;
    //Output information
    person.toString();
    return 0;
}

int expRate() {
    int rate = 0;
    cout << "What is their Hourly Rate?: ";
    cin >> rate;
    if(rate > 0 && rate < 200) {
        return rate;
    }
    else {
        throw rate;
    }
    return rate;
}

int expHour() {
    int hours = 0;
    cout << "How many hours do you work?: ";
    cin >> hours;
    if(hours > 0 && hours < 84) {
        return hours;
    }
    else {
        throw hours;
    }
    return hours;
}