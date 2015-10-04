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
void arrSelectSort(int [],int);
void showArray(int [],int);
void showArrPtr(int [],int);

//Program starts here
int main(int argc, char** argv) {
    //const int NUM_DONATIONS= 15; //number of donations
    
    int NUM_DONATIONS;
    int *donations;
    
    //An Array containing the donation amounts.
    //int donations[NUM_DONATIONS]={5,100,5,25,10,5,25,5,5,100,10,15,10,5,10};
    //An array that allows them to enter however many they want
    cout<<"Enter the amount of donations you will receive\n";
    cin>>NUM_DONATIONS;
    //Set up the dynamnic array
    donations=new int [NUM_DONATIONS];
    //Set up the loop to hae them enter scores
    cout<<"Enter the amount for each donation\n";
        for (int scroll=0;scroll<NUM_DONATIONS;scroll++){
        cin>>donations[NUM_DONATIONS];
    }

    //An Array of pointers to int.
    //int *arrPtr[NUM_DONATIONS];
    
    //Each elements of arrPtr is a pointer to int. Make
    //each element point to an element in the donations array
    //for (int count =0; count < NUM_DONATIONS;count++)
        //arrPtr[count]= &donations[count];
    
    //sort the elements of the array of points
    arrSelectSort(donations, NUM_DONATIONS);
    
    //Display the donations using the array of pointers. This
    //will display them in sorted order
    cout<<"The donations, sorted in ascending order, are: \n";
    showArrPtr(donations,  NUM_DONATIONS);
    
    //Display the donation in thier original order
    cout<<"The donations, in thier original order, are:\n";
    showArray(donations, NUM_DONATIONS);
    return 0;
}

void arrSelectSort(int donation[], int size)
{
    int startScan, minIndex;
    int minElem;
    
    for (startScan =0; startScan<(size-1); startScan++)
    {
        minIndex = startScan;
        minElem= donation[startScan];
        for(int index = startScan+1; index<size; index++)
        {
            if ((donation[index])<minElem)
            {
                minElem=donation[index];
                minIndex= index;   
            }       
        }
        donation[minIndex]=donation[startScan];
        donation[startScan]=minElem;
    }
}

void showArray(int donations[],int size)
{
    for (int count=0;count<size;count++)
        cout<<donations[count]<<" ";
    cout<<endl;
}

void showArrPtr(int arr[], int size)
{
    for (int count=0;count<size;count++)
        cout<<arr[count]<<" ";
    cout<<endl;
}