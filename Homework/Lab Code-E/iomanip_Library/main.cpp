/* 
 * Author: Jyro Jimenez
 * Date: June 27, 2021
 * Purpose: Hello World Program
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float inOne,
          inTwo,
          inThree,
          inFour;
    
    //Initialize or input data here
    cin >> inOne;
    cin >> inTwo;
    cin >> inThree;
    cin >> inFour;
        
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    cout << "        " << inOne << "       " << setprecision(1) << fixed << inOne << "      " << setprecision(2) << fixed << inOne << endl;
    cout << "        " << setprecision(0) << fixed << inTwo << "       " << setprecision(1) << fixed << inTwo << "      " << setprecision(2) << fixed << inTwo << endl;
    cout << "        " << setprecision(0) << fixed << inThree << "       " << setprecision(1) << fixed << inThree << "      " << setprecision(2) << fixed << inThree << endl;
    cout << "        " << setprecision(0) << fixed << inFour << "       " << setprecision(1) << fixed << inFour << "      " << setprecision(2) << fixed << inFour;
    
    //Format and display outputs here
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}