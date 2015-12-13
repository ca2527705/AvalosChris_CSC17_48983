/* 
 * File:   dice.h
 * Author: rcc
 *
 * Created on November 19, 2015, 11:49 AM
 */

#ifndef DICE_H
#define	DICE_H

class dice
{
    private:
        //holds the roll result
        int roll;
    public:
        void rolldice();//constructor
        int results()//inline function
        {return roll;}
};

#endif	/* DICE_H */

