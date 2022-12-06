/***************************************************************
 * Name:      dziennik_guiMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2022-11-12
 * Copyright:  ()
 * License:
 **************************************************************/

#include "dziennik_guiMain.h"
#include <wx/msgdlg.h>
#include <iostream>
#include <DziennikLib.h>
#include <subject.h>
#include<vector>


//(*InternalHeaders(dziennik_guiFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(dziennik_guiFrame)
const long dziennik_guiFrame::ID_TEXTCTRLNICK = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT1 = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRLPASSREGISTER = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT2 = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRLREGISTERREAPEATPASSWORD = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT3 = wxNewId();
const long dziennik_guiFrame::ID_BUTTONREGISTER = wxNewId();
const long dziennik_guiFrame::ID_PANELCREATEADMIN = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRLLOGINNICK = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT5 = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRLLOGINPASSWORD = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT4 = wxNewId();
const long dziennik_guiFrame::ID_BUTTONLOGIN = wxNewId();
const long dziennik_guiFrame::ID_PANELLOGIN = wxNewId();
const long dziennik_guiFrame::ID_LISTCTRLSTUDENTS = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRLSTUDENTPESEL = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT13 = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRLSTUDENTNAME = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT12 = wxNewId();
const long dziennik_guiFrame::ID_DATEPICKERCTRLSTUDENTBIRTHDAY = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT15 = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRL5 = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT14 = wxNewId();
const long dziennik_guiFrame::ID_BUTTONSAVESTUDENT = wxNewId();
const long dziennik_guiFrame::ID_BUTTONDELETESTUDENT = wxNewId();
const long dziennik_guiFrame::ID_BUTTONCANCELSTUDENT = wxNewId();
const long dziennik_guiFrame::ID_PANELStudents = wxNewId();
const long dziennik_guiFrame::ID_LISTCTRL2 = wxNewId();
const long dziennik_guiFrame::ID_PANELMYGRADES = wxNewId();
const long dziennik_guiFrame::ID_GRID1 = wxNewId();
const long dziennik_guiFrame::ID_PANELYOURSTUdNETS = wxNewId();
const long dziennik_guiFrame::ID_LISTCTRLTEACHERS = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRLTEACHERPESEL = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT7 = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRL2 = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT8 = wxNewId();
const long dziennik_guiFrame::ID_DATEPICKERCTRLTEACHERBIRTHDAY = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT9 = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRLTEACHERSURNAME = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT11 = wxNewId();
const long dziennik_guiFrame::ID_COMBOBOXTEACHERSUBJECT = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT10 = wxNewId();
const long dziennik_guiFrame::ID_BUTTONSAVETEACHER = wxNewId();
const long dziennik_guiFrame::ID_BUTTONDELETETEACHER = wxNewId();
const long dziennik_guiFrame::ID_BUTTONCANCELTEACHER = wxNewId();
const long dziennik_guiFrame::ID_PANELTEACHERS = wxNewId();
const long dziennik_guiFrame::ID_LISTCTRLSUBJECTSLIST = wxNewId();
const long dziennik_guiFrame::ID_STATICTEXT6 = wxNewId();
const long dziennik_guiFrame::ID_TEXTCTRLSUBJECTEDITOR = wxNewId();
const long dziennik_guiFrame::ID_BUTTONSAVESUBJECT = wxNewId();
const long dziennik_guiFrame::ID_BUTTONDELTETSUBJCECT = wxNewId();
const long dziennik_guiFrame::ID_BUTTONLOGINCANCLE = wxNewId();
const long dziennik_guiFrame::ID_PANELSUBJECTS = wxNewId();
const long dziennik_guiFrame::ID_NOTEBOOKMAIN = wxNewId();
const long dziennik_guiFrame::idMenuNewFIle = wxNewId();
const long dziennik_guiFrame::idMenuOpenFile = wxNewId();
const long dziennik_guiFrame::ID_MENUITEM1 = wxNewId();
const long dziennik_guiFrame::idMenuAbout = wxNewId();
const long dziennik_guiFrame::ID_STATUSBAR1 = wxNewId();
const long dziennik_guiFrame::ID_PASSWORDENTRYDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dziennik_guiFrame,wxFrame)
    //(*EventTable(dziennik_guiFrame)
    //*)
END_EVENT_TABLE()

