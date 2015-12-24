#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "functions.h"
using namespace std;



int main()
{
system("COLOR B");

BoardClear();
RandGen();          //genrate 2 numbers at the beginning...
RandGen();
while(1)
{
    system("cls");
    cout<<"------------------\n";
    cout<<"------2048(64)----\n";
    cout<<"------------------\n";
    for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            cout<<GameBoard[row][col]<<"  ";
        }
        cout<<endl;
    }
    cout<<"\t   Score: "<<Score;
   cout<<endl<<"ENTER INPUT\n";
   cin>>UserInput;


    switch(UserInput)
    {
        case 'a':MoveLeft();
               RandGen();
                break;

        case 'd':MoveRight();
                RandGen();
                break;

        case 'w':MoveUp();
                RandGen();
                break;

        case 's':MoveDown();
                RandGen();
                break;
        case '4': MoveLeft();
                RandGen();
                break;
        case '6': MoveRight();
                RandGen();
                break;
        case '8': MoveUp();
                RandGen();
                break;
        case '2': MoveDown();
                RandGen();
                break;
        case '.':  BoardClear();
                break;

        case 'r':RandGen();
                break;
        case '0':wonORnot=1;
                break;

        default:cout<<"Wrong input...try again";
                Sleep(800);
                break;


    }


WinCheck();
 if(wonORnot==1)
    {cout<<"YOU HAAAVE WON!!!!! THANKS FOR PLAYING!!";
     Sleep(5000);
     return 0;
    }
}
}
//-----------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------------------


