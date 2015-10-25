/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: HMWK 10.6
 * Created on October 8, 2015, 10:38 AM
 */
//System libraries
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
//User libraries

//global constants

//Function prototypes
int vowels(char *, char);//function to find the vowels in the sentence
int consant(char *, char);//function to find the consanants

//Fun starts here
int main(int argc, char** argv) {
    //intialize the variables
    const int SIZE=101;
    char line[SIZE],answer;
    
    //Input the string
    cout<<"Enter a string up to 100 letters:\n";
    cin.getline(line,SIZE);
    //send it to the functions and then bring it right back
    int vow=vowels(line,SIZE);
    int con=consant(line,SIZE);
    //Present the menu
    do{
    cout<<"What would you like to do? Enter either A,B,C,D or E to exit"<<endl;
    cin>>answer;
    switch(answer){
        case 'a':
        case 'A':{      
            cout<<"There are "<<vow<<" vowels in the string you entered"<<endl;
                break;
        }
        case 'b':
        case 'B':{
        cout<<"There are "<<con<<" consonants in the string you entered"<<endl;
                break;
        }
        case 'c':
        case 'C':{
            cout<<"There are "<<con+vow<<" letters in the sentence"<<endl;
            break;
        }
        case 'd':
        case 'D':
        {
        cout<<"Enter a string up to 100 letters:\n";
        cin.getline(line,SIZE);
            break;
        }
        case 'e':
        case 'E':
        { cout<<"goodbye"<<endl;
        }
        default:    ;     
    } 

    }while (answer!='E'&&answer!='e');  
    
    return 0;
}

int vowels(char *i, char j){
    int times=0;
    while (*i!='\0'){
        if (*i=='a'||*i=='e'||*i=='i'||*i=='o'||*i=='u'||*i=='y')
            times++;
        i++;
    }
;
    return times;
    
}

int consant(char *i, char j){
    int times=0;
    while (*i!='\0'){
        if (!(*i=='a'||*i=='e'||*i=='i'||*i=='o'||*i=='u'||*i=='y'||*i==' '))
            times++;
        i++;
    }
;
    return times;
    
}
