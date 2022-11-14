/***************************************************************
 * Name:      dziennik_guiApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2022-11-12
 * Copyright:  ()
 * License:
 **************************************************************/

#include "dziennik_guiApp.h"
#include <iostream>
//(*AppHeaders
#include "dziennik_guiMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(dziennik_guiApp);

bool dziennik_guiApp::OnInit()
{
    std::cout<<"initilizaed console for test, needs to be delted late"<<std::endl;
    this->dziennik= new DziennikLib;
    dziennik->loadDataBase("dataBsse2.db");
    dziennik->printDataBase();
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	dziennik_guiFrame* Frame = new dziennik_guiFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
