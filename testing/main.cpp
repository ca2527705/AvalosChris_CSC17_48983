/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 19, 2015, 11:49 AM
 */
#include"dice.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;



int main(int argc, char** argv) {
    srand(static_cast<int>(time(0)));
    dice test;
    test.rolldice();
    cout<<"You rolled a "<<test.results()<<endl;
    return 0;
}

