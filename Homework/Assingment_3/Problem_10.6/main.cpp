/* 
 * File:   main.cpp
 * Author: rcc
 *
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
    char line[SIZE];
    
    //Input the string
    cout<<"Enter a string up to 100 letters:\n";
    cin.getline(line,SIZE);
    
    vowels(line,SIZE);
    consant(line,SIZE);
    

    return 0;
}

int vowels(char *i, char j){
    int times=0;
    while (*i!='\0'){
        if (*i=='a'||*i=='e'||*i=='i'||*i=='o'||*i=='u'||*i=='y')
            times++;
        i++;
    }
    cout<<"There are "<<times<<" vowels in the string you entered"<<endl;
    return times;
    
}

int consant(char *i, char j){
    int times=0;
    while (*i!='\0'){
        if (!(*i=='a'||*i=='e'||*i=='i'||*i=='o'||*i=='u'||*i=='y'||*i==' '))
            times++;
        i++;
    }
    cout<<"There are "<<times<<"consonants in the string you entered"<<endl;
    return times;
    
}