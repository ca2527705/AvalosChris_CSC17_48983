/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 21, 2015, 12:57 PM
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int answer;
    int roll;
    do{
    int roll1,roll2;
    srand(static_cast<int>(time(0)));
    roll1=(rand()%6)+1;
    roll2=(rand()%6)+1;
    cout<<"A "<<roll1<<" and a "<<roll2<<" was rolled\n";
    roll=roll1+roll2;
    cout<<"Your total is "<<roll<<endl;
    cout<<"Roll again? press 1 for yes"<<endl;
    cin>>answer;
    }while(answer==1);

    return 0;
}

