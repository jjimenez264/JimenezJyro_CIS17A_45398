/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   July 26, 2021
    Purpose:Final Problem 2: Sorting
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;   //Library Name-space

//User Libraries
#include "sort.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execute code
int main() {
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    int count = 0;
    while(infile.get(*ch2)){
        cout<<*ch2;
        if(count == 14) {
            cout << endl;
            count = -1;
        }
        count++;
        ch2++;
    }
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc = rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            cout<<zc[i*15 + j];
        }
        cout << endl;
    }
    cout<<endl;
    delete []zc;
    return 0;
}