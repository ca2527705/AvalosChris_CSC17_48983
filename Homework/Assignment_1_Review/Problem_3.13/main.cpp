/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: HMWK 3.13
 * Created on September 10, 2015, 10:25 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Program starts here
int main(int argc, char** argv) {
    
    //Identify the variable
    float ass_val,act_val,prop_tax;
    //Ask for the input
    cout<<"Please input the Value of the property\n";
    cin>>act_val;
    //Calculations
    ass_val=act_val*.60;
    prop_tax=(ass_val/100)*.64;
    //Output the results
    cout<<setprecision(2)<<fixed;
    cout<<"The actual value for the property is $"<<act_val<<endl;
    cout<<"The assessment value is set at $"<<ass_val<<endl;
    cout<<"The property Tax is $"<<prop_tax<<endl;
                   
    return 0;
}

