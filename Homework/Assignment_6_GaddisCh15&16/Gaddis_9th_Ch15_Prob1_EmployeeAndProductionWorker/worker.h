/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   worker.h
 * Author: jyroj
 *
 * Created on July 25, 2021, 10:16 PM
 */

#ifndef WORKER_H
#define WORKER_H
#include <string>
using namespace std;

//BaseClass
class employee {
protected:
    string empName, phoneNum, hireDate;
public:
    employee();
};
//DerivedClass
class productionWorker: public employee {
private:
    int shift;
    float hourPay;
public:
    productionWorker();
    void display();
};

#endif /* WORKER_H */

