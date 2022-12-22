#ifndef PASSWORDCONFIRMFRAME_H
#define PASSWORDCONFIRMFRAME_H

//(*Headers(PasswordConfirmFrame)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class PasswordConfirmFrame: public wxDialog
{
	public:

		PasswordConfirmFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PasswordConfirmFrame();

		//(*Declarations(PasswordConfirmFrame)
		wxButton* ButtonConfirmPass;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrlPassowrd;
		wxTextCtrl* TextCtrlRepeatPassword;
		//*)

	protected:

		//(*Identifiers(PasswordConfirmFrame)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTONCONFIRMAPASS;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(PasswordConfirmFrame)
		void OnButtonConfirmPassClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
