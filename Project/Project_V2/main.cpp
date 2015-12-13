/* 
 * File:   main.cpp
 * Author: Christopher Avalos
 * Subject: Second Project
 */
//System Libraries
#include "badguy.h"//computer class
#include "dice.h"//My dice rolling class
#include <iostream>//basic cin/cout usage
#include <cstdlib>//To use the rand
#include <ctime>//For use in the rand
#include <fstream>//For use in the file in/out
#include <string>//For use in the name
using namespace std;

//user libraries

//global constants

//function prototypes

struct player   //Structure used to hold all of the players information
                //this information in this structure will be passed between the
                //different functions
{
    string name;//player name, keep it under 50 letters
    int pow;    //players power
    int def;    //players defensive stat
    int attk;   //players attack value
};

void intro(player *info);   //function that holds the initial player setup
void battle(player *info);  //function used for the different fight segements



//The fun starts here!
int main(int argc, char** argv) {
    //define the variables
    player *info = new player; //setup for the structure to be used
    
    short pow,def,attk,PlayHp;
    
    intro(info);
    
    battle(info);
            
    return 0;
}

void intro(player *info){
    //Mostly variables involving dice rolls and the random generator
    //rolls using D6
    srand(time(0));//Used to determine the stats
    //for file in/out
    char answer;
    ofstream fileout;
    fstream filein;
    //Creating the character stats
    cout<<"Hello! Please enter the player name\n";//Player enters their name
    getline(cin, info->name);                       
    cout<<"Welcome "<<info->name<<"!\n";//Their name will be repeated throughout
                                        //the game
    cout<<"Let checks and see if you have any files saved on here"<<endl;
    filein.open("Your_Stats.dat", ios::in);
    if(filein.fail())//checks to see if a previous file with the information is one here
    {
        cout<<"Doesn't look like you do..."<<endl;//if there isnt, this message
        //is displayed letting them know
    }
    else//if there is, this message will pop and read off their stats they used
        //before
    {
        cout<<"Looks like theres something here, these are the stats used last "
                "time\n";
        string input;
        getline(filein, input);
        while(filein){
            cout<<input<<endl;
            getline(filein,input);
        }
        filein.close();
    }
    cout<<"Keep these stats in mind if you want to use them again\n";  
    //Gives them an option to either roll randomly for their stats or to input
    //their own
    cout<<"Would you like to roll randomly for your stats or assign your own?\n";
    cout<<"Enter either Y for yes, or n to input your own\n";
    
    cin>>answer;
    //If they answer yes, Character creation is random using a 3 sided die and
    //added to the minimum modifier
    if (answer=='Y'||answer=='y'){
        do{
        cout<<"The following rolls will see what kind of stats you have"<<endl;
        //uses 3 sided die plus minimum result-1
        info->pow =(rand()%3)+11; //pow is rolled and placed into the structure
        info->def=(rand()%3)+14;  //def is rolled and placed into the structure
        info->attk=(rand()%3)+6;  //attk is rolled and placed into the structure
        //show them the random results
        //all this information is called back from the function
        cout<<"Your Attack modifier is "<<info->attk<<endl;       
        cout<<"Your Defense is "<<info->def<<endl;
        cout<<"Your Pow is "<<info->pow<<endl;
        //Give them the option to reroll if they want
        cout<<"Are you okay with these stats?"<<endl;
        cout<<"Enter Y to accept and N to enter new stats"<<endl;
        cin>>answer;
        }while (answer=='n'||answer=='N');
    }
    //If they decide to put in their own stats, they will have to be within
    //a resonable range in order to prevent them from being "over powered"
    //The player will be asked to input entire for their pow, def, and attk
    else if (answer=='n'||answer=='N'){
        cout<<"Please input your desired stats as requested\n";
        //If they put in an improper value, then ask them to but it in again
        do{
        cout<<"For your pow, enter a number between 10 and 16\n";
        cin>>info->pow;
        while (info->pow<10||info->pow>15){
            cout<<"Input a number between or equal to 10 and 16\n";
            cin>>info->pow; 
        }
        cout<<"For your def, enter a number between or equal to 14 and 16\n";
        cin>>info->def;
        while (info->def<14||info->def>16){
            cout<<"Input a number between 14 and 16\n";
            cin>>info->def;
        }
        cout<<"For your Attk, enter a number between or equal to 7 and 9\n";
        cin>>info->attk;
        while (info->attk<7||info->attk>9){
            cout<<"Input a number between or equal to 7 and 9\n";
            cin>>info->attk;
        }
        //show them their choosen results
        cout<<"These are your choosen stats: "<<endl;
        cout<<"Your Pow is "<<info->pow<<endl;
        cout<<"Your Def is "<<info->def<<endl;
        cout<<"Your Attk is "<<info->attk<<endl;
        //Give them the option to re input their stats if they want
        cout<<"Are you okay with these stats?"<<endl;
        cout<<"Enter Y to accept and N to enter new stats"<<endl;
        cin>>answer;
    }while (answer=='n'||answer=='N');
    }

    //Reserve this spot for the input into a file
    cout<<"Your chosen stats will be put into a file if you want to use it "
            "later"<<endl;
    fileout.open("Your_Stats.dat");
    fileout<<"Your Pow is = "<<info->pow<<"\r\n"
            <<"Your Def is = "<<info->def<<"\r\n"
            <<"Your Attk is = "<<info->attk<<endl;
    fileout.close();
}


