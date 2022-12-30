#include "SettingsDialog.h"
#include "LocationDialog.h"
#include "WinAirqApp.h"
#include "ConfigFile.h"

//(*InternalHeaders(SettingsDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(SettingsDialog)
const long SettingsDialog::ID_LBLLOCATION = wxNewId();
const long SettingsDialog::ID_TXTLOCATION = wxNewId();
const long SettingsDialog::ID_BTNCHANGELOCATION = wxNewId();
const long SettingsDialog::ID_STATICLINE1 = wxNewId();
const long SettingsDialog::ID_CHKSHOWMAINWINDOWONPROGRAMLAUNCH = wxNewId();
const long SettingsDialog::ID_CHKUPDATEONPROGRAMLAUNCH = wxNewId();
const long SettingsDialog::ID_CHKUPDATEEVERY15MINUTES = wxNewId();
const long SettingsDialog::ID_STATICLINE2 = wxNewId();
const long SettingsDialog::ID_LBLCURRENTLANGUAGE = wxNewId();
const long SettingsDialog::ID_BTNCHANGELANGUAGE = wxNewId();
const long SettingsDialog::ID_BTNAPPLY = wxNewId();
//*)

BEGIN_EVENT_TABLE(SettingsDialog,wxDialog)
	//(*EventTable(SettingsDialog)
	//*)
END_EVENT_TABLE()

