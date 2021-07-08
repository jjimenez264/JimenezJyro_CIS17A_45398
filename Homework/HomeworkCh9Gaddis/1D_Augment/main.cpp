/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on: July 4 2021
 * Purpose: 1D Augment - Dynamic Memory Allocation
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *getData(int);       //Fill the array
int *augment(int *, int);//Augment and copy the original array
void prntAry(int *, int);//Print the array
void prntAug(int *, int);//Print the Augment

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size, *array, *aug;
    
    //Initialize Variables
    cin >> size;
    
    //Process Input
    array = getData(size);
    aug = augment(array, size);
    
    //Output
    prntAry(array, size);
    prntAug(aug, size);

    //Exit
    delete []array;
    delete []aug;
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

int *augment(int *array, int size) {
    //Allocate memory
    int *aug = new int[size + 1];
    
    //Fill augmented array
    aug[0] = 0;
    for(int i = 0; i < size; i++){
        aug[i+1] = array[i];
    }
    
    return aug;
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

void prntAug(int *array, int size) {
    for(int i = 0; i < size + 1; i++) {
        cout << array[i];
        if(i != size) {
            cout << " ";
        }
    }
}