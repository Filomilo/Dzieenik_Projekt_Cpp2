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
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/textdlg.h>
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
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrlNickRegisterText(wxCommandEvent& event);
        void OnTextCtrlNickText(wxCommandEvent& event);
        void OnTextCtrlPassRegisterText(wxCommandEvent& event);
        void OnButtonRegisterClick(wxCommandEvent& event);
        //*)

        void removeAllPages();

        //(*Identifiers(dziennik_guiFrame)
        static const long ID_TEXTCTRLNICK;
        static const long ID_TEXTCTRLPASSREGISTER;
        static const long ID_BUTTONREGISTER;
        static const long ID_PANELCREATEADMIN;
        static const long ID_BUTTON2;
        static const long ID_CHECKBOX1;
        static const long ID_PANEL1;
        static const long ID_NOTEBOOKMAIN;
        static const long ID_MENUITEM1;
        static const long idMenuNewFIle;
        static const long idMenuOpenFile;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_PASSWORDENTRYDIALOG1;
        //*)

        //(*Declarations(dziennik_guiFrame)
        wxButton* Button2;
        wxButton* ButtonRegister;
        wxCheckBox* CheckBox1;
        wxFileDialog* FileDialog1;
        wxMenu Menu3;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxNotebook* NotebookMain;
        wxPanel* Panel1;
        wxPanel* PanelCreateAdmin;
        wxPasswordEntryDialog* PasswordEntryDialog1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrlNick;
        wxTextCtrl* TextCtrlPassRegister;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DZIENNIK_GUIMAIN_H
