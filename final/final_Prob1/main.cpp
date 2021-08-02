/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   July 26, 2021
    Purpose:Final Problem 1: Random Sequence
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;   //Library Name-space

//User Libraries
#include "random.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes


//Execute code
int main() {
    //Set Random Seed
    srand(static_cast<unsigned int>(time(0)));
    //Initialize
    char n = 5;
    char rndseq[] = { 19, 34, 57, 79, 126};
    int ntimes = 100000;
    //Initialize class
    Prob1Random a(n,rndseq);
    //Random number set
    for(int i = 1; i <= ntimes; i++){
        a.randFromSet();
    }
    //Return Values
    int *x = a.getFreq();
    char *y = a.getSet();
    //Output frequency
    for(int i = 0; i < n; i++){
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    //End Code
    return 0;
}