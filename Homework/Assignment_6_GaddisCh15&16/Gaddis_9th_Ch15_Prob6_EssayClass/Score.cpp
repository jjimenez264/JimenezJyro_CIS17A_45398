/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Score.cpp
 * Author: jyroj
 * 
 * Created on July 26, 2021, 1:29 AM
 */

#include <iostream>
using namespace std;

#include "Score.h"

score::score() {
    cout << "This program inputs student scores and output if they passed or failed." << endl;
    cout << "Input Each field for student's score..." << endl;
    cout << "Grammar Score     (0-30): ";
    cin >> grammar;
    //Validation
    if(grammar > 30 || grammar < 0) {
        cout << "Invalid Score! Try Again: ";
        cin >> grammar;
    }
    cout << "Spelling Score    (0-20): ";
    cin >> spell;
    //Validation
    if(spell > 20 || spell < 0) {
        cout << "Invalid Score! Try Again: ";
        cin >> spell;
    }
    cout << "Word Length Score (0-20): ";
    cin >> length;
    //Validation
    if(length > 20 || length < 0) {
        cout << "Invalid Score! Try Again: ";
        cin >> length;
    }
    cout << "Content Score     (0-30): ";
    cin >> content;
    //Validation
    if(content > 30 || content < 0) {
        cout << "Invalid Score! Try Again: ";
        cin >> content;
    }
}

PassFail::PassFail() {
    minPass = 70;
    totScore = grammar + spell + length + content;
}

void PassFail::display() {
    cout << endl << "The Total Score of the student has been graded." << endl;
    cout << "Score: " << totScore << "/100" << endl;
    if(totScore >= minPass) {
        cout << "The Student has Passed the class with a letter grade of a(n) ";
        if(totScore >= 70 && totScore < 80) {
            cout << "C";
        }
        else if(totScore >= 80 && totScore < 90) {
            cout << "B";
        }
        if(totScore >= 90 && totScore <= 100) {
            cout << "A";
        }
    }
    else {
        cout << "The Student did not pass,as the grade is less than 70.";
    }
    cout << endl;
}