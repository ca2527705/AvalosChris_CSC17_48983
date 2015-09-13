/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: HMWK 4.10
 * Created on September 10, 2015, 10:34 AM
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
    //verify varaiables
    float total,units;
    //ask for amount wanted
    cout<<"How many units are being puchased?\n";
    cin>>units;
    cout<<setprecision(2)<<fixed;
    //calculate and produce reults according to amount wanted
    if (units<10)
        cout<<"Your total is $"<<99.00*units<<endl;
    else if (units>=10&&units<=19)
        cout<<"Your total is $"<<(99*units)*.8<<endl;
    else if (units>=20&&units<=49)
        cout<<"Your total is $"<<(99*units)*.7<<endl;
    else if (units>=50&&units<=99)
        cout<<"Your total is $"<<(99*units)*.6<<endl;        
    else if (units>=100)
        cout<<"Your total is $"<<(99*units)*.5<<endl;    
    return 0;
}

