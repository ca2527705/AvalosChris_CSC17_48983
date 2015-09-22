/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: Fine the Mode in an Array
 * Created on September 21, 2015, 6:41 PM
 */

#include <iostream>

using namespace std;

//Function Prototypes
void SamAry (int);//Function to set up the array
void SrtAry (int [],int);//Function to call in the array
void ShwAry (const int[], int);//Function to show sorted numbers

int main(int argc, char** argv) {
    //Set up the Array
    const int SIZE = 6;
    int numbers[SIZE]={2,4,3,1,5,3};
    cout<<"The unsorted numbers in the array are:\n";
    //Cycles through the numbers one by one and prints them out
    for (int index=0; index<SIZE; index++)
        SamAry(numbers[index]);
    cout<<"\n";
    //Sort the Array
    SrtAry(numbers,SIZE);
    cout<<"The sorted Values are:\n";
    ShwAry(numbers, SIZE);

    return 0;
}

void SamAry (int num)
{
    cout<<num<<" ";
}

void SrtAry (int array[],int size)
{
    bool swap;
    int temp;
    
    do
    {
        swap=false;
        for (int count = 0; count<(size-1);count++)
        {
            if(array[count]>array[count+1])
            {
                temp=array[count];
                array[count]=array[count+1];
                array[count+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}      

void ShwAry (const int array[], int size)
{
    for (int count=0;count<size;count++)
        cout<<array[count]<<" ";
    cout<<endl;
}
        