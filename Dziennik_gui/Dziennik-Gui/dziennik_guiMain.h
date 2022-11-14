/***************************************************************
 * Name:      dziennik_guiMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2022-11-12
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef DZIENNIK_GUIMAIN_H
#define DZIENNIK_GUIMAIN_H

//(*Headers(dziennik_guiFrame)
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include <sqlite3.h>
#include <DziennikLib.h>


class dziennik_guiFrame: public wxFrame
{
    public:
        DziennikLib* dziennik;
        dziennik_guiFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~dziennik_guiFrame();

    private:

        //(*Handlers(dziennik_guiFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnNewFile(wxCommandEvent& event);
        void OnOpenFile(wxCommandEvent& event);
        //*)

        //(*Identifiers(dziennik_guiFrame)
        static const long ID_MENUITEM1;
        static const long idMenuNewFIle;
        static const long idMenuOpenFile;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(dziennik_guiFrame)
        wxFileDialog* FileDialogOpenDataBase;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DZIENNIK_GUIMAIN_H
