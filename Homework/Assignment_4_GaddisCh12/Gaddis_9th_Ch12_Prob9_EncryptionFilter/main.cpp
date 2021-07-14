

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 12 2021
 * Purpose:  Gaddis Chapter 12 Problem 9 - File Encryption Filter
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void wrtTxt(fstream &,string);
void wrtBin(fstream &,string);
void encrypt(string &);
void prnt(string);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Open the Text and binary files
    fstream txtFile,binFile;
    txtFile.open("data.txt",ios::in|ios::out);
    binFile.open("data.bin",ios::in|ios::out|ios::binary);
    string input;
    
    ///Initialize
    cout << "Enter the sentence input: " << endl;
    
    //Input the sentences
    cin.clear();
    getline(cin, input);
    
    //Write to binary and text files
    encrypt(input);
    wrtTxt(txtFile,input);
    wrtBin(binFile,input);
    
    //Read back in the array, then print out
    cout << "The Encrypted Message is: " << endl;
    prnt(input);
    
    //Close the files
    txtFile.close();
    binFile.close();
    
    //Exit
    return 0;
}

void wrtBin(fstream &out, string input){
    int size = input.size();
    char *copy = new char[size];
    for(int i = 0; i < size; i++) {
        copy[i] = input[i];
    }
    out.write(reinterpret_cast<char  *>(copy), size*sizeof(char));
    delete []copy;
}

void wrtTxt(fstream &out, string input){
    int size = input.size();
    for(int i = 0 ,n = size ; i < n ; i++) {
        out << input[i];

    }
}

void encrypt(string &input){
    int size = input.size();
    char a;
    for(int i = 0 ,n = size ; i < n ; i++) {
        //Encrypt by changing char 10 steps less in ASCII
        if(input[i]  >= 'a' && input[i]<='z' || input[i]  >= 'A' && input[i]<='Z') {
            //convert the Lowercase to uppercase
            a = input[i] - 10 ;
            input[i] = a;
        }
    }
}

void prnt(string input) {
    int  size = input.size();
    for(int i = 0; i < size; i++) {
        cout << input[i];
    }
}