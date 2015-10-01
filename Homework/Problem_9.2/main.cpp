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
float avrge (int[],int);
int sort(int[],int);

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
    cout<<"Be sure they are all positive numbers"<<endl;
    if (scores<0)
        cout<<"Cannot acccept negative numbers"<<endl;
    else{
    for (scroll=0;scroll<scores;scroll++){
        cin>>test[scroll];
    }
    }    
    
    //Output the information to confirm
    cout<<"The numbers you entered were"<<endl;
    for (scroll=0;scroll<scores;scroll++){
        cout<<test[scroll]<<" ";
    }
    cout<<endl;
    //bubble sort function
    sort(test,scores);
    
    //Average scores function
    avrge(test, scores);

    return 0;
}

float avrge(int test[],int scores){
    //calculation for average scores
    int total;
    for (int scroll=0;scroll<scores;scroll++){
        total+=test[scroll];
    }
    float avrge=(float)total/(float)scores;
    cout<<"The Average is "<<avrge<<endl;
    return 0;
}

//bubble sort
int sort(int test[],int scores){
    bool swap;
    int temp;
    
    do
    {
        swap=false;
        for (int count=0;count<(scores-1);count++)
        {
            if (test[count]>test[count+1])
            {
                temp=test[count];
                test[count]=test[count+1];
                test[count+1]=temp;
                swap=true;
            }
        }
    } while(swap);
    cout<<"The scores sorted are: "<<endl;
    for (int count=0; count<scores;count++)
        cout<<test[count]<<" ";
    cout<<endl;
}

       
    


