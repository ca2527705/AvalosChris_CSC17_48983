/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: HMWK 11.9
 * Created on October 16, 2015, 6:21 PM
 */
//System libraries
#include <iostream>

using namespace std;

//User libraries

//Global Constants

//Function Prototypes
struct speaker
{
    string name;
    int phone;
    string topic;
    int fee;
};
  

//Fun starts here
int main(int argc, char** argv) {
    //set the array for the data to be entered into
    speaker bureau[10];
    int num,menu;
    
    //loop the menu
    do{
    cout<<"Choose the area you wish to visit: \n";
    cout<<"1:Input data\n"
           "2:Output data\n"
            "3:Change contents of a file\n"
            "4:Exit\n";
    cin>>menu;

    //display the menu
    switch(menu)
    {    

        case 1: //input the info
                cout<<"Input the file number of the person you wish to enter"<<endl;
                cin>>num;
                cout<<"Input information on client: "<<num<<endl;
                cout<<"enter a name "<<endl;
                cin>>bureau[num].name;
                cout<<"enter a fee"<<endl;
                cin>>bureau[num].fee;
                cout<<"enter a phone number"<<endl;
                cin>>bureau[num].phone;
                cout<<"enter thier topic"<<endl;
                cin>>bureau[num].topic;
                cout<<"Data stored\n";
                cout<<"returning to main menu"<<endl;
                break;
                
        case 2:
    
                //ask for the info
                cout<<"enter the number of the database you wish to vist\n";
                cin>>num;
                //display the info
                cout<<"Information on client: "<<num<<endl;
                cout<<"Name:"<<bureau[num].name<<endl;
                cout<<"Fee: "<<bureau[num].fee<<endl;
                cout<<"Phone Number: "<<bureau[num].phone<<endl;
                cout<<"Topic: "<<bureau[num].topic<<endl;
                cout<<"returning to main menu"<<endl;
                break;
        case 3:
            break;
    }
}    while(menu<=3);
cout<<"Goodbye"<<endl;

    return 0;
}

