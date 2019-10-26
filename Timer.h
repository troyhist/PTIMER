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
// Last edit: 08/ IV.2000
//     Build: 1
// =======================================================================
//------------------------------------------------------------------------
#ifndef TimerH
#define TimerH
//------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "perfgrap.h"
#include "cgrid.h"
#include "pies.h"
#include "cdiroutl.h"
#include <Grids.hpp>
#include <Outline.hpp>
#include "ccalendr.h"
#include "cspin.h"
#include <ExtCtrls.hpp>
//------------------------------------------------------------------------
class TFTimer : public TForm
{
__published:	// IDE-managed Components
    TButton *Start;
    TButton *Quit;
    TButton *Reset;
    TEdit *Edit2;
    TLabel *Label1;
    TEdit *Edit1;
    TLabel *Label2;
    TTimer *Timer1;
    void __fastcall QuitClick(TObject *Sender);
    void __fastcall StartClick(TObject *Sender);
    void __fastcall ResetClick(TObject *Sender);    
    void __fastcall Label2DblClick(TObject *Sender);
    
    

    
    void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
    //--------------------------------------------------------------------
    int thour, tmin, tsec, tms; // calculeted hours, minutes, seconds, milli
    int thour0, tmin0, tsec0, tms0; // previous values
    int thourR, tminR, tsecR, tmsR; // real time values
    int running;                // Flag: "Does timer run"
    int roundoff;               // Flag: "Roundoff seconds"
    //--------------------------------------------------------------------
    void RedrawTimedValue(void);
    void RedrawTimerValue(void);
    void Timer(void);
    //--------------------------------------------------------------------
    __fastcall TFTimer(TComponent* Owner);
};
//------------------------------------------------------------------------
extern PACKAGE TFTimer *FTimer;
//------------------------------------------------------------------------
#endif
