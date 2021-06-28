/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
    Author: Jyro Jimenez
    Date:   June 23, 2021 5:00pm
    Purpose:Gadis Chapter 8 problem 7: Binary String Search
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
#include <cstring>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void sort(string [],int);
int print(string [],int);
int binSrch(string, int, string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins", "Smith", "Allen", "Griffin", "Stamey",
                               "Rose", "Taylor", "Johnson", "Allison", "Looney",
                               "Wolfe", "James", "Weaver", "Pore", "Rutherford",
                               "Javens", "Harrison", "Setzer", "Pike", "Holland"};
    char choice[20];
    int found = -1;
    
    //Initialize variables
    cout << "This is a program that utilizes binary search to find a specific name." << endl;
    cout << "Input the last name you want to search for: ";
    
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    sort(names,NUM_NAMES);
    found = print(names, NUM_NAMES);
    
    if(found >= 0) {
        cout << "The name " << choice << " was found in the index at " << found;
    }
    else {
        cout << "The name was not found in the index";
    }
    
    //Exit stage right
    return 0;
}

void sort(string names[], int NUM_NAMES) {
    for(int i = 0; i < NUM_NAMES-1; i++) {
        int idxMin = i;
        for(int j = i+1; j < NUM_NAMES; j++) {
            if(names[idxMin] > names[j]) {
                idxMin = j;
            }
        }
        string temp = names[i];
        names[i] = names[idxMin];
        names[idxMin] = temp;
    }
}

int print(string names[], int NUM_NAMES) {
    string choice;
    cin >> choice;
    
    int low, high, middle;
    low = 0;
    high = NUM_NAMES-1;
    do {
        middle = (low+high)/2;
        if(names[middle] == choice) {
            return middle;
        }
        else if(names[middle] < choice){
            low = middle + 1;
        }
        else {
            high = middle-1;
        }
    }
    while(high >= low);
}