/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on: July 4 2021
 * Purpose: Sum - Dynamic Memory Allocation
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *getData(int);      //Fill the array
int *sumAry(int *,int); //Return the array with successive sums
void prntAry(int *,int);//Print the array
void prntSum(int *,int);//Print Sum

//Program Execution Begins Here
int main(int argc, char** argv) {
    int size, *array, *sum;
    
    //Initialize Variables
    cin >> size;
    
    //Process Input
    array = getData(size);
    sum = sumAry(array, size);
    
    //Output
    prntAry(array, size);
    prntSum(sum, size);

    //Exit
    delete []array;
    delete []sum;
    return 0;
}

int *getData(int size) {
    //Allocate memory
    int *array = new int[size];
    
    //Fill Array
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
    
    return array;
}

int *sumAry(int *array, int size) {
    // initialize a sum value
    int *sum = new int[size];
    int val = 0;
    
    // add precedening values
    for(int i = 0; i < size; i++) {
        val += array[i];
        sum[i] = val;
    }
    
    return sum;
}

void prntAry(int *array, int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i];
        if(i != size - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void prntSum(int *sum, int size) {
    for(int i = 0; i < size; i++) {
        cout << sum[i];
        if(i != size - 1) {
            cout << " ";
        }
    }
}