/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Problem 3.12
 * Created on September 10, 2015, 9:17 AM
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
    
    //identify the variables
    string month;
    float year, total, sales, state_tx=.04, count_tx=.02,sale_tx;
    
    //Ask for the different things needed
    cout<<"Please input the month\n";
    cin>>month;
    cout<<"Please input the year\n";
    cin>>year;
    cout<<"Please input the total amount collected at the cash register\n";
    cin>>total;
    //Run the calculations
    sales=total/1.06;
    count_tx=sales*count_tx;
    state_tx=sales*state_tx;
    sale_tx=count_tx+state_tx;
    //Output the Results
    cout<<"The month is "<<month<<endl;
    cout<<"----------------\n";
    cout<<setprecision(2)<<fixed;
    cout<<"Total Collected: "<<total<<endl;
    cout<<"Sales: "<<sales<<endl;
    cout<<"County Sales Tax: "<<count_tx<<endl;
    cout<<"State Sales Tax: "<<state_tx<<endl;
    cout<<"Total Sales Tax: "<<sale_tx<<endl;

    return 0;
}

