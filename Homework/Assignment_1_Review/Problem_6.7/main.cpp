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
    
    float f,cel,C;
    cin>>f;
    cel=celsius(f);
    //C=(5.0/9.0)*(f-32);
    cout<<setprecision(2)<<fixed;
    cout<<C<<endl;

    return 0;
}

float celsius (float f){
    float C;
    C=(5.0/9.0)*(f-32);
    return C;
}