void battle(player *info){
    //Set up the array to keep track of score
    int wins[1],loses[1];
    int PlayHp=50;
    badguy cpu;//computer instance
    dice test;//dice instance
    //After their stats are either input or rolled, have them select their
    //opponents from the list
    cout<<"Please select your opponent\n";
    char choice;
    do{
    cout<<"Type 1 to fight a Grunt"<<endl;
    cout<<"Type 2 to fight a Leader"<<endl;
    cout<<"Type 3 to fight an Elite"<<endl;
    cout<<"Type 4 to fight The Butcher"<<endl;
    //To bring up their score
    cout<<"Type 5 to see your score so far"<<endl;
    cout<<"Or type anything else to exit"<<endl;
    cin>>choice;

    switch(choice){
        case '1':{
                //Variables
                //different dice rolls for player and opponent, 2 sets, one for hitting
                //one for damage rolls. If i were smarter i could probably reduce it to just
                //the two dice rolls lol   
                bool computer;
                char roll;
                //e=enemy; so enemy to hit, enemy to roll...
                int toHit,eRoll,etohit,Droll,NDroll,Dmg,
                        comp_Hp=cpu.set_hp(),comp_dmg=cpu.set_dmg(),
                        compatk=cpu.set_attk();

                cout<<"A Grunt decides to pick a fight!"<<endl;                 
                computer=false;    
                do{
                srand(static_cast<int>(time(0)));
                //Initiate the roll to Hit  
                cout<<"Its your turn "<<info->name<<", Roll to hit!"<<endl;
                cout<<"Enter R then hit enter"<<endl;
                cin>>roll;
                if (roll=='r'||roll=='R'){
                    test.rolldice();
                    Droll=test.results();
                }
                cout<<"You rolled a "<<Droll;
                toHit=Droll+(info->attk);
                cout<<"! Added to your attack modifer of "<<info->attk<<
                       " you got a total of "<<toHit<<endl;
                //If the player hits
                            if (toHit>=12){
                            //Roll for Damage
                            cout<<"You hit!"<<endl;
                            cout<<"Roll for Damage!"<<endl;
                            cout<<"Enter R then hit enter"<<endl;
                            cin>>roll;
                            if (roll=='r'||roll=='R'){
                            test.rolldice();
                            NDroll=test.results();
                            }
                            cout<<"You rolled a "<<NDroll<<endl;
                            Dmg=NDroll+(info->pow);
                            cout<<"Your Damage total is "<<Dmg<<endl;
                            comp_Hp-=Dmg;
                //If the player misses            
                            }else{
                            cout<<"You missed!"<<endl;
                        }
                cout<<"The opponents health is at "<<comp_Hp<<endl;
                //Switching to the computer if the computer lives or player misses
                    if(comp_Hp>0){
                    cout<<"You didnt hit hard enough! The target lives!"<<endl;        
                    computer=true;
                    cout<<"Its the opponents turn!"<<endl;
                    cout<<"The opponent tries to attack!"<<endl;
                    cout<<"Press R to have them roll"<<endl;
                    cin>>roll;
                    test.rolldice();
                    eRoll=test.results();
                    cout<<"The opponent rolled a "<<eRoll<<"!"<<endl;
                    etohit=eRoll+compatk;
                    cout<<"The total they have is "<<compatk+eRoll<<endl;
                    if (etohit>=(info->def)){
                        cout<<"The opponent managed to hit you!"<<endl;
                        cout<<"They are going to damage you now"<<endl;
                        cout<<"Press R to have them roll for damage"<<endl;
                        cin>>roll;
                        test.rolldice();
                        PlayHp-=(test.results()+comp_dmg);
                        cout<<"The computer rolled a "<<eRoll<<endl;
                        cout<<"The computer hits you for "<<eRoll+comp_dmg<<endl;
                        cout<<"You have "<<PlayHp<<" Hit points left!"<<endl;
                    }
        
                else
                    cout<<"The computer missed!"<<endl;

                }
                else{
                    computer=false;
                }    
                }while (comp_Hp>=1);

                if (comp_Hp<=0){
                    cout<<"The target is dead!"<<endl;
                    cout<<"You win!"<<endl;
                    wins[1]+=1;
                }else 
                    cout<<"You died!"<<endl;
                    loses[1]+=1;
                    break;
        }
        case '2':{
            //Copy paste case 1 but change the comp variables to make them stronger
                bool computer;
                char roll;
                int toHit,eRoll,etohit,Droll,NDroll,Dmg,
                        comp_Hp=20,comp_dmg=12,compatk=6,PlayHp=50;

                cout<<"A Leader decides to pick a fight!"<<endl;                 
                    computer=false;    
                do{
                srand(static_cast<int>(time(0)));
                //Initiate the roll to Hit  
                cout<<"Its your turn "<<info->name<<", Roll to hit!"<<endl;
                cout<<"Enter R then hit enter"<<endl;
                cin>>roll;
                if (roll=='r'||roll=='R'){
                    test.rolldice();
                    Droll=test.results();
                }
                cout<<"You rolled a "<<Droll;
                toHit=Droll+(info->attk);
                cout<<"! Added to your attack modifer of "<<(info->attk)<<
                       " you got a total of "<<toHit<<endl;
                //If the player hits
                            if (toHit>=13){
                            //Roll for Damage
                            cout<<"You hit!"<<endl;
                            cout<<"Roll for Damage!"<<endl;
                            cout<<"Enter R then hit enter"<<endl;
                            cin>>roll;
                            if (roll=='r'||roll=='R'){
                            test.rolldice();
                            NDroll=test.results();
                            }
                            cout<<"You rolled a "<<NDroll<<endl;
                            Dmg=NDroll+(info->pow);
                            cout<<"Your Damage total is "<<Dmg<<endl;
                            comp_Hp-=Dmg;
                //If the player misses            
                            }else{
                            cout<<"You missed!"<<endl;
                        }
                cout<<"The opponents health is at "<<comp_Hp<<endl;
                //Switching to the computer if the computer lives or player misses
                    if(comp_Hp>0){
                    cout<<"You didnt hit hard enough! The target lives!"<<endl;        
                    computer=true;
                    cout<<"Its the opponents turn!"<<endl;
                    cout<<"The opponent tries to attack!"<<endl;
                    cout<<"Press R to have them roll"<<endl;
                    cin>>roll;
                    test.rolldice();
                    eRoll=test.results();
                    cout<<"The opponent rolled a "<<eRoll<<"!"<<endl;
                    etohit=eRoll+compatk;
                    cout<<"The total they have is "<<compatk+eRoll<<endl;
                    if (etohit>=(info->def)){
                        cout<<"The opponent managed to hit you!"<<endl;
                        cout<<"They are going to damage you now"<<endl;
                        cout<<"Press R to have them roll for damage"<<endl;
                        cin>>roll;
                        PlayHp-=(eRoll+comp_dmg);
                        cout<<"The computer rolled a "<<eRoll<<endl;
                        cout<<"The computer hits you for "<<eRoll+comp_dmg<<endl;
                        cout<<"You have "<<PlayHp<<" Hit points left!"<<endl;
                    }
        
                else
                    cout<<"The computer missed!"<<endl;

                }
                else{
                    computer=false;
                }    
                }while (comp_Hp>=1);

                if (comp_Hp<=0){
                    cout<<"The target is dead!"<<endl;
                    cout<<"You win!"<<endl;
                    wins[1]+=1;
                }else 
                    cout<<"You died!"<<endl;
                    loses[1]+=1;
                    break;
        }
        case '3':{
                bool computer;
                char roll;
                int i,array[1],number;
                int toHit,eRoll,etohit,Droll,NDroll,Dmg,comp_Hp=25,comp_dmg=12,compatk=7,PlayHp=50;

                cout<<"An Elite decides to pick a fight!"<<endl;                 
                    computer=false;    
                do{
                srand(static_cast<int>(time(0)));

                //Initiate the roll to Hit  
                cout<<"Its your turn "<<info->name<<",Roll to hit!"<<endl;
                cout<<"Enter R then hit enter"<<endl;
                cin>>roll;
                if (roll=='r'||roll=='R'){
                    test.rolldice();
                    Droll=test.results();
                }
                cout<<"You rolled a "<<Droll;
                toHit=Droll+(info->attk);
                cout<<"! Added to your attack modifer of "<<(info->attk)<<
                       " you got a total of "<<toHit<<endl;
                //If the player hits
                            if (toHit>=14){
                            //Roll for Damage
                            cout<<"You hit!"<<endl;
                            cout<<"Roll for Damage!"<<endl;
                            cout<<"Enter R then hit enter"<<endl;
                            cin>>roll;
                            if (roll=='r'||roll=='R'){
                            test.rolldice();
                            NDroll=test.results();
                            }
                            cout<<"You rolled a "<<NDroll<<endl;
                            Dmg=NDroll+(info->pow);
                            cout<<"Your Damage total is "<<Dmg<<endl;
                            comp_Hp-=Dmg;
                //If the player misses            
                            }else{
                            cout<<"You missed!"<<endl;
                        }
                cout<<"The opponents health is at "<<comp_Hp<<endl;
                //Switching to the computer if the computer lives or player misses
                    if(comp_Hp>0){
                    cout<<"You didnt hit hard enough! The target lives!"<<endl;        
                    computer=true;
                    cout<<"Its the opponents turn!"<<endl;
                    cout<<"The opponent tries to attack!"<<endl;
                    cout<<"Press R to have them roll"<<endl;
                    cin>>roll;
                    test.rolldice();
                    eRoll=test.results();
                    cout<<"The opponent rolled a "<<eRoll<<"!"<<endl;
                    etohit=eRoll+compatk;
                    cout<<"The total they have is "<<compatk+eRoll<<endl;
                    if (etohit>=(info->def)){
                        cout<<"The opponent managed to hit you!"<<endl;
                        cout<<"They are going to damage you now"<<endl;
                        cout<<"Press R to have them roll for damage"<<endl;
                        cin>>roll;
                        PlayHp-=(eRoll+comp_dmg);
                        cout<<"The computer rolled a "<<eRoll<<endl;
                        cout<<"The computer hits you for "<<eRoll+comp_dmg<<endl;
                        cout<<"You have "<<PlayHp<<" Hit points left!"<<endl;
                    }
        
                else
                    cout<<"The computer missed!"<<endl;

                }
                else{
                    computer=false;
                }    
                }while (comp_Hp>=1);

                if (comp_Hp<=0){
                    cout<<"The target is dead!"<<endl;
                    cout<<"You win!"<<endl;
                    wins[1]+=1;
                }else 
                    cout<<"You died!"<<endl;
                    loses[1]+=1;
                    break;
        }
        case '4':{
                bool computer;
                char roll;
                int toHit,eRoll,etohit,Droll,NDroll,Dmg,comp_Hp=50
                ,comp_dmg=16,compatk=9;

                cout<<"The Butcher decides to pick a fight!"<<endl;                 
                computer=false;    
                do{
                srand(static_cast<int>(time(0)));

                //Initiate the roll to Hit  
                cout<<"Its your turn "<<info->name<<", Roll to hit!"<<endl;
                cout<<"Enter R then hit enter"<<endl;
                cin>>roll;
                if (roll=='r'||roll=='R'){
                    test.rolldice();
                    Droll=test.results();
                }
                cout<<"You rolled a "<<Droll;
                toHit=Droll+(info->attk);
                cout<<"! Added to your attack modifer of "<<(info->attk)<<
                       " you got a total of "<<toHit<<endl;
                //If the player hits
                            if (toHit>=13){
                            //Roll for Damage
                            cout<<"You hit!"<<endl;
                            cout<<"Roll for Damage!"<<endl;
                            cout<<"Enter R then hit enter"<<endl;
                            cin>>roll;
                            if (roll=='r'||roll=='R'){
                            test.rolldice();
                            NDroll=test.results();
                            }
                            cout<<"You rolled a "<<NDroll<<endl;
                            Dmg=NDroll+(info->pow);
                            cout<<"Your Damage total is "<<Dmg<<endl;
                            comp_Hp-=Dmg;
                //If the player misses            
                            }else{
                            cout<<"You missed!"<<endl;
                        }
                cout<<"The opponents health is at "<<comp_Hp<<endl;
                //Switching to the computer if the computer lives or player misses
                    if(comp_Hp>0){
                    cout<<"You didnt hit hard enough! The target lives!"<<endl;        
                    computer=true;
                    cout<<"Its the opponents turn!"<<endl;
                    cout<<"The opponent tries to attack!"<<endl;
                    cout<<"Press R to have them roll"<<endl;
                    cin>>roll;
                    test.rolldice();
                    eRoll=test.results();
                    cout<<"The opponent rolled a "<<eRoll<<"!"<<endl;
                    etohit=eRoll+compatk;
                    cout<<"The total they have is "<<compatk+eRoll<<endl;
                    if (etohit>=(info->def)){
                        cout<<"The opponent managed to hit you!"<<endl;
                        cout<<"They are going to damage you now"<<endl;
                        cout<<"Press R to have them roll for damage"<<endl;
                        cin>>roll;
                        PlayHp-=(eRoll+comp_dmg);
                        cout<<"The computer rolled a "<<eRoll<<endl;
                        cout<<"The computer hits you for "<<eRoll+comp_dmg<<endl;
                        cout<<"You have "<<PlayHp<<" Hit points left!"<<endl;
                    }
        
                else
                    cout<<"The computer missed!"<<endl;

                }
                else{
                    computer=false;
                }    
                }while (comp_Hp>=1&&PlayHp>=1);

                if (comp_Hp<=0){
                    cout<<"The target is dead!"<<endl;
                    cout<<"You win!"<<endl;
                    wins[1]+=1;
                }else 
                    cout<<"You died!"<<endl;
                    loses[1]+=1;
                    break;
        }
        case '5':{
            cout<<"You have won "<<wins[1]<<" times"<<endl;
            cout<<"You have lost "<<loses[2]<<" times"<<endl;
            break;
        }
        default:{
            cout<<"Good-Bye"<<endl;
        }
    }
    }while (choice>='1'&&choice<='5');
    //Exit stage right 
}