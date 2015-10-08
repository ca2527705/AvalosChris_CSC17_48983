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
int wrdcount(char *,char);//function to find amount of words
//Program starts here
int main(int argc, char** argv) {
    //Initialize the variables
    const int SIZE=101;
    char line[SIZE];
    char letter;
    int count=0,length;
    float word;
    
    cout<<"Enter a string up to 100 letters:\n";
    cin.getline(line,SIZE);
    
    //Repeat what was entered to the user
    cout<<"This is what you entered:\n";
    cout<<line<<endl;
    
    //Send it to the function and return the value to be used for the average
    int temp=wrdcount(line,SIZE);
    //length function
    length=strlen(line);
    //average amount of letters per word, using a float to get most accurate
    word=float((length-temp)/float(temp));
    
    
    cout<<"There are "<<temp<<" words in the sentence"<<endl;
    cout<<"There are an average of "<<word<<" letters per word"<<endl;   

    return 0;
}
//function used to find the amount of words in the entered sentence
int wrdcount(char *line,char SIZE){
    int count=0;
    int length;
        for (int i=0;i<SIZE;i++){
        if (*line==' ')
            count++;
        line++;
        }
    return count;
}


