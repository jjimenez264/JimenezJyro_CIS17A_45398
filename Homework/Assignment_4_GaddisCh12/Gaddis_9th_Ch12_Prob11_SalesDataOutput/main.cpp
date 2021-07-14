/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 11 2021
 * Purpose:  Gaddis Chapter 12 Problem 11 - Corporate Sales Data Output
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries Here
#include "division.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float *fillAry(const int);
void printAry(const int, company []);
int writeBin(fstream &out, company[], const int);
int writeTxt(fstream &out, company[], const int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Open the Text and binary files
    fstream txtFile,binFile;
    txtFile.open("data.txt",ios::in|ios::out);
    binFile.open("data.bin",ios::in|ios::out|ios::binary);
    const int size = 4;
    company div[size];
    
    //Initialize
    cout << "This program inputs the quarterly sales of each division of a company into a file." << endl << endl;
    cout << "Input the sales for the Eastern Division...." << endl;
    div[0].qrtSales = fillAry(size);
    cout << "Input the sales for the Western Division...." << endl;
    div[1].qrtSales = fillAry(size);
    cout << "Input the sales for the Northern Division..." << endl;
    div[2].qrtSales = fillAry(size);
    cout << "Input the sales for the Southern Division..." << endl;
    div[3].qrtSales = fillAry(size);
    
    //Output data into a file
    writeTxt(txtFile, div, size);
    writeBin(binFile, div, size);
    
    //Output List
    cout << endl << "The inputed list for each division's quarterly sales is: " << endl;
    printAry(size, div);
    
    //Delete memory
    delete []div[0].qrtSales;
    delete []div[1].qrtSales;
    delete []div[2].qrtSales;
    delete []div[3].qrtSales;
    
    //Exit
    return 0;
}

float *fillAry(const int size) {
    //initialize dynamic array
    float *array = new float[size];
    cout << "Input for each quarter..." << endl;
    //fill dynamic array
    for(int i = 0; i < size; i++) {
        cout << i + 1 << " Quarter: ";
        cin >> array[i];
    }
    
    return array;
}

void printAry(const int size, company div[]) {
    cout << "The Eastern division:" << endl;
    for(int i = 0; i < size; i++) {
        cout << i + 1 << " Quarter: " << div[0].qrtSales[i] << endl;
    }
    cout << "The Western division:" << endl;
    for(int i = 0; i < size; i++) {
        cout << i + 1 << " Quarter: " << div[1].qrtSales[i] << endl;
    }
    cout << "The Northern division:" << endl;
    for(int i = 0; i < size; i++) {
        cout << i + 1 << " Quarter: " << div[2].qrtSales[i] << endl;
    }
    cout << "The Southern division:" << endl;
    for(int i = 0; i < size; i++) {
        cout << i + 1 << " Quarter: " << div[3].qrtSales[i] << endl;
    }
}

int writeBin(fstream &out, company div[], const int size) {
    for(int i = 0; i < size; i++) {
        out.write(reinterpret_cast<char *>(div[i].qrtSales),size*sizeof(int));
    }
}

int writeTxt(fstream &out, company div[], const int size) {
    out << "The Eastern division:" << endl;
    for(int i = 0; i < size; i++) {
        out << i + 1 << " Quarter: " << div[0].qrtSales[i] << endl;
    }
    out << "The Western division:" << endl;
    for(int i = 0; i < size; i++) {
        out << i + 1 << " Quarter: " << div[1].qrtSales[i] << endl;
    }
    out << "The Northern division:" << endl;
    for(int i = 0; i < size; i++) {
        out << i + 1 << " Quarter: " << div[2].qrtSales[i] << endl;
    }
    out << "The Southern division:" << endl;
    for(int i = 0; i < size; i++) {
        out << i + 1 << " Quarter: " << div[3].qrtSales[i] << endl;
    }
}