/***************************************************************
 * Name:      dziennik_guiApp.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2022-11-12
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef DZIENNIK_GUIAPP_H
#define DZIENNIK_GUIAPP_H

#include <wx/app.h>
#include <sqlite3.h>
#include <DziennikLib.h>
#include <DziennikLib_adders.cpp>
#include <DziennikLib_callbacks.cpp>
#include <DziennikLib_communication.cpp>
#include <DziennikLib_constants.cpp>
#include <DziennikLib_execute.cpp>
#include <DziennikLib_find.cpp>
#include <DziennikLib_insert.cpp>
#include <DziennikLib_manager.cpp>
#include <DziennikLib_print.cpp>
#include <DziennikLib_testing.cpp>
#include <DziennikLib_tools.cpp>
#include <DziennikLib_update.cpp>
#include <DziennikLib_validators.cpp>
#include <DziennkLib_account.cpp>

class dziennik_guiApp : public wxApp
{
    public:
        virtual bool OnInit();
        DziennikLib* dziennik;
};

#endif // DZIENNIK_GUIAPP_H