SettingsDialog::SettingsDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	//(*Initialize(SettingsDialog)
	wxFlexGridSizer* FgsButtons;
	wxFlexGridSizer* FgsLocation;
	wxFlexGridSizer* FgsLanguage;
	wxFlexGridSizer* FgsBoolSettings;
	wxFlexGridSizer* FgsMain;

	Create(parent, wxID_ANY, _("Program settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FgsMain = new wxFlexGridSizer(6, 1, 0, 0);
	FgsLocation = new wxFlexGridSizer(1, 3, 0, 0);
	FgsLocation->AddGrowableCol(1);
	FgsLocation->AddGrowableRow(1);
	LblLocation = new wxStaticText(this, ID_LBLLOCATION, _("Location:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLLOCATION"));
	FgsLocation->Add(LblLocation, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TxtLocation = new wxTextCtrl(this, ID_TXTLOCATION, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TXTLOCATION"));
	FgsLocation->Add(TxtLocation, 1, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BtnChangeLocation = new wxButton(this, ID_BTNCHANGELOCATION, _("*"), wxDefaultPosition, wxSize(20,-1), 0, wxDefaultValidator, _T("ID_BTNCHANGELOCATION"));
	FgsLocation->Add(BtnChangeLocation, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FgsMain->Add(FgsLocation, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	StaticLine1->SetMinSize(wxSize(300,-1));
	FgsMain->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsBoolSettings = new wxFlexGridSizer(3, 1, 0, 0);
	ChkShowMainWindowOnProgramLaunch = new wxCheckBox(this, ID_CHKSHOWMAINWINDOWONPROGRAMLAUNCH, _("Show main window on program launch"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKSHOWMAINWINDOWONPROGRAMLAUNCH"));
	ChkShowMainWindowOnProgramLaunch->SetValue(false);
	FgsBoolSettings->Add(ChkShowMainWindowOnProgramLaunch, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ChkUpdateOnProgramLaunch = new wxCheckBox(this, ID_CHKUPDATEONPROGRAMLAUNCH, _("Update data on program launch"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKUPDATEONPROGRAMLAUNCH"));
	ChkUpdateOnProgramLaunch->SetValue(false);
	FgsBoolSettings->Add(ChkUpdateOnProgramLaunch, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ChkUpdateEvery15Minutes = new wxCheckBox(this, ID_CHKUPDATEEVERY15MINUTES, _("Update data every 15 minutes"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKUPDATEEVERY15MINUTES"));
	ChkUpdateEvery15Minutes->SetValue(false);
	FgsBoolSettings->Add(ChkUpdateEvery15Minutes, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FgsMain->Add(FgsBoolSettings, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	StaticLine2->SetMinSize(wxSize(300,-1));
	FgsMain->Add(StaticLine2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsLanguage = new wxFlexGridSizer(1, 2, 0, 0);
	LblCurrentLanguage = new wxStaticText(this, ID_LBLCURRENTLANGUAGE, _("Current language: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLCURRENTLANGUAGE"));
	FgsLanguage->Add(LblCurrentLanguage, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BtnChangeLanguage = new wxButton(this, ID_BTNCHANGELANGUAGE, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNCHANGELANGUAGE"));
	FgsLanguage->Add(BtnChangeLanguage, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsMain->Add(FgsLanguage, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsButtons = new wxFlexGridSizer(0, 3, 0, 0);
	BtnOK = new wxButton(this, wxID_YES, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_YES"));
	BtnOK->SetDefault();
	FgsButtons->Add(BtnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	BtnCancel = new wxButton(this, wxID_OK, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	FgsButtons->Add(BtnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	BtnApply = new wxButton(this, ID_BTNAPPLY, _("&Apply"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNAPPLY"));
	FgsButtons->Add(BtnApply, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	FgsMain->Add(FgsButtons, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FgsMain);
	FgsMain->Fit(this);
	FgsMain->SetSizeHints(this);
	Center();

	Connect(ID_BTNCHANGELOCATION,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnBtnChangeLocationClick);
	Connect(ID_BTNCHANGELANGUAGE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnBtnChangeLanguageClick);
	Connect(wxID_YES,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnBtnOKClick);
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnBtnCancelClick);
	Connect(ID_BTNAPPLY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnBtnApplyClick);
	//*)

	chosenLocation = wxGetApp().location;
	TxtLocation->SetLabel(chosenLocation);
	chosenLongitude = wxGetApp().longitude;
	chosenLatitude = wxGetApp().latitude;
	ChkShowMainWindowOnProgramLaunch->SetValue(wxGetApp().showMainWindowOnProgramLaunch);
	ChkUpdateOnProgramLaunch->SetValue(wxGetApp().updateOnProgramLaunch);
	ChkUpdateEvery15Minutes->SetValue(wxGetApp().updateEvery15Minutes);
	wxString currentLanguageName = wxLocale::GetLanguageName(wxGetApp().languageID);
	if (currentLanguageName.Contains(wxT(DEFAULT_LANGUAGE_FORMAL_NAME)))
    {
        currentLanguageName = wxT(DEFAULT_LANGUAGE_FORMAL_NAME);
    }
    currentLanguageName = wxGetTranslation(currentLanguageName);
	LblCurrentLanguage->SetLabel(_("Current language: ") + currentLanguageName);
	chosenLanguageID = wxGetApp().languageID;
}

SettingsDialog::~SettingsDialog()
{
	//(*Destroy(SettingsDialog)
	//*)
}

void SettingsDialog::ApplySettings()
{
    if(wxGetApp().languageID != chosenLanguageID)
    {
        wxMessageBox(_("Another language has just been selected. To reflect all the changes, please restart the application."), _("Message"));
        wxGetApp().languageID = chosenLanguageID;
    }
    wxGetApp().location = chosenLocation;
    wxGetApp().longitude = chosenLongitude;
    wxGetApp().latitude = chosenLatitude;
    wxGetApp().showMainWindowOnProgramLaunch = ChkShowMainWindowOnProgramLaunch->IsChecked();
    wxGetApp().updateOnProgramLaunch = ChkUpdateOnProgramLaunch->IsChecked();
    wxGetApp().updateEvery15Minutes = ChkUpdateEvery15Minutes->IsChecked();

    returnCode = wxID_OK;

    ConfigFile *configFile = new ConfigFile();
    configFile->SaveConfiguration(wxGetApp().languageID, wxGetApp().location, wxGetApp().longitude, wxGetApp().latitude, wxGetApp().showMainWindowOnProgramLaunch, wxGetApp().updateOnProgramLaunch, wxGetApp().updateEvery15Minutes);
    wxDELETE(configFile);
}

void SettingsDialog::OnBtnOKClick(wxCommandEvent& event)
{
    ApplySettings();
    Close();
    SetReturnCode(returnCode);
}

void SettingsDialog::OnBtnCancelClick(wxCommandEvent& event)
{
    if(wxGetApp().languageID != chosenLanguageID)
    {
        wxGetApp().OnSetLanguage(wxGetApp().languageID);
    }
    Close();
    SetReturnCode(returnCode);
}

void SettingsDialog::OnBtnApplyClick(wxCommandEvent& event)
{
    ApplySettings();
}

void SettingsDialog::OnBtnChangeLanguageClick(wxCommandEvent& event)
{
    short selectedLanguageID = wxGetApp().SelectLanguage();
    if (selectedLanguageID != wxLANGUAGE_UNKNOWN)
    {
        chosenLanguageID = selectedLanguageID;
    }
}

void SettingsDialog::OnBtnChangeLocationClick(wxCommandEvent& event)
{
    LocationDialog *locationDialog = new LocationDialog(GetParent(), -1);
    if (locationDialog->ShowModal() == wxID_OK)
    {
        chosenLocation = locationDialog->GetSelectedLocation();
        chosenLongitude = locationDialog->GetSelectedLongitude();
        chosenLatitude = locationDialog->GetSelectedLatitude();
	    TxtLocation->SetLabel(chosenLocation);
    }
    wxDELETE(locationDialog);
}
