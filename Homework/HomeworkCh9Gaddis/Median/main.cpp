/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on: July 3 2021
 * Purpose: Meidian - Dynamic Memory Allocation
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *getData(int);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float median(int *,int, float &);  // find median
float *medianArray(int *,int, float);//Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *, int);     //Print the median Array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size, *ary;
    float med, *medAry;
    
    //Initialize Variables
    cin >> size;
    ary = getData(size);
    
    //Process Input
    prntDat(ary, size);
    median(ary,size,med);
    medAry = medianArray(ary,size, med);
    
    //Output
    prntMed(medAry, size);
    
    //Exit
    delete []ary;
    delete []medAry;
    return 0;
}

int *getData(int size){
    //Allocate memory
    int *array=new int[size];
    
    //Fill Array
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
    
    return array;
}

void prntDat(int *array, int size) {
    //Output the array
    for(int i = 0; i < size; i++){
        cout << array[i];
        if(i != size - 1) {
            cout << " ";
        }
    }
    
    cout<<endl;
}

float median(int *ary,int size, float &med) {
    //Place holder for position
    int medPlace;
    
    //Find the Median
    if(size%2 != 0) {
        medPlace = size/2;
        med = ary[medPlace];
    }
    else if(size%2 == 0) {
        medPlace = size/2;
        med = (ary[medPlace] + ary[medPlace - 1]) / 2.0;
    }
}

float *medianArray(int *ary,int size, float med) {
    //New Size for array;
    int n = size + 2;
    
    //Allocate memory
    float *array=new float[n];
    
    //Fill first two numbers of float Array
    array[0] = n;
    array[1] = med;
    
    //Fill Array
    for(int i = 0; i < size; i++){
        array[i + 2] = ary[i];
    }
    
    return array;
}

void prntMed(float *array, int size) {
    //Output the array
    cout << array[0] << " ";
    for(int i = 1; i < size + 2; i++){
        cout << setprecision(2) << fixed << showpoint << array[i];
        if(i != size + 1) {
            cout << " ";
        }
    }
}