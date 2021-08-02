/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sort.cpp
 * Author: jyroj
 * 
 * Created on July 27, 2021, 4:40 PM
 */

#include <iostream> 
using namespace std;

#include "sort.h"


char *Prob2Sort::sortArray(char *ch2p, int rows, int cols, int column, bool ascending) {
    cout << endl << "Sorting on column " << column << endl;\
    //convert to a 2 dim string
    char **a= new char*[rows];
    //allocate per row
    for(int row = 0; row < rows; row++) {
        a[row] = new char[cols];
    }
    
    //initialize with proper values
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 15; j++) {
            a[i][j] = ch2p[i*15 + j];
        }
    }
    
    //sort
    for(int i = 0; i < rows - 1; i++) {
        int idxMin = i;
        for(int j = i+1; j < rows; j++) {
            if(a[idxMin][column - 1] < a[j][column - 1]) {
                idxMin = j;
            }
        }
        char *temp = new char;
        temp = a[i];
        a[i] = a[idxMin];
        a[idxMin] = temp;
    }
    
    //Move Values to ch2p again
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 15; j++) {
            ch2p[i*15 + j] = a[i][j];
        }
    }
    
    //deallocate
    for(int i = 0; i < rows; i++){
        delete [] a[i];
    }
    delete [] a;
    //Return
    return ch2p;
}