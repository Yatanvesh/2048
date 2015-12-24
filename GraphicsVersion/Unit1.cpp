//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <iostream>
#include <cstdlib>
#include <ctime>


#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.SmXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.NmXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.GGlass.fmx", _PLAT_ANDROID)
#pragma resource ("*.LgXhdpiTb.fmx", _PLAT_ANDROID)
#pragma resource ("*.XLgXhdpiTb.fmx", _PLAT_ANDROID)

Tevents *events;
//---------------------------------------------------------------------------
__fastcall Tevents::Tevents(TComponent* Owner)
	: TForm(Owner)
{
//pta nhi kya hai
}
//---------------------------------------------------------------------------
 using namespace std;

void __fastcall Tevents::StartClick(TObject *Sender)
{
//start
BoardClear();
RandGen();
RandGen();
Edit1->Text=GameBoard[0][0];
Edit2->Text=GameBoard[0][1];
Edit3->Text=GameBoard[0][2];
Edit4->Text=GameBoard[0][3];
Edit5->Text=GameBoard[1][0];
Edit6->Text=GameBoard[1][1];
Edit7->Text=GameBoard[1][2];
Edit8->Text=GameBoard[1][3];
Edit9->Text=GameBoard[2][0];
Edit10->Text=GameBoard[2][1];
Edit11->Text=GameBoard[2][2];
Edit12->Text=GameBoard[2][3];
Edit13->Text=GameBoard[3][0];
Edit14->Text=GameBoard[3][1];
Edit15->Text=GameBoard[3][2];
Edit16->Text=GameBoard[3][3];

if(Edit1->Text==0) Edit1->Text=" ";
if(Edit2->Text==0) Edit2->Text=" ";
if(Edit3->Text==0) Edit3->Text=" ";
if(Edit4->Text==0) Edit4->Text=" ";
if(Edit5->Text==0) Edit5->Text=" ";
if(Edit6->Text==0) Edit6->Text=" ";
if(Edit7->Text==0) Edit7->Text=" ";
if(Edit8->Text==0) Edit8->Text=" ";
if(Edit9->Text==0) Edit9->Text=" ";
if(Edit10->Text==0) Edit10->Text=" ";
if(Edit11->Text==0) Edit11->Text=" ";
if(Edit12->Text==0) Edit12->Text=" ";
if(Edit13->Text==0) Edit13->Text=" ";
if(Edit14->Text==0) Edit14->Text=" ";
if(Edit15->Text==0) Edit15->Text=" ";
if(Edit16->Text==0) Edit16->Text=" ";



//BoardUpdate();
}
//---------------------------------------------------------------------------


void __fastcall Tevents::LeftClick(TObject *Sender)
{
  Shift_Left();
  RandGen();
Edit1->Text=GameBoard[0][0];
Edit2->Text=GameBoard[0][1];
Edit3->Text=GameBoard[0][2];
Edit4->Text=GameBoard[0][3];
Edit5->Text=GameBoard[1][0];
Edit6->Text=GameBoard[1][1];
Edit7->Text=GameBoard[1][2];
Edit8->Text=GameBoard[1][3];
Edit9->Text=GameBoard[2][0];
Edit10->Text=GameBoard[2][1];
Edit11->Text=GameBoard[2][2];
Edit12->Text=GameBoard[2][3];
Edit13->Text=GameBoard[3][0];
Edit14->Text=GameBoard[3][1];
Edit15->Text=GameBoard[3][2];
Edit16->Text=GameBoard[3][3];

if(Edit1->Text==0) Edit1->Text=" ";
if(Edit2->Text==0) Edit2->Text=" ";
if(Edit3->Text==0) Edit3->Text=" ";
if(Edit4->Text==0) Edit4->Text=" ";
if(Edit5->Text==0) Edit5->Text=" ";
if(Edit6->Text==0) Edit6->Text=" ";
if(Edit7->Text==0) Edit7->Text=" ";
if(Edit8->Text==0) Edit8->Text=" ";
if(Edit9->Text==0) Edit9->Text=" ";
if(Edit10->Text==0) Edit10->Text=" ";
if(Edit11->Text==0) Edit11->Text=" ";
if(Edit12->Text==0) Edit12->Text=" ";
if(Edit13->Text==0) Edit13->Text=" ";
if(Edit14->Text==0) Edit14->Text=" ";
if(Edit15->Text==0) Edit15->Text=" ";
if(Edit16->Text==0) Edit16->Text=" ";

ScoreBox->Text=Score;

WinCheck();
if(wonORnot==1) win->Text="YOU HAVE WON!!";


}
//---------------------------------------------------------------------------

