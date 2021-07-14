

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 12 2021
 * Purpose:  Gaddis Chapter 12 Problem 10 - File Decryption Filter
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
void wrtTxt(fstream &,string, int);
void wrtBin(fstream &, string, int);
char *readBin(fstream &,int);
void wrtBin2(fstream &, int, char *);
void wrtTxt2(fstream &, int, char *);
void encrypt(string &, int);
char *decrypt(char *, int);
void prnt(string, int);
void prntChar(int, char *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Open the Text and binary files
    fstream txtFile,binFile,decryptTxt,decryptBin;
    txtFile.open("data.txt",ios::in|ios::out);
    binFile.open("data.bin",ios::in|ios::out|ios::binary);
    decryptTxt.open("decrypt.txt",ios::in|ios::out);
    decryptBin.open("decrypt.bin",ios::in|ios::out|ios::binary);
    string input;
    
    ///Initialize
    cout << "Enter the sentence input: " << endl;
    
    //Input the sentences
    cin.clear();
    getline(cin, input);
    int size = input.size();
    
    //Write to binary and text files
    encrypt(input,size);
    wrtTxt(txtFile,input,size);
    wrtBin(binFile,input,size);
    
    //Read back in the array, then print out
    cout << "The Encrypted Message is: " << endl;
    prnt(input, size);
    
    //Decrypt the encrypted message
    char *copy = new char[size];
    copy = readBin(binFile, size);
    char *finish = new char[size];
    finish = decrypt(copy, size);
    
    //Write decrypted to files
    wrtBin2(decryptBin, size, finish);
    wrtTxt2(decryptTxt, size, finish);
    
    //Output decrypted files
    cout << "The Decrypted message is: " << endl;
    prntChar(size, finish);
    
    //Delete the array
    delete []copy;
    delete []finish;
    
    //Close the files
    txtFile.close();
    binFile.close();
    
    //Exit
    return 0;
}

void wrtBin(fstream &out, string input, int size){
    char *copy = new char[size];
    for(int i = 0; i < size; i++) {
        copy[i] = input[i];
    }
    out.write(reinterpret_cast<char  *>(copy), size*sizeof(char));
    delete []copy;
}

void wrtTxt(fstream &out, string input, int size){
    for(int i = 0 ,n = size ; i < n ; i++) {
        out << input[i];

    }
}

char *readBin(fstream &in, int size) {
    //Initialize cursor and array
    long cursor = 0;
    char *array = new char[size];
    //Read file
    in.seekg(cursor,ios::beg);
    in.read(reinterpret_cast<char *>(array),size*sizeof(int));
    return array;
}

void wrtBin2(fstream &out, int size, char *copy) {
    out.write(reinterpret_cast<char  *>(copy), size*sizeof(char));
}

void wrtTxt2(fstream &out, int size, char *copy){
    for(int i = 0 ,n = size ; i < n ; i++) {
        out << copy[i];
    }
}

void encrypt(string &input, int size){
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

char *decrypt(char *copy, int size) {
    char *finish = new char[size];
    for(int i = 0 ,n = size ; i < n ; i++) {
        finish[i] = copy[i] + 10;
        if(finish[i] == '*') {
            finish[i] = ' ';
        }
    }
    return finish;
}

void prnt(string input, int size) {
    for(int i = 0; i < size; i++) {
        cout << input[i];
    }
    cout << endl;
}

void prntChar(int size, char *copy) {
    for(int i = 0 ,n = size ; i < n ; i++) {
        cout << copy[i];
    }
}