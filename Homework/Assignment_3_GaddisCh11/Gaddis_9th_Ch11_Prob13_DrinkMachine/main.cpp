/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 8 2021
 * Purpose:Structure Drink Machine Simulator
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Structure
struct soda {
    string name;
    int price, stock;
};

//Function Prototypes
int totPay(soda buyer, int &total);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int size = 5;
    soda machine[size] = {"ola", 75, 20,
                          "Root Beer", 75, 20,
                          "Lemon-Lime", 75, 20,
                          "Grape Soda", 80, 20,
                          "Cream Soda", 80, 20};
    soda buyer;
    int total, totDiff, diff;
    bool active = true;
    total = diff = totDiff = 0;
    
    
    //Output menu
    while(active) {
        cout << "Cola" << setw(9) << "75" << setw(4) << machine[0].stock << endl;
        cout << "Root Beer" << setw(4) << "75" << setw(4) << machine[1].stock << endl;
        cout << "Lemon-Lime" << setw(3) << "75" << setw(4) << machine[2].stock << endl;
        cout << "Grape Soda" << setw(3) << "80" << setw(4) << machine[3].stock << endl;
        cout << "Cream Soda" << setw(3) << "80" << setw(4) << machine[4].stock << endl;
        cout << "Quit" << endl;
        //Input buyer choice
        cin.ignore();
        getline(cin,buyer.name);
        //End or not;
        if(buyer.name == "Quit") {
            active= false;
            // Stop Loop Here if Quit
            break;
        }
        //Input Money
        cin >> buyer.price;
        //Validate user input
        if(buyer.price > 100 || buyer.price < 0) {
            cout << "This amount is not accepted" << endl;
        }
        //Add Buyer's money
        totPay(buyer, total);
        //Output change
        for(int i = 0; i < size; i++) {
            if(buyer.name == machine[i].name) {
                //Calculate change
                diff = buyer.price - machine[i].price;
                cout << diff << endl;
                //calculate total change
                totDiff += diff;
                //calculate how much is in stock
                machine[i].stock--;
            }
        }
    }
    
    //Output total money spent
    total -= totDiff;
    cout << total << endl;

    //Exit stage right!
    return 0;
}

int totPay(soda buyer, int &total) {
    total += buyer.price;
}