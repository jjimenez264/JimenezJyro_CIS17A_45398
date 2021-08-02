/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   July 27, 2021
    Purpose:Final Problem 3: Spreadsheet Stuff
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
#include <fstream>
using namespace std;   //Library Name-space

//User Libraries
#include "aug.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes


//Execute code
int main() {
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited tab;
    const int *naugT = tab.getTable();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT = tab.getAugTable();
    for(int i = 0; i < rows + 1; i++){
        for(int j = 0; j < cols + 1; j++){
            cout << augT[i*(1 + cols)+j] << " ";
        }
        cout << endl;
    }
    return 0;
}