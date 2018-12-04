#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

//// this is a move function. it checks for proper coin and player and returns 1 on success and 0 on fail
int place(int player,int froms,int tos)
{
int token=0;
            a[tos] = a[froms]; c[tos]= c[froms]; a[froms] = ' ';
            //checking for queen ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~begin ~
            if (player == 2 && (tos == 1 || tos == 2 || tos == 3 || tos == 4)){cout<<"\a\a\a\a\a\a"; c[tos] = 4; a[tos] = Q2;}
            else if (player == 1 && (tos == 29 || tos == 30 || tos == 31 || tos == 32)){cout<<"\a\a\a\a\a\a"; c[tos] = 2; a[tos] = Q1;}
            //checking for queen ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ end  ~
            c[froms] = 0; token = 1;

return token;
 }
int singleM (int player,int froms,int tos)
 {
     int coin = 0;
     int green =0;
     int temp[16] = {5,6,7,8,13,14,15,16,21,22,23,24,29,30,31,32};
     for(int i=0; i<16;i++){if(froms==temp[i])green=1;}
// if (player == 1 && tos == froms + 4 || player == 2 && tos == froms - 4) coin = 1;
// c[] values :::: 1 = player one plain coin 2 = player one queen
// c[] values :::: 3 = player two plain coin 4 = player two queen
// c[] values :::: 0 = not occupied.
if (c[tos] != 0) coin = 0;
else if ((player == 1 || c[froms]==4 )&& tos == froms + 4 ) coin =1;
else if((player ==2 || c[froms]==2 ) && tos == froms -4) coin =1;
else if ((player == 1 || c[froms]==4 )&& green == 1 && tos == froms +3 ) coin =1;
else if ((player == 1 || c[froms]==4 )&& green == 0 && tos == froms +5 ) coin =1;
else if ((player == 2 || c[froms]==2 )&& green == 1 && tos == froms -5 ) coin =1;
else if ((player == 2 || c[froms]==2 )&& green == 0 && tos == froms -3 ) coin =1;

    return coin;
 }
 //this function has two functionalities 1) check for double move and if valid then kill the middle coin.
 int doubleM(int player,int froms,int tos)
 {

     int coin = 0;
     int green =0;
     int temp[16] = {5,6,7,8,13,14,15,16,21,22,23,24,29,30,31,32};
     for(int i=0; i<16;i++){if(froms==temp[i])green=1;}
// if (player == 1 && tos == froms + 4 || player == 2 && tos == froms - 4) coin = 1;
// c[] values :::: 1 = player one plain coin 2 = player one queen
// c[] values :::: 3 = player two plain coin 4 = player two queen
// c[] values :::: 0 = not occupied.
        if (c[tos] != 0) coin = 0;
        else if (green == 0 && (player == 1 || c[froms] == 4) && c[tos] == c[froms + 9] && c[froms + 5] != 0) coin = froms + 5;
        else if (green == 0 && (player == 1 || c[froms] == 4) && c[tos] == c[froms + 7] && c[froms + 4] != 0) coin = froms + 4;


        else if (green == 1 && (player == 1 || c[froms] == 4) && c[tos] == c[froms + 9] && c[froms + 4] != 0) coin = froms + 4;
        else if (green == 1 && (player == 1 || c[froms] == 4) && c[tos] == c[froms + 7] && c[froms + 3] != 0) coin = froms + 3;


        else if (green == 0 && (player == 2 || c[froms] == 2) && c[tos] == c[froms - 9] && c[froms - 4] != 0) coin = froms - 4;
        else if (green == 0 && (player == 2 || c[froms] == 2) && c[tos] == c[froms - 7] && c[froms - 3] != 0) coin = froms - 3;

        else if (green == 1 && (player == 2 || c[froms] == 2) && c[tos] == c[froms - 9] && c[froms - 5] != 0) coin = froms - 5;
        else if (green == 1 && (player == 2 || c[froms] == 2) && c[tos] == c[froms - 7] && c[froms - 4] != 0) coin = froms - 4;

        if (player ==1 && (c[coin] == 1 || c[coin]==2 )) coin = 0;
        if (player ==2 && (c[coin] == 2 || c[coin]==4 )) coin = 0;

        if(coin != 0)
        {
            if (c[coin] == 1 || c[coin]==2) --out1;
            else --out2;

            a[coin]=' ';
            c[coin]= 0;
            coin =1;
        }

       return coin;
}

void startB()
{
   for(int i =1; i<=12; i++) {a[i] = X; c[i] = 1;}
   for(int i =21; i<=32; i++){a[i] = O; c[i] = 3;}
   for(int i =13; i<=20; i++){a[i] = ' '; c[i] = 0;}

}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}






