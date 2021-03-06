//////////////////////////////////////////////////////////////////////////////////////////////
// CIRCULO WINDOWS C++ 1.0                                                                  //
//                                                                                          //
// An�lisis y Dise�o:                                                                       //
//                                                                                          //
// Humberto Andres Carrillo Calvet                                                          //
// Antonio Carrillo Ledesma                                                                 //
// Oscar Garc�a Regis                                                                       //
// Miguel Angel Mendoza Reyes                                                               //
// Fernando Alberto Ongay Larios                                                            //
//                                                                                          //
// Programaci�n:                                                                            //
//                                                                                          //
// Humberto Andres Carrillo Calvet                                                          //
// Antonio Carrillo Ledesma                                                                 //
//                                                                                          //
//////////////////////////////////////////////////////////////////////////////////////////////

#include <vcl\vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include "ParamLenguas.h"
#pragma hdrstop


//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

// Constructor de la ventana
__fastcall TVCap_Lenguas::TVCap_Lenguas(TComponent* Owner) : TForm(Owner)
{
   Aceptar = false;
}

// Al presionar el boton de aceptar
void __fastcall TVCap_Lenguas::Button1Click(TObject *Sender)
{
   // Valida que sean distintos
   if (ComboBox1->ItemIndex == ComboBox2->ItemIndex) return;
   Aceptar = true;
   Close();        
}

// Activa la captura del par�metro seleccionado
void __fastcall TVCap_Lenguas::ListBoxParametrosClick(TObject *Sender)
{
   unsigned int Log_max_param = 6; // longitud m�xima del nombre del par�metro
   unsigned int i1, i2;
   int i;
   for (i = 0; i < ListBoxParametros->Items->Count; i++) {
       if (ListBoxParametros->Selected[i]) {
           char xcad[100], xcad1[100];
           // Nombre del par�metro
           AnsiString txt1(ListBoxParametros->Items->Strings[i]);
           strcpy(xcad1,txt1.c_str());
           for (i1 = 0; i1 < Log_max_param; i1++) { 
               if (xcad1[i1] != ' ') xcad[i1] = xcad1[i1];
                else break;
           }
           xcad[i1] = ':';
           xcad[i1+1] = 0;
           NombreParametro->Caption = xcad;
           // Valor del par�metro
           for (i2 = 0, i1 = (Log_max_param + 3); i1 < strlen(xcad1); i2++, i1++) { 
               xcad[i2] = xcad1[i1];
           }
           xcad[i2] = 0;
           EditValorParametro->Text = xcad;
           // Se hace visible el nombre y valor del par�metro
           NombreParametro->Visible = true;
           EditValorParametro->Visible = true;
           break;
       }
   }
}

// Cambia el valor del par�metro activo
void __fastcall TVCap_Lenguas::EditValorParametroKeyPress(TObject *Sender, char &Key)
{
   if (Key == VK_RETURN) {
      Key = 0;
      PostMessage(Handle, WM_NEXTDLGCTL,0,0);
      char xcad[100], xcad1[100];
      AnsiString txt1(NombreParametro->Caption);
      strcpy(xcad1,txt1.c_str());
      AnsiString txt2(EditValorParametro->Text);
      sprintf(xcad,"%-6s = %1.9f",xcad1,atof(txt2.c_str()));
      for (int i = 0; i < ListBoxParametros->Items->Count; i++) {
          if (ListBoxParametros->Selected[i]) ListBoxParametros->Items->Strings[i] = xcad; 
      }    
      NombreParametro->Visible = false;
      EditValorParametro->Visible = false;     
   }
}

