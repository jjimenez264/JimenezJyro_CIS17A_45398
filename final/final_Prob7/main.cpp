/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on August 1 2021
 * Purpose:Final Problem 7: Menu
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
using namespace std;

//User Libraries
#include "random.h"
#include "sort.h"
#include "aug.h"
#include "bank.h"
#include "person.h"

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
//Function Prototypes
void menu();
//Problem 1
void prblm1();
//Problem 2
void prblm2();
//Problem 3
void prblm3();
//Problem 4
void prblm4();
//Problem 5
void prblm5();
int expRate();
int expHour();
//Problem 6
void prblm6();


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='6');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    //Set Random Seed
    srand(static_cast<unsigned int>(time(0)));
    //Initialize
    char n = 5;
    char rndseq[] = { 19, 34, 57, 79, 126};
    int ntimes = 100000;
    //Initialize class
    Prob1Random a(n,rndseq);
    //Random number set
    for(int i = 1; i <= ntimes; i++){
        a.randFromSet();
    }
    //Return Values
    int *x = a.getFreq();
    char *y = a.getSet();
    //Output frequency
    for(int i = 0; i < n; i++){
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    int count = 0;
    while(infile.get(*ch2)){
        cout<<*ch2;
        if(count == 14) {
            cout << endl;
            count = -1;
        }
        count++;
        ch2++;
    }
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc = rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            cout<<zc[i*15 + j];
        }
        cout << endl;
    }
    cout<<endl;
    delete []zc;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited tab;
    const int *naugT = tab.getTable();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT = tab.getAugTable();
    for(int i = 0; i < rows + 1; i++){
        for(int j = 0; j < cols + 1; j++){
            cout << augT[i*(1 + cols)+j] << " ";
        }
        cout << endl;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    //Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    //Driver Code
    SavingsAccount mine;
    for(int i=1;i<=10;i++){
        mine.Transaction((rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout << setprecision(2) << fixed;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total(0.10,7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive(0.10,7)
        <<" Recursive Calculation "<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 5
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm5(){
    cout << "Problem 5: Employee Class" << endl;
    cout << "Extra Credit to discuss making code better..." << endl;
    cout << "I changed the character properties to strings so that the user can input name and job title." << endl
         << "This is better in a way, as the user manually inputs the properties rather than pre-inputed properties." << endl
         << "In addition to this, I added exception handling for the hours and work rate inputed by the user." << endl
         << "I also changed the doable property for Tax(), cause no doubles and wasn't needed." << endl;
    //Declare
    string name, job;
    float rate;
    int hours;
    //Ask Questions
    cout << "What is the name of the employee: ";
    cin.ignore();
    getline(cin, name);
    cout << "What is their Job title?: ";
    getline(cin, job);
    //Exception Handling for Rate
    try {
        rate = expRate();
    }
    catch(int error) {
        cout << "The Inputed Hourly Rate " << rate << " is Invalid! Try Again..." <<endl;
        rate = expRate();
    }
    //Exception Handling for Hours
    try {
        hours = expHour();
    }
    catch(int error) {
        cout << "The Inputed Hours Worked " << rate << " is Invalid! Try Again..." <<endl;
        hours = expHour();
    }
    //Declare Class
    Employee person(name, job, hours, rate);
    //Calculate pay rate
    person.CalculatePay(rate, hours);
    cout << endl;
    //Output information
    person.toString();
}

int expRate() {
    int rate = 0;
    cout << "What is their Hourly Rate?: ";
    cin >> rate;
    if(rate > 0 && rate < 200) {
        return rate;
    }
    else {
        throw rate;
    }
    return rate;
}

int expHour() {
    int hours = 0;
    cout << "How many hours do you work?: ";
    cin >> hours;
    if(hours > 0 && hours < 84) {
        return hours;
    }
    else {
        throw hours;
    }
    return hours;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 6
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm6(){
    cout << "Problem 6: Conversions" << endl;
    //Output results for question 1
    cout << "1.) a.) 5.75 Base 10 --> 5.C         Base 16 --> 0101.1100              Base 2 --> 5.6                Base 8" << endl
         << "    b.) 0.9  Base 10 --> 0.E...6...  Base 16 --> 0.1110...0110...       Base 2 --> 0.7...1463...      Base 8" << endl
         << "    c.) 99.7 Base 10 --> 63.B...3... Base 16 --> 1100011.1011...0011... Base 2 --> 143.5463...1463... Base 8" << endl << endl;
    //Output results for question 2
    cout << "2.) a.) 0.1011100 x 2^3               = 0101 1100 | 0000 0000 | 0000 0000 | 0000 0011 = 5C000003" << endl
         << "    b.) 0.1110...0110... x 2^0        = 0111 0011 | 0011 0011 | 0011 0011 | 0000 0000 = 73333300" << endl
         << "    c.) 0.11000111011...0011... x 2^7 = 0110 0011 | 1011 0011 | 0011 0011 | 0000 0111 = 63B33307" << endl << endl;
    //Output results for question 3
    cout << "3.) a.) 5.C Base 16         --> 5C x 16^-1    = 8WD 4BP" << endl
         << "    b.) 0.E...6... Base 16  --> E666 x 16^4   = 16WD 16BP" << endl
         << "    c.) 63.B...3... Base 16 --> 63B333 x 16^4 = 24WD 16BP" << endl << endl;
    //Output results for question 4
    cout << "4.) a.) 8WD 4BP   * 4WD 0BP = 12WD 4BP" << endl
         << "    b.) 16WD 16BP * 4WD 0BP = 20WD 16BP" << endl
         << "    c.) 24WD 16BP * 4WD 0BP = 28WD 16BP" << endl << endl;
    //Output results for question 5
    cout << "5.) a.) 1.011100 x 2^2               = 0(100 0000 | 1)011 1000 | 0000 0000 | 0000 0000 = 40B80000" << endl
         << "    b.) 1.110...0110... x 2^-1       = 0(011 1111 | 0)110 0110 | 0110 0110 | 0110 0110 = 3F666666" << endl
         << "    c.) 1.1000111011...0011... x 2^6 = 0(100 0010 | 0)110 0111 | 0110 0110 | 0110 0110 = 42C76666" << endl << endl;
}