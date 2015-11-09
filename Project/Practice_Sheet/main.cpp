#include <iostream>//basic cin/cout usage
#include <cstdlib>//To use the rand
#include <string>

using namespace std;

//user libraries

//global constants

//function prototypes

struct balance
    {
        int account;
        int balance;
        int tot_chec;
        int tot_dep;
    };
//function used for dice rolls


//The fun starts here!
int main(int argc, char** argv) {
    balance cust;
    int pin, answer,i;
    cout<<"Input your pin\n";
    cout<<cust.account<<endl;
    cout<<cust.balance<<endl;
    cout<<cust.tot_chec<<endl;
    cout<<cust.tot_dep<<endl;
    cin>>pin;
        if ((pin>=1000)&&(pin<10000)){  
            cout<<"Input your initial balance\n";
            cin>>cust.account;
            cout<<"Input the amount charged per check, enter 0 when done\n";
            do{
                cin>>answer;
                cust.tot_dep+=answer;
            }while (answer>0);
            cout<<"Input the amount added per check, enter 0 when done\n";
            do{
                cin>>i;
                cust.tot_chec+=i;
            }while(i>0);
            cout<<cust.tot_dep<<" dollars was credited to your accout"<<endl;
            cout<<cust.tot_chec<<" dollars were put into your account"<<endl;

            cust.balance=cust.account-cust.tot_dep+cust.tot_chec;

            if (cust.balance<0){
                cout<<"You have overdrawn, a charge of $15.00 has been added to "
                        "your account\n";
                cout<<cust.balance-15.00<<" dollars is your new balance"<<endl;
                cout<<"In order to allow further charges to occur the card \n"
                      "will have to be zeroed out and a new credit balance "
                        "applied"<<endl;
            }else
            cout<<cust.balance<<" dollars is your current account"<<endl;
    }else
    cout<<"Improper pin number\n";
    
    return 0;
}