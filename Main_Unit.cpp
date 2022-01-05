/*******************************************************************************
*      Fichier            : Main_Unit.cpp                                      *
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

#include <vcl.h>
#include <tlhelp32.h>// pour les fonctions utilisées dans la fonction qui termine un programme
#include <iostream.h>// pour cout
#pragma hdrstop

#include "Main_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain_Form *Main_Form;
//---------------------------------------------------------------------------
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

/**----------------------------------------------------------------------------*
*                     Kill_Process                                             *
*       Déscription :                                                          *
*               Cette fonction permet de terminer un proessus                  *
*       Paramètres :                                                           *
*               - char *Process_Name : le nom du processus à terminer          *
*       Valeurs retournées :                                                   *
*               - true : la fonction a réussi.                                 *
*               - false : la fonction a échoué.                                *
*       Remarque :                                                             *
*               le code de cette fonction est Distribué par :                  *
*               http://www.developpez.com ; Auteur : MiGoN                     *
*                                                                              *
*-----------------------------------------------------------------------------*/
bool __fastcall  Kill_Process(char *Process_Name)
{
        //Recherche du processus:
        HANDLE hSnapShot;
        PROCESSENTRY32 uProcess;
        bool r;
        unsigned int PID = 0; //variable qui va stocker l'ID du processus de l'application que l'on désire fermer.

        hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL,0);
        uProcess.dwSize = (DWORD) sizeof(PROCESSENTRY32);

        r = Process32First(hSnapShot, &uProcess);
        do   // Cette boucle énnumère tout les processus
        {
                //on cherche le nom de notre application dans le chemin d'accès de l'éxécutable du processus.
                if ( !strcmp(uProcess.szExeFile, Process_Name) )
                PID = (unsigned int) uProcess.th32ProcessID;

                r = Process32Next(hSnapShot, &uProcess);
        } while ( r );

        CloseHandle(hSnapShot);

        if ( PID == 0)
        {
                return false;
        }

        //Fermeture du processus:
        HANDLE hTemp = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD) PID);
        TerminateProcess(hTemp,0);

        return true;
}
/*-----------------------------------------------------------------------------*
*                       </Kill_Process>                                        *
*-----------------------------------------------------------------------------*/

void __fastcall TMain_Form::Terminate_SpeedButtonClick(TObject *Sender)
{
        if(Process_Edit->Text=="")
        {
                MessageDlg("Veuillez entrer le nom du processus à termier",mtWarning,TMsgDlgButtons() << mbOK,0);
        }
        else
        {
                Kill_Process(Process_Edit->Text.c_str());
        }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::About_LabelClick(TObject *Sender)
{
        MessageDlg("ZM Process Killer v0.23.11.2008\nProgrammé par : Mohammed ZAGANE\nE-mail : zagmoh2005@yahoo.fr\nsite web  : http://zaagane-mohammed.ifrance.com",mtInformation,TMsgDlgButtons() << mbOK,0);
}
//---------------------------------------------------------------------------
