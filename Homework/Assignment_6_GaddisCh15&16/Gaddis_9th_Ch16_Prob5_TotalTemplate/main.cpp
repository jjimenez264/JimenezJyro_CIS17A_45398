/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   July 26, 2021
    Purpose:Gaddis Chapter 16 Prob 5:  Total Template
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
int *input(int);
template <class T>
T Total(T *array, T size) {
    T add = 0;
    for(int i = 0; i < size; i++) {
        add += array[i];
    }
    return add;
}
//Execute code
int main() {
    //Initialize class
    int *array, size, total;
    
    //Start
    cout << "This Program inputs the total of each inputed number." << endl;
    cout << "Input The number of inputs you will add." << endl;
    cout << "Enter Size: ";
    cin >> size;
    
    //process
    array = input(size);
    total = Total(array, size);
    
    //Output
    cout << endl << "The running total is = " << total << endl;
    
    //End
    return 0;
}
//For dynamic array
int *input(int size) {
    int *array = new int[size];
    for(int i = 0; i < size; i++) {
        cout << "Input Num#" << i+1 << ": ";
        cin >> array[i];
    }
    return array;
}
