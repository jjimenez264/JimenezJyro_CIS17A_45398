/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   July 26, 2021
    Purpose:Gaddis Chapter 16 Prob 3: Minimum/Maximum Templates
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
using namespace std;   //Library Name-space

//User Libraries


//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
template <class max>
max getMax(max num1, max num2) {
    max result;
    result = (num1>num2)? num1 : num2;
    return (result);
}
template <class min>
min getMin(min num1, min num2) {
    min result;
    result = (num1<num2)? num1 : num2;
    return (result);
}

//Execute code
int main() {
    //Initialize class
    int num1, num2, minNum, maxNum;
    //Output
    cout << "This Program Utilizes templates to find the maximum and minimum between 2 inputs." << endl;
    cout << "Input num1 and num2: ";
    cin >> num1 >> num2;
    //Calculate max and min
    maxNum = getMax(num1, num2);
    minNum = getMin(num1, num2);
    cout << endl << "The Maximum is: " << maxNum << endl;
    cout << "The Minimum is: " << minNum << endl;
    return 0;
}