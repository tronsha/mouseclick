//---------------------------------------------------------------------------

#include <vcl.h>
#include <winuser.h>
#include <stdlib.h>
#include <time.h>
#pragma hdrstop

#include "klick.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMausForm *MausForm;
//---------------------------------------------------------------------------
__fastcall TMausForm::TMausForm(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
#define arrow_top 90
#define arrow_left -5

int mode = 0;
int milli = 1000;
//---------------------------------------------------------------------------

void __fastcall TMausForm::MouseTimerTimer(TObject *Sender)
{
    int x = MausForm->Edit_x->Text.ToInt();
    int y = MausForm->Edit_y->Text.ToInt();

    int randzeit = rand()%180+60;

    if(random1->Checked == true)
    {
        EditTimer->Text = randzeit;
        MausForm->MouseTimer->Interval = randzeit*milli;
    }

    if(mode == 2)
    {
        keybd_event((0x41+ComboBox->ItemIndex), 0x0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
        keybd_event((0x41+ComboBox->ItemIndex), 0x0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    }
    else
    {
        SetCursorPos(x, y);

        if(mode == 1)
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        }
        else
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
    }

    MausForm->FocusTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::FocusTimerTimer(TObject *Sender)
{
    MausForm->EndeButton->SetFocus();
    MausForm->FocusTimer->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::EditKeyPress(TObject *Sender, char &Key)
{
    if (((Key >= '0')&&(Key <= '9'))||(Key == '\x08'))
        Key = Key;
    else
        Key = '\0';
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::StartButtonClick(TObject *Sender)
{
    if(milli == 1000)
    {
        if (MausForm->EditTimer->Text.ToInt() < 10)
        {
            MausForm->EditTimer->Text = 10;
        }
    }
    else if(milli == 1)
    {
        if (MausForm->EditTimer->Text.ToInt() < 10000)
        {
            MausForm->EditTimer->Text = 10000;
        }
    }

    MausForm->MouseTimer->Interval = MausForm->EditTimer->Text.ToInt()*milli;
    MausForm->MouseTimer->Enabled = true;
    MausForm->StopButton->Enabled = true;
    MausForm->StartButton->Enabled = false;
    MausForm->GetOrtButton->Enabled = false;
    MausForm->MenuStop->Enabled = true;
    MausForm->MenuStart->Enabled = false;
    MausForm->MenuSet->Enabled = false;
    MausForm->Edit_x->Enabled = false;
    MausForm->Edit_y->Enabled = false;
    MausForm->EditTimer->Enabled = false;
    MausForm->ComboBox->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::GetOrtButtonClick(TObject *Sender)
{
    Edit_x->Text = MausForm->Left + arrow_left;
    Edit_y->Text = MausForm->Top + arrow_top;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::StopButtonClick(TObject *Sender)
{
    MausForm->MouseTimer->Enabled = false;
    MausForm->StopButton->Enabled = false;
    MausForm->StartButton->Enabled = true;
    MausForm->GetOrtButton->Enabled = true;
    MausForm->MenuStop->Enabled = false;
    MausForm->MenuStart->Enabled = true;
    MausForm->MenuSet->Enabled = true;
    MausForm->Edit_x->Enabled = true;
    MausForm->Edit_y->Enabled = true;
    MausForm->EditTimer->Enabled = true;
    MausForm->ComboBox->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::EndeButtonClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
int igOldMouseX, igOldMouseY;
//---------------------------------------------------------------------------

void __fastcall TMausForm::ImagePfeilMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button == mbLeft)
    {
        igOldMouseX = X;
        igOldMouseY = Y;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::ImagePfeilMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    int iDeltaX, iDeltaY;
    if(Shift.Contains(ssLeft))
    {
        iDeltaX = X - igOldMouseX;
        iDeltaY = Y - igOldMouseY;
        Top = Top + iDeltaY;
        Left = Left + iDeltaX;
    }
    Label_x_now->Caption = MausForm->Left + arrow_left;
    Label_y_now->Caption = MausForm->Top + arrow_top;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::MenuSetClick(TObject *Sender)
{
    Edit_x->Text = MausForm->Left + arrow_left;
    Edit_y->Text = MausForm->Top + arrow_top;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::MenuExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::MenuStartClick(TObject *Sender)
{
    if(milli == 1000)
    {
        if(MausForm->EditTimer->Text.ToInt() < 10)
        {
            MausForm->EditTimer->Text = 10;
        }
    }
    else if(milli == 1)
    {
        if(MausForm->EditTimer->Text.ToInt() < 10000)
        {
            MausForm->EditTimer->Text = 10000;
        }
    }

    MausForm->MouseTimer->Interval = MausForm->EditTimer->Text.ToInt()*milli;
    MausForm->MouseTimer->Enabled = true;
    MausForm->StopButton->Enabled = true;
    MausForm->StartButton->Enabled = false;
    MausForm->GetOrtButton->Enabled = false;
    MausForm->MenuStop->Enabled = true;
    MausForm->MenuStart->Enabled = false;
    MausForm->MenuSet->Enabled = false;
    MausForm->Edit_x->Enabled = false;
    MausForm->Edit_y->Enabled = false;
    MausForm->EditTimer->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::MenuStopClick(TObject *Sender)
{
    MausForm->MouseTimer->Enabled = false;
    MausForm->StopButton->Enabled = false;
    MausForm->StartButton->Enabled = true;
    MausForm->GetOrtButton->Enabled = true;
    MausForm->MenuStop->Enabled = false;
    MausForm->MenuStart->Enabled = true;
    MausForm->MenuSet->Enabled = true;
    MausForm->Edit_x->Enabled = true;
    MausForm->Edit_y->Enabled = true;
    MausForm->EditTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::EditTimerKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if(EditTimer->Text != "")
    {
        if(milli == 1)
        {
            double zeit = EditTimer->Text.ToDouble();
            if (zeit > 86400000)
                EditTimer->Text = "86400000";
        }
        else if(milli == 1000)
        {
            double zeit = EditTimer->Text.ToDouble();
            if(zeit > 86400)
                EditTimer->Text = "86400";
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::sekunden1Click(TObject *Sender)
{
    if(milli == 1)
    {
        milli = 1000;
        ShowMessage("Timer in Seconds");
        if(EditTimer->Text != "")
        {
            double zeit = EditTimer->Text.ToDouble();
            EditTimer->Text = zeit / 1000;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::millisekunden1Click(TObject *Sender)
{
    if(milli == 1000)
    {
        milli = 1;
        ShowMessage("Timer in Milliseconds");
        if(EditTimer->Text != "")
        {
            double zeit = EditTimer->Text.ToDouble();
            EditTimer->Text = zeit * 1000;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::rechts1Click(TObject *Sender)
{
    mode = 1;
    ShowMessage("Right Mouse Button");
    PanelZiel->Visible = true;
    PanelOrt->Visible = true;
    ComboBox->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::links1Click(TObject *Sender)
{
    mode = 0;
    ShowMessage("Left Mouse Button");
    PanelZiel->Visible = true;
    PanelOrt->Visible = true;
    ComboBox->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::taste1Click(TObject *Sender)
{
    mode = 2;
    ShowMessage("Keyboard Mode");
    PanelZiel->Visible = false;
    PanelOrt->Visible = false;
    ComboBox->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TMausForm::random1Click(TObject *Sender)
{
    if(random1->Checked == true)
    {
        random1->Checked = false;
        ShowMessage("Random Off");
    }
    else
    {
        random1->Checked = true;
        ShowMessage("Random On");
    }
}
//---------------------------------------------------------------------------

