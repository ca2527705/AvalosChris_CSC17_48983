/* 
 * File:   main.cpp
 * Author: CHristopher Avalos
 * Purpose: HMWK 12.7
 * Created on October 12, 2015, 1:41 PM
 */
//System libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

//User libraries

//Global constants

//function prototypes

//fun starts here
int main(int argc, char** argv) {
    //name the variables
    string filename1,filename2;
    string str;
    char ch;
    //name the files
    cout<<"Input a file name to be input into, and another to have data\n"
          "output into to be placed inside a file\n";
    getline(cin,filename1);
    cout<<"The second file\n";
    getline(cin,filename2);
    //open the file to output to it
    ofstream odata(filename2.c_str());
    //open the first file input into it
    fstream idata(filename1.c_str(),ios::out);
    cout<<"Now write some random sentence into it\n";
    //cin.get allows you to write to the file
    cin.get(ch);
    //As long as there is no period, the file continues recording
    //whatever is written
    while(ch!='.')
    {
        idata.put(ch);
        cin.get(ch);
    }
    idata.put(ch);
    //close the file to seal confirm the data, then reopen to work with it
    idata.close();
    idata.open(filename1.c_str(), ios::in);
    if(idata)
    {
        //read the sentence from file1
        cin.ignore();
        getline(idata,str);
        cout<<str;
        if (str.length()>0){
            str[0]=toupper(str[0]);
            for(int i=0;i<str.length()-1;i++){
                //This is
                if(str[i]==' '&&isalpha(str[i+1])){
                   str[i+1]=toupper(str[i+1]);
                }
            }
        }
        odata<<str;
            //close the files
        idata.close();
        odata.close();
        cout<<"\nIt worked!";
        
    }else
        cout<<"shits broken yo\n";
    
    return 0;
}

