/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   random.h
 * Author: jyroj
 *
 * Created on July 27, 2021, 3:48 AM
 */

#ifndef RANDOM_H
#define RANDOM_H

class Prob1Random {
private:
    char *set; //The set of numbers to draw random numbers from
    char nset; //Number of variables in the sequence
    int *freq; //Frequency of all the random numbers returned
    int numRand; //The total number of times the random number
public:
    Prob1Random(char, char *);//Constructor
    ~Prob1Random(void); //Destructor
    char randFromSet(void); //Returns a random number from the set
    int *getFreq(void) const; //Returns the frequency histogram
    char *getSet(void) const; //Returns the set used
    int getNumRand(void) const; //Gets the number of times randFromSet
};

#endif /* RANDOM_H */

