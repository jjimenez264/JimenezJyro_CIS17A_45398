/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 16 2021
 * Purpose:Midterm Problem 8: Menu
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries
#include "account.h"
#include "company.h"
#include "digits.h"
#include "numPrimes.h"

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void menu();
//Problem 1
void prblm1();
bank *fillAcc(int &, int &);
float calcTot(bank *, int, int, float &, float &);
//Problem 2
void prblm2();
employee *inField(int);
void checkOut(employee *, int, string);
//Problem 3
void prblm3();
//Problem 4
void prblm4();
encrypt *inData(int);
decrypt *outData(int, encrypt *);
//Problem 5
void prblm5();
//Problem 6
void prblm6();
//Problem 7
void prblm7();
primes *calcPrime(unsigned short);
void prntPrm(primes *, int);

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
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
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
    cout<<"Type 4 for Problem 5"<<endl;
    cout<<"Type 4 for Problem 6"<<endl;
    cout<<"Type 4 for Problem 7"<<endl<<endl;
    
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    cout<<endl<<"Problem 1:"<<endl<<endl;
    //Declare Variable Data Types and Constants
    bank *account;
    int numChk, numDepo;
    float totChks, totDepo;
    
    //Initialize
    totChks = totDepo = 0;
    
    //input all fields
    cout << "This program determines the banking Account's balance." << endl;
    account = fillAcc(numChk, numDepo);
    
    //Calculate Deposits and Checks
    calcTot(account, numChk, numDepo, totChks, totDepo);
    
    //Calculate Balance
    account->bal = account->bal + totDepo - totChks;
    
    //Output Account's transactions
    cout << endl << "Account No." << account->num <<" Summary..." << endl;
    cout << "The Account's Total Checks amount to : $" << totChks << endl;
    cout << "The Account's Total Deposit amount to: $" << totDepo << endl;
    
    
    //If account is overdraw or not
    if(account->bal >= 0) {
        cout << "The Account's Total Balance amount to: $" << account->bal;
    }
    else if(account->bal < 0) {
        cout << "The Account's Total Balance amount to:-$" << account->bal*-1 <<endl;
        cout << "The Account's Balance is Overdrawn..." << endl
             << "A Debit of $50 is now needed..." << endl;
        account->bal -= 50;
        cout << "The New Account Balance is: -$" << account->bal*-1;
    }
    
    //Output End of program
    cout << endl << endl << "Thank you for choosing us " << account->name << "! Good Bye!";
    
    //Deallocate memory
    delete [] account->checks;
    delete [] account->depo;
    delete [] account->address;
    delete [] account;
}

bank *fillAcc(int &numChk, int &numDepo) {
    //Initialize dynamic array
    bank *a = new bank;
    a->checks = new float;
    a->depo = new float;
    
    //Input fields
    cout << "Please input the given fields for the program..." << endl;
    cout << "Account Number (5-Digit Num.): ";
    cin >> a->num;
    //Input Account name
    cout << "Account Holder's Name        : ";
    cin.ignore();
    getline(cin, a->name);
    //Allocate data for char array
    int size = 120; //Size for name and address
    a->address = new char[size];
    cout << "Account Holder's Address     : ";
    cin.getline(a->address, size  - 1);
    //Input Account Balance
    cout << "Account's Starting Balance   : $";
    cin >> a->bal;
    //Input No. of checks and the amount of each check
    cout << "Total No. of Checks Written  : ";
    cin >> numChk;
    cout << "Input Amount of Each Check Written..." << endl;
    for(int i = 0; i < numChk; i++) {
        cout << "Check " << i + 1 << ": $";
        cin >> a->checks[i];
    }
    //Input No. of deposits and the amount of deposit check
    cout << "Total No. of Deposits Written: ";
    cin >> numDepo;
    cout << "Input Amount of Each Check Written..." << endl;
    for(int i = 0; i < numDepo; i++) {
        cout << "Check " << i + 1 << ": $";
        cin >> a->depo[i];
    }
    
    //Return Value
    return a;
}

