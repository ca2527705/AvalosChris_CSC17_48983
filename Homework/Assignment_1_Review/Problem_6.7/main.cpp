/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: Hmwk 6.7
 * Created on September 13, 2015, 2:15 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float celsius(float);

//Program starts here
int main(int argc, char** argv) {
    //Verify the variable
    float f,C;
    //Create a loop for the function
    for(int f=0;f<=20;f++){
        //Call the function
        float C=celsius(f);
        //Display the results for every temp
        cout<<setprecision(2)<<fixed;
        cout<<f<<" Degres Fahrenheit = "<<C<<" Celsius"<<endl;
    }

    return 0;
}
//Function for converting Fahrenheit to Celsius
float celsius (float f){
    float C;
    C=(5.0/9.0)*(f-32);
    return C;
}