dziennik_guiFrame::dziennik_guiFrame(wxWindow* parent,wxWindowID id)
{

               this->dziennik= new DziennikLib;
    std::setlocale(LC_ALL, "");
    //(*Initialize(dziennik_guiFrame)
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer13;
    wxBoxSizer* BoxSizer14;
    wxBoxSizer* BoxSizer15;
    wxBoxSizer* BoxSizer16;
    wxBoxSizer* BoxSizer17;
    wxBoxSizer* BoxSizer18;
    wxBoxSizer* BoxSizer19;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer20;
    wxBoxSizer* BoxSizer21;
    wxBoxSizer* BoxSizer22;
    wxBoxSizer* BoxSizer23;
    wxBoxSizer* BoxSizer24;
    wxBoxSizer* BoxSizer25;
    wxBoxSizer* BoxSizer26;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer9;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1360,763));
    NotebookMain = new wxNotebook(this, ID_NOTEBOOKMAIN, wxPoint(384,544), wxDefaultSize, 0, _T("ID_NOTEBOOKMAIN"));
    PanelCreateAdmin = new wxPanel(NotebookMain, ID_PANELCREATEADMIN, wxPoint(441,526), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELCREATEADMIN"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    TextCtrlNick = new wxTextCtrl(PanelCreateAdmin, ID_TEXTCTRLNICK, wxEmptyString, wxDefaultPosition, wxSize(500,37), 0, wxDefaultValidator, _T("ID_TEXTCTRLNICK"));
    BoxSizer2->Add(TextCtrlNick, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(PanelCreateAdmin, ID_STATICTEXT1, _("Nick"), wxDefaultPosition, wxSize(500,37), 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlPassRegister = new wxTextCtrl(PanelCreateAdmin, ID_TEXTCTRLPASSREGISTER, wxEmptyString, wxDefaultPosition, wxSize(500,37), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRLPASSREGISTER"));
    BoxSizer2->Add(TextCtrlPassRegister, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(PanelCreateAdmin, ID_STATICTEXT2, _("Passoword"), wxDefaultPosition, wxSize(500,19), 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlRegisterReapeatPassword = new wxTextCtrl(PanelCreateAdmin, ID_TEXTCTRLREGISTERREAPEATPASSWORD, wxEmptyString, wxDefaultPosition, wxSize(487,37), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRLREGISTERREAPEATPASSWORD"));
    BoxSizer2->Add(TextCtrlRegisterReapeatPassword, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(PanelCreateAdmin, ID_STATICTEXT3, _("Reapeat Password"), wxDefaultPosition, wxSize(500,37), 0, _T("ID_STATICTEXT3"));
    BoxSizer2->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonRegister = new wxButton(PanelCreateAdmin, ID_BUTTONREGISTER, _("Register"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONREGISTER"));
    BoxSizer2->Add(ButtonRegister, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PanelCreateAdmin->SetSizer(BoxSizer1);
    BoxSizer1->Fit(PanelCreateAdmin);
    BoxSizer1->SetSizeHints(PanelCreateAdmin);
    PanelLogin = new wxPanel(NotebookMain, ID_PANELLOGIN, wxPoint(184,8), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELLOGIN"));
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    TextCtrlLoginNick = new wxTextCtrl(PanelLogin, ID_TEXTCTRLLOGINNICK, wxEmptyString, wxDefaultPosition, wxSize(500,37), 0, wxDefaultValidator, _T("ID_TEXTCTRLLOGINNICK"));
    BoxSizer4->Add(TextCtrlLoginNick, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(PanelLogin, ID_STATICTEXT5, _("Nick"), wxDefaultPosition, wxSize(500,37), 0, _T("ID_STATICTEXT5"));
    BoxSizer4->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLoginPassword = new wxTextCtrl(PanelLogin, ID_TEXTCTRLLOGINPASSWORD, wxEmptyString, wxDefaultPosition, wxSize(500,37), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRLLOGINPASSWORD"));
    BoxSizer4->Add(TextCtrlLoginPassword, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(PanelLogin, ID_STATICTEXT4, _("Password"), wxDefaultPosition, wxSize(500,37), 0, _T("ID_STATICTEXT4"));
    BoxSizer4->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonLogin = new wxButton(PanelLogin, ID_BUTTONLOGIN, _("Login"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONLOGIN"));
    BoxSizer4->Add(ButtonLogin, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PanelLogin->SetSizer(BoxSizer3);
    BoxSizer3->Fit(PanelLogin);
    BoxSizer3->SetSizeHints(PanelLogin);
    PanelStudents = new wxPanel(NotebookMain, ID_PANELStudents, wxPoint(248,30), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELStudents"));
    BoxSizer16 = new wxBoxSizer(wxVERTICAL);
    ListCtrlStudents = new wxListCtrl(PanelStudents, ID_LISTCTRLSTUDENTS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRLSTUDENTS"));
    BoxSizer16->Add(ListCtrlStudents, 12, wxALL|wxEXPAND, 5);
    BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer21 = new wxBoxSizer(wxVERTICAL);
    TextCtrlStudentPesel = new wxTextCtrl(PanelStudents, ID_TEXTCTRLSTUDENTPESEL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLSTUDENTPESEL"));
    BoxSizer21->Add(TextCtrlStudentPesel, 0, wxALL|wxEXPAND, 5);
    StaticText13 = new wxStaticText(PanelStudents, ID_STATICTEXT13, _("Pesel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    BoxSizer21->Add(StaticText13, 1, wxALL|wxALIGN_LEFT, 5);
    TextCtrlStudentName = new wxTextCtrl(PanelStudents, ID_TEXTCTRLSTUDENTNAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLSTUDENTNAME"));
    BoxSizer21->Add(TextCtrlStudentName, 1, wxALL|wxEXPAND, 5);
    StaticText12 = new wxStaticText(PanelStudents, ID_STATICTEXT12, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer21->Add(StaticText12, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer19->Add(BoxSizer21, 1, wxALL|wxEXPAND, 5);
    BoxSizer22 = new wxBoxSizer(wxVERTICAL);
    DatePickerCtrlStudentBirthday = new wxDatePickerCtrl(PanelStudents, ID_DATEPICKERCTRLSTUDENTBIRTHDAY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRLSTUDENTBIRTHDAY"));
    BoxSizer22->Add(DatePickerCtrlStudentBirthday, 1, wxALL|wxEXPAND, 5);
    StaticText15 = new wxStaticText(PanelStudents, ID_STATICTEXT15, _("Birthday"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    BoxSizer22->Add(StaticText15, 1, wxALL|wxALIGN_LEFT, 5);
    TextCtrlStudentSurname = new wxTextCtrl(PanelStudents, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    BoxSizer22->Add(TextCtrlStudentSurname, 1, wxALL|wxEXPAND, 5);
    StaticText14 = new wxStaticText(PanelStudents, ID_STATICTEXT14, _("Surname"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    BoxSizer22->Add(StaticText14, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer19->Add(BoxSizer22, 1, wxALL|wxEXPAND, 5);
    BoxSizer18->Add(BoxSizer19, 5, wxALL|wxEXPAND, 5);
    BoxSizer20 = new wxBoxSizer(wxVERTICAL);
    BoxSizer20->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonSaveStudent = new wxButton(PanelStudents, ID_BUTTONSAVESTUDENT, _("save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONSAVESTUDENT"));
    BoxSizer20->Add(ButtonSaveStudent, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonDeleteStudent = new wxButton(PanelStudents, ID_BUTTONDELETESTUDENT, _("delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONDELETESTUDENT"));
    BoxSizer20->Add(ButtonDeleteStudent, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonCancelStudent = new wxButton(PanelStudents, ID_BUTTONCANCELSTUDENT, _("cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONCANCELSTUDENT"));
    BoxSizer20->Add(ButtonCancelStudent, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer20->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer18->Add(BoxSizer20, 1, wxALL|wxEXPAND, 5);
    BoxSizer17->Add(BoxSizer18, 1, wxALL|wxEXPAND, 5);
    BoxSizer16->Add(BoxSizer17, 1, wxALL|wxEXPAND, 5);
    PanelStudents->SetSizer(BoxSizer16);
    BoxSizer16->Fit(PanelStudents);
    BoxSizer16->SetSizeHints(PanelStudents);
    PanelMyGrades = new wxPanel(NotebookMain, ID_PANELMYGRADES, wxPoint(375,9), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELMYGRADES"));
    BoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
    ListCtrlMyGrades = new wxListCtrl(PanelMyGrades, ID_LISTCTRL2, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL2"));
    BoxSizer23->Add(ListCtrlMyGrades, 1, wxALL|wxEXPAND, 5);
    PanelMyGrades->SetSizer(BoxSizer23);
    BoxSizer23->Fit(PanelMyGrades);
    BoxSizer23->SetSizeHints(PanelMyGrades);
    PanelYourStudentes = new wxPanel(NotebookMain, ID_PANELYOURSTUdNETS, wxPoint(439,24), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELYOURSTUdNETS"));
    BoxSizer24 = new wxBoxSizer(wxVERTICAL);
    BoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
    GridYourStudentList = new wxGrid(PanelYourStudentes, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    GridYourStudentList->CreateGrid(0,1);
    GridYourStudentList->EnableEditing(true);
    GridYourStudentList->EnableGridLines(true);
    GridYourStudentList->SetColLabelSize(10);
    GridYourStudentList->SetRowLabelSize(200);
    GridYourStudentList->SetDefaultRowSize(20, true);
    GridYourStudentList->SetDefaultColSize(10, true);
    GridYourStudentList->SetDefaultCellFont( GridYourStudentList->GetFont() );
    GridYourStudentList->SetDefaultCellTextColour( GridYourStudentList->GetForegroundColour() );
    BoxSizer26->Add(GridYourStudentList, 1, wxALL|wxEXPAND, 5);
    BoxSizer24->Add(BoxSizer26, 3, wxALL|wxEXPAND, 5);
    BoxSizer25 = new wxBoxSizer(wxVERTICAL);
    BoxSizer25->Add(142,144,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer24->Add(BoxSizer25, 1, wxALL|wxEXPAND, 5);
    PanelYourStudentes->SetSizer(BoxSizer24);
    BoxSizer24->Fit(PanelYourStudentes);
    BoxSizer24->SetSizeHints(PanelYourStudentes);
    PanelTeachers = new wxPanel(NotebookMain, ID_PANELTEACHERS, wxPoint(574,7), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELTEACHERS"));
    BoxSizer9 = new wxBoxSizer(wxVERTICAL);
    ListCtrlTeachers = new wxListCtrl(PanelTeachers, ID_LISTCTRLTEACHERS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRLTEACHERS"));
    BoxSizer9->Add(ListCtrlTeachers, 12, wxALL|wxEXPAND, 5);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer11 = new wxBoxSizer(wxVERTICAL);
    TextCtrlTeacherPesel = new wxTextCtrl(PanelTeachers, ID_TEXTCTRLTEACHERPESEL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLTEACHERPESEL"));
    BoxSizer11->Add(TextCtrlTeacherPesel, 1, wxALL|wxEXPAND, 5);
    StaticText7 = new wxStaticText(PanelTeachers, ID_STATICTEXT7, _("Pesel"), wxDefaultPosition, wxSize(46,17), 0, _T("ID_STATICTEXT7"));
    BoxSizer11->Add(StaticText7, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer14 = new wxBoxSizer(wxVERTICAL);
    TextCtrlTeacherName = new wxTextCtrl(PanelTeachers, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer14->Add(TextCtrlTeacherName, 1, wxALL|wxEXPAND, 5);
    StaticText8 = new wxStaticText(PanelTeachers, ID_STATICTEXT8, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    BoxSizer14->Add(StaticText8, 1, wxALL|wxALIGN_LEFT, 5);
    DatePickerCtrlTeacherBirthday = new wxDatePickerCtrl(PanelTeachers, ID_DATEPICKERCTRLTEACHERBIRTHDAY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRLTEACHERBIRTHDAY"));
    BoxSizer14->Add(DatePickerCtrlTeacherBirthday, 1, wxALL|wxEXPAND, 5);
    StaticText9 = new wxStaticText(PanelTeachers, ID_STATICTEXT9, _("Birthday"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    BoxSizer14->Add(StaticText9, 1, wxALL|wxALIGN_LEFT, 2);
    BoxSizer13->Add(BoxSizer14, 1, wxALL|wxEXPAND, 5);
    BoxSizer15 = new wxBoxSizer(wxVERTICAL);
    TextCtrlTeacherSurname = new wxTextCtrl(PanelTeachers, ID_TEXTCTRLTEACHERSURNAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLTEACHERSURNAME"));
    BoxSizer15->Add(TextCtrlTeacherSurname, 1, wxALL|wxEXPAND, 5);
    StaticText11 = new wxStaticText(PanelTeachers, ID_STATICTEXT11, _("Surname"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    BoxSizer15->Add(StaticText11, 1, wxALL|wxALIGN_LEFT, 5);
    ComboBoxTeacherSubject = new wxChoice(PanelTeachers, ID_COMBOBOXTEACHERSUBJECT, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOXTEACHERSUBJECT"));
    BoxSizer15->Add(ComboBoxTeacherSubject, 1, wxALL|wxEXPAND, 5);
    StaticText10 = new wxStaticText(PanelTeachers, ID_STATICTEXT10, _("Subject"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer15->Add(StaticText10, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer13->Add(BoxSizer15, 1, wxALL|wxEXPAND, 5);
    BoxSizer11->Add(BoxSizer13, 6, wxALL|wxEXPAND, 5);
    BoxSizer10->Add(BoxSizer11, 8, wxALL|wxEXPAND, 5);
    BoxSizer12 = new wxBoxSizer(wxVERTICAL);
    BoxSizer12->Add(-1,-1,2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonSaveTeacher = new wxButton(PanelTeachers, ID_BUTTONSAVETEACHER, _("save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONSAVETEACHER"));
    BoxSizer12->Add(ButtonSaveTeacher, 1, wxALL|wxEXPAND, 5);
    ButtonDeleteTeacher = new wxButton(PanelTeachers, ID_BUTTONDELETETEACHER, _("delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONDELETETEACHER"));
    BoxSizer12->Add(ButtonDeleteTeacher, 1, wxALL|wxEXPAND, 5);
    ButtonCancelTeacher = new wxButton(PanelTeachers, ID_BUTTONCANCELTEACHER, _("cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONCANCELTEACHER"));
    BoxSizer12->Add(ButtonCancelTeacher, 1, wxALL|wxEXPAND, 5);
    BoxSizer12->Add(-1,-1,2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(BoxSizer12, 1, wxALL|wxEXPAND, 5);
    BoxSizer9->Add(BoxSizer10, 1, wxALL|wxEXPAND, 5);
    PanelTeachers->SetSizer(BoxSizer9);
    BoxSizer9->Fit(PanelTeachers);
    BoxSizer9->SetSizeHints(PanelTeachers);
    PanelSubjects = new wxPanel(NotebookMain, ID_PANELSUBJECTS, wxPoint(776,13), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELSUBJECTS"));
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    ListCtrlSubjectList = new wxListCtrl(PanelSubjects, ID_LISTCTRLSUBJECTSLIST, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_EDIT_LABELS, wxDefaultValidator, _T("ID_LISTCTRLSUBJECTSLIST"));
    BoxSizer5->Add(ListCtrlSubjectList, 11, wxALL|wxEXPAND, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    StaticText6 = new wxStaticText(PanelSubjects, ID_STATICTEXT6, _("Subject name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer8->Add(StaticText6, 1, wxALL|wxEXPAND, 5);
    TextCtrlSubjectEditor = new wxTextCtrl(PanelSubjects, ID_TEXTCTRLSUBJECTEDITOR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLSUBJECTEDITOR"));
    BoxSizer8->Add(TextCtrlSubjectEditor, 1, wxALL|wxEXPAND, 5);
    BoxSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer8, 6, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    BoxSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonSaveSubject = new wxButton(PanelSubjects, ID_BUTTONSAVESUBJECT, _("save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONSAVESUBJECT"));
    BoxSizer7->Add(ButtonSaveSubject, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonDeleteSubject = new wxButton(PanelSubjects, ID_BUTTONDELTETSUBJCECT, _("delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONDELTETSUBJCECT"));
    BoxSizer7->Add(ButtonDeleteSubject, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonLoginCancel = new wxButton(PanelSubjects, ID_BUTTONLOGINCANCLE, _("cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONLOGINCANCLE"));
    BoxSizer7->Add(ButtonLoginCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer7, 1, wxALL|wxEXPAND, 5);
    BoxSizer5->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
    PanelSubjects->SetSizer(BoxSizer5);
    BoxSizer5->Fit(PanelSubjects);
    BoxSizer5->SetSizeHints(PanelSubjects);
    NotebookMain->AddPage(PanelCreateAdmin, _("Create admin"), false);
    NotebookMain->AddPage(PanelLogin, _("Login"), false);
    NotebookMain->AddPage(PanelStudents, _("Students"), false);
    NotebookMain->AddPage(PanelMyGrades, _("My grades"), false);
    NotebookMain->AddPage(PanelYourStudentes, _("Your Students"), false);
    NotebookMain->AddPage(PanelTeachers, _("Teachers"), false);
    NotebookMain->AddPage(PanelSubjects, _("Subjects"), false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuNewFIle, _("New File\tctrl+n"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuOpenFile, _("Open File"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    PasswordEntryDialog1 = new wxPasswordEntryDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, wxCANCEL|wxCENTRE|wxOK, wxDefaultPosition);

    Connect(ID_TEXTCTRLNICK,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnTextCtrlNickText);
    Connect(ID_TEXTCTRLPASSREGISTER,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnTextCtrlPassRegisterText);
    Connect(ID_TEXTCTRLREGISTERREAPEATPASSWORD,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnTextCtrlRegisterReapeatPasswordText);
    Connect(ID_BUTTONREGISTER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonRegisterClick);
    Connect(ID_BUTTONLOGIN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonLoginClick);
    Connect(ID_LISTCTRLSTUDENTS,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&dziennik_guiFrame::OnListCtrlStudentsBeginDrag);
    Connect(ID_LISTCTRLSTUDENTS,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&dziennik_guiFrame::OnListCtrlStudentsItemActivated);
    Connect(ID_TEXTCTRLSTUDENTPESEL,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnChangeInStudents);
    Connect(ID_TEXTCTRLSTUDENTNAME,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnChangeInStudents);
    Connect(ID_DATEPICKERCTRLSTUDENTBIRTHDAY,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&dziennik_guiFrame::OnDatePickerCtrlStudentBirthdayChanged);
    Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnChangeInStudents);
    Connect(ID_BUTTONSAVESTUDENT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonSaveStudentClick);
    Connect(ID_BUTTONDELETESTUDENT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonDeleteStudentClick);
    Connect(ID_BUTTONCANCELSTUDENT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonCancelStudentClick);
    Connect(ID_LISTCTRLTEACHERS,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&dziennik_guiFrame::OnListCtrlTeachersBeginDrag);
    Connect(ID_TEXTCTRLTEACHERPESEL,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnChangeInTeachers);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnChangeInTeachers);
    Connect(ID_DATEPICKERCTRLTEACHERBIRTHDAY,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&dziennik_guiFrame::OnDatePickerCtrlTeacherBirthdayChanged);
    Connect(ID_TEXTCTRLTEACHERSURNAME,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnChangeInTeachers);
    Connect(ID_COMBOBOXTEACHERSUBJECT,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnChangeInTeachers);
    Connect(ID_BUTTONSAVETEACHER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonSaveTeacherClick);
    Connect(ID_BUTTONDELETETEACHER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonDeleteTeacherClick);
    Connect(ID_BUTTONCANCELTEACHER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonCancelTeacherClick);
    PanelTeachers->Connect(wxEVT_PAINT,(wxObjectEventFunction)&dziennik_guiFrame::OnPanelTeachersPaint,0,this);
    Connect(ID_LISTCTRLSUBJECTSLIST,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&dziennik_guiFrame::OnListCtrlSubjectListBeginDrag);
    Connect(ID_TEXTCTRLSUBJECTEDITOR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnTextCtrlSubjectEditorText);
    Connect(ID_BUTTONSAVESUBJECT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonSaveSubjectClick);
    Connect(ID_BUTTONDELTETSUBJCECT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButton1Click1);
    Connect(ID_BUTTONLOGINCANCLE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonLoginCancelClick);
    Connect(ID_NOTEBOOKMAIN,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&dziennik_guiFrame::OnNotebookMainPageChanged);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&dziennik_guiFrame::OnClose);
    //*)
    Connect(idMenuNewFIle,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnNewFile);
    Connect(idMenuOpenFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnOpenFile);
    Connect(ID_LISTCTRLSUBJECTSLIST,wxEVT_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&dziennik_guiFrame::OnListCtrlSubjectListBeginDrag);
    Connect(ID_LISTCTRLTEACHERS,wxEVT_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&dziennik_guiFrame::OnListCtrlTeachersBeginDrag);

  //  removeAllPages();
    dziennik->loadDataBase("exampple.dznk");
    dziennik->login("TEACHER","TEACHER");
    std::cout<<"login: "<<dziennik->getUserStudentProfile()<<std::endl;
    refreshSubjectSelection();
    refreshTeacherSelection();
    refreshStudentSelection();
    refreshMyGradeList();
    refreshYourStudentGrid();
}

dziennik_guiFrame::~dziennik_guiFrame()
{
    //(*Destroy(dziennik_guiFrame)
    //*)
}

void dziennik_guiFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}
void dziennik_guiFrame::clearLoginData()
{
        TextCtrlLoginNick->Clear();
      TextCtrlLoginPassword->Clear();
      TextCtrlRegisterReapeatPassword->Clear();
      TextCtrlPassRegister->Clear();
      TextCtrlNick->Clear();

}

void dziennik_guiFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void dziennik_guiFrame::OnNewFile(wxCommandEvent& event)
{
  std::cout<<"new File"<<std::endl;
  wxFileDialog saveFileDialog(this, _("Save Dziennik file"), "", "","dziennik files (*.dznk)|*.dznk", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
  saveFileDialog.ShowModal();
  std::cout<<saveFileDialog.GetPath()<<std::endl;
  this->dziennik->createNewDataBase(std::string(saveFileDialog.GetPath().mbc_str()));
  setViewAsNewDb();
  clearLoginData();
}

void dziennik_guiFrame::OnOpenFile(wxCommandEvent& event)
{
    std::cout<<"open File"<<std::endl;
    wxFileDialog openFileDialog(this, _("Open Dziennik file"), "", "","dziennik files (*.dznk)|*.dznk", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    openFileDialog.ShowModal();
    std::cout<<openFileDialog.GetPath()<<std::endl;
    this->dziennik->loadDataBase(std::string(openFileDialog.GetPath().mbc_str()));
    this->dziennik->printDataBase();
    setViewAsNoLogged();
      clearLoginData();
}

void dziennik_guiFrame::removeAllPages()
{

    int amount=NotebookMain->GetPageCount();
    for(int i=0;i<amount;i++)
    {
        NotebookMain->GetPage(0)->Show(false);
        NotebookMain->RemovePage(0);
    }

}

void dziennik_guiFrame::OnButton1Click(wxCommandEvent& event)
{

}


void dziennik_guiFrame::OnTextCtrlNickText(wxCommandEvent& event)
{
}

void dziennik_guiFrame::OnTextCtrlPassRegisterText(wxCommandEvent& event)
{
}

void dziennik_guiFrame::OnButtonRegisterClick(wxCommandEvent& event)
{
        std::string nick=std::string(TextCtrlNick->GetLineText(0).mbc_str());
     std::string pass=std::string(TextCtrlPassRegister->GetLineText(0).mbc_str());
     std::cout<<nick<<std::endl;
     this->dziennik->addUser(nick,pass,DziennikLib::Account_types::ADMIN);
     setViewAsNoLogged();
       clearLoginData();
}
void dziennik_guiFrame::setViewAsNewDb()
        {
            removeAllPages();
            NotebookMain->AddPage(PanelCreateAdmin, _("Create admin"), true);
        }
void dziennik_guiFrame::setViewAsNoLogged()
        {
            removeAllPages();
            NotebookMain->AddPage(PanelLogin, _("Login"), true);
        }
void dziennik_guiFrame::setViewAsTeacher()
        {
            removeAllPages();
             NotebookMain->AddPage(PanelYourStudentes, _("My Students"), true);
        }
void dziennik_guiFrame::setViewAsStudent()
        {
            removeAllPages();
            NotebookMain->AddPage(PanelMyGrades, _("My Grades"), true);

        }
void dziennik_guiFrame::setViewAsAdmin()
        {
            removeAllPages();
            NotebookMain->AddPage(PanelStudents, _("Students"), true);
            NotebookMain->AddPage(PanelSubjects, _("Subjects"), false);
            NotebookMain->AddPage(PanelTeachers, _("Teachers"), false);
            refreshStudentSelection();
            refreshSubjectSelection();
            refreshTeacherSelection();
        }

void dziennik_guiFrame::OnTextCtrlRegisterReapeatPasswordText(wxCommandEvent& event)
{
}


void dziennik_guiFrame::OnButtonLoginClick(wxCommandEvent& event)
{

     std::string nick=std::string(TextCtrlLoginNick->GetLineText(0).mbc_str());
     std::string pass=std::string(TextCtrlLoginPassword->GetLineText(0).mbc_str());
     std::cout<<nick<<std::endl;
     if(this->dziennik->login(nick,pass)==false){
        return;
        std::cout<<"not logged"<<std::endl;
     }
     switch(this->dziennik->getUserAccountType())
     {
         case DziennikLib::Account_types::ADMIN: setViewAsAdmin(); break;
         case DziennikLib::Account_types::TEACHER: setViewAsTeacher(); break;
         case DziennikLib::Account_types::STUDNET: setViewAsStudent(); break;
     }
  clearLoginData();
}

void dziennik_guiFrame::refreshSubjectList()
{
    checkVariables();
    ListCtrlSubjectList->ClearAll();
    ListCtrlSubjectList->AppendColumn(_("id"));
    ListCtrlSubjectList->AppendColumn(_("subject name"));
    std::vector<subject> subjectList=this->dziennik->findSubjectsAll();
    int i=0;
    for(auto it=subjectList.begin();it!=subjectList.end();it++)
    {
      ListCtrlSubjectList->InsertItem(i, wxString::Format(wxT("%i"),(*it).getSubjectId()));
      ListCtrlSubjectList->SetItem(i++, 1, (*it).getName());
    }
}

void dziennik_guiFrame::OnClose(wxCloseEvent& event)
{
}

void dziennik_guiFrame::OnListCtrlSubjectListBeginDrag(wxListEvent& event)
{

    isSubjectSelected=false;
          std::cout<<"clicked\n";
        long SelctedItem = ListCtrlSubjectList->GetNextItem(-1,  wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        wxListItem item;
        item.SetId(SelctedItem);
        ListCtrlSubjectList->GetItem(item);
        subject itemSelcted=dziennik->findSubjectsById(wxAtoi(item.GetText()))[0];
        if(!isSubjectInEditModde)
        {
            std::cout<<"into subject mode\n";
            TextCtrlSubjectEditor->Clear();
            TextCtrlSubjectEditor->AppendText(itemSelcted.getName());
            selectedSubjectId=itemSelcted.getSubjectId();
             isSubjectSelected=true;
        }
        else
        {
               std::cout<<"something in edit\n";
        }
}

void OnSubjectListItemClicked(wxListEvent& event)
{

}

void dziennik_guiFrame::OnPanelTeachersPaint(wxPaintEvent& event)
{
}

void dziennik_guiFrame::OnTextCtrlSubjectEditorText(wxCommandEvent& event)
{
        //checkVariables();

        std::cout<<"locked: "<<selectedSubjectId<<std::endl;
        isSubjectInEditModde=true;

}

void dziennik_guiFrame::OnButtonLoginCancelClick(wxCommandEvent& event)
{
        checkVariables();
    refreshSubjectSelection();
}

void dziennik_guiFrame::OnButtonSaveSubjectClick(wxCommandEvent& event)
{
    checkVariables();
    if(isSubjectInEditModde)
    {
         wxString name=TextCtrlSubjectEditor->GetLineText(0);
    if(selectedSubjectId>0)
    {
        this->dziennik->updateSubject(selectedSubjectId,std::string(name.mbc_str()));
    }
    else
    {
        this->dziennik->addSubject(std::string(name.mbc_str()));

    }
refreshSubjectSelection();
    }
}

void dziennik_guiFrame::refreshSubjectSelection()
{
        checkVariables();

    selectedSubjectId=-1;
    TextCtrlSubjectEditor->Clear();
        isSubjectInEditModde=false;
    isSubjectSelected=false;
    refreshSubjectList();
}

void dziennik_guiFrame::OnButton1Click1(wxCommandEvent& event)
{
    if(selectedSubjectId>0)
    {
        this->dziennik->removeSubject(selectedSubjectId);
    }
    refreshSubjectSelection();
}

void dziennik_guiFrame::checkVariables()
{
    std::cout<<"is subject in edit mdoe: "<<isSubjectInEditModde<<std::endl;
       std:: cout<<"isSubjectSelected  "<<isSubjectSelected<<std::endl;

}

void dziennik_guiFrame::OnNotebookMainPageChanged(wxNotebookEvent& event)
{
   //refreshSubjectList();
   //refreshTeacherList();
}

void dziennik_guiFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
}





void dziennik_guiFrame::refreshTeacherList()
{
    ListCtrlTeachers->ClearAll();

    ListCtrlTeachers->AppendColumn(_("Pesel"));
    ListCtrlTeachers->AppendColumn(_("Name"));
    ListCtrlTeachers->AppendColumn(_("Surname"));
    ListCtrlTeachers->AppendColumn(_("Birthday"));
    ListCtrlTeachers->AppendColumn(_("Subject"));
    std::vector<teacher> teachersList=this->dziennik->findTeacherstAll();
    int i=0;
    ComboBoxTeacherSubject->Clear();
    for(auto it=teachersList.begin();it!=teachersList.end();it++)
    {
      ListCtrlTeachers->InsertItem(i, (*it).getPesel());
      ListCtrlTeachers->SetItem(i, 1, (*it).getName());
      ListCtrlTeachers->SetItem(i, 2, (*it).getSurname());
      ListCtrlTeachers->SetItem(i, 3, (*it).getBirthday());
      ListCtrlTeachers->SetItem(i, 4, dziennik->findSubjectsById((*it).getSubjectId())[0].getName());
    }
     std::vector<subject> subjectList=this->dziennik->findSubjectsAll();
    for(auto it=subjectList.begin();it!=subjectList.end();it++)
    {

      ComboBoxTeacherSubject->Append((*it).getName());

    }
}
void dziennik_guiFrame::OnListCtrlTeachersBeginDrag(wxListEvent& event)
{
    std::cout<<"item clokced"<<std::endl;
        isTeacherSelected=false;
        long SelctedItem = ListCtrlTeachers->GetNextItem(-1,  wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        wxListItem item;
        item.SetId(SelctedItem);
        std::cout<<std::string(ListCtrlTeachers->GetItemText(item,0).mb_str())<<std::endl;
        teacher itemSelcted=dziennik->findTeachersByPesel(std::string(ListCtrlTeachers->GetItemText(item,0).mb_str()))[0];
        std::cout<<"test"<<std::endl;
        if(!isTeacherInEditModde)
        {
            std::cout<<"into teacher mode\n";
            TextCtrlTeacherPesel->Clear();
            TextCtrlTeacherPesel->AppendText(itemSelcted.getPesel());
             TextCtrlTeacherName->Clear();
            TextCtrlTeacherName->AppendText(itemSelcted.getName());
            TextCtrlTeacherSurname->Clear();
            TextCtrlTeacherSurname->AppendText(itemSelcted.getSurname());


            std::cout<<"date: "<<itemSelcted.getBirthdayYear()<<std::endl;
            wxDateTime date;
               date.SetToCurrent();
            date.SetYear(itemSelcted.getBirthdayYear());
            date.SetMonth(wxDateTime::Month(wxDateTime::Jan + itemSelcted.getBirthdayMonth() - 1)   );
            date.SetDay(itemSelcted.getBirthdayDay());
            //date.Format(_("1964-08-11"),"%Y-%m-%d");

            DatePickerCtrlTeacherBirthday->SetValue(date);
            ComboBoxTeacherSubject->SetSelection(itemSelcted.getSubjectId()-1);

            //DatePickerCtrlTeacherBirthday->se();
            //DatePickerCtrlTeacherBirthday->;

            TextCtrlTeacherPesel->SetEditable(false);
            selectedTeacherId=itemSelcted.getPesel();
             isTeacherSelected=true;
             isTeacherInEditModde=false;
        }
        else
        {
               std::cout<<"something in edit\n";
        }

}







void dziennik_guiFrame::OnComboBoxTeacherSubjectSelect(wxCommandEvent& event)
{
}

void dziennik_guiFrame::OnChangeInTeachers(wxCommandEvent& event)
{

    isTeacherInEditModde=true;
}

void dziennik_guiFrame::OnButtonCancelTeacherClick(wxCommandEvent& event)
{

    refreshTeacherSelection();
}

void dziennik_guiFrame::refreshTeacherSelection()
{
    TextCtrlTeacherPesel->SetEditable(true);
    selectedTeacherId[0]='\0';
    TextCtrlTeacherName->Clear();
    TextCtrlTeacherPesel->Clear();
    TextCtrlTeacherSurname->Clear();
    ComboBoxTeacherSubject->SetSelection(-1);
    wxDateTime data;
    data.SetToCurrent();
    DatePickerCtrlTeacherBirthday->SetValue(data);
        isTeacherInEditModde=false;
    isTeacherSelected=false;
    refreshTeacherList();
}


void dziennik_guiFrame::OnDatePickerCtrlTeacherBirthdayChanged(wxDateEvent& event)
{
    OnChangeInTeachers(event);
}

void dziennik_guiFrame::OnButtonSaveTeacherClick(wxCommandEvent& event)
{
    if(isTeacherInEditModde)
    {
        std::cout<<"test\n";
         wxString name=TextCtrlTeacherName->GetLineText(0);
         wxString pesel=TextCtrlTeacherPesel->GetLineText(0);
         wxString surname=TextCtrlTeacherSurname->GetLineText(0);
         wxDateTime birthday=DatePickerCtrlTeacherBirthday->GetValue();
         wxString birthdayString= birthday.Format(wxT("%Y-%m-%d"), wxDateTime::CET );
         int subjectId=ComboBoxTeacherSubject->GetSelection()+1;
    if(selectedTeacherId[0]!='\0')
    {
          this->dziennik->updateTeacher(
                                   std::string(pesel.mbc_str()),
                                   std::string(name.mbc_str()),
                                   std::string(surname.mbc_str()),
                                   std::string(birthdayString.mbc_str()),
                                   subjectId
                                   );
    }
    else
    {
        this->dziennik->addTeacher(
                                   std::string(pesel.mbc_str()),
                                   std::string(name.mbc_str()),
                                   std::string(surname.mbc_str()),
                                   std::string(birthdayString.mbc_str()),
                                   subjectId
                                   );
        std::cout<<birthdayString<<std::endl;
    }
refreshTeacherSelection();
    }
}

void dziennik_guiFrame::OnButtonDeleteTeacherClick(wxCommandEvent& event)
{
        if(selectedTeacherId[0]!='\0')
    {
        this->dziennik->removeTeacher(selectedTeacherId);
    }
    refreshTeacherSelection();
}







 void dziennik_guiFrame::refreshStudentList()
 {
         ListCtrlStudents->ClearAll();
     std::vector<subject> subjectList=this->dziennik->findSubjectsAll();
    ListCtrlStudents->AppendColumn(_("Pesel"));
    ListCtrlStudents->AppendColumn(_("Name"));
    ListCtrlStudents->AppendColumn(_("Surname"));
    ListCtrlStudents->AppendColumn(_("Birthday"));
    std::vector<student> studentList=this->dziennik->findSstudentAll();
    int i=0;
    for(auto it=studentList.begin();it!=studentList.end();it++)
    {
      ListCtrlStudents->InsertItem(i, (*it).getPesel());
      ListCtrlStudents->SetItem(i, 1, (*it).getName());
     ListCtrlStudents->SetItem(i, 2, (*it).getSurname());
      ListCtrlStudents->SetItem(i, 3, (*it).getBirthday());
    }

 }
void dziennik_guiFrame::OnStudentListItemClicked(wxListEvent &e)
{


}
void dziennik_guiFrame::refreshStudentSelection()
{
    TextCtrlStudentPesel->SetEditable(true);
    selectedStudentId[0]='\0';
    TextCtrlStudentName->Clear();
    TextCtrlStudentPesel->Clear();
    TextCtrlStudentSurname->Clear();
    wxDateTime data;
    data.SetToCurrent();
    DatePickerCtrlStudentBirthday->SetValue(data);
        isStudentInEditModde=false;
    isStudentInEditModde=false;
    refreshStudentList();
}



void dziennik_guiFrame::OnListCtrlStudentsItemActivated(wxListEvent& event)
{
       std::cout<<"item clokced"<<std::endl;
        isStudentSelected=false;
        long SelctedItem = ListCtrlStudents->GetNextItem(-1,  wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        wxListItem item;
        item.SetId(SelctedItem);
        std::cout<<std::string(ListCtrlStudents->GetItemText(item,0).mb_str())<<std::endl;
        student itemSelcted=dziennik->findStudentByPesel(std::string(ListCtrlStudents->GetItemText(item,0).mb_str()))[0];
        std::cout<<"test"<<std::endl;
        if(!isStudentInEditModde)
        {
            std::cout<<"into teacher mode\n";
            TextCtrlStudentPesel->Clear();
            TextCtrlStudentPesel->AppendText(itemSelcted.getPesel());
            TextCtrlStudentName->Clear();
            TextCtrlStudentName->AppendText(itemSelcted.getName());
            TextCtrlStudentSurname->Clear();
            TextCtrlStudentSurname->AppendText(itemSelcted.getSurname());
            wxDateTime date;
            date.SetToCurrent();
            date.SetYear(itemSelcted.getBirthdayYear());
            date.SetMonth(wxDateTime::Month(wxDateTime::Jan + itemSelcted.getBirthdayMonth() - 1)   );
            date.SetDay(itemSelcted.getBirthdayDay());
            //date.Format(_("1964-08-11"),"%Y-%m-%d");

            DatePickerCtrlStudentBirthday->SetValue(date);
            TextCtrlStudentPesel->SetEditable(false);
            selectedStudentId=itemSelcted.getPesel();
             isStudentSelected=true;
             isStudentInEditModde=false;
        }
        else
        {
               std::cout<<"something in edit\n";
        }
}
void dziennik_guiFrame::OnListCtrlStudentsBeginDrag(wxListEvent& event)
{

}

void dziennik_guiFrame::OnButtonCancelStudentClick(wxCommandEvent& event)
{
    refreshStudentSelection();
}

void dziennik_guiFrame::OnButtonDeleteStudentClick(wxCommandEvent& event)
{
    if(selectedStudentId[0]!='\0')
    {
        this->dziennik->removeStudent(selectedStudentId);
    }
    refreshStudentSelection();
}

void dziennik_guiFrame::OnButtonSaveStudentClick(wxCommandEvent& event)
{
     if(isStudentInEditModde)
    {
        std::cout<<"test\n";
         wxString name=TextCtrlStudentName->GetLineText(0);
         wxString pesel=TextCtrlStudentPesel->GetLineText(0);
         wxString surname=TextCtrlStudentSurname->GetLineText(0);
         wxDateTime birthday=DatePickerCtrlStudentBirthday->GetValue();
         wxString birthdayString= birthday.Format(wxT("%Y-%m-%d"), wxDateTime::CET );
    if(selectedStudentId[0]!='\0')
    {
          this->dziennik->updateStudent(
                                   std::string(pesel.mbc_str()),
                                   std::string(name.mbc_str()),
                                   std::string(surname.mbc_str()),
                                   std::string(birthdayString.mbc_str())
                                   );
    }
    else
    {
        this->dziennik->addStudent(
                                   std::string(pesel.mbc_str()),
                                   std::string(name.mbc_str()),
                                   std::string(surname.mbc_str()),
                                   std::string(birthdayString.mbc_str())
                                   );
    }
refreshStudentSelection();
    }
}

void dziennik_guiFrame::OnTextCtrlStudentPeselText(wxCommandEvent& event)
{
}

void dziennik_guiFrame::OnChangeInStudents(wxCommandEvent& event)
{
        isStudentInEditModde=true;

}

void dziennik_guiFrame::OnDatePickerCtrlStudentBirthdayChanged(wxDateEvent& event)
{
    OnChangeInStudents(event);
}



void dziennik_guiFrame::refreshMyGradeList()
{
    int maxValue=dziennik->findMaxGradesFromSubjectByStudentId(dziennik->getUserIdInDb());
    ListCtrlStudents->ClearAll();
    std::vector<subject> subjectList=this->dziennik->findSubjectsAll();
    for(auto it=subjectList.begin();it!=subjectList.end();it++)
    {
         ListCtrlMyGrades->AppendColumn(_(it->getName().c_str()));
    }


    for(int i=0;i<maxValue;i++)
    {
          ListCtrlMyGrades->InsertItem(0, "");
    }

    std::vector<grade> gradeList=this->dziennik->findGradesByStudentId(dziennik->getUserIdInDb());

    int prevSubject=-1;
    int counter=0;
      for(auto it=gradeList.begin();it!=gradeList.end();it++)
    {
    int subjectid=it->getSubjectId()-1;
    if(subjectid!=prevSubject)
    {
        counter=0;
        prevSubject=subjectid;
    }
    ListCtrlMyGrades->SetItem(counter++, subjectid, wxString::Format(wxT("%i"),it->getGrade()));

}
}

void dziennik_guiFrame::refreshYourStudentGrid()
{
    this->GridYourStudentList->SetColLabelSize(0);
    std::vector<student> studentList=this->dziennik->findSstudentAll();
    int row=0;
    for(auto it=studentList.begin();it!=studentList.end();it++)
    {
      GridYourStudentList->AppendRows();
      GridYourStudentList->SetRowLabelValue(row,(wxString)_((it->getName()+" "+it->getSurname()).c_str()));
    int col=0;
      std::vector<grade> studentList=this->dziennik->findGradesByStudentIdAndSubject(it->getPesel(),this->dziennik->getUserTeacherProfile().getSubjectId());    for(auto iter=studentList.begin();iter!=studentList.end();iter++)
    {
        std::cout<<*iter<<std::endl;
        wxString GradeVal;
        GradeVal << iter->getGrade();
       GridYourStudentList->SetCellValue(row,col++,GradeVal);
       if(col>=GridYourStudentList->GetNumberCols())
       {
           GridYourStudentList->AppendCols(1);
       }
    }
    row++;
    }


}


