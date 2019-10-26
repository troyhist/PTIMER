// =======================================================================
// Sergy's Timer ver. 1.0 (C, CPP)
// Troy computing, Inc.
// Copyright (c) 1994-'2000
// -----------------------------------------------------------------------
// Win32 timer. Double click at "Label2" sets the flag "Seconds' roundoff"
// Used library: <none>
// -----------------------------------------------------------------------
// File: Timer.cpp
// -----------------------------------------------------------------------
//     Compiler: Borland C++ Builder 3.0 (Build 3.70)
//  Application: Win32 GUI
// -----------------------------------------------------------------------
// Made date: 07/ IV.2000
// Last edit: 24/ IV.2000
//     Build: 34
// =======================================================================
//------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Timer.h"
//------------------------------------------------------------------------
#include <stdio.h>      //  sprintf
//------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "perfgrap"
#pragma link "cgrid"
#pragma link "pies"
#pragma link "cdiroutl"
#pragma link "ccalendr"
#pragma link "cspin"
#pragma resource "*.dfm"
TFTimer *FTimer;
// =======================================================================
void TFTimer::RedrawTimedValue(void)
{
// -----------------------------------------------------------------------
// Description: Redraws timeD value
//   Parametrs: <none>
//      Return: <none>
// -----------------------------------------------------------------------
char temp[80];
sprintf(temp, "%02d:%02d:%02d.%02d", thour0, tmin0, tsec0, tms0/10);
Edit2->Text=temp;
}
// =======================================================================
void TFTimer::RedrawTimerValue(void)
{
// -----------------------------------------------------------------------
// Description: Redraws timer value
//   Parametrs: <none>
//      Return: <none>
// -----------------------------------------------------------------------
char temp[80];
sprintf(temp, "%02d:%02d:%02d.%02d", thour, tmin, tsec, tms/10);
Edit1->Text=temp;
}
// =======================================================================
__fastcall TFTimer::TFTimer(TComponent* Owner)
    : TForm(Owner)
{
// -----------------------------------------------------------------------
ResetClick(NULL);
running=0;                  // Timer doesn't run
roundoff=0;                 // Don't roundoff seconds
}
// =======================================================================
void __fastcall TFTimer::QuitClick(TObject *Sender)
{
FTimer->Close();
}
// =======================================================================
void __fastcall TFTimer::Timer1Timer(TObject *Sender)
{
if (running)
    {
    SYSTEMTIME tm; GetLocalTime(&tm);
    // -------------------------------------------------------------------
    if (tm.wMilliseconds<tmsR) {tm.wMilliseconds+=(WORD)1000; tm.wSecond--; }
    if (tm.wSecond<tsecR) {tm.wSecond+=(WORD)60; tm.wMinute--; }
    if (tm.wMinute<tminR) {tm.wMinute+=(WORD)60; tm.wHour--; }
    if (tm.wHour<thourR) {tm.wHour+=(WORD)24; }
    // -------------------------------------------------------------------
    tms=tm.wMilliseconds-tmsR+tms0;
    tsec=tm.wSecond-tsecR+tsec0;
    tmin=tm.wMinute-tminR+tmin0;
    thour=tm.wHour-thourR+thour0;
    //*
    if (tms>=1000) { tms=0;  tsec++; }
    if (tsec>=60)  { tsec=0; tmin++; }
    if (tmin>=60)  { tmin=0; thour++; }
    if (thour>=24) { thour=0; }//*/
    // -------------------------------------------------------------------
    RedrawTimerValue();
    }
}
// =======================================================================
void __fastcall TFTimer::StartClick(TObject *Sender)
{
running=!running;
Start->Caption=running?"&Stop":"&Start";
if (running)
    {
    // -------------------------------------------------------------------
    // Timer was Started (remebering time of Start)
    // -------------------------------------------------------------------
    SYSTEMTIME tm; GetLocalTime(&tm);
    // -------------------------------------------------------------------
    // Remebering the Real time
    // -------------------------------------------------------------------
    tmsR=tm.wMilliseconds;tsecR=tm.wSecond;tminR=tm.wMinute;thourR=tm.wHour;
    // -------------------------------------------------------------------
    thour0=thour; tmin0=tmin; tsec0=tsec; tms0=tms;
    }
else
    {
    // -------------------------------------------------------------------
    // Timer was Stopped
    // -------------------------------------------------------------------
    if (tms<tms0) {tms+=1000; tsec--; }
    if (tsec<tsec0) {tsec+=60; tmin--; }
    if (tmin<tmin0) {tmin+=60; thour--; }
    if (thour<thour0) {thour+=24;}
    // -------------------------------------------------------------------
    tms0=tms-tms0;
    tsec0=tsec-tsec0; if (roundoff) if (tms0) {tms0=0; tsec0++; }
    tmin0=tmin-tmin0; if (roundoff) if (tsec0) {tsec0=0; tmin0++; }
    thour0=thour-thour0;
    RedrawTimedValue();
    // -------------------------------------------------------------------
    }
}
// =======================================================================
void __fastcall TFTimer::ResetClick(TObject *Sender)
{
// -----------------------------------------------------------------------
SYSTEMTIME tm; GetLocalTime(&tm);
// -----------------------------------------------------------------------
// Remebering the Real time
// -----------------------------------------------------------------------
tmsR=tm.wMilliseconds;tsecR=tm.wSecond;tminR=tm.wMinute;thourR=tm.wHour;
// -----------------------------------------------------------------------
thour0=tmin0=tsec0=tms0=0;
thour=tmin=tsec=tms=0;
RedrawTimerValue();
}
// =======================================================================
void __fastcall TFTimer::Label2DblClick(TObject *Sender)
{
roundoff=!roundoff;
}
// =======================================================================

