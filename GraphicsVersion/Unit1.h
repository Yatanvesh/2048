//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class Tevents : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TEdit *Edit14;
	TEdit *Edit15;
	TEdit *Edit16;
	TLabel *Label2;
	TButton *Up;
	TButton *Left;
	TButton *Right;
	TButton *Down;
	TLabel *Label1;
	TButton *Start;
	TButton *End;
	TEdit *ScoreBox;
	TLabel *win;
	TButton *Random;
	void __fastcall StartClick(TObject *Sender);
	void __fastcall LeftClick(TObject *Sender);
	void __fastcall RightClick(TObject *Sender);
	void __fastcall UpClick(TObject *Sender);
	void __fastcall DownClick(TObject *Sender);
	void __fastcall RandomClick(TObject *Sender);
	void __fastcall EndClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tevents(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tevents *events;
//---------------------------------------------------------------------------
using namespace std;

int randX,randY;
int GameBoard[4][4];
int zero, row, col, mod;
int wonORnot=0;
int Score=0;
int PreventMultipleAddition=2;

char UserInput;
//------------------------------------------------------------------------------
void BoardClear();
void RandGen();
void Shift_Left();
void Shift_Right();
void Shift_Up();
void Shift_Down();
void WinCheck(int x);
//void BoardUpdate();




//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void RandGen()
{
    srand(time(0));
    int loopTerminator=40;//helps to exit loop
    while(loopTerminator>0)
   {
    randX=rand()%4;
    randY=rand()%4;

        if(GameBoard[randX][randY]==0)
            {
                GameBoard[randX][randY]=2;
                break;
            }

        else if(GameBoard[randX][randY]!=0)
            {
                loopTerminator--;
                continue;

            }
    }
}
//------------------------------------------------------------------------------
void Shift_Left()
{
   zero=0;
while(zero<3)
	{
        for(row=0;row<4;row++)
        {
            for(col=0;col<4;col++)
            {
                mod=col +1;
				if(GameBoard[row][col]==0)
                {
					if(mod==4)mod--;
                    GameBoard[row][col]=GameBoard[row][mod];
                    GameBoard[row][mod]=0;
                }
				else if((GameBoard[row][col]==GameBoard[row][mod])&&(PreventMultipleAddition>1))
                {
                    GameBoard[row][col]=GameBoard[row][col] + GameBoard[row][mod];
                    GameBoard[row][mod]=0;
					Score=Score+GameBoard[row][col];
					PreventMultipleAddition--;
				}
            }

        }
    zero++;
	}
	PreventMultipleAddition=2;
}
//------------------------------------------------------------------------------
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
                {
					if(mod== 4)  mod--;
					if(mod==-1) mod++;

					GameBoard[row][col]=GameBoard[row][mod];
                    GameBoard[row][mod]=0;
                }
				else if((GameBoard[row][col]==GameBoard[row][mod])&&(PreventMultipleAddition>1))
                {
					GameBoard[row][col]=GameBoard[row][col] + GameBoard[row][mod];
                    GameBoard[row][mod]=0;
					Score=Score+GameBoard[row][col];
					PreventMultipleAddition--;
                }

            }

        }
    zero++;
	}
	PreventMultipleAddition=2;
}
//------------------------------------------------------------------------------
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
				if(GameBoard[row][col]==0)
                {
					if(mod==4)mod--;
                    GameBoard[row][col]=GameBoard[mod][col];
                    GameBoard[mod][col]=0;
                }
				else if((GameBoard[row][col]==GameBoard[mod][col])&&(PreventMultipleAddition>1))
                {
                    GameBoard[row][col]=GameBoard[row][col] + GameBoard[mod][col];
                    GameBoard[mod][col]=0;
					Score=Score+GameBoard[row][col];
					PreventMultipleAddition--;
				}
			}

		}
	zero++;
	PreventMultipleAddition=2;
    }
}
//------------------------------------------------------------------------------
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



                if(GameBoard[row][col]==0)
                {
                    if(mod== 4)  mod--;
                    if(mod==-1) mod++;

                    GameBoard[row][col]=GameBoard[mod][col];
                    GameBoard[mod][col]=0;
                }
				else if((GameBoard[row][col]==GameBoard[mod][col])&&(PreventMultipleAddition>1))
                {
                    GameBoard[row][col]=GameBoard[row][col] + GameBoard[mod][col];
					GameBoard[mod][col]=0;
					Score=Score+GameBoard[row][col];
					PreventMultipleAddition--;
                }
            }

        }
    zero++;
	}
	PreventMultipleAddition=2;
}
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
}

//---------------------------------------------------------------------------
#endif
