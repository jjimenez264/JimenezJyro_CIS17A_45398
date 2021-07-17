/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 15 2021
 * Purpose:Midterm Problem 7: Primes
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries
#include "numPrimes.h"

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
primes *calcPrime(unsigned short);
void prntPrm(primes *, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    primes *nums;
    unsigned short input;
    
    //Initialize
    cout << "This Program calculates the prime factors of a number." << endl;
    cout << "Input Number: ";
    cin >> input;
    
    //Dynamic array
    nums = calcPrime(input);
    
    //Output
    prntPrm(nums, input);
    
    //Deallocate memory
    delete [] nums->prime;
    delete [] nums;
    
    //Exit stage right!
    return 0;
}

primes *calcPrime(unsigned short num) {
    //Allocate memory
    primes *a = new primes;
    a->prime = new unsigned short;
    a->nPrimes = 0;
    
    //Calculate prime factors
    //Initial calculation to see if a prime is equal to 2
    while(num % 2 == 0){
        num = num / 2;
        a->prime[a->nPrimes] = 2;
        a->nPrimes++;
    }
    //Second calculation to see what other numbers are left
    for(unsigned int i = 3; i <= sqrt(num); i = i+2){
        while(num%i == 0){
            num = num / i;
            a->prime[a->nPrimes] = i;
            a->nPrimes++;
        }
    }
    //Last calculation to see last prime
    if(num > 2){
        a->prime[a->nPrimes] = num;
        a->nPrimes++;
    }
    
    return a;
}
void prntPrm(primes *nums, int input) {
    cout << "The Prime factors of the input is..." << endl;
    cout << input << " = ";
    //Output each individual prime number
    for(int i = 0; i < nums->nPrimes; i++) {
        cout << nums->prime[i];
        if(i != nums->nPrimes - 1) {
            cout << " * ";
        }
    }
}
