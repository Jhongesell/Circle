//////////////////////////////////////////////////////////////////////////////////////////////
// CIRCULO WINDOWS C++ 1.0                                                                  //
//                                                                                          //
// Análisis y Diseño:                                                                       //
//                                                                                          //
// Humberto Andres Carrillo Calvet                                                          //
// Antonio Carrillo Ledesma                                                                 //
// Oscar García Regis                                                                       //
// Miguel Angel Mendoza Reyes                                                               //
// Fernando Alberto Ongay Larios                                                            //
//                                                                                          //
// Programación:                                                                            //
//                                                                                          //
// Humberto Andres Carrillo Calvet                                                          //
// Antonio Carrillo Ledesma                                                                 //
//                                                                                          //
//////////////////////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop
USEFORM("VentanaPrincipal.cpp", FormaPrincipal);
USEFORM("Acecade.cpp", VAcercaDe);
USEFORM("..\..\Libreria\FORMAS\Lmensaje.cpp", LMensajeForm);
USEFORM("..\..\Libreria\FORMAS\Ayuda.cpp", AyudaForm);
USEFORM("..\..\Libreria\FORMAS\Editor.cpp", EditorForm);
USEFORM("..\..\Libreria\FORMAS\EnviarCorreo.cpp", FormaEnviarCorreo);
USEFORM("..\..\Libreria\FORMAS\ACX-WebBrowser.cpp", FormaWebBrowzer);
USEFORM("..\..\Libreria\FORMAS\VEditor.cpp", VentanaCaptura);
USEFORM("..\Libreria\Formas\ParamBifurcaciones.cpp", VCap_Bifurcaciones);
USEFORM("..\Libreria\Formas\ParamCirculo.cpp", VCap_Circunferencia);
USEFORM("..\Libreria\Formas\ParamEscalera.cpp", VCap_Escalera);
USEFORM("..\Libreria\Formas\ParamGlobales.cpp", VCap_General);
USEFORM("..\Libreria\Formas\ParamLenguas.cpp", VCap_Lenguas);
USEFORM("..\Libreria\Formas\ParamLevantamientos.cpp", VCap_Levantamientos);
USEFORM("..\Libreria\Formas\ParamToro.cpp", VCap_Toro);
USEFORM("..\Libreria\Formas\VentanaBifurcaciones.cpp", FormaBifurcaciones);
USEFORM("..\Libreria\Formas\VentanaCirculo.cpp", FormaCirculo);
USEFORM("..\Libreria\Formas\VentanaEscalera.cpp", FormaEscalera);
USEFORM("..\Libreria\Formas\VentanaLenguas.cpp", FormaLenguas);
USEFORM("..\Libreria\Formas\VentanaLevantamientos.cpp", FormaLevantamientos);
USEFORM("..\Libreria\Formas\VentanaToro.cpp", FormaToro);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "";
                 Application->CreateForm(__classid(TFormaPrincipal), &FormaPrincipal);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------

