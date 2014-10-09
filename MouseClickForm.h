//---------------------------------------------------------------------------

#ifndef MouseClickFormH
#define MouseClickFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMouseClickForm : public TForm
{
__published:	// IDE-managed Components
        TTimer *MouseTimer;
        TTimer *FocusTimer;
        TPanel *PanelSetPosition;
        TEdit *EditX;
        TEdit *EditY;
        TLabel *LabelX;
        TLabel *LabelY;
        TPanel *PanelCurrentPosition;
        TLabel *LabelCurrentX;
        TLabel *LabelCurrentY;
        TPanel *PanelTimer;
        TLabel *LabelSetTimer;
        TEdit *EditTimer;
        TImage *ImageArrow;
        TButton *ExitButton;
        TButton *SetButton;
        TButton *StopButton;
        TButton *StartButton;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *MenuSet;
        TMenuItem *MenuStart;
        TMenuItem *MenuStop;
        TMenuItem *MenuExit;
        TMenuItem *Options1;
        TMenuItem *RightMouseMode1;
        TMenuItem *LeftMouseMode1;
        TMenuItem *Seconds1;
        TMenuItem *Milliseconds1;
        TMenuItem *KeyMode1;
        TMenuItem *Random1;
        TComboBox *ComboBox;
        TButton *AboutButton;
        TMenuItem *AboutMenu;
        void __fastcall MouseTimerTimer(TObject *Sender);
        void __fastcall FocusTimerTimer(TObject *Sender);
        void __fastcall StartButtonClick(TObject *Sender);
        void __fastcall EditKeyPress(TObject *Sender, char &Key);
        void __fastcall ExitButtonClick(TObject *Sender);
        void __fastcall ImageArrowMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ImageArrowMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
        void __fastcall SetButtonClick(TObject *Sender);
        void __fastcall StopButtonClick(TObject *Sender);
        void __fastcall MenuSetClick(TObject *Sender);
        void __fastcall MenuExitClick(TObject *Sender);
        void __fastcall MenuStartClick(TObject *Sender);
        void __fastcall MenuStopClick(TObject *Sender);
        void __fastcall EditTimerKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall Seconds1Click(TObject *Sender);
        void __fastcall Milliseconds1Click(TObject *Sender);
        void __fastcall RightMouseMode1Click(TObject *Sender);
        void __fastcall LeftMouseMode1Click(TObject *Sender);
        void __fastcall KeyMode1Click(TObject *Sender);
        void __fastcall Random1Click(TObject *Sender);
        void __fastcall AboutButtonClick(TObject *Sender);
        void __fastcall AboutMenuClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TMouseClickForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMouseClickForm *MouseClickForm;
//---------------------------------------------------------------------------
#endif