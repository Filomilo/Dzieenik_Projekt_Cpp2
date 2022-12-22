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
        bool isChanging=false;
		//(*Declarations(AccountDataChangeFrame)
		wxButton* ButtonSaveAccountData;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrlNickChange;
		wxTextCtrl* TextCtrlPasswordChange;
		wxTextCtrl* TextCtrlPasswordReapeat;
		//*)

	protected:

		//(*Identifiers(AccountDataChangeFrame)
		static const long ID_TEXTCTRLNICKCHANGE;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRLPASSWORDCHANGE;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRLPASSWRODREPEAD;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTONSAAVEACCOUNTDATA;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(AccountDataChangeFrame)
		void OnButtonSaveAccountDataClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
