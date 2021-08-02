/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sort.h
 * Author: jyroj
 *
 * Created on July 27, 2021, 4:40 PM
 */

#ifndef SORT_H
#define SORT_H

#include <iostream> 
#include <cstring>
using namespace std;

class Prob2Sort {
private:
    char *index; //Index that is utilized
                //in the sort
public:
    Prob2Sort(){index=NULL;};                //Constructor
    ~Prob2Sort(){delete []index;};           //Destructor
    char *sortArray(char*,int,int,int,bool);      //Sorts a 2 dimensional array
                                             //represented as a 1 dim array
};

#endif /* SORT_H */

