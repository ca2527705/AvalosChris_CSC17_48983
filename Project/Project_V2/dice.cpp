#include "dice.h"
#include <iostream>
#include <ctime>
#include <cstdlib>



void dice::rolldice()
{    
    int roll1,roll2;
    
    roll1=(rand()%6)+1;
    roll2=(rand()%6)+1;
    
    roll=roll1+roll2;
        
};
