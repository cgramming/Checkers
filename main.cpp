#include <iostream>
#include<conio.h>
#include <windows.h>
using namespace std;
char a[33]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
int c[42]={8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8};
int out1=12;
int out2=12;
// c[] values :::: 1 = player one plain coin 2 = player one queen
// c[] values :::: 3 = player two plain coin 4 = player two queen
// c[] values :::: 0 = not occupied.
const char X ='X';
const char O ='O';
const char Q1 ='#';
const char Q2 ='Q';

#include"board.h"
//int places = 14;
int main()
{
int froms = 1;
int tos =0;
int player =1;
int passmove;
int moved;

startB();
drawB(0);
for (int i = 1; i>0; i++)
{
    moved=0;
    cout<<"Player "<<player<<" Enter the coin box #        : ";cin>>froms;
   system("cls");
   drawB(froms);
    cout<<"Player "<<player<<" Enter the destination box # : ";cin>>tos;

    moved=singleM(player,froms,tos);
    if (moved==1) passmove=place(player,froms,tos);
    else if(doubleM(player,froms,tos)){passmove=place(player,froms,tos);}
    else {cout<<"\a\a"; continue;}

    if(out1 <=0) {cout<<"\a\a\a\a\a\a\a PLAYER 2 WON  ******************* "; getch(); break;}
    if(out2 <=0) {cout<<"\a\a\a\a\a\a\a PLAYER 1 WON  ******************* "; getch(); break;}

    system("cls");
    drawB(tos);


    if (player == 1)player =2;
    else player = 1;
}

    return 0;
}
