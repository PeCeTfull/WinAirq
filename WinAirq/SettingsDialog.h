#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

//(*Headers(SettingsDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class SettingsDialog: public wxDialog
{
	public:

		SettingsDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
		virtual ~SettingsDialog();

		//(*Declarations(SettingsDialog)
		wxButton* BtnCancel;
		wxTextCtrl* TxtLocation;
		wxCheckBox* ChkUpdateEvery15Minutes;
		wxButton* BtnChangeLocation;
		wxCheckBox* ChkShowMainWindowOnProgramLaunch;
		wxButton* BtnApply;
		wxStaticLine* StaticLine2;
		wxCheckBox* ChkUpdateOnProgramLaunch;
		wxStaticLine* StaticLine1;
		wxStaticText* LblLocation;
		wxStaticText* LblCurrentLanguage;
		wxButton* BtnChangeLanguage;
		wxButton* BtnOK;
		//*)

	protected:

		//(*Identifiers(SettingsDialog)
		static const long ID_LBLLOCATION;
		static const long ID_TXTLOCATION;
		static const long ID_BTNCHANGELOCATION;
		static const long ID_STATICLINE1;
		static const long ID_CHKSHOWMAINWINDOWONPROGRAMLAUNCH;
		static const long ID_CHKUPDATEONPROGRAMLAUNCH;
		static const long ID_CHKUPDATEEVERY15MINUTES;
		static const long ID_STATICLINE2;
		static const long ID_LBLCURRENTLANGUAGE;
		static const long ID_BTNCHANGELANGUAGE;
		static const long ID_BTNAPPLY;
		//*)

	private:

	    void ApplySettings();
	    short chosenLanguageID;
	    wxString chosenLocation;
	    wxString chosenLongitude;
	    wxString chosenLatitude;
	    short returnCode = wxID_CANCEL;

		//(*Handlers(SettingsDialog)
		void OnBtnOKClick(wxCommandEvent& event);
		void OnBtnCancelClick(wxCommandEvent& event);
		void OnBtnApplyClick(wxCommandEvent& event);
		void OnBtnChangeLanguageClick(wxCommandEvent& event);
		void OnBtnChangeLocationClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
