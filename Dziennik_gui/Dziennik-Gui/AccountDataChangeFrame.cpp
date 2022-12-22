#include "AccountDataChangeFrame.h"

//(*InternalHeaders(AccountDataChangeFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(AccountDataChangeFrame)
const long AccountDataChangeFrame::ID_TEXTCTRLNICKCHANGE = wxNewId();
const long AccountDataChangeFrame::ID_STATICTEXT3 = wxNewId();
const long AccountDataChangeFrame::ID_TEXTCTRLPASSWORDCHANGE = wxNewId();
const long AccountDataChangeFrame::ID_STATICTEXT2 = wxNewId();
const long AccountDataChangeFrame::ID_TEXTCTRLPASSWRODREPEAD = wxNewId();
const long AccountDataChangeFrame::ID_STATICTEXT1 = wxNewId();
const long AccountDataChangeFrame::ID_BUTTONSAAVEACCOUNTDATA = wxNewId();
const long AccountDataChangeFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AccountDataChangeFrame,wxDialog)
	//(*EventTable(AccountDataChangeFrame)
	//*)
END_EVENT_TABLE()

AccountDataChangeFrame::AccountDataChangeFrame(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(AccountDataChangeFrame)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(240,368), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	TextCtrlNickChange = new wxTextCtrl(Panel1, ID_TEXTCTRLNICKCHANGE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLNICKCHANGE"));
	BoxSizer1->Add(TextCtrlNickChange, 1, wxALL|wxEXPAND, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Nick"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer1->Add(StaticText3, 1, wxALL|wxEXPAND, 5);
	TextCtrlPasswordChange = new wxTextCtrl(Panel1, ID_TEXTCTRLPASSWORDCHANGE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRLPASSWORDCHANGE"));
	BoxSizer1->Add(TextCtrlPasswordChange, 1, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("new Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer1->Add(StaticText2, 1, wxALL|wxEXPAND, 5);
	TextCtrlPasswordReapeat = new wxTextCtrl(Panel1, ID_TEXTCTRLPASSWRODREPEAD, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRLPASSWRODREPEAD"));
	BoxSizer1->Add(TextCtrlPasswordReapeat, 1, wxALL|wxEXPAND, 5);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("repeat new Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer1->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
	ButtonSaveAccountData = new wxButton(Panel1, ID_BUTTONSAAVEACCOUNTDATA, _("Save changes"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONSAAVEACCOUNTDATA"));
	BoxSizer1->Add(ButtonSaveAccountData, 1, wxALL|wxEXPAND, 5);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);
	//*)
}

AccountDataChangeFrame::~AccountDataChangeFrame()
{
	//(*Destroy(AccountDataChangeFrame)
	//*)
}

