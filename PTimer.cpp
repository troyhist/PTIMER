//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("PTimer.res");
USEFORM("Timer.cpp", FTimer);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TFTimer), &FTimer);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
