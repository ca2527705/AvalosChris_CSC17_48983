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
    bad_hp=15;
    return bad_hp;
    }
    int set_dmg(){
    bad_dmg=10;    
    return bad_dmg;    
    };
    int set_attk(){
    bad_attk=5;    
    return bad_attk;    
    };
    int set_def(){
    bad_def=12;    
    return bad_def;
    };     
    
};



#endif	/* BADGUY_H */

