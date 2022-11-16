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
const long dziennik_guiFrame::ID_PANELStudents = wxNewId();
const long dziennik_guiFrame::ID_PANELMYGRADES = wxNewId();
const long dziennik_guiFrame::ID_PANELYOURSTUdNETS = wxNewId();
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
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
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
    PanelMyGrades = new wxPanel(NotebookMain, ID_PANELMYGRADES, wxPoint(375,9), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELMYGRADES"));
    PanelYourStudentes = new wxPanel(NotebookMain, ID_PANELYOURSTUdNETS, wxPoint(439,24), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELYOURSTUdNETS"));
    PanelTeachers = new wxPanel(NotebookMain, ID_PANELTEACHERS, wxPoint(574,7), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELTEACHERS"));
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
    PanelTeachers->Connect(wxEVT_PAINT,(wxObjectEventFunction)&dziennik_guiFrame::OnPanelTeachersPaint,0,this);
    Connect(ID_LISTCTRLSUBJECTSLIST,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&dziennik_guiFrame::OnListCtrlSubjectListBeginDrag);
    Connect(ID_TEXTCTRLSUBJECTEDITOR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&dziennik_guiFrame::OnTextCtrlSubjectEditorText);
    Connect(ID_BUTTONSAVESUBJECT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonSaveSubjectClick);
    Connect(ID_BUTTONDELTETSUBJCECT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButton1Click1);
    Connect(ID_BUTTONLOGINCANCLE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dziennik_guiFrame::OnButtonLoginCancelClick);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&dziennik_guiFrame::OnClose);
    //*)
    Connect(idMenuNewFIle,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnNewFile);
    Connect(idMenuOpenFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnOpenFile);
    Connect(ID_LISTCTRLSUBJECTSLIST,wxEVT_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&dziennik_guiFrame::OnListCtrlSubjectListBeginDrag);

    //removeAllPages();
    dziennik->loadDataBase("exampple.dznk");
    refreshSubjectList();

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
    setViewAsNoLogged();
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
}

void dziennik_guiFrame::refreshSubjectList()
{

    ListCtrlSubjectList->ClearAll();
    ListCtrlSubjectList->AppendColumn(_("id"));
    ListCtrlSubjectList->AppendColumn(_("subject name"));
   dziennik->printSubjects();
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
        std::cout<<itemSelcted<<std::endl;
        if(!isSubjectInEditModde)
        {
            TextCtrlSubjectEditor->Clear();
            TextCtrlSubjectEditor->AppendText(itemSelcted.getName());
            selectedSubjectId=itemSelcted.getSubjectId();
             isSubjectSelected=true;
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
    if(isSubjectSelected)
    {
        std::cout<<"locked"<<std::endl;
        isSubjectInEditModde=true;
    }
}

void dziennik_guiFrame::OnButtonLoginCancelClick(wxCommandEvent& event)
{
    refreshSubjectSelection();
}

void dziennik_guiFrame::OnButtonSaveSubjectClick(wxCommandEvent& event)
{
    if(isSubjectInEditModde)
    {
    if(selectedSubjectId>0)
    {
    }
    else
    {
        wxString name=TextCtrlSubjectEditor->GetLineText(0);
        this->dziennik->addSubject(std::string(name.mbc_str()));

    }
  TextCtrlSubjectEditor->Clear();
refreshSubjectSelection();
    }
}

void dziennik_guiFrame::refreshSubjectSelection()
{
       isSubjectInEditModde=false;
    isSubjectSelected=true;
    refreshSubjectList();
}

void dziennik_guiFrame::OnButton1Click1(wxCommandEvent& event)
{
}
