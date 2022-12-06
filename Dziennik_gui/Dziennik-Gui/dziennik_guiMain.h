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
#include <wx/choice.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/listbox.h>
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
        void OnListCtrlTeachersBeginDrag(wxListEvent& event);
        void OnComboBoxTeacherSubjectSelect(wxCommandEvent& event);
        void OnChangeInTeachers(wxCommandEvent& event);
        void OnButtonCancelTeacherClick(wxCommandEvent& event);
        void OnDatePickerCtrlTeacherBirthdayChanged(wxDateEvent& event);
        void OnButtonSaveTeacherClick(wxCommandEvent& event);
        void OnButtonDeleteTeacherClick(wxCommandEvent& event);
        void OnListCtrlStudentsItemActivated(wxListEvent& event);
        void OnListCtrlStudentsBeginDrag(wxListEvent& event);
        void OnButtonCancelStudentClick(wxCommandEvent& event);
        void OnButtonDeleteStudentClick(wxCommandEvent& event);
        void OnButtonSaveStudentClick(wxCommandEvent& event);
        void OnTextCtrlStudentPeselText(wxCommandEvent& event);
        void OnChangeInStudents(wxCommandEvent& event);
        void OnDatePickerCtrlStudentBirthdayChanged(wxDateEvent& event);
        void OnGridYourStudentListCellChanged(wxGridEvent& event);
        //*)

        void removeAllPages();
        void setViewAsNewDb();
        void setViewAsNoLogged();
        void setViewAsTeacher();
        void setViewAsStudent();
        void setViewAsAdmin();

        void clearLoginData();

        void refreshSubjectList();
        void OnSubjectListItemClicked(wxListEvent &e);
        void refreshSubjectSelection();
        bool isSubjectSelected=true;
        bool isSubjectInEditModde=false;
        int selectedSubjectId=-1;


        void refreshTeacherList();
        void OnTeacherListItemClicked(wxListEvent &e);
        void refreshTeacherSelection();
        bool isTeacherSelected=true;
        bool isTeacherInEditModde=false;
        std::string selectedTeacherId="0";


        void refreshStudentList();
        void OnStudentListItemClicked(wxListEvent &e);
        void refreshStudentSelection();
        bool isStudentSelected=true;
        bool isStudentInEditModde=false;
        std::string selectedStudentId="0";


        void refreshMyGradeList();


        void refreshYourStudentGrid();


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
        static const long ID_LISTCTRLSTUDENTS;
        static const long ID_TEXTCTRLSTUDENTPESEL;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRLSTUDENTNAME;
        static const long ID_STATICTEXT12;
        static const long ID_DATEPICKERCTRLSTUDENTBIRTHDAY;
        static const long ID_STATICTEXT15;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT14;
        static const long ID_BUTTONSAVESTUDENT;
        static const long ID_BUTTONDELETESTUDENT;
        static const long ID_BUTTONCANCELSTUDENT;
        static const long ID_PANELStudents;
        static const long ID_LISTCTRL2;
        static const long ID_PANELMYGRADES;
        static const long ID_GRID1;
        static const long ID_PANELYOURSTUdNETS;
        static const long ID_LISTCTRLTEACHERS;
        static const long ID_TEXTCTRLTEACHERPESEL;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT8;
        static const long ID_DATEPICKERCTRLTEACHERBIRTHDAY;
        static const long ID_STATICTEXT9;
        static const long ID_TEXTCTRLTEACHERSURNAME;
        static const long ID_STATICTEXT11;
        static const long ID_COMBOBOXTEACHERSUBJECT;
        static const long ID_STATICTEXT10;
        static const long ID_BUTTONSAVETEACHER;
        static const long ID_BUTTONDELETETEACHER;
        static const long ID_BUTTONCANCELTEACHER;
        static const long ID_PANELTEACHERS;
        static const long ID_LISTCTRLSUBJECTSLIST;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRLSUBJECTEDITOR;
        static const long ID_BUTTONSAVESUBJECT;
        static const long ID_BUTTONDELTETSUBJCECT;
        static const long ID_BUTTONLOGINCANCLE;
        static const long ID_PANELSUBJECTS;
        static const long ID_GRID2;
        static const long ID_LISTBOXATTANDANCEDATES;
        static const long ID_DATEPICKERCTRLATTANDANCECONTORL;
        static const long ID_BUTTONADDDATEATTADNACECOTROL;
        static const long ID_BUTTONREMOVEDATEATTANDANCECONTROL;
        static const long ID_PANEL1;
        static const long ID_NOTEBOOKMAIN;
        static const long idMenuNewFIle;
        static const long idMenuOpenFile;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_PASSWORDENTRYDIALOG1;
        //*)

        //(*Declarations(dziennik_guiFrame)
        wxButton* Button2;
        wxButton* ButtonCancelStudent;
        wxButton* ButtonCancelTeacher;
        wxButton* ButtonDateAttandadnceControl;
        wxButton* ButtonDeleteStudent;
        wxButton* ButtonDeleteSubject;
        wxButton* ButtonDeleteTeacher;
        wxButton* ButtonLogin;
        wxButton* ButtonLoginCancel;
        wxButton* ButtonRegister;
        wxButton* ButtonSaveStudent;
        wxButton* ButtonSaveSubject;
        wxButton* ButtonSaveTeacher;
        wxChoice* ComboBoxTeacherSubject;
        wxDatePickerCtrl* DatePickerCtrlAttandanceControl;
        wxDatePickerCtrl* DatePickerCtrlStudentBirthday;
        wxDatePickerCtrl* DatePickerCtrlTeacherBirthday;
        wxFileDialog* FileDialog1;
        wxGrid* Grid1;
        wxGrid* GridYourStudentList;
        wxListBox* ListBoxAtanndacneDates;
        wxListCtrl* ListCtrlMyGrades;
        wxListCtrl* ListCtrlStudents;
        wxListCtrl* ListCtrlSubjectList;
        wxListCtrl* ListCtrlTeachers;
        wxMenu Menu3;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxNotebook* NotebookMain;
        wxPanel* PanelCreateAdmin;
        wxPanel* PanelLogin;
        wxPanel* PanelMyGrades;
        wxPanel* PanelStudentAttandnace;
        wxPanel* PanelStudents;
        wxPanel* PanelSubjects;
        wxPanel* PanelTeachers;
        wxPanel* PanelYourStudentes;
        wxPasswordEntryDialog* PasswordEntryDialog1;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
        wxStaticText* StaticText13;
        wxStaticText* StaticText14;
        wxStaticText* StaticText15;
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
        wxTextCtrl* TextCtrlLoginNick;
        wxTextCtrl* TextCtrlLoginPassword;
        wxTextCtrl* TextCtrlNick;
        wxTextCtrl* TextCtrlPassRegister;
        wxTextCtrl* TextCtrlRegisterReapeatPassword;
        wxTextCtrl* TextCtrlStudentName;
        wxTextCtrl* TextCtrlStudentPesel;
        wxTextCtrl* TextCtrlStudentSurname;
        wxTextCtrl* TextCtrlSubjectEditor;
        wxTextCtrl* TextCtrlTeacherName;
        wxTextCtrl* TextCtrlTeacherPesel;
        wxTextCtrl* TextCtrlTeacherSurname;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DZIENNIK_GUIMAIN_H
