/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: HmWK 7.6
 * Created on September 13, 2015, 10:01 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Program starts here
int main(int argc, char** argv) {
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE];
    int count = 0;
    ifstream inputFile;
    int number;
    
    //Open the file.
    inputFile.open("numbers.txt");
    while(count<ARRAY_SIZE && inputFile >> numbers[count])
        count++;
    
    //close the file
    inputFile.close();
    
    //Display the numbers read:
    cout<<"The numbers are: ";
    for (count=0;count<ARRAY_SIZE;count++){
        cout<<numbers[count]<<" ";

    }
    cout<<endl;
    int total=0;
    for (int count =0;count<ARRAY_SIZE;count++)
        total+=numbers[count];
    cout<<"The total of the numbers is "<<total<<endl;
    cout<<"The Average is "<<total/ARRAY_SIZE<<endl;
    
    int highest;
    highest=numbers[0];
    for (count = 1;count<ARRAY_SIZE;count++)
    {
        if (numbers[ARRAY_SIZE]<highest)
            highest = numbers[count];
    
    }
    cout<<"The highest number is "<<highest<<endl;
    int lowest;
    lowest=numbers[0];
    for (count = 1;count<ARRAY_SIZE;count++)
    {
        if (numbers[ARRAY_SIZE]>lowest)
            lowest = numbers[count];
    }
    cout<<"The lowest number is "<<lowest<<endl;
    

    return 0;
}

