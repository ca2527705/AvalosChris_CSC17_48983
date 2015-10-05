/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: HMWK 10.4
 * Created on October 5, 2015, 9:17 AM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void wrdcount(char *,char);

//Program starts here
int main(int argc, char** argv) {
    const int SIZE=101;
    char line[SIZE];
    char letter;
    int count=0;
    int length;
    
    cout<<"Enter a string up to 100 letters:\n";
    cin.getline(line,SIZE);
    
    cout<<"This is what you entered:\n";
    while(line[count]!='\0'){
        cout<<line[count];
        count++;           
    }

    wrdcount(line,SIZE);
    

    

    return 0;
}

void wrdcount(char *line,char SIZE){
    int count=0;    
        for (int i=0;i<SIZE;i++){
        if (*line==' ')
            count++;
        line++;
        }
    cout<<"\nThere are "<<count+1<<" words in the sentence"<<endl;
}

