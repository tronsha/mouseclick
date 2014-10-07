//---------------------------------------------------------------------------

#include <vcl.h>
#include <winuser.h>
#include <stdlib.h>
#include <time.h>
#pragma hdrstop

#include "MouseClickForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMouseClickForm *MouseClickForm;
//---------------------------------------------------------------------------
__fastcall TMouseClickForm::TMouseClickForm(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
#define ARROW_TOP 90
#define ARROW_LEFT -5
int oldMouseX;
int oldMouseY;
int mode = 0;
int milli = 1000;
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::MouseTimerTimer(TObject *Sender)
{
    int x = MouseClickForm->EditX->Text.ToInt();
    int y = MouseClickForm->EditY->Text.ToInt();

    int randomtime = rand()%180+60;

    if(Random1->Checked == true)
    {
        EditTimer->Text = randomtime;
        MouseClickForm->MouseTimer->Interval = randomtime*milli;
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

    MouseClickForm->FocusTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::FocusTimerTimer(TObject *Sender)
{
    MouseClickForm->ExitButton->SetFocus();
    MouseClickForm->FocusTimer->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::EditKeyPress(TObject *Sender, char &Key)
{
    if (((Key >= '0')&&(Key <= '9'))||(Key == '\x08'))
        Key = Key;
    else
        Key = '\0';
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::StartButtonClick(TObject *Sender)
{
    if(milli == 1000)
    {
        if (MouseClickForm->EditTimer->Text.ToInt() < 10)
        {
            MouseClickForm->EditTimer->Text = 10;
        }
    }
    else if(milli == 1)
    {
        if (MouseClickForm->EditTimer->Text.ToInt() < 10000)
        {
            MouseClickForm->EditTimer->Text = 10000;
        }
    }

    MouseClickForm->MouseTimer->Interval = MouseClickForm->EditTimer->Text.ToInt()*milli;
    MouseClickForm->MouseTimer->Enabled = true;
    MouseClickForm->StopButton->Enabled = true;
    MouseClickForm->StartButton->Enabled = false;
    MouseClickForm->SetButton->Enabled = false;
    MouseClickForm->MenuStop->Enabled = true;
    MouseClickForm->MenuStart->Enabled = false;
    MouseClickForm->MenuSet->Enabled = false;
    MouseClickForm->EditX->Enabled = false;
    MouseClickForm->EditY->Enabled = false;
    MouseClickForm->EditTimer->Enabled = false;
    MouseClickForm->ComboBox->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::SetButtonClick(TObject *Sender)
{
    EditX->Text = MouseClickForm->Left + ARROW_LEFT;
    EditY->Text = MouseClickForm->Top + ARROW_TOP;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::StopButtonClick(TObject *Sender)
{
    MouseClickForm->MouseTimer->Enabled = false;
    MouseClickForm->StopButton->Enabled = false;
    MouseClickForm->StartButton->Enabled = true;
    MouseClickForm->SetButton->Enabled = true;
    MouseClickForm->MenuStop->Enabled = false;
    MouseClickForm->MenuStart->Enabled = true;
    MouseClickForm->MenuSet->Enabled = true;
    MouseClickForm->EditX->Enabled = true;
    MouseClickForm->EditY->Enabled = true;
    MouseClickForm->EditTimer->Enabled = true;
    MouseClickForm->ComboBox->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::ExitButtonClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::ImageArrowMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button == mbLeft)
    {
        oldMouseX = X;
        oldMouseY = Y;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::ImageArrowMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    int deltaX, deltaY;
    if(Shift.Contains(ssLeft))
    {
        deltaX = X - oldMouseX;
        deltaY = Y - oldMouseY;
        Top = Top + deltaY;
        Left = Left + deltaX;
    }
    LabelCurrentX->Caption = MouseClickForm->Left + ARROW_LEFT;
    LabelCurrentY->Caption = MouseClickForm->Top + ARROW_TOP;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::MenuSetClick(TObject *Sender)
{
    EditX->Text = MouseClickForm->Left + ARROW_LEFT;
    EditY->Text = MouseClickForm->Top + ARROW_TOP;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::MenuExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::MenuStartClick(TObject *Sender)
{
    if(milli == 1000)
    {
        if(MouseClickForm->EditTimer->Text.ToInt() < 10)
        {
            MouseClickForm->EditTimer->Text = 10;
        }
    }
    else if(milli == 1)
    {
        if(MouseClickForm->EditTimer->Text.ToInt() < 10000)
        {
            MouseClickForm->EditTimer->Text = 10000;
        }
    }

    MouseClickForm->MouseTimer->Interval = MouseClickForm->EditTimer->Text.ToInt()*milli;
    MouseClickForm->MouseTimer->Enabled = true;
    MouseClickForm->StopButton->Enabled = true;
    MouseClickForm->StartButton->Enabled = false;
    MouseClickForm->SetButton->Enabled = false;
    MouseClickForm->MenuStop->Enabled = true;
    MouseClickForm->MenuStart->Enabled = false;
    MouseClickForm->MenuSet->Enabled = false;
    MouseClickForm->EditX->Enabled = false;
    MouseClickForm->EditY->Enabled = false;
    MouseClickForm->EditTimer->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::MenuStopClick(TObject *Sender)
{
    MouseClickForm->MouseTimer->Enabled = false;
    MouseClickForm->StopButton->Enabled = false;
    MouseClickForm->StartButton->Enabled = true;
    MouseClickForm->SetButton->Enabled = true;
    MouseClickForm->MenuStop->Enabled = false;
    MouseClickForm->MenuStart->Enabled = true;
    MouseClickForm->MenuSet->Enabled = true;
    MouseClickForm->EditX->Enabled = true;
    MouseClickForm->EditY->Enabled = true;
    MouseClickForm->EditTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::EditTimerKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if(EditTimer->Text != "")
    {
        if(milli == 1)
        {
            double time = EditTimer->Text.ToDouble();
            if (time > 86400000)
                EditTimer->Text = "86400000";
        }
        else if(milli == 1000)
        {
            double time = EditTimer->Text.ToDouble();
            if(time > 86400)
                EditTimer->Text = "86400";
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::Seconds1Click(TObject *Sender)
{
    if(milli == 1)
    {
        milli = 1000;
        ShowMessage("Timer in Seconds");
        if(EditTimer->Text != "")
        {
            double time = EditTimer->Text.ToDouble();
            EditTimer->Text = time / 1000;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::Milliseconds1Click(TObject *Sender)
{
    if(milli == 1000)
    {
        milli = 1;
        ShowMessage("Timer in Milliseconds");
        if(EditTimer->Text != "")
        {
            double time = EditTimer->Text.ToDouble();
            EditTimer->Text = time * 1000;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::RightMouseMode1Click(TObject *Sender)
{
    mode = 1;
    ShowMessage("Right Mouse Button");
    PanelSetPosition->Visible = true;
    PanelCurrentPosition->Visible = true;
    ComboBox->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::LeftMouseMode1Click(TObject *Sender)
{
    mode = 0;
    ShowMessage("Left Mouse Button");
    PanelSetPosition->Visible = true;
    PanelCurrentPosition->Visible = true;
    ComboBox->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::KeyMode1Click(TObject *Sender)
{
    mode = 2;
    ShowMessage("Keyboard Mode");
    PanelSetPosition->Visible = false;
    PanelCurrentPosition->Visible = false;
    ComboBox->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TMouseClickForm::Random1Click(TObject *Sender)
{
    if(Random1->Checked == true)
    {
        Random1->Checked = false;
        ShowMessage("Random Off");
    }
    else
    {
        Random1->Checked = true;
        ShowMessage("Random On");
    }
}
//---------------------------------------------------------------------------

