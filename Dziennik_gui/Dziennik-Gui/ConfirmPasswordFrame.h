#ifndef CONFIRMPASSWORDFRAME_H
#define CONFIRMPASSWORDFRAME_H

//(*Headers(ConfirmPasswordFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class ConfirmPasswordFrame: public wxFrame
{
	public:

		ConfirmPasswordFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ConfirmPasswordFrame();

		//(*Declarations(ConfirmPasswordFrame)
		wxButton* ButtonConfrim;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrlCofirmPassword;
		wxTextCtrl* TextCtrlReapeatPass;
		//*)

	protected:

		//(*Identifiers(ConfirmPasswordFrame)
		static const long ID_TEXTCTRLCOFNIRMPASSWORD;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRLREAPETPASS;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTONCONFRIM;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(ConfirmPasswordFrame)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
