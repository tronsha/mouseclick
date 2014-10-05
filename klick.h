//---------------------------------------------------------------------------

#ifndef klickH
#define klickH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMausForm : public TForm
{
__published:	// IDE-managed Components
    TTimer *MouseTimer;
    TTimer *FocusTimer;
    TPanel *PanelZiel;
    TEdit *Edit_x;
    TEdit *Edit_y;
    TLabel *Label_x;
    TLabel *Label_y;
    TPanel *PanelOrt;
    TLabel *Label_x_now;
    TLabel *Label_y_now;
    TPanel *PanelTimer;
    TLabel *LabelSetTimer;
    TEdit *EditTimer;
    TImage *ImagePfeil;
    TButton *EndeButton;
    TButton *GetOrtButton;
    TButton *StopButton;
    TButton *StartButton;
    TMainMenu *MainMenu1;
    TMenuItem *Datei1;
    TMenuItem *MenuSet;
    TMenuItem *MenuStart;
    TMenuItem *MenuStop;
    TMenuItem *MenuExit;
    TMenuItem *Extra1;
    TMenuItem *rechts1;
    TMenuItem *links1;
    TMenuItem *sekunden1;
    TMenuItem *millisekunden1;
    TMenuItem *taste1;
    TMenuItem *random1;
    TComboBox *ComboBox;
    void __fastcall MouseTimerTimer(TObject *Sender);
    void __fastcall FocusTimerTimer(TObject *Sender);
    void __fastcall StartButtonClick(TObject *Sender);
    void __fastcall EditKeyPress(TObject *Sender, char &Key);
    void __fastcall EndeButtonClick(TObject *Sender);
    void __fastcall ImagePfeilMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall ImagePfeilMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
    void __fastcall GetOrtButtonClick(TObject *Sender);
    void __fastcall StopButtonClick(TObject *Sender);
    void __fastcall MenuSetClick(TObject *Sender);
    void __fastcall MenuExitClick(TObject *Sender);
    void __fastcall MenuStartClick(TObject *Sender);
    void __fastcall MenuStopClick(TObject *Sender);
    void __fastcall EditTimerKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall sekunden1Click(TObject *Sender);
    void __fastcall millisekunden1Click(TObject *Sender);
    void __fastcall rechts1Click(TObject *Sender);
    void __fastcall links1Click(TObject *Sender);
    void __fastcall taste1Click(TObject *Sender);
    void __fastcall random1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
    __fastcall TMausForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMausForm *MausForm;
//---------------------------------------------------------------------------
#endif