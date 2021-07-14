/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 11 2021
 * Purpose:  Gaddis Chapter 12 Problem 8 - Array/File Functions
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int arrayToFileBin(fstream &, int *, int);
int arrayToFileTxt(fstream &, int *, int);
int *fileToArray(fstream &in, int);
int *fillAry(int);
void prntFile(int *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Open the Text and binary files
    int *array, size;
    fstream txtFile,binFile;
    txtFile.open("data.txt",ios::in|ios::out);
    binFile.open("data.bin",ios::in|ios::out|ios::binary);
    
    //Initialize
    cout << "Input the size of the array: ";
    cin >> size;
    
    //Initialize array
    array = fillAry(size);
    
    //Write into files
    arrayToFileBin(binFile, array, size);
    arrayToFileTxt(txtFile, array, size);
    
    //Read files
    int *read = new int[size];
    read = fileToArray(binFile, size);
    prntFile(read, size);
    
    //Close the files
    txtFile.close();
    binFile.close();
    
    //Delete dynamic arrays
    delete []read;
    delete []array;
    
    //Exit
    return 0;
}

int arrayToFileBin(fstream &out, int *a, int size) {
    out.write(reinterpret_cast<char *>(a),size*sizeof(int));
}

int arrayToFileTxt(fstream &out, int *array, int size) {
    for(int i = 0; i < size; i++) {
        out << array[i];
    }
}

int *fileToArray(fstream &in, int size) {
    //Initialize cursor and array
    long cursor = 0;
    int *array = new int[size];
    //Read file
    in.seekg(cursor,ios::beg);
    in.read(reinterpret_cast<char *>(array),size*sizeof(int));
    return array;
}

int *fillAry(int size) {
    //initialize dynamic array
    int *array = new int[size];
    //fill dynamic array
    for(int i = 0; i < size; i++) {
        array[i] = rand()%9;
    }
    return array;
}

void prntFile(int *array, int size) {
    cout << "The random array with the size of " << size << " is: ";
    for(int i = 0; i < size; i++) {
        cout << array[i];
    }
}