void drawB(int light)
{
  //char l[33]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char lc = (char)218;  //left corner character
    char rc = (char)191; //right corner character
    char lb = (char)192; //
    char rb = (char)217;
    char hl = (char)196;
    char vl = (char)179;
    char mt = (char)194;
    char mb = (char)193;
    char ml = (char)195;
    char mr = (char)180;
    char cr = (char)197;
    char l = (char)178;
    //char l = (char)178;
    //char l = (char)176;
    string s[6][33]{
        {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}
    };

//    s[1][light] = ""+l+l+l+l+l+l;
//    s[2][light] = l+"     "+l;
//    s[3][light] = l+"  "+ a[light]; s[3][light] += "  "+l;
//    s[4][light] = l+"     "+l;
//    s[5][light] = l+l+l+l+l+l+l;
    for(int i =1; i<=32; i++)
    {

        if (i == light)
        {
            if (i>9) s[1][light].insert(0,5,l);
            else s[1][light].insert(0,6,l);
            s[2][light].insert(0,1,l); s[2][light] += "     "; s[2][light].insert(6,1,l);
            s[3][light].insert(0,1,l); s[3][light] += "  "; s[3][light] +=a[light]; s[3][light] += "  ";  s[3][light].insert(6,1,l);
            s[4][light].insert(0,1,l); s[4][light] += "     "; s[4][light].insert(6,1,l);
            s[5][light].insert(0,7,l);
        }
        else
        {
            if (i>9) s[1][i] ="     ";
            else s[1][i] ="      ";
            s[2][i] ="       ";
            s[3][i] += "   "; s[3][i] +=a[i]; s[3][i] += "   ";
            s[4][i] = "       ";
            s[5][i] = "       ";

        }
    }


    cout<<lc<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mt<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mt<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mt<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mt<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mt<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mt<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mt<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<rc<<endl;
    cout<<vl<<"       "<<vl<<"1"<<s[1][1]<<vl<<"       "<<vl<<"2"<<s[1][2]<<vl<<"       "<<vl<<"3"<<s[1][3]<<vl<<"       "<<vl<<"4"<<s[1][4]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[2][1]<<vl<<"       "<<vl<<s[2][2]<<vl<<"       "<<vl<<s[2][3]<<vl<<"       "<<vl<<s[2][4]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[3][1]<<vl<<"       "<<vl<<s[3][2]<<vl<<"       "<<vl<<s[3][3]<<vl<<"       "<<vl<<s[3][4]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[4][1]<<vl<<"       "<<vl<<s[4][2]<<vl<<"       "<<vl<<s[4][3]<<vl<<"       "<<vl<<s[4][4]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[5][1]<<vl<<"       "<<vl<<s[5][2]<<vl<<"       "<<vl<<s[5][3]<<vl<<"       "<<vl<<s[5][4]<<vl<<endl;
    cout<<ml<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mr<<endl;
    cout<<vl<<"5"<<s[1][5]<<vl<<"       "<<vl<<"6"<<s[1][6]<<vl<<"       "<<vl<<"7"<<s[1][7]<<vl<<"       "<<vl<<"8"<<s[1][8]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[2][5]<<vl<<"       "<<vl<<s[2][6]<<vl<<"       "<<vl<<s[2][7]<<vl<<"       "<<vl<<s[2][8]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[3][5]<<vl<<"       "<<vl<<s[3][6]<<vl<<"       "<<vl<<s[3][7]<<vl<<"       "<<vl<<s[3][8]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[4][5]<<vl<<"       "<<vl<<s[4][6]<<vl<<"       "<<vl<<s[4][7]<<vl<<"       "<<vl<<s[4][8]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[5][5]<<vl<<"       "<<vl<<s[5][6]<<vl<<"       "<<vl<<s[5][7]<<vl<<"       "<<vl<<s[5][8]<<vl<<"       "<<vl<<endl;
    cout<<ml<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mr<<endl;
    cout<<vl<<"       "<<vl<<"9"<<s[1][9]<<vl<<"       "<<vl<<"10"<<s[1][10]<<vl<<"       "<<vl<<"11"<<s[1][11]<<vl<<"       "<<vl<<"12"<<s[1][12]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[2][9]<<vl<<"       "<<vl<<s[2][10]<<vl<<"       "<<vl<<s[2][11]<<vl<<"       "<<vl<<s[2][12]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[3][9]<<vl<<"       "<<vl<<s[3][10]<<vl<<"       "<<vl<<s[3][11]<<vl<<"       "<<vl<<s[3][12]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[4][9]<<vl<<"       "<<vl<<s[4][10]<<vl<<"       "<<vl<<s[4][11]<<vl<<"       "<<vl<<s[4][12]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[5][9]<<vl<<"       "<<vl<<s[5][10]<<vl<<"       "<<vl<<s[5][11]<<vl<<"       "<<vl<<s[5][12]<<vl<<endl;
    cout<<ml<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mr<<endl;
    cout<<vl<<"13"<<s[1][13]<<vl<<"       "<<vl<<"14"<<s[1][14]<<vl<<"       "<<vl<<"15"<<s[1][15]<<vl<<"       "<<vl<<"16"<<s[1][16]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[2][13]<<vl<<"       "<<vl<<s[2][14]<<vl<<"       "<<vl<<s[2][15]<<vl<<"       "<<vl<<s[2][16]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[3][13]<<vl<<"       "<<vl<<s[3][14]<<vl<<"       "<<vl<<s[3][15]<<vl<<"       "<<vl<<s[3][16]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[4][13]<<vl<<"       "<<vl<<s[4][14]<<vl<<"       "<<vl<<s[4][15]<<vl<<"       "<<vl<<s[4][16]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[5][13]<<vl<<"       "<<vl<<s[5][14]<<vl<<"       "<<vl<<s[5][15]<<vl<<"       "<<vl<<s[5][16]<<vl<<"       "<<vl<<endl;
    cout<<ml<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mr<<endl;
    cout<<vl<<"       "<<vl<<"17"<<s[1][17]<<vl<<"       "<<vl<<"18"<<s[1][18]<<vl<<"       "<<vl<<"19"<<s[1][19]<<vl<<"       "<<vl<<"20"<<s[1][20]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[2][17]<<vl<<"       "<<vl<<s[2][18]<<vl<<"       "<<vl<<s[2][19]<<vl<<"       "<<vl<<s[2][20]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[3][17]<<vl<<"       "<<vl<<s[3][18]<<vl<<"       "<<vl<<s[3][19]<<vl<<"       "<<vl<<s[3][20]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[4][17]<<vl<<"       "<<vl<<s[4][18]<<vl<<"       "<<vl<<s[4][19]<<vl<<"       "<<vl<<s[4][20]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[5][17]<<vl<<"       "<<vl<<s[5][18]<<vl<<"       "<<vl<<s[5][19]<<vl<<"       "<<vl<<s[5][20]<<vl<<endl;
    cout<<ml<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mr<<endl;
    cout<<vl<<"21"<<s[1][21]<<vl<<"       "<<vl<<"22"<<s[1][22]<<vl<<"       "<<vl<<"23"<<s[1][23]<<vl<<"       "<<vl<<"24"<<s[1][24]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[2][21]<<vl<<"       "<<vl<<s[2][22]<<vl<<"       "<<vl<<s[2][23]<<vl<<"       "<<vl<<s[2][24]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[3][21]<<vl<<"       "<<vl<<s[3][22]<<vl<<"       "<<vl<<s[3][23]<<vl<<"       "<<vl<<s[3][24]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[4][21]<<vl<<"       "<<vl<<s[4][22]<<vl<<"       "<<vl<<s[4][23]<<vl<<"       "<<vl<<s[4][24]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[5][21]<<vl<<"       "<<vl<<s[5][22]<<vl<<"       "<<vl<<s[5][23]<<vl<<"       "<<vl<<s[5][24]<<vl<<"       "<<vl<<endl;
    cout<<ml<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mr<<endl;
    cout<<vl<<"       "<<vl<<"25"<<s[1][25]<<vl<<"       "<<vl<<"26"<<s[1][26]<<vl<<"       "<<vl<<"27"<<s[1][27]<<vl<<"       "<<vl<<"28"<<s[1][28]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[2][25]<<vl<<"       "<<vl<<s[2][26]<<vl<<"       "<<vl<<s[2][27]<<vl<<"       "<<vl<<s[2][28]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[3][25]<<vl<<"       "<<vl<<s[3][26]<<vl<<"       "<<vl<<s[3][27]<<vl<<"       "<<vl<<s[3][28]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[4][25]<<vl<<"       "<<vl<<s[4][26]<<vl<<"       "<<vl<<s[4][27]<<vl<<"       "<<vl<<s[4][28]<<vl<<endl;
    cout<<vl<<"       "<<vl<<s[5][25]<<vl<<"       "<<vl<<s[5][26]<<vl<<"       "<<vl<<s[5][27]<<vl<<"       "<<vl<<s[5][28]<<vl<<endl;
    cout<<ml<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<cr<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mr<<endl;
    cout<<vl<<"29"<<s[1][29]<<vl<<"       "<<vl<<"30"<<s[1][30]<<vl<<"       "<<vl<<"31"<<s[1][31]<<vl<<"       "<<vl<<"32"<<s[1][32]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[2][29]<<vl<<"       "<<vl<<s[2][30]<<vl<<"       "<<vl<<s[2][31]<<vl<<"       "<<vl<<s[2][32]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[3][29]<<vl<<"       "<<vl<<s[3][30]<<vl<<"       "<<vl<<s[3][31]<<vl<<"       "<<vl<<s[3][32]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[4][29]<<vl<<"       "<<vl<<s[4][30]<<vl<<"       "<<vl<<s[4][31]<<vl<<"       "<<vl<<s[4][32]<<vl<<"       "<<vl<<endl;
    cout<<vl<<s[5][29]<<vl<<"       "<<vl<<s[5][30]<<vl<<"       "<<vl<<s[5][31]<<vl<<"       "<<vl<<s[5][32]<<vl<<"       "<<vl<<endl;
    cout<<lb<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mb<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mb<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mb<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mb<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mb<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mb<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<mb<<hl<<hl<<hl<<hl<<hl<<hl<<hl<<rb<<endl;

}


#endif // BOARD_H_INCLUDED
