/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   random.cpp
 * Author: jyroj
 * 
 * Created on July 27, 2021, 3:48 AM
 */

#include <iostream>
using namespace std;

#include "random.h"

Prob1Random::Prob1Random(char n , char *rndseq) {
    cout << "This Program counts the frequency of each number in a data set." << endl;
    //Set sequence and number of set
    set = rndseq;
    nset = n;
    numRand = 0;
    freq = new int;
    for(int i = 0; i < 5; i++) {
        freq[i] = 0;
    }
}

Prob1Random::~Prob1Random(void) {
    delete [] freq;
}

char Prob1Random::randFromSet(void) {
    int randNum = rand() % 5;
    freq[randNum]++;
    numRand++;
}

int *Prob1Random::getFreq(void) const {
    return freq;
}

char *Prob1Random::getSet(void) const {
    return set;
}

int Prob1Random::getNumRand(void) const {
    return numRand;
}