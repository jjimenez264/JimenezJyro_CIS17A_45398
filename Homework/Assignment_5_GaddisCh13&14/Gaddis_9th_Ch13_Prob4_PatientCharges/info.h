/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   info.h
 * Author: jyroj
 *
 * Created on July 23, 2021, 3:25 AM
 */

#ifndef INFO_H
#define INFO_H
#include <string>
using namespace std;

class Info {
private: 
    string first, middle, last, address, city, state, zip, phone, emgName, emgPhone;
public:
    Info();
    void display();
};
        

#endif /* INFO_H */

