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
const long dziennik_guiFrame::ID_PANELLOGIN = wxNewId();
const long dziennik_guiFrame::ID_PANELStudents = wxNewId();
const long dziennik_guiFrame::ID_PANELMYGRADES = wxNewId();
const long dziennik_guiFrame::ID_PANELYOURSTUdNETS = wxNewId();
const long dziennik_guiFrame::ID_PANELTEACHERS = wxNewId();
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
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
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
    TextCtrlNick = new wxTextCtrl(PanelCreateAdmin, ID_TEXTCTRLNICK, wxEmptyString, wxDefaultPosition, wxSize(487,37), 0, wxDefaultValidator, _T("ID_TEXTCTRLNICK"));
    BoxSizer2->Add(TextCtrlNick, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(PanelCreateAdmin, ID_STATICTEXT1, _("Nick"), wxDefaultPosition, wxSize(487,37), 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlPassRegister = new wxTextCtrl(PanelCreateAdmin, ID_TEXTCTRLPASSREGISTER, wxEmptyString, wxDefaultPosition, wxSize(487,37), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRLPASSREGISTER"));
    BoxSizer2->Add(TextCtrlPassRegister, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(PanelCreateAdmin, ID_STATICTEXT2, _("Passoword"), wxDefaultPosition, wxSize(487,19), 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlRegisterReapeatPassword = new wxTextCtrl(PanelCreateAdmin, ID_TEXTCTRLREGISTERREAPEATPASSWORD, wxEmptyString, wxDefaultPosition, wxSize(487,37), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRLREGISTERREAPEATPASSWORD"));
    BoxSizer2->Add(TextCtrlRegisterReapeatPassword, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(PanelCreateAdmin, ID_STATICTEXT3, _("Reapeat Password"), wxDefaultPosition, wxSize(487,37), 0, _T("ID_STATICTEXT3"));
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
    PanelStudents = new wxPanel(NotebookMain, ID_PANELStudents, wxPoint(248,30), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELStudents"));
    PanelMyGrades = new wxPanel(NotebookMain, ID_PANELMYGRADES, wxPoint(375,9), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELMYGRADES"));
    PanelYourStudentes = new wxPanel(NotebookMain, ID_PANELYOURSTUdNETS, wxPoint(439,24), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELYOURSTUdNETS"));
    PanelTeachers = new wxPanel(NotebookMain, ID_PANELTEACHERS, wxPoint(574,7), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELTEACHERS"));
    PanelSubjects = new wxPanel(NotebookMain, ID_PANELSUBJECTS, wxPoint(776,13), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELSUBJECTS"));
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
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnAbout);
    //*)
    Connect(idMenuNewFIle,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnNewFile);
    Connect(idMenuOpenFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnOpenFile);
    removeAllPages();
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
}

void dziennik_guiFrame::OnOpenFile(wxCommandEvent& event)
{
    std::cout<<"open File"<<std::endl;
    wxFileDialog openFileDialog(this, _("Open Dziennik file"), "", "","dziennik files (*.dznk)|*.dznk", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    openFileDialog.ShowModal();
    std::cout<<openFileDialog.GetPath()<<std::endl;
    this->dziennik->loadDataBase(std::string(openFileDialog.GetPath().mbc_str()));
    this->dziennik->printDataBase();
}

void dziennik_guiFrame::removeAllPages()
{

    int amount=NotebookMain->GetPageCount();
    for(int i=0;i<amount;i++)
    {
        NotebookMain->GetPage(0)->Show(false);
        //NotebookMain->RemovePage(0);
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

        }

void dziennik_guiFrame::OnTextCtrlRegisterReapeatPasswordText(wxCommandEvent& event)
{
}