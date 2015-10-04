/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Purpose: HMWK 9.6
 * Created on October 3, 2015, 5:51 PM
 */

//System libraires
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function Prototypes
void arrSelectSort(int *[],int);
void showArray(const int [],int);
void showArrPtr(int *[],int);

//Program starts here
int main(int argc, char** argv) {
    const int NUM_DONATIONS= 15; //number of donations
    
    //An Array containing the donation amounts.
    int donations[NUM_DONATIONS]={5,100,5,25,10,5,25,5,5,100,10,15,10,5,10};
    //An Array of pointers to int.
    int *arrPtr[NUM_DONATIONS];
    
    //Each elements of arrPtr is a pointer to int. Make
    //each element point to an element in the donations array
    for (int count =0; count < NUM_DONATIONS;count++)
        arrPtr[count]= &donations[count];
    
    //sort the elements of the array of points
    arrSelectSort(arrPtr, NUM_DONATIONS);
    
    //Display the donations using the array of pointers. This
    //will display them in sorted order
    cout<<"The donations, sorted in ascending order, are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);
    
    //Display the donation in thier original order
    cout<<"The donations, in thier original order, are:\n";
    showArray(donations, NUM_DONATIONS);
    return 0;
}

void arrSelectSort(int *arr[], int size)
{
    int startScan, minIndex;
    int *minElem;
    
    for (startScan =0; startScan<(size-1); startScan++)
    {
        minIndex = startScan;
        minElem= arr[startScan];
        for(int index = startScan+1; index<size; index++)
        {
            if (*(arr[index])>*minElem)
            {
                minElem=arr[index];
                minIndex= index;   
            }       
        }
        arr[minIndex]=arr[startScan];
        arr[startScan]=minElem;
    }
}

void showArray(const int arr[],int size)
{
    for (int count=0;count<size;count++)
        cout<<arr[count]<<" ";
    cout<<endl;
}

void showArrPtr(int *arr[], int size)
{
    for (int count=0;count<size;count++)
        cout<<*arr[count]<<" ";
    cout<<endl;
}