/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on: July 3 2021
 * Purpose: Reverse - Dynamic Memory Allocation
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *getData(int);           //Fill the array
int *sort(int *,int);     //Sort smallest to largest
int reverse(int *,int); //Sort in reverse order
void prntDat(int *,int); //Print the array
void minPos(int *, int, int); //Find main pos
void swap(int *,int *);     //Swap

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size, *array, *sorted;
    
    //Initialize Variables
    cin >> size;
    array = getData(size);
    
    //Process Input
    sorted = sort(array, size);
    
    //Output
    prntDat(sorted, size);
    reverse(sorted, size);
    
    //Exit
    delete[]array;
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

int *sort(int *array, int n) {
    for(int i = 0; i < n - 1; i++){
        minPos(array, n,i);
    }
    
    return array;
}

void minPos(int *array, int n, int pos){
    for(int i = pos + 1; i < n; i++){
        if(*(array+pos) >* (array+i))
            swap(array+pos, array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

int reverse(int *sorted, int size) {
    for(int i = size - 1; i >= 0; i--) {
        cout << sorted[i];
        if(i != 0) {
            cout << " ";
        }
    }
}

void prntDat(int *array, int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i];
        if(i != size - 1) {
            cout << " ";
        }
    }
    
    cout<<endl;
}