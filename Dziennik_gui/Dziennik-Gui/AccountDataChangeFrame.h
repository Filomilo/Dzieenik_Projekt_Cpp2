#ifndef ACCOUNTDATACHANGEFRAME_H
#define ACCOUNTDATACHANGEFRAME_H

//(*Headers(AccountDataChangeFrame)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class AccountDataChangeFrame: public wxDialog
{
	public:

		AccountDataChangeFrame(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~AccountDataChangeFrame();

		//(*Declarations(AccountDataChangeFrame)
		wxButton* ButtonSaveAccountData;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(AccountDataChangeFrame)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTONSAAVEACCOUNTDATA;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(AccountDataChangeFrame)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
