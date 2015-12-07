/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float d=.14,w=.10125, cd=.5,e=.0023679;
    
    float vt=((8*w)/(3.14*e*pow(d,2)*cd));
    
    vt=sqrt(vt);
    
    float q=.5*e*pow(vt,2);
    
    cout<<vt<<endl;
    cout<<q<<endl;
    

    return 0;
}

