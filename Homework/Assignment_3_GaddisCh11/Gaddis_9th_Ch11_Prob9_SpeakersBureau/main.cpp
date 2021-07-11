/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 9 2021
 * Purpose:Gaddis Chapter 11 Problem 9 - Speakers' Bureau
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Structure
struct speaker {
    string name, topic;
    int num;
    float fee;
};

//Function Prototypes
speaker *fillDat(int &);//Fill the Structure with Data
void prntMembr (speaker *, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    speaker *person;
    //Number of people speaking;
    int members, change;
    char choice;
    
    //Initialize data structure
    person = fillDat(members);
    
    cout << "Would you like to see the list of all the members? (y/n): ";
    cin >> choice;
    while(choice == 'y') {
        //Print members
        prntMembr(person, members);
        //Ask if they want to change something
        cout << "Would you like to change anything in the list? (y/n): ";
        cin >> choice;
        
        while(choice == 'y') {
            cout << "Which one would you like to change?" << endl;
            cout << "Enter the index of the one you would change: ";
            cin >> change;
            change -= 1;
            //Change specific one
            cin.ignore();
            //Input Name of speaker
            cout << "Input the name of the speaker: ";
            getline(cin, person[change].name);
            //Input speaking topic
            cout << "Input the speaking topic: ";
            getline(cin, person[change].topic);
            //Input speaker's telephone number
            cout << "Input the speaker's telephone number: ";
            cin >> person[change].num;
            //Input Fee required for speaker
            cout << "Input the speaker's fee: ";
            cin >> person[change].fee;
            //Validation
            if(person[change].fee < 0) {
                cout << "Negative numbers are not accepted" << endl
                     << "Input fee: ";
                cin >> person[change].fee;
            }  
            
            cout << "Would you like to change another one? (y/n): ";
            cin >> choice;
        }
        
        cout << "Would you like to see the list again (y/n): ";
        cin >> choice;
    }
    
    //Exit stage right!
    return 0;
}

speaker *fillDat(int &members){
    cout << "This Program keeps information about the speaking members." << endl;
    //Ask how many people are going to speak
    cout << "Please input the number of people speaking: ";
    cin >> members;
    
    //Allocate dynamic array
    speaker *person = new speaker[members];

    //loop to input data
    for(int i = 0; i < members; i++) {
        cin.ignore();
        //Input Name of speaker
        cout << "Input the name of the speaker: ";
        getline(cin, person[i].name);
        //Input speaking topic
        cout << "Input the speaking topic: ";
        getline(cin, person[i].topic);
        //Input speaker's telephone number
        cout << "Input the speaker's telephone number: ";
        cin >> person[i].num;
        //Input Fee required for speaker
        cout << "Input the speaker's fee: ";
        cin >> person[i].fee;
        //Validation
        if(person[i].fee < 0) {
            cout << "Negative numbers are not accepted" << endl
                 << "Input fee: ";
            cin >> person[i].fee;
        }
    }
    
    //Return what you filled
    return person;
}

void prntMembr (speaker *person, int members) {
    for(int i = 0; i < members; i++) {
        cout << "Member No." << i + 1 << "'s information is:" << endl;
        cout << "Name       : " << person[i].name << endl;
        cout << "Topic      : " << person[i].topic << endl;
        cout << "Tell Number: " << person[i].num << endl;
        cout << "Speaker Fee: " << person[i].fee << endl;
    }
}