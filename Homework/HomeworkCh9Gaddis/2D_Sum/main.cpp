/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on: July 4 2021
 * Purpose: 2D Sum - Dynamic Memory Allocation
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int **getData(int,int);     //Return the 2-D array and its size.
void prntDat(int**,int,int);//Print the 2-D Array
void destroy(int **);       //Deallocate memory
int sum(int **,int,int);    //Return the Sum

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int rows, cols, **array, add;
    
    //Initialize Variables
    cin >> rows >> cols;
    
    //Process Input
    array = getData(rows, cols);
    add = sum(array, rows, cols);
    
    //Output
    prntDat(array, rows, cols);
    cout << add;
    
    //Exit
    destroy(array);
    return 0;
}

int **getData(int rows,int cols) {
    //Allocate memory (pointers for each row array)
    int **array = new int*[rows];
    //Allocate the memory for each row
    for(int row = 0; row < rows; row++) {
        array[row] = new int[cols];
    }
    //Fill Array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> array[i][j];
        }
    }
    
    return array;
}

void prntDat(int **array,int rows,int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << array[i][j];
            if(j != cols - 1) {
                cout << " ";
            }
        }
        cout <<  endl;
    }
}

void destroy(int **array) {
    delete []array;
}

int sum(int **array, int rows, int cols) {
    //Initialize sum value
    int add = 0;
    //Add values
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            add += array[i][j];
        }
    }
    
    return add;
}