float calcTot(bank *a, int numChk, int numDepo, float &totChks, float &totDepo) {
    //Calculate total checks
    for(int i = 0; i < numChk; i++) {
        totChks += a->checks[i];
    }
    //Calculate total Deposits
    for(int i = 0; i < numDepo; i++) {
        totDepo += a->depo[i];
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<endl<<"Problem 2"<<endl<<endl;
    //Declare Variable Data Types and Constants
    employee *indiv;
    int numEmpl;
    string compName;
    
    //Initialize
    cout << "This Program determines the gross pay for any number of employees." << endl;
    
    //Ask For company name and input it
    cout << "What is the name of the Company?" << endl;
    cout << "Input name: ";
    cin.clear();
    getline(cin, compName);
    
    //Ask for the number of employees
    cout << "Please input the number of employees: ";
    cin >> numEmpl;
    
    //Initialize the structure array
    indiv = inField(numEmpl);
    
    //Output
    cout << endl;
    checkOut(indiv, numEmpl, compName);
    
    //Deallocate memory
    delete [] indiv;
}

employee *inField(int numEmpl) {
    //Initialize dynamic array
    employee *a = new employee[numEmpl];
    
    //Fill Each field
    for(int i = 0; i < numEmpl; i++) {
        cout << "Enter each field for Employee No." << i+1 << "..." << endl;
        cout << "Employee Name   : ";
        cin.ignore();
        getline(cin, a[i].name);
        cout << "No. Hours Worked: ";
        cin >> a[i].hours;
        cout << "Pay Rate in $/hr: ";
        cin >> a[i].payRate;
        //Validate User input for negatives
        if(a[i].hours < 0 || a[i].payRate < 0) {
            cout << "These are invalid inputs, and will not count" << endl;
            numEmpl = i;
        }
    }
    
    //Calculate total pay for each employee
    for(int i = 0; i < numEmpl; i++) {
        if(a[i].hours <= 20){
            a[i].totPay = a[i].payRate * a[i].hours;
        }
        else if(a[i].hours > 20 && a[i].hours <= 40) {
            a[i].totPay = a[i].payRate * 20;
            a[i].totPay += (a[i].payRate * ((a[i].hours - 20) * 2));
        }
        else if(a[i].hours > 40) {
            a[i].totPay = a[i].payRate * 20;
            a[i].totPay += (a[i].payRate * ((a[i].hours - 20) * 2));
            a[i].totPay -= (a[i].payRate * ((a[i].hours - 40) * 2));
            a[i].totPay += (a[i].payRate * ((a[i].hours - 40) * 3));
        }
    }
    
    //Return array
    return a;
}

void checkOut(employee *a, int numEmpl, string compName) {
    //Initialize numbers
    int num1, num2, num3, num4;
    cout << "Printing out Employee Checks..." << endl << endl;
    //Output employee checks
    for(int i = 0; i < numEmpl; i++) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Company: " << compName << endl;
        cout << "Name: " << a[i].name << "    Amount: $" << a[i].totPay << endl;
        cout << "Amount: ";
        //Calculate the 1000's, 100's, 10's and 1's
        //Had to take modulus in second step cause it wouldn't compile
        num1 = a[i].totPay;
        num1 = num1 % 10;
        num2 = a[i].totPay / 10;
        num2 = num2 % 10;
        num3 = a[i].totPay / 100;
        num3 = num3 % 10;
        num4 = a[i].totPay / 1000;
        num4 = num4 % 10;
        //Convert to English numerical Value
        //Thousands Place
        switch(num4) {
            case 1:
                cout << "One Thousand ";
                break;
            case 2:
                cout << "Two Thousand ";
                break;
            case 3:
                cout << "Three Thousand ";
                break;
            case 4:
                cout << "Four Thousand ";
                break;
            case 5:
                cout << "Five Thousand ";
                break;
            case 6:
                cout << "Six Thousand ";
                break;
            case 7:
                cout << "Seven Thousand ";
                break;
            case 8:
                cout << "Eight Thousand ";
                break;
            case 9:
                cout << "Nine Thousand ";
                break;
        }
        //Hundreths place
        switch(num3) {
            case 1:
                cout << "One Hundred ";
                break;
            case 2:
                cout << "Two Hundred ";
                break;
            case 3:
                cout << "Three Hundred ";
                break;
            case 4:
                cout << "Four Hundred ";
                break;
            case 5:
                cout << "Five Hundred ";
                break;
            case 6:
                cout << "Six Hundred ";
                break;
            case 7:
                cout << "Seven Hundred ";
                break;
            case 8:
                cout << "Eight Hundred ";
                break;
            case 9:
                cout << "Nine Hundred ";
                break;
        }
        //Tenths place depending on teen or not
        if (num2 == 1) {
            switch(num1) {
                case 0:
                    cout << "Ten ";
                    break;
                case 1:
                    cout << "Eleven ";
                    break;
                case 2:
                    cout << "Twelve ";
                    break;
                case 3:
                    cout << "Thirteen ";
                    break;
                case 4:
                    cout << "Fourteen ";
                    break;
                case 5:
                    cout << "Fifteen ";
                    break;
                case 6:
                    cout << "Sixteen ";
                    break;
                case 7:
                    cout << "Seventeen ";
                    break;
                case 8:
                    cout << "Eighteen ";
                    break;
                case 9:
                    cout << "Nineteen ";
                    break;
            }
        }
        else {
            switch(num2) {
                case 2:
                    cout << "Twenty ";
                    break;
                case 3:
                    cout << "Thirty ";
                    break;
                case 4:
                    cout << "Forty ";
                    break;
                case 5:
                    cout << "Fifty ";
                    break;
                case 6:
                    cout << "Sixty ";
                    break;
                case 7:
                    cout << "Seventy ";
                    break;
                case 8:
                    cout << "Eighty ";
                    break;
                case 9:
                    cout << "Ninety ";
                    break;
            }
            //Ones place
            switch(num1) {
                case 0:
                    cout << "";
                    break;
                case 1:
                    cout << "One ";
                    break;
                case 2:
                    cout << "Two ";
                    break;
                case 3:
                    cout << "Three ";
                    break;
                case 4:
                    cout << "Fourt ";
                    break;
                case 5:
                    cout << "Five ";
                    break;
                case 6:
                    cout << "Six ";
                    break;
                case 7:
                    cout << "Seven ";
                    break;
                case 8:
                    cout << "Eight ";
                    break;
                case 9:
                    cout << "Nine ";
                    break;
            }
        }
        //Output Signature line
        cout << "Dollars." << endl;
        cout << "Signature Line:__________________________________" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<endl<<"Problem 3"<<endl<<endl;
    cout<<"This project is in another File...." << endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    cout<<endl<<"problem 4"<<endl<<endl;
    //Declare Variable Data Types and Constants
    encrypt *in;
    decrypt *out;
    int input;
    
    //Initialize
    cout << "This program encrypts data then decrypts the data and outputs both instances." << endl;
    cout << "Please Input the Initial Data to encrypt..." << endl;
    cout << "Input 4-Digit Numbers (0-7): ";
    cin >> input;
    
    //Initialize encrypted data
    in = inData(input);
    out = outData(input, in);
    
    //Output encrypted Data
    cout << endl << "The Encrypted data is: " << in->digits << endl;
    cout << setw(14) << "and";
    cout << endl << "The Decrypted data is: " << out->digits << endl << endl;
    
    //Validate that decrypted code is right
    if(out->digits == input) {
        cout << "Decrypted data is right as the input and decryption are equal to each other..." << endl
             << out->digits << " = " << input;
    }
    
    //Deallocate memory
    delete [] in;
    delete [] out;
}

encrypt *inData(int input) {
    //Initialize a dynamic array
    encrypt *a = new encrypt;
    
    //Get individual numbers
    a->num1 = input % 10;
    a->num2 = input / 10 % 10;
    a->num3 = input / 100 % 10;
    a->num4 = input / 1000 % 10;
    
    //Encrypt each number
    a->num1 = (a->num1 + 6) % 8;
    a->num2 = (a->num2 + 6) % 8;
    a->num3 = (a->num3 + 6) % 8;
    a->num4 = (a->num4 + 6) % 8;
    
    //Add encrypted number to a single line
    a->digits = 0;
    a->digits += (a->num2 * 1000);
    a->digits += (a->num1 * 100);
    a->digits += (a->num4 * 10);
    a->digits += a->num3;
    
    //Return data
    return a;
}

decrypt *outData(int input, encrypt *in) {
    //Initialize a dynamic array
    decrypt *a = new decrypt;
    
    //Get individual numbers
    a->num1 = in->digits % 10;
    a->num2 = in->digits / 10 % 10;
    a->num3 = in->digits / 100 % 10;
    a->num4 = in->digits / 1000 % 10;
    
    //Encrypt each number
    a->num1 = (a->num1 - 6 + 8) % 8;
    a->num2 = (a->num2 - 6 + 8) % 8;
    a->num3 = (a->num3 - 6 + 8) % 8;
    a->num4 = (a->num4 - 6 + 8) % 8;
    
    //Add encrypted number to a single line
    a->digits = 0;
    a->digits += (a->num2 * 1000);
    a->digits += (a->num1 * 100);
    a->digits += (a->num4 * 10);
    a->digits += a->num3;
    
    //Return data
    return a;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 5
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm5(){
    cout<<endl<<"problem 5"<<endl<<endl;
    //Output results
    cout << "Problem 5: Outputing largest n for n! in each data type." << endl;
    cout << "Data Type" << setw(13) << "Largest n" << setw(10) << "Output" << endl;
    cout << "short" << setw(11) << "17!" << setw(16) << "-32768" << endl;
    cout << "Uns-short" << setw(7) << "17!" << setw(15) << "32768" << endl;
    cout << "int" << setw(13) << "33!" << setw(21) << "-2147483648" << endl;
    cout << "Uns-int" << setw(9) << "33!" << setw(20) << "2147483648" << endl;
    cout << "long" << setw(12) << "65!" << setw(30) << "-9223372036854775808" << endl;
    cout << "Uns-long" << setw(8) << "65!" << setw(29) << "-9223372036854775808" << endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 6
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm6(){
    cout<<endl<<"problem 6"<<endl<<endl;
    //Output results
    cout << "Problem 6: Outputs results for NASA Float conversion problems" << endl << endl;
    cout << "Convert to binary, octal, hex, then to NASA float:" << endl;
    cout << "A.) 1. 51.1875 base 10    = .1100110011 base 2 x 2^6  = 1100 1100 | 1100 0000 | 0000 0000 | 0000 0110 = CCC00006" << endl;
    cout << "       51.1875 base 10    = (HEX) 33.3 base 16   = (OCTAL) 63.14 base 8     = (BINARY) 110011.0011 base 2" << endl;
    cout << "    2. 3.19921875 base 10 = .1100110011 base 2 x 2^2  = 1100 1100 | 1100 0000 | 0000 0000 | 0000 0010 = CCC00002" << endl;
    cout << "       3.19921875 base 10 = (HEX) 3.33 base 16   = (OCTAL) 3.146 base 8     = (BINARY) 11.00110011 base 2" << endl;
    cout << "    3. 0.2 base 10        = .11..0011.. base 2 x 2^-1 = 1100 1100 | 1100 1100 | 1100 1100 | 1111 1110 = CCCCCCFE" << endl;
    cout << "       0.2 base 10        = (HEX) 0.3... base 16 = (OCTAL) 0.1463... base 8 = (BINARY) 0.0011... base 2" << endl << endl;
    cout << "Convert the same numbers to NASA float but they are negative:" << endl;
    cout << "B.) 1. -51.1875 base 10    = -.1100110011 base 2 x 2^6  = 0011 0011 | 0100 0000 | 0000 0000 | 0000 0110 = 33400006" << endl;
    cout << "    2. -3.19921875 base 10 = -.1100110011 base 2 x 2^2  = 0011 0011 | 0100 0000 | 0000 0000 | 0000 0010 = 33400002" << endl;
    cout << "    3. -0.2 base 10        = -.11..0011.. base 2 x 2^-1 = 0011 0011 | 0011 0011 | 0011 0100 | 1111 1110 = 333334FE" << endl << endl;
    cout << "Convert NASA Float to decimal numbers: " << endl;
    cout << "C.) 1. 69999902 = 1.10...1001... base 2 OR .0110...1001... base 2 x 2^2" << endl;
    cout << "    2. 69999902 = 11.0...1001... base 2 OR .0110...1001... base 2 x 2^3" << endl;
    cout << "    3. 966667FF = .0100101100110011001100111 base 2 OR .100101100110011001100111 base 2 x 2^-1" << endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 7
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm7(){
    cout<<endl<<"problem 7"<<endl<<endl;
    //Declare Variable Data Types and Constants
    primes *nums;
    unsigned short input;
    
    //Initialize
    cout << "This Program calculates the prime factors of a number." << endl;
    cout << "Input Number: ";
    cin >> input;
    
    //Dynamic array
    nums = calcPrime(input);
    
    //Output
    prntPrm(nums, input);
    
    //Deallocate memory
    delete [] nums->prime;
    delete [] nums;
}

primes *calcPrime(unsigned short num) {
    //Allocate memory
    primes *a = new primes;
    a->prime = new unsigned short;
    a->nPrimes = 0;
    
    //Calculate prime factors
    //Initial calculation to see if a prime is equal to 2
    while(num % 2 == 0){
        num = num / 2;
        a->prime[a->nPrimes] = 2;
        a->nPrimes++;
    }
    //Second calculation to see what other numbers are left
    for(unsigned int i = 3; i <= sqrt(num); i = i+2){
        while(num%i == 0){
            num = num / i;
            a->prime[a->nPrimes] = i;
            a->nPrimes++;
        }
    }
    //Last calculation to see last prime
    if(num > 2){
        a->prime[a->nPrimes] = num;
        a->nPrimes++;
    }
    
    return a;
}
void prntPrm(primes *nums, int input) {
    cout << "The Prime factors of the input is..." << endl;
    cout << input << " = ";
    //Output each individual prime number
    for(int i = 0; i < nums->nPrimes; i++) {
        cout << nums->prime[i];
        if(i != nums->nPrimes - 1) {
            cout << " * ";
        }
    }
    cout << endl;
}
