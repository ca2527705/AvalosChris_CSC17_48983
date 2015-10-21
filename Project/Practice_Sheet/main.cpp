/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 21, 2015, 1:09 PM
 */

#include <iostream>//basic cin/cout usage
#include <cstdlib>//To use the rand
#include <ctime>//For use in the rand
#include <fstream>//For use in the file in/out
#include <string>//For use in the name
using namespace std;

struct practice
{
    int pow;
};
/*
 * 
 */
int main(int argc, char** argv) {
    practice exam;
    
    
    int pow=13;
    
    exam.pow=pow;
    
    cout<<exam.pow<<endl;
    
    
    
    
    

    return 0;
}

