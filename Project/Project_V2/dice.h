/* 
 * File:   dice.h
 * Author: Christopher Avalos
 *
 * Created on November 19, 2015, 11:49 AM
 */

//This class is supposed to be combined with the dice main file in
//order to be useable

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

