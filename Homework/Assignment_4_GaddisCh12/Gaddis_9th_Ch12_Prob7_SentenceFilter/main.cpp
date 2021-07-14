

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 11 2021
 * Purpose:  Gaddis Chapter 12 Problem 7 - Sentence Filter
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
void wrtTxt(fstream &,string);
void wrtBin(fstream &,string);
void filter(string &);
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
    wrtTxt(txtFile,input);
    wrtBin(binFile,input);
    filter(input);
    
    //Read back in the array, then print out
    cout << "The filtered sentences is: " << endl;
    prnt(input);
    
    //Delete the array
    
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
}

void wrtTxt(fstream &out, string input){
    int size = input.size();
    for(int i = 0 ,n = size ; i < n ; i++) {
        out << input[i];

    }
}

void filter(string &input){
    int size = input.size();
    char a;
    //Capitalize first letter
    if(input[0]  >= 'a' && input[0] <= 'z') {
        a = input[0] - 32 ;
        input[0] = a;
    }
    for(int i = 1 ,n = size ; i < n ; i++) {
        //Check which ones to lower case and which one to upper case
        if(input[i]  >= 'a' && input[i]<='z' && input[i - 2] == '.') {
            //convert the Lowercase to uppercase
            a = input[i] - 32 ;
            input[i] = a;
        }
        else if(input[i]  >= 'A' && input[i]<='Z' && input[i - 2] != '.') {
            //convert the uppercase to lowercase
            a = input[i] + 32 ;
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