/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: HMWK 9.2
 * Created on September 29, 2015, 10:15 AM
 */
//System libraries
#include <iostream>

//User libraries

//Global Constants

//Function prototypes
float avrge (int);  

using namespace std;

//Starts here
int main(int argc, char** argv) {\
    //Set up the variables
    int scroll,scores,total;
    int *test;
    //Ask for the number of tests to be recorded
    cout<<"How many test scores do you want to enter?"<<endl;
    cin>>scores;
    //setup the dynamic array
    test=new int [scores];
    //Set up the loop to record the scores
    cout<<"Enter "<<scores<<" test scores\n";
    for (scroll=0;scroll<scores;scroll++){
        cin>>test[scroll];
    }
    //calculation for average scores
    for (scroll=0;scroll<scores;scroll++){
        total+=test[scroll];
    }
    float avrge=total/scores*1.0;
    //avrge(test);
    //Output the information to confirm
    cout<<"The numbers you entered were"<<endl;
    for (scroll=0;scroll<scores;scroll++){
        cout<<test[scroll]<<" ";
    }
    cout<<"\nThe Average is "<<avrge<<endl;
    
        
           

    return 0;
}

//float avrge(int test){
 //   float total;
  //  for (int count=0;count<test;count++)
   //     total+=test[count];
//}

