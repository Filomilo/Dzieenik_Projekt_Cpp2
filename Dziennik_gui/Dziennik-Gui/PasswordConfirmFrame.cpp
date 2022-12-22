#include "PasswordConfirmFrame.h"

//(*InternalHeaders(PasswordConfirmFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PasswordConfirmFrame)
const long PasswordConfirmFrame::ID_TEXTCTRL1 = wxNewId();
const long PasswordConfirmFrame::ID_STATICTEXT1 = wxNewId();
const long PasswordConfirmFrame::ID_TEXTCTRL2 = wxNewId();
const long PasswordConfirmFrame::ID_STATICTEXT2 = wxNewId();
const long PasswordConfirmFrame::ID_BUTTONCONFIRMAPASS = wxNewId();
const long PasswordConfirmFrame::ID_PANEL1 = wxNewId();
//*)
#include <wx/msgdlg.h>

BEGIN_EVENT_TABLE(PasswordConfirmFrame,wxDialog)
	//(*EventTable(PasswordConfirmFrame)
	//*)
END_EVENT_TABLE()

PasswordConfirmFrame::PasswordConfirmFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(PasswordConfirmFrame)
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(240,336), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	TextCtrlPassowrd = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer1->Add(TextCtrlPassowrd, 1, wxALL|wxEXPAND, 5);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("old password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer1->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
	TextCtrlRepeatPassword = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer1->Add(TextCtrlRepeatPassword, 1, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("repeat old password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer1->Add(StaticText2, 1, wxALL|wxEXPAND, 5);
	ButtonConfirmPass = new wxButton(Panel1, ID_BUTTONCONFIRMAPASS, _("Confirm"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONCONFIRMAPASS"));
	BoxSizer1->Add(ButtonConfirmPass, 1, wxALL|wxEXPAND, 5);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);

	Connect(ID_BUTTONCONFIRMAPASS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PasswordConfirmFrame::OnButtonConfirmPassClick);
	//*)
}

PasswordConfirmFrame::~PasswordConfirmFrame()
{
	//(*Destroy(PasswordConfirmFrame)
	//*)
}


void PasswordConfirmFrame::OnButtonConfirmPassClick(wxCommandEvent& event)
{
    wxString firstpass=this->TextCtrlPassowrd->GetValue();
    wxString secpass=this->TextCtrlRepeatPassword->GetValue();
    if(firstpass!=secpass)
    {
wxMessageDialog * warring= new wxMessageDialog(0,"password dont match","warrning");
    warring->ShowModal();
    delete(warring);

    }
}