void __fastcall Tevents::RightClick(TObject *Sender)
{
   Shift_Right();
  RandGen();
Edit1->Text=GameBoard[0][0];
Edit2->Text=GameBoard[0][1];
Edit3->Text=GameBoard[0][2];
Edit4->Text=GameBoard[0][3];
Edit5->Text=GameBoard[1][0];
Edit6->Text=GameBoard[1][1];
Edit7->Text=GameBoard[1][2];
Edit8->Text=GameBoard[1][3];
Edit9->Text=GameBoard[2][0];
Edit10->Text=GameBoard[2][1];
Edit11->Text=GameBoard[2][2];
Edit12->Text=GameBoard[2][3];
Edit13->Text=GameBoard[3][0];
Edit14->Text=GameBoard[3][1];
Edit15->Text=GameBoard[3][2];
Edit16->Text=GameBoard[3][3];

if(Edit1->Text==0) Edit1->Text=" ";
if(Edit2->Text==0) Edit2->Text=" ";
if(Edit3->Text==0) Edit3->Text=" ";
if(Edit4->Text==0) Edit4->Text=" ";
if(Edit5->Text==0) Edit5->Text=" ";
if(Edit6->Text==0) Edit6->Text=" ";
if(Edit7->Text==0) Edit7->Text=" ";
if(Edit8->Text==0) Edit8->Text=" ";
if(Edit9->Text==0) Edit9->Text=" ";
if(Edit10->Text==0) Edit10->Text=" ";
if(Edit11->Text==0) Edit11->Text=" ";
if(Edit12->Text==0) Edit12->Text=" ";
if(Edit13->Text==0) Edit13->Text=" ";
if(Edit14->Text==0) Edit14->Text=" ";
if(Edit15->Text==0) Edit15->Text=" ";
if(Edit16->Text==0) Edit16->Text=" ";

ScoreBox->Text=Score;

WinCheck();
if(wonORnot==1) win->Text="YOU HAVE WON!!";
}


//---------------------------------------------------------------------------

void __fastcall Tevents::UpClick(TObject *Sender)
{
Shift_Up();
  RandGen();
Edit1->Text=GameBoard[0][0];
Edit2->Text=GameBoard[0][1];
Edit3->Text=GameBoard[0][2];
Edit4->Text=GameBoard[0][3];
Edit5->Text=GameBoard[1][0];
Edit6->Text=GameBoard[1][1];
Edit7->Text=GameBoard[1][2];
Edit8->Text=GameBoard[1][3];
Edit9->Text=GameBoard[2][0];
Edit10->Text=GameBoard[2][1];
Edit11->Text=GameBoard[2][2];
Edit12->Text=GameBoard[2][3];
Edit13->Text=GameBoard[3][0];
Edit14->Text=GameBoard[3][1];
Edit15->Text=GameBoard[3][2];
Edit16->Text=GameBoard[3][3];

if(Edit1->Text==0) Edit1->Text=" ";
if(Edit2->Text==0) Edit2->Text=" ";
if(Edit3->Text==0) Edit3->Text=" ";
if(Edit4->Text==0) Edit4->Text=" ";
if(Edit5->Text==0) Edit5->Text=" ";
if(Edit6->Text==0) Edit6->Text=" ";
if(Edit7->Text==0) Edit7->Text=" ";
if(Edit8->Text==0) Edit8->Text=" ";
if(Edit9->Text==0) Edit9->Text=" ";
if(Edit10->Text==0) Edit10->Text=" ";
if(Edit11->Text==0) Edit11->Text=" ";
if(Edit12->Text==0) Edit12->Text=" ";
if(Edit13->Text==0) Edit13->Text=" ";
if(Edit14->Text==0) Edit14->Text=" ";
if(Edit15->Text==0) Edit15->Text=" ";
if(Edit16->Text==0) Edit16->Text=" ";

ScoreBox->Text=Score;

WinCheck();
if(wonORnot==1) win->Text="YOU HAVE WON!!";
 }

