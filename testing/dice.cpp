#include "dice.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {
    
    int answer;
    int roll,roll1,roll2;
    srand(static_cast<int>(time(0)));
    roll1=(rand()%6)+1;
    roll2=(rand()%6)+1;
    roll=roll1+roll2;
        
    return roll;
};

int dice::results()
{
    return roll;
}