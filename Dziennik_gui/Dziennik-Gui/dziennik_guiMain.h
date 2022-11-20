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
#include <wx/combobox.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
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
        void OnClose(wxCloseEvent& event);
        void OnListCtrlSubjectListBeginDrag(wxListEvent& event);
        void OnPanelTeachersPaint(wxPaintEvent& event);
        void OnTextCtrlSubjectEditorText(wxCommandEvent& event);
        void OnButtonLoginCancelClick(wxCommandEvent& event);
        void OnButtonSaveSubjectClick(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnNotebookMainPageChanged(wxNotebookEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        //*)

        void removeAllPages();
        void setViewAsNewDb();
        void setViewAsNoLogged();
        void setViewAsTeacher();
        void setViewAsStudent();
        void setViewAsAdmin();

        void refreshSubjectList();

        void OnSubjectListItemClicked(wxListEvent &e);



        void refreshSubjectSelection();
        bool isSubjectSelected=true;
        bool isSubjectInEditModde=false;
        int selectedSubjectId=-1;

        void checkVariables();
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
        static const long ID_LISTCTRLTEACHERS;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT9;
        static const long ID_DATEPICKERCTRL1;
        static const long ID_STATICTEXT11;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT10;
        static const long ID_COMBOBOX1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_PANELTEACHERS;
        static const long ID_LISTCTRLSUBJECTSLIST;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRLSUBJECTEDITOR;
        static const long ID_BUTTONSAVESUBJECT;
        static const long ID_BUTTONDELTETSUBJCECT;
        static const long ID_BUTTONLOGINCANCLE;
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
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* ButtonDeleteSubject;
        wxButton* ButtonLogin;
        wxButton* ButtonLoginCancel;
        wxButton* ButtonRegister;
        wxButton* ButtonSaveSubject;
        wxComboBox* ComboBox1;
        wxDatePickerCtrl* DatePickerCtrl1;
        wxFileDialog* FileDialog1;
        wxListCtrl* ListCtrlSubjectList;
        wxListCtrl* ListCtrlTeachers;
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
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrlLoginNick;
        wxTextCtrl* TextCtrlLoginPassword;
        wxTextCtrl* TextCtrlNick;
        wxTextCtrl* TextCtrlPassRegister;
        wxTextCtrl* TextCtrlRegisterReapeatPassword;
        wxTextCtrl* TextCtrlSubjectEditor;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DZIENNIK_GUIMAIN_H
