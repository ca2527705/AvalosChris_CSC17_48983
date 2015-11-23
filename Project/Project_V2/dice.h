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
        int roll;
    public:
        void rolldice();
        int results(){return roll;}
};

#endif	/* DICE_H */

