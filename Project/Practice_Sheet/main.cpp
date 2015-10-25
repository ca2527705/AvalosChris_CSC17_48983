/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Subject: Second Project
 * Created on October 12, 2015, 4:00 PM
 */
//System Libraries
#include <iostream>//basic cin/cout usage
#include <cstdlib>//To use the rand
#include <ctime>//For use in the rand
#include <fstream>//For use in the file in/out
#include <string>//For use in the name
using namespace std;

//user libraries

//global constants
struct player
{
    string name;    //player name
    int pow;    //players power
    int def;    //players defensive stat
    int attk;   //players attack value
};
//function prototypes
void intro(player *info);
void battle(player *info);
short dice(int);



//The fun starts here!
int main(int argc, char** argv) {
    
    fstream filein;
    
    
    filein.open("Your_Stats.dat", ios::in);
    if(filein.fail())
    {
        cout<<"Oops"<<endl;
    }
    else
    {
        string input;
        getline(filein, input);
        while(filein){
            cout<<input<<endl;
            getline(filein,input);
        }
        filein.close();
    }
    
    
            

            
    return 0;
}
