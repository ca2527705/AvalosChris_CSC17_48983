/*
 * File:   main.cpp
 * Author: Christopher Avalos
 */
#include <cmath>
#include <iostream>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

        
    int d=14,w=10125, cd=5,e=2368;
    
    int vt=(((8*w))/((3.14*e*pow(d,2)*cd)/100))*10000;
    
    vt=sqrt(vt);
    
    cout<<vt<<endl;
    
    int q=((e*(pow(vt,2)))/2)/1000000;
    cout<<q<<endl;
    
    return 0;
}
