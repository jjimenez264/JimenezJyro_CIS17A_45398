/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   proced.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 3:48 AM
 */

#ifndef PROCED_H
#define PROCED_H
#include <string>
using namespace std;

struct procedures {
    string namePro, datePro, doctr;
    int chrg;
};

class Proced {
private:
    procedures *a;
    int size;
public:
    Proced();
    ~Proced();
    void display();
    procedures *fill();
};

#endif /* PROCED_H */

