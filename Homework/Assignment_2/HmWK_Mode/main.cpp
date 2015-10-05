/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: Find the Mode in an Array
 * Created on September 21, 2015, 6:41 PM
 */
//System Programs
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
//User Programs

//Global constants

//Function Prototypes
void SamAry (int);//Function to set up the array
void SrtAry (int [],int);//Function to call in the array
void ShwAry (const int[], int);//Function to show sorted numbers
void Mode(int [], int);//Function to find mode
void mean (int [], int);//Function to find mean
void median (int[],int);//Function to find the median

int main(int argc, char** argv) {
    //Set up the Array
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE= 9;
    int i;
    int numbers[SIZE];
    cout<<"The unsorted numbers in the array are:\n";
      for( i=0; i<SIZE; i++){
        numbers[i]=rand()%9+1;   
    } 
    
    //Cycles through the numbers one by one and prints them out
    for (int index=0; index<SIZE; index++)
        SamAry(numbers[index]);
        cout<<"\n";  
    //Sort the Array
    SrtAry(numbers,SIZE);
    //Show the Array, now sorted
    cout<<"The sorted Values are:\n";
    ShwAry(numbers,SIZE);
    Mode(numbers,SIZE);
    mean (numbers, SIZE);
    median (numbers,SIZE);
    
    return 0;
}

void SamAry (int num)
{
    cout<<num<<" ";
}
//Function that sort array, sample from Gaddis 9th edition, page 467
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
//to show that values of the sorted array, also from gaddis
void ShwAry (const int array[], int size)
{
    for (int count=0;count<size;count++)
        cout<<array[count]<<" ";
    cout<<endl;
}

//I wont even begin to pretend like i came up with this myself
//Shamefully stolen from http://www.cplusplus.com/forum/beginner/116489/
//all credit for this function goes to them
void Mode(int array[],int size){
    int counter=1,max=0,mode=array[0];
    for (int pass=0;pass<size-1;pass++)
    {
        if(array[pass]==array[pass+1])
        {
            counter++;
            if(counter>max)
            {
                max=counter;
                mode=array[pass];
                
            }
        }else
            counter=1;
    }
    cout<<"The mode is: "<<mode<<endl;
}

void mean(int test[],int scores){
    //calculation for average scores
    int total;
    for (int scroll=0;scroll<scores;scroll++){
        total+=test[scroll];
    }
    float avrge=(float)total/(float)scores;
    cout<<"The mean is "<<avrge<<endl;
}
//reference to 
//http://stackoverflow.com/questions/20636914/c-mean-median-and-mode
void median(int array[], int size){
    //calculate the mean
    if(size % 2 != 0){//checks to see if the size of the array is an even number
        int temp = ((size+1)/2)-1;//takes the size, adds one,divides it by 2 and
        //then subtracts 1 and the number in that position is displayed
        cout << "The median is " << array[temp] << endl;
    }
    else{//if the array is even, there are two numbers that need to be displayed
        cout << "The median is "<< array[(size/2)-1] << " and " <<array[size/2]<< endl;
    }
}