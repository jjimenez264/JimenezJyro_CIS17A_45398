/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aug.cpp
 * Author: jyroj
 * 
 * Created on July 27, 2021, 8:35 PM
 */

#include <iostream>    //Input/Output Library
#include <fstream>
using namespace std;   //Library Name-space

#include "aug.h"

Prob3Table::Prob3Table() {
    //Initialize Rows and Cols
    ifstream infile;
    infile.open("Problem3.txt",ios::in);
    rows = 5;
    cols = 6;
    //Initialize table;
    table = new int[rows*cols];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            infile >> table[i*cols+j];
        }
    }
    //Initialize rowSum
    rowSum = new int[rows];
    for(int i = 0; i < rows; i++){
        rowSum[i] = 0;
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            rowSum[i] += table[i*cols+j];
        }
    }
    //Initialize colSum
    colSum = new int[cols];
    for(int i = 0; i < cols; i++){
        colSum[i] = 0;
    }
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++) {
            colSum[i] += table[j*cols + i];
        }
    }
    //Initialize grand total
    grandTotal = 0;
    for(int i = 0; i < cols; i++){
        grandTotal += colSum[i];
    }
}

Prob3TableInherited::Prob3TableInherited() {   
    augTable = new int[(1+rows)*(1+cols)];
    for(int i = 0; i < rows + 1; i++){
        for(int j = 0; j < cols + 1; j++){
            if(i < rows && j < cols) {
                augTable[i*(1 + cols)+j] = table[i*cols+j];
            }
            else if(i < rows && j == cols) {
                augTable[i*(1 + cols)+j] = rowSum[i];
            }
            else if(i == rows) {
                if(j < cols) {
                    augTable[i*(1 + cols)+j] = colSum[j];
                }
                else {
                    augTable[i*(1 + cols)+j] = grandTotal;
                }
            }
        }
    }
}