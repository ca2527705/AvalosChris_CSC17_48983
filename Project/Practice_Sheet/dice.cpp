#include "dice.h"
#include <iostream>
#include <ctime>
#include <cstdlib>



void dice::rolldice()
{    
    //two different rolls that are added together to equal the total
    int roll1,roll2;
    //srand is seeded here so i donty have to keep calling it when its out
    srand(time(0));
    roll1=(rand()%6)+1;
    roll2=(rand()%6)+1;
    //The two different rolls added together
    roll=roll1+roll2;
        
};
