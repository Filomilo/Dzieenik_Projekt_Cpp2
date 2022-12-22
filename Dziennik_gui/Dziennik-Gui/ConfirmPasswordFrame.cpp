#include "ConfirmPasswordFrame.h"

//(*InternalHeaders(ConfirmPasswordFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ConfirmPasswordFrame)
const long ConfirmPasswordFrame::ID_TEXTCTRLCOFNIRMPASSWORD = wxNewId();
const long ConfirmPasswordFrame::ID_STATICTEXT1 = wxNewId();
const long ConfirmPasswordFrame::ID_TEXTCTRLREAPETPASS = wxNewId();
const long ConfirmPasswordFrame::ID_STATICTEXT2 = wxNewId();
const long ConfirmPasswordFrame::ID_BUTTONCONFRIM = wxNewId();
const long ConfirmPasswordFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ConfirmPasswordFrame,wxFrame)
	//(*EventTable(ConfirmPasswordFrame)
	//*)
END_EVENT_TABLE()

ConfirmPasswordFrame::ConfirmPasswordFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ConfirmPasswordFrame)
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(248,336), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	TextCtrlCofirmPassword = new wxTextCtrl(Panel1, ID_TEXTCTRLCOFNIRMPASSWORD, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRLCOFNIRMPASSWORD"));
	BoxSizer1->Add(TextCtrlCofirmPassword, 1, wxALL|wxEXPAND, 5);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Confirm your old Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer1->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
	TextCtrlReapeatPass = new wxTextCtrl(Panel1, ID_TEXTCTRLREAPETPASS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRLREAPETPASS"));
	BoxSizer1->Add(TextCtrlReapeatPass, 1, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("repeat Your Old Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer1->Add(StaticText2, 1, wxALL|wxEXPAND, 5);
	ButtonConfrim = new wxButton(Panel1, ID_BUTTONCONFRIM, _("Cofirm"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONCONFRIM"));
	BoxSizer1->Add(ButtonConfrim, 1, wxALL|wxEXPAND, 5);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);
	//*)
}

ConfirmPasswordFrame::~ConfirmPasswordFrame()
{
	//(*Destroy(ConfirmPasswordFrame)
	//*)
}

