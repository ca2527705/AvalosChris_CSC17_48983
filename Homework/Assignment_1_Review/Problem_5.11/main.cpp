/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: HMWK 5.11
 * Created on September 13, 2015, 1:25 PM
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
    //varify the varaiables
    float num_org,pop_num,num_days,predict,total=0;
    //Ask for input
    cout<<"Input the Starting size of the population. "
            "Cannot be less then 2\n";
    cin>>num_org;
    if (num_org>=2){
        cout<<"Input the Average Population increase.Cannot be less then or equal to 0\n";
        cin>>pop_num;
        if(pop_num>0){
            cout<<"Input the number days it will multiply. cannot be less then 1\n";
            cin>>num_days;
            if(num_days>=1){
                //loop it and show to outcome
                pop_num=pop_num/100;
                for(int count=1;count<=num_days;count++){
                    predict=(num_org+(pop_num*num_org));
                    total+=predict;
                    num_org=total;
                    cout<<setprecision(0)<<fixed;
                    cout<<"For day "<<count<<" "<<total<<endl;
                }
            }    else
                    cout<<"Improper Input"<<endl;
    }
        else
            cout<<"Improper Input"<<endl;
    }
    else
        cout<<"Improper Input"<<endl;
    return 0;
}