//---------------------------------------------------------------------------

void __fastcall Tevents::DownClick(TObject *Sender)
{
Shift_Down();
 RandGen();
Edit1->Text=GameBoard[0][0];
Edit2->Text=GameBoard[0][1];
Edit3->Text=GameBoard[0][2];
Edit4->Text=GameBoard[0][3];
Edit5->Text=GameBoard[1][0];
Edit6->Text=GameBoard[1][1];
Edit7->Text=GameBoard[1][2];
Edit8->Text=GameBoard[1][3];
Edit9->Text=GameBoard[2][0];
Edit10->Text=GameBoard[2][1];
Edit11->Text=GameBoard[2][2];
Edit12->Text=GameBoard[2][3];
Edit13->Text=GameBoard[3][0];
Edit14->Text=GameBoard[3][1];
Edit15->Text=GameBoard[3][2];
Edit16->Text=GameBoard[3][3];

if(Edit1->Text==0) Edit1->Text=" ";
if(Edit2->Text==0) Edit2->Text=" ";
if(Edit3->Text==0) Edit3->Text=" ";
if(Edit4->Text==0) Edit4->Text=" ";
if(Edit5->Text==0) Edit5->Text=" ";
if(Edit6->Text==0) Edit6->Text=" ";
if(Edit7->Text==0) Edit7->Text=" ";
if(Edit8->Text==0) Edit8->Text=" ";
if(Edit9->Text==0) Edit9->Text=" ";
if(Edit10->Text==0) Edit10->Text=" ";
if(Edit11->Text==0) Edit11->Text=" ";
if(Edit12->Text==0) Edit12->Text=" ";
if(Edit13->Text==0) Edit13->Text=" ";
if(Edit14->Text==0) Edit14->Text=" ";
if(Edit15->Text==0) Edit15->Text=" ";
if(Edit16->Text==0) Edit16->Text=" ";


ScoreBox->Text=Score;

WinCheck();
if(wonORnot==1) win->Text="YOU HAVE WON!!";


}
//---------------------------------------------------------------------------

void __fastcall Tevents::RandomClick(TObject *Sender)
{
RandGen();
Edit1->Text=GameBoard[0][0];
Edit2->Text=GameBoard[0][1];
Edit3->Text=GameBoard[0][2];
Edit4->Text=GameBoard[0][3];
Edit5->Text=GameBoard[1][0];
Edit6->Text=GameBoard[1][1];
Edit7->Text=GameBoard[1][2];
Edit8->Text=GameBoard[1][3];
Edit9->Text=GameBoard[2][0];
Edit10->Text=GameBoard[2][1];
Edit11->Text=GameBoard[2][2];
Edit12->Text=GameBoard[2][3];
Edit13->Text=GameBoard[3][0];
Edit14->Text=GameBoard[3][1];
Edit15->Text=GameBoard[3][2];
Edit16->Text=GameBoard[3][3];

if(Edit1->Text==0) Edit1->Text=" ";
if(Edit2->Text==0) Edit2->Text=" ";
if(Edit3->Text==0) Edit3->Text=" ";
if(Edit4->Text==0) Edit4->Text=" ";
if(Edit5->Text==0) Edit5->Text=" ";
if(Edit6->Text==0) Edit6->Text=" ";
if(Edit7->Text==0) Edit7->Text=" ";
if(Edit8->Text==0) Edit8->Text=" ";
if(Edit9->Text==0) Edit9->Text=" ";
if(Edit10->Text==0) Edit10->Text=" ";
if(Edit11->Text==0) Edit11->Text=" ";
if(Edit12->Text==0) Edit12->Text=" ";
if(Edit13->Text==0) Edit13->Text=" ";
if(Edit14->Text==0) Edit14->Text=" ";
if(Edit15->Text==0) Edit15->Text=" ";
if(Edit16->Text==0) Edit16->Text=" ";
}
//---------------------------------------------------------------------------

void __fastcall Tevents::EndClick(TObject *Sender)
{
   Application->Terminate();
}
//---------------------------------------------------------------------------



