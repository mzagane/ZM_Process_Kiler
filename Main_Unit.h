/*******************************************************************************
*      Fichier            : Main_Unit.h                                        *
*      Programmeur        : ZAGANE Mohammed                                    *
*      Email              : zagmoh2005@yahoo.fr                                *
*      site web           : http://zaagane-mohammed.ifrance.com                *
*      Date source        : samedi 22 novembre 2008                            *
*      Version source     : 0.23.11.2008                                       *
*      Langage            : C++ Builder                                        *
*      Type licence       : libre.                                             *
*      Modification       : dimenche 23 novembre 2008                          *
*******************************************************************************/
//---------------------------------------------------------------------------

#ifndef Main_UnitH
#define Main_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMain_Form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Process_Edit;
        TSpeedButton *Terminate_SpeedButton;
        TLabel *About_Label;
        void __fastcall Terminate_SpeedButtonClick(TObject *Sender);
        void __fastcall About_LabelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
