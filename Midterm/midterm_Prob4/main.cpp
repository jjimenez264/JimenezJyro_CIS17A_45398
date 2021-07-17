/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 14 2021
 * Purpose:Midterm Problem 4: Encrypted Data and Decrypting it
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "digits.h"

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
encrypt *inData(int);
decrypt *outData(int, encrypt *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    encrypt *in;
    decrypt *out;
    int input;
    
    //Initialize
    cout << "This program encrypts data then decrypts the data and outputs both instances." << endl;
    cout << "Please Input the Initial Data to encrypt..." << endl;
    cout << "Input 4-Digit Numbers (0-7): ";
    cin >> input;
    
    //Initialize encrypted data
    in = inData(input);
    out = outData(input, in);
    
    //Output encrypted Data
    cout << endl << "The Encrypted data is: " << in->digits << endl;
    cout << setw(14) << "and";
    cout << endl << "The Decrypted data is: " << out->digits << endl << endl;
    
    //Validate that decrypted code is right
    if(out->digits == input) {
        cout << "Decrypted data is right as the input and decryption are equal to each other..." << endl
             << out->digits << " = " << input;
    }
    
    //Deallocate memory
    delete [] in;
    delete [] out;
    
    //Exit stage right!
    return 0;
}

encrypt *inData(int input) {
    //Initialize a dynamic array
    encrypt *a = new encrypt;
    
    //Get individual numbers
    a->num1 = input % 10;
    a->num2 = input / 10 % 10;
    a->num3 = input / 100 % 10;
    a->num4 = input / 1000 % 10;
    
    //Encrypt each number
    a->num1 = (a->num1 + 6) % 8;
    a->num2 = (a->num2 + 6) % 8;
    a->num3 = (a->num3 + 6) % 8;
    a->num4 = (a->num4 + 6) % 8;
    
    //Add encrypted number to a single line
    a->digits = 0;
    a->digits += (a->num2 * 1000);
    a->digits += (a->num1 * 100);
    a->digits += (a->num4 * 10);
    a->digits += a->num3;
    
    //Return data
    return a;
}

decrypt *outData(int input, encrypt *in) {
    //Initialize a dynamic array
    decrypt *a = new decrypt;
    
    //Get individual numbers
    a->num1 = in->digits % 10;
    a->num2 = in->digits / 10 % 10;
    a->num3 = in->digits / 100 % 10;
    a->num4 = in->digits / 1000 % 10;
    
    //Encrypt each number
    a->num1 = (a->num1 - 6 + 8) % 8;
    a->num2 = (a->num2 - 6 + 8) % 8;
    a->num3 = (a->num3 - 6 + 8) % 8;
    a->num4 = (a->num4 - 6 + 8) % 8;
    
    //Add encrypted number to a single line
    a->digits = 0;
    a->digits += (a->num2 * 1000);
    a->digits += (a->num1 * 100);
    a->digits += (a->num4 * 10);
    a->digits += a->num3;
    
    //Return data
    return a;
}