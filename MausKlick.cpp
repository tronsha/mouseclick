//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#include <time.h>
#pragma hdrstop
USERES("MausKlick.res");
USEFORM("klick.cpp", MausForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        time_t zeit;
        time(&zeit);
        srand(zeit);

        try
        {
                 Application->Initialize();
                 Application->Title = "Maus Klick";
                 Application->CreateForm(__classid(TMausForm), &MausForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
