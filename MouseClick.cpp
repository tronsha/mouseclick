//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#include <time.h>
#pragma hdrstop
USERES("MouseClick.res");
USEFORM("MouseClickForm.cpp", MouseClickForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    time_t t;
    srand((unsigned) time(&t));

    try
    {
        Application->Initialize();
        Application->Title = "MouseClick";
        Application->CreateForm(__classid(TMouseClickForm), &MouseClickForm);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------