/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   account.h
 * Author: jyroj
 *
 * Created on July 14, 2021, 2:30 AM
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

struct bank {
    int num;
    float bal, *checks, *depo;
    string name;
    char *address;
};

#endif /* ACCOUNT_H */

