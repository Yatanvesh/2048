
using namespace std;

int randX,randY, FourORtwo, store;
int GameBoard[4][4];
int zero, row, col, mod;
int wonORnot=0;
int Score=0;
int AddSuccess=0;
int Execute;

char UserInput;
//----------------------------------------------------------------------------------------
void BoardClear();
void RandGen();
//void Shift_Left();
//void Shift_Right();
//void Shift_Up();
//void Shift_Down();
void MoveLeft();
void MoveRight();
void MoveUp();
void MoveDown();
void WinCheck(int x);

//----------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------
    void BoardClear()
{
   for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            GameBoard[row][col]= 0 ;
        }

    }
}
//----------------------------------------------------------------------------------------
void RandGen()
{
    srand(time(0));
    int loopTerminator=40;//helps to exit loop
    store=rand()%10;
    if((store>=0)&&(store<9)) FourORtwo=2;
    else FourORtwo=4;
    while(loopTerminator>0)
   {
    randX=rand()%4;
    randY=rand()%4;

        if(GameBoard[randX][randY]==0)
            {
                GameBoard[randX][randY]=FourORtwo;
                break;
            }

        else if(GameBoard[randX][randY]!=0)
            {
                loopTerminator--;
                continue;

            }
    }
}
//----------------------------------------------------------------------------------------
/*void Shift_Left()
{
   zero=0;
while(zero<3)
	{
        for(row=0;row<4;row++)
        {
            for(col=0;col<4;col++)
            {
                mod=col +1;
                if(mod==4)mod--;
				if(GameBoard[row][col]==0)
                {

                    GameBoard[row][col]=GameBoard[row][mod];
                    GameBoard[row][mod]=0;
                }
				else if(GameBoard[row][col]==GameBoard[row][mod])//&&(PreventMultipleAddition>1))
                {
                    GameBoard[row][col]=GameBoard[row][col] + GameBoard[row][mod];
                    GameBoard[row][mod]=0;
					Score=Score+GameBoard[row][col];
					//PreventMultipleAddition--;
				}
            }

        }
    zero++;
	}
	//PreventMultipleAddition=2;
}
//----------------------------------------------------------------------------------------
void Shift_Right()
{
   zero=0;
while(zero<3)
    {

        for(row=0;row<4;row++)
        {
            for(col=0;col<4;col++)
            {
                mod=col-1;




                if(GameBoard[row][col]==0)
                {   if(mod==-1) mod++;
                    //if(mod== 4)  mod--;

        //cout<<row<<"   "<<col<<endl<<row<<"   "<<mod<<endl<<endl;cin.get();//dis showed dat mode becomes -1 smtimes
                    GameBoard[row][col]=GameBoard[row][mod];
                    GameBoard[row][mod]=0;
                }
                else if(GameBoard[row][col]==GameBoard[row][mod])
                {
                    if(mod==-1)mod++;
                    GameBoard[row][col]=GameBoard[row][col] + GameBoard[row][mod];
                    GameBoard[row][mod]=0;
                    //zero=3;
                    Score=Score+GameBoard[row][col];
                }

            }

        }
    zero++;
    }

}
//----------------------------------------------------------------------------------------
void Shift_Up()
{
 zero=0;
while(zero<3)
    {
        for(row=0;row<4;row++)
        {
            for(col=0;col<4;col++)
            {
                mod=row +1;
                 if(mod==4)mod--;
                if(GameBoard[row][col]==0)//&&(GameBoard[row][col]!=GameBoard[row][mod]))
                {
                    //wen mod becomes 4, unexpected shit happens
                    GameBoard[row][col]=GameBoard[mod][col];
                    GameBoard[mod][col]=0;
                }
                else if(GameBoard[row][col]==GameBoard[mod][col])
                {
                    GameBoard[row][col]=GameBoard[row][col] + GameBoard[mod][col];
                    GameBoard[mod][col]=0;
                    zero=3;
                    Score=Score+GameBoard[row][col];
                }
            }

        }
    zero++;
    }
}
//----------------------------------------------------------------------------------------
void Shift_Down()
{
   zero=0;
while(zero<3)
    {

        for(row=0;row<4;row++)
        {
            for(col=0;col<4;col++)
            {
                mod=row-1;
                if(mod==-1) mod++;


                if(GameBoard[row][col]==0)
                {


        //cout<<row<<"   "<<col<<endl<<row<<"   "<<mod<<endl<<endl;cin.get();//dis showed dat mode becomes -1 smtimes
                    GameBoard[row][col]=GameBoard[mod][col];
                    GameBoard[mod][col]=0;
                }
                else if(GameBoard[row][col]==GameBoard[mod][col])
                {
                    GameBoard[row][col]=GameBoard[row][col] + GameBoard[mod][col];
                    GameBoard[mod][col]=0;
                    zero=3;
                    Score=Score+GameBoard[row][col];
                }
            }

        }
    zero++;
    }
}*/
//----------------------------------------------------------------------------------------
void WinCheck()
{
    for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            if(GameBoard[row][col]==2048)
            {
                wonORnot=1;
            }
    }
}

}
//----------------------------------------------------------------------------------------
void MoveLeft()
{
    Execute=0;
    for(zero=0;zero<3;zero++)//loop 3 times to make sure d tile at leftmost reaches rightmost
    {
        for(row=0;row<4;row++)
        {
            for(col=0;col<4;col++)
            {

                mod=col +1;//DO NOT PUT THIS INSIDE IF!! IT BEHAVES..WELL, REMOVE WHILE LOOP/FIRST LOOP AND CHECK 4 URSELF
                if(mod==4)mod--;

				if(Execute>=2)
                {
                    if(GameBoard[row][col]==GameBoard[row][mod])//&&(PreventMultipleAddition>1))
                    {
                        GameBoard[row][col]=GameBoard[row][col] + GameBoard[row][mod];
                        GameBoard[row][mod]=0;
                        Score=Score+GameBoard[row][col];
                        //PreventMultipleAddition--;
                    }
                }

				if(GameBoard[row][col]==0)
                {
                    //cout<<row<<"   "<<col<<endl<<row<<"   "<<mod<<endl<<endl;cin.get();
                    GameBoard[row][col]=GameBoard[row][mod];
                    GameBoard[row][mod]=0;
                }
            }
        }
        Execute++;
    }




}
//----------------------------------------------------------------------------------------
void MoveRight()
{
    Execute=0;
    for(zero=0;zero<3;zero++)//loop 3 times to make sure d tile at leftmost reaches rightmost
    {
        for(row=3;row>-1;row--)
        {
            for(col=3;col>-1;col--)
            {
                mod=col-1;//DO NOT PUT THIS INSIDE IF!! IT BEHAVES..WELL, REMOVE WHILE LOOP/FIRST LOOP AND CHECK 4 URSELF
                if(mod==-1)mod++;

                if(Execute>=2)
                {
                    if(GameBoard[row][col]==GameBoard[row][mod])
                    {
                        GameBoard[row][col]=GameBoard[row][col] + GameBoard[row][mod];
                        GameBoard[row][mod]=0;
                        Score=Score+GameBoard[row][col];
                    }
                }

				if(GameBoard[row][col]==0)
                {
                    GameBoard[row][col]=GameBoard[row][mod];
                    GameBoard[row][mod]=0;
                }
            }
        }
        Execute++;
    }




}
//----------------------------------------------------------------------------------------
void MoveUp()
{
    Execute=0;
    for(zero=0;zero<3;zero++)//loop 3 times to make sure d tile at leftmost reaches rightmost
    {
         for(row=0;row<4;row++)
        {
            for(col=0;col<4;col++)
            {
                mod=row +1;
                if(mod==4)mod--;

                if(Execute>=2)
                 {
                     if(GameBoard[row][col]==GameBoard[mod][col])
                    {
                        GameBoard[row][col]=GameBoard[row][col] + GameBoard[mod][col];
                        GameBoard[mod][col]=0;
                        Score=Score+GameBoard[row][col];
                    }
                 }
                if(GameBoard[row][col]==0)//&&(GameBoard[row][col]!=GameBoard[row][mod]))
                {
                    //wen mod becomes 4, unexpected shit happens
                    GameBoard[row][col]=GameBoard[mod][col];
                    GameBoard[mod][col]=0;
                }
            }
        }
        Execute++;
    }

}
//----------------------------------------------------------------------------------------
void MoveDown()
{
    Execute=2;
    for(zero=0;zero<3;zero++)//loop 3 times to make sure d tile at leftmost reaches rightmost
    {
        for(row=3;row>-1;row--)
        {
            for(col=3;col>-1;col--)
            {
                mod=row-1;
                if(mod==-1) mod++;

                if(Execute>=2)
                {
                    if(GameBoard[row][col]==GameBoard[mod][col])
                    {
                        GameBoard[row][col]=GameBoard[row][col] + GameBoard[mod][col];
                        GameBoard[mod][col]=0;
                        Score=Score+GameBoard[row][col];
                    }
                }

                if(GameBoard[row][col]==0)
                {
                    GameBoard[row][col]=GameBoard[mod][col];
                    GameBoard[mod][col]=0;
                }
            }
        }
        Execute++;
    }

}
//----------------------------------------------------------------------------------------
