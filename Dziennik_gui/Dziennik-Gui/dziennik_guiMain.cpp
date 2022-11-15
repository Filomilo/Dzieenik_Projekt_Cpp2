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
const long dziennik_guiFrame::ID_MENUITEM1 = wxNewId();
const long dziennik_guiFrame::idMenuNewFIle = wxNewId();
const long dziennik_guiFrame::idMenuOpenFile = wxNewId();
const long dziennik_guiFrame::idMenuAbout = wxNewId();
const long dziennik_guiFrame::ID_STATUSBAR1 = wxNewId();
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
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1657,750));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem3 = new wxMenuItem(Menu1, idMenuNewFIle, _("New File"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuOpenFile, _("Open File"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
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

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnAbout);
    //*)
    Connect(idMenuNewFIle,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnNewFile);
    Connect(idMenuOpenFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dziennik_guiFrame::OnOpenFile);


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
