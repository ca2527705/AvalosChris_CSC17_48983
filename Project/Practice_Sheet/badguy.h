/* 
 * File:   badguy.h
 * Author: rcc
 *
 * Created on December 9, 2015, 1:11 PM
 */

#ifndef BADGUY_H
#define	BADGUY_H

class badguy
{
private:
    
    int bad_hp;
    int bad_dmg;
    int bad_attk;
    int bad_def;
    
public:
    
    int set_hp(){
    bad_hp=20;
    return bad_hp;
    }
//    void set_dmg;
//    void set_attk;
//    void set_def;     
    
};



#endif	/* BADGUY_H */

