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
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
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
        void OnTextCtrlRegisterReapeatPasswordText(wxCommandEvent& event);
        void OnButtonLoginClick(wxCommandEvent& event);
        //*)

        void removeAllPages();
        void setViewAsNewDb();
        void setViewAsNoLogged();
        void setViewAsTeacher();
        void setViewAsStudent();
        void setViewAsAdmin();

        //(*Identifiers(dziennik_guiFrame)
        static const long ID_TEXTCTRLNICK;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRLPASSREGISTER;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRLREGISTERREAPEATPASSWORD;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTONREGISTER;
        static const long ID_PANELCREATEADMIN;
        static const long ID_TEXTCTRLLOGINNICK;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRLLOGINPASSWORD;
        static const long ID_STATICTEXT4;
        static const long ID_BUTTONLOGIN;
        static const long ID_PANELLOGIN;
        static const long ID_PANELStudents;
        static const long ID_PANELMYGRADES;
        static const long ID_PANELYOURSTUdNETS;
        static const long ID_PANELTEACHERS;
        static const long ID_PANELSUBJECTS;
        static const long ID_NOTEBOOKMAIN;
        static const long idMenuNewFIle;
        static const long idMenuOpenFile;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_PASSWORDENTRYDIALOG1;
        //*)

        //(*Declarations(dziennik_guiFrame)
        wxButton* ButtonLogin;
        wxButton* ButtonRegister;
        wxFileDialog* FileDialog1;
        wxMenu Menu3;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxNotebook* NotebookMain;
        wxPanel* PanelCreateAdmin;
        wxPanel* PanelLogin;
        wxPanel* PanelMyGrades;
        wxPanel* PanelStudents;
        wxPanel* PanelSubjects;
        wxPanel* PanelTeachers;
        wxPanel* PanelYourStudentes;
        wxPasswordEntryDialog* PasswordEntryDialog1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrlLoginNick;
        wxTextCtrl* TextCtrlLoginPassword;
        wxTextCtrl* TextCtrlNick;
        wxTextCtrl* TextCtrlPassRegister;
        wxTextCtrl* TextCtrlRegisterReapeatPassword;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DZIENNIK_GUIMAIN_H
