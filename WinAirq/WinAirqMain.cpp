/***************************************************************
 * Name:      WinAirqMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    PeCeT_full (me@pecetfull.pl)
 * Created:   2022-03-08
 * Copyright: PeCeT_full (https://www.pecetfull.pl/)
 * License:   The MIT License
 **************************************************************/

#include "WinAirqMain.h"
#include "WinAirqApp.h"
#include "SettingsDialog.h"
#include "include/AirPollutionRequestThread.h"
#include <wx/aboutdlg.h>
#include <wx/msgdlg.h>
#include <wx/url.h>

#define ICON_NAME "aaaa"

#define GOOD_QUALITY_ICON_NAME "q_good"
#define FAIR_QUALITY_ICON_NAME "q_fair"
#define MODERATE_QUALITY_ICON_NAME "q_moderate"
#define POOR_QUALITY_ICON_NAME "q_poor"
#define VERY_POOR_QUALITY_ICON_NAME "q_verypoor"
#define UNKNOWN_QUALITY_ICON_NAME "q_unknown"

#define GREEN_STATUS_COLOUR "#008000"
#define BLUE_STATUS_COLOUR "#0000FF"
#define YELLOW_STATUS_COLOUR "#808000"
#define RED_STATUS_COLOUR "#FF0000"
#define GREY_STATUS_COLOUR "#808080"

//(*InternalHeaders(WinAirqDialog)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxBuildInfoFormat {
    short_f, long_f };

wxString wxBuildInfo(wxBuildInfoFormat format)
{
    wxString wxBuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxBuild << _T("-Windows");
#elif defined(__UNIX__)
        wxBuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxBuild << _T("-Unicode build");
#else
        wxBuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxBuild;
}

//(*IdInit(WinAirqDialog)
const long WinAirqDialog::ID_LBLLOCATION = wxNewId();
const long WinAirqDialog::ID_LBLLOCATIONVAL = wxNewId();
const long WinAirqDialog::ID_LBLDATETIME = wxNewId();
const long WinAirqDialog::ID_LBLDATETIMEVAL = wxNewId();
const long WinAirqDialog::ID_LBLAIRQUALITY = wxNewId();
const long WinAirqDialog::ID_LBLAIRQUALITYVAL = wxNewId();
const long WinAirqDialog::ID_PNLHEADER = wxNewId();
const long WinAirqDialog::ID_STATICLINE1 = wxNewId();
const long WinAirqDialog::ID_LBLCO = wxNewId();
const long WinAirqDialog::ID_LBLCOVAL = wxNewId();
const long WinAirqDialog::ID_LBLNO = wxNewId();
const long WinAirqDialog::ID_LBLNOVAL = wxNewId();
const long WinAirqDialog::ID_LBLNO2_1 = wxNewId();
const long WinAirqDialog::ID_LBLNO2_2 = wxNewId();
const long WinAirqDialog::ID_LBLNO2_3 = wxNewId();
const long WinAirqDialog::ID_LBLNO2VAL = wxNewId();
const long WinAirqDialog::ID_LBLO3_1 = wxNewId();
const long WinAirqDialog::ID_LBLO3_2 = wxNewId();
const long WinAirqDialog::ID_LBLO3_3 = wxNewId();
const long WinAirqDialog::ID_LBLO3VAL = wxNewId();
const long WinAirqDialog::ID_LBLSO2_1 = wxNewId();
const long WinAirqDialog::ID_LBLSO2_2 = wxNewId();
const long WinAirqDialog::ID_LBLSO2_3 = wxNewId();
const long WinAirqDialog::ID_LBLSO2VAL = wxNewId();
const long WinAirqDialog::ID_LBLPM25_1 = wxNewId();
const long WinAirqDialog::ID_LBLPM25_2 = wxNewId();
const long WinAirqDialog::ID_LBLPM25_3 = wxNewId();
const long WinAirqDialog::ID_LBLPM25VAL = wxNewId();
const long WinAirqDialog::ID_LBLPM10_1 = wxNewId();
const long WinAirqDialog::ID_LBLPM10_2 = wxNewId();
const long WinAirqDialog::ID_LBLPM10_3 = wxNewId();
const long WinAirqDialog::ID_LBLPM10VAL = wxNewId();
const long WinAirqDialog::ID_LBLNH3_1 = wxNewId();
const long WinAirqDialog::ID_LBLNH3_2 = wxNewId();
const long WinAirqDialog::ID_LBLNH3_3 = wxNewId();
const long WinAirqDialog::ID_LBLNH3VAL = wxNewId();
const long WinAirqDialog::ID_PNLMEASURES = wxNewId();
const long WinAirqDialog::ID_BTNUPDATE = wxNewId();
const long WinAirqDialog::idMenuDetails = wxNewId();
const long WinAirqDialog::idMenuUpdate = wxNewId();
const long WinAirqDialog::idMenuSettings = wxNewId();
const long WinAirqDialog::idMenuAQILegend = wxNewId();
const long WinAirqDialog::idMenuAbout = wxNewId();
const long WinAirqDialog::idMenuExit = wxNewId();
//*)

BEGIN_EVENT_TABLE(WinAirqDialog,wxDialog)
EVT_TIMER(4949, WinAirqDialog::OnTimer)
    //(*EventTable(WinAirqDialog)
    //*)
END_EVENT_TABLE()

AirPollutionRequestThread *airPollutionRequestThread = NULL;

WinAirqDialog::WinAirqDialog(wxWindow* parent,wxWindowID id) : timer(this, 4949)
{
    //(*Initialize(WinAirqDialog)
    wxFlexGridSizer* FgsButtons;
    wxFlexGridSizer* FgsPM10;
    wxFlexGridSizer* FgsMeasures;
    wxFlexGridSizer* FgsNH3;
    wxFlexGridSizer* FgsNO2;
    wxFlexGridSizer* FgsHeader;
    wxFlexGridSizer* FgsSO2;
    wxFlexGridSizer* FgsPM25;
    wxFlexGridSizer* FgsMain;
    wxFlexGridSizer* FgsO3;

    Create(parent, wxID_ANY, _("WinAirq"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    FgsMain = new wxFlexGridSizer(4, 1, 0, 0);
    PnlHeader = new wxPanel(this, ID_PNLHEADER, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLHEADER"));
    PnlHeader->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    FgsHeader = new wxFlexGridSizer(3, 2, 0, 0);
    LblLocation = new wxStaticText(PnlHeader, ID_LBLLOCATION, _("Location:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLLOCATION"));
    LblLocation->SetMinSize(wxSize(120,-1));
    FgsHeader->Add(LblLocation, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblLocationVal = new wxStaticText(PnlHeader, ID_LBLLOCATIONVAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLLOCATIONVAL"));
    FgsHeader->Add(LblLocationVal, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblDateTime = new wxStaticText(PnlHeader, ID_LBLDATETIME, _("Date && time:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLDATETIME"));
    LblDateTime->SetMinSize(wxSize(120,-1));
    FgsHeader->Add(LblDateTime, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblDateTimeVal = new wxStaticText(PnlHeader, ID_LBLDATETIMEVAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLDATETIMEVAL"));
    LblDateTimeVal->SetMinSize(wxSize(120,-1));
    FgsHeader->Add(LblDateTimeVal, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblAirQuality = new wxStaticText(PnlHeader, ID_LBLAIRQUALITY, _("Air quality:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLAIRQUALITY"));
    LblAirQuality->SetMinSize(wxSize(120,-1));
    FgsHeader->Add(LblAirQuality, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblAirQualityVal = new wxStaticText(PnlHeader, ID_LBLAIRQUALITYVAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLAIRQUALITYVAL"));
    LblAirQualityVal->SetMinSize(wxSize(120,-1));
    FgsHeader->Add(LblAirQualityVal, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    PnlHeader->SetSizer(FgsHeader);
    FgsHeader->Fit(PnlHeader);
    FgsHeader->SetSizeHints(PnlHeader);
    FgsMain->Add(PnlHeader, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FgsMain->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PnlMeasures = new wxPanel(this, ID_PNLMEASURES, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLMEASURES"));
    PnlMeasures->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    FgsMeasures = new wxFlexGridSizer(8, 2, 0, 0);
    LblCO = new wxStaticText(PnlMeasures, ID_LBLCO, _("CO:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLCO"));
    LblCO->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblCO, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblCOVal = new wxStaticText(PnlMeasures, ID_LBLCOVAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLCOVAL"));
    LblCOVal->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblCOVal, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblNO = new wxStaticText(PnlMeasures, ID_LBLNO, _("NO:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNO"));
    LblNO->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblNO, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblNOVal = new wxStaticText(PnlMeasures, ID_LBLNOVAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNOVAL"));
    LblNOVal->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblNOVal, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FgsNO2 = new wxFlexGridSizer(0, 3, 0, 0);
    LblNO2_1 = new wxStaticText(PnlMeasures, ID_LBLNO2_1, _("NO "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNO2_1"));
    FgsNO2->Add(LblNO2_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblNO2_2 = new wxStaticText(PnlMeasures, ID_LBLNO2_2, _("2 "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNO2_2"));
    FgsNO2->Add(LblNO2_2, 1, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LblNO2_3 = new wxStaticText(PnlMeasures, ID_LBLNO2_3, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNO2_3"));
    FgsNO2->Add(LblNO2_3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FgsMeasures->Add(FgsNO2, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblNO2Val = new wxStaticText(PnlMeasures, ID_LBLNO2VAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNO2VAL"));
    LblNO2Val->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblNO2Val, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FgsO3 = new wxFlexGridSizer(0, 3, 0, 0);
    LblO3_1 = new wxStaticText(PnlMeasures, ID_LBLO3_1, _("O "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLO3_1"));
    FgsO3->Add(LblO3_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblO3_2 = new wxStaticText(PnlMeasures, ID_LBLO3_2, _("3 "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLO3_2"));
    FgsO3->Add(LblO3_2, 1, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LblO3_3 = new wxStaticText(PnlMeasures, ID_LBLO3_3, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLO3_3"));
    FgsO3->Add(LblO3_3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FgsMeasures->Add(FgsO3, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblO3Val = new wxStaticText(PnlMeasures, ID_LBLO3VAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLO3VAL"));
    LblO3Val->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblO3Val, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FgsSO2 = new wxFlexGridSizer(0, 3, 0, 0);
    LblSO2_1 = new wxStaticText(PnlMeasures, ID_LBLSO2_1, _("SO "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLSO2_1"));
    FgsSO2->Add(LblSO2_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblSO2_2 = new wxStaticText(PnlMeasures, ID_LBLSO2_2, _("2 "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLSO2_2"));
    FgsSO2->Add(LblSO2_2, 1, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LblSO2_3 = new wxStaticText(PnlMeasures, ID_LBLSO2_3, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLSO2_3"));
    FgsSO2->Add(LblSO2_3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FgsMeasures->Add(FgsSO2, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblSO2Val = new wxStaticText(PnlMeasures, ID_LBLSO2VAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLSO2VAL"));
    LblSO2Val->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblSO2Val, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FgsPM25 = new wxFlexGridSizer(0, 3, 0, 0);
    LblPM25_1 = new wxStaticText(PnlMeasures, ID_LBLPM25_1, _("PM "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM25_1"));
    FgsPM25->Add(LblPM25_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblPM25_2 = new wxStaticText(PnlMeasures, ID_LBLPM25_2, _("2.5 "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM25_2"));
    FgsPM25->Add(LblPM25_2, 1, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LblPM25_3 = new wxStaticText(PnlMeasures, ID_LBLPM25_3, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM25_3"));
    FgsPM25->Add(LblPM25_3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FgsMeasures->Add(FgsPM25, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblPM25Val = new wxStaticText(PnlMeasures, ID_LBLPM25VAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM25VAL"));
    LblPM25Val->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblPM25Val, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FgsPM10 = new wxFlexGridSizer(0, 3, 0, 0);
    LblPM10_1 = new wxStaticText(PnlMeasures, ID_LBLPM10_1, _("PM "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM10_1"));
    FgsPM10->Add(LblPM10_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblPM10_2 = new wxStaticText(PnlMeasures, ID_LBLPM10_2, _("10 "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM10_2"));
    FgsPM10->Add(LblPM10_2, 1, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LblPM10_3 = new wxStaticText(PnlMeasures, ID_LBLPM10_3, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM10_3"));
    FgsPM10->Add(LblPM10_3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FgsMeasures->Add(FgsPM10, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblPM10Val = new wxStaticText(PnlMeasures, ID_LBLPM10VAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM10VAL"));
    LblPM10Val->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblPM10Val, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FgsNH3 = new wxFlexGridSizer(0, 3, 0, 0);
    LblNH3_1 = new wxStaticText(PnlMeasures, ID_LBLNH3_1, _("NH "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNH3_1"));
    FgsNH3->Add(LblNH3_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblNH3_2 = new wxStaticText(PnlMeasures, ID_LBLNH3_2, _("3 "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNH3_2"));
    FgsNH3->Add(LblNH3_2, 1, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LblNH3_3 = new wxStaticText(PnlMeasures, ID_LBLNH3_3, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNH3_3"));
    FgsNH3->Add(LblNH3_3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FgsMeasures->Add(FgsNH3, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    LblNH3Val = new wxStaticText(PnlMeasures, ID_LBLNH3VAL, _("\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNH3VAL"));
    LblNH3Val->SetMinSize(wxSize(120,-1));
    FgsMeasures->Add(LblNH3Val, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    PnlMeasures->SetSizer(FgsMeasures);
    FgsMeasures->Fit(PnlMeasures);
    FgsMeasures->SetSizeHints(PnlMeasures);
    FgsMain->Add(PnlMeasures, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FgsButtons = new wxFlexGridSizer(0, 3, 0, 0);
    BtnOK = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
    BtnOK->SetDefault();
    FgsButtons->Add(BtnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
    BtnUpdate = new wxButton(this, ID_BTNUPDATE, _("&Update"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNUPDATE"));
    FgsButtons->Add(BtnUpdate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
    FgsMain->Add(FgsButtons, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FgsMain);
    MenuItem5 = new wxMenuItem((&TaskbarMenu), idMenuDetails, _("Show &details"), wxEmptyString, wxITEM_NORMAL);
    TaskbarMenu.Append(MenuItem5);
    MenuItem3 = new wxMenuItem((&TaskbarMenu), idMenuUpdate, _("&Update"), wxEmptyString, wxITEM_NORMAL);
    TaskbarMenu.Append(MenuItem3);
    TaskbarMenu.AppendSeparator();
    MenuItem4 = new wxMenuItem((&TaskbarMenu), idMenuSettings, _("&Settings"), wxEmptyString, wxITEM_NORMAL);
    TaskbarMenu.Append(MenuItem4);
    TaskbarMenu.AppendSeparator();
    MenuItem6 = new wxMenuItem((&TaskbarMenu), idMenuAQILegend, _("AQI &legend"), wxEmptyString, wxITEM_NORMAL);
    TaskbarMenu.Append(MenuItem6);
    MenuItem1 = new wxMenuItem((&TaskbarMenu), idMenuAbout, _("&About..."), wxEmptyString, wxITEM_NORMAL);
    TaskbarMenu.Append(MenuItem1);
    TaskbarMenu.AppendSeparator();
    MenuItem2 = new wxMenuItem((&TaskbarMenu), idMenuExit, _("E&xit"), wxEmptyString, wxITEM_NORMAL);
    TaskbarMenu.Append(MenuItem2);
    FgsMain->Fit(this);
    FgsMain->SetSizeHints(this);
    Center();

    Connect(ID_BTNUPDATE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&WinAirqDialog::OnBtnUpdateClick);
    //*)

    SetIcon(wxIcon(wxT(ICON_NAME)));

    TaskbarMenu.Connect(idMenuDetails, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&WinAirqDialog::OnDetails, NULL, this);
    TaskbarMenu.Connect(idMenuUpdate, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&WinAirqDialog::OnUpdate, NULL, this);
    TaskbarMenu.Connect(idMenuSettings, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&WinAirqDialog::OnSettings, NULL, this);
    TaskbarMenu.Connect(idMenuAQILegend, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&WinAirqDialog::OnAQILegend, NULL, this);
    TaskbarMenu.Connect(idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&WinAirqDialog::OnAbout, NULL, this);
    TaskbarMenu.Connect(idMenuExit, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&WinAirqDialog::OnQuit, NULL, this);

    taskbarIcon = new wxTaskBarIcon();
    taskbarIcon->SetIcon(wxIcon(wxT(UNKNOWN_QUALITY_ICON_NAME)), this->GetLabel());
    taskbarIcon->Connect(wxEVT_TASKBAR_CLICK, (wxObjectEventFunction)&WinAirqDialog::OnTaskbarMenuRightClick, NULL, this);
    taskbarIcon->Connect(wxEVT_TASKBAR_LEFT_DOWN, (wxObjectEventFunction)&WinAirqDialog::OnDetails, NULL, this);

    RefreshLocationValLabel();
    CentreOnScreen();

    defaultFontColour = LblLocationVal->GetForegroundColour().GetAsString();

    if (wxGetApp().updateOnProgramLaunch)
    {
        CallAirPollutionRequest(true);
    }

    if (wxGetApp().updateEvery15Minutes)
    {
        StartUpdatingEvery15Minutes();
    }
}

WinAirqDialog::~WinAirqDialog()
{
    //(*Destroy(WinAirqDialog)
    //*)

    taskbarIcon->RemoveIcon();
    wxDELETE(taskbarIcon);
}

void WinAirqDialog::RefreshLocationValLabel()
{
    if (wxGetApp().location.Trim().IsEmpty())
    {
        LblLocationVal->SetLabel(wxT('?'));
    }
    else
    {
        LblLocationVal->SetLabel(wxGetApp().location);
    }
    PnlHeader->Layout();
    PnlHeader->GetSizer()->SetSizeHints(PnlHeader);
    GetSizer()->Fit(this);
}

void WinAirqDialog::StartScheduledTasks(unsigned int& totalAmountOfSeconds)
{
    timer.Start(totalAmountOfSeconds * 1000);
    isTimerRunning = true;
}

void WinAirqDialog::StopScheduledTasks()
{
    timer.Stop();
    isTimerRunning = false;
}

void WinAirqDialog::UpdateMeasureParameter(wxJSONValue &jsonRoot, wxString parameterJson, wxStaticText* parameterValLabel)
{
    wxString parameterVal = jsonRoot[wxT("list")][0][wxT("components")][parameterJson].AsString();

    if (parameterVal == wxT("null"))
    {
        parameterVal = _("Unknown");
    }

    parameterValLabel->SetLabel(parameterVal);
}

void WinAirqDialog::SetColourForParameter(wxStaticText* parameterValLabel, wxStaticText* parameterLabelPart1, wxStaticText* parameterLabelPart2, wxStaticText* parameterLabelPart3, wxString colour)
{
    parameterLabelPart1->SetForegroundColour(wxColour(colour));
    parameterLabelPart2->SetForegroundColour(wxColour(colour));
    parameterLabelPart3->SetForegroundColour(wxColour(colour));
    parameterValLabel->SetForegroundColour(wxColour(colour));
}

void WinAirqDialog::UpdateMeasureParameter(wxJSONValue &jsonRoot, wxString parameterJson, wxStaticText* parameterValLabel, wxStaticText* parameterLabelPart1, wxStaticText* parameterLabelPart2, wxStaticText* parameterLabelPart3, int firstThresholdHit, int secondThresholdHit, int thirdThresholdHit, int fourthThresholdHit)
{
    wxString parameterVal = jsonRoot[wxT("list")][0][wxT("components")][parameterJson].AsString();
    wxFont newParameterFont = parameterValLabel->GetFont();

    if (parameterVal == wxT("null"))
    {
        parameterVal = _("Unknown");

        newParameterFont.SetWeight(wxFONTWEIGHT_NORMAL);
        SetColourForParameter(parameterValLabel, parameterLabelPart1, parameterLabelPart2, parameterLabelPart3, defaultFontColour);
    }
    else
    {
        long parameterValLong;
        parameterVal.ToLong(&parameterValLong);

        if (parameterValLong > fourthThresholdHit + parameterVal.Contains(wxT(".")))
        {
            SetColourForParameter(parameterValLabel, parameterLabelPart1, parameterLabelPart2, parameterLabelPart3, wxT(GREY_STATUS_COLOUR));
        }
        else if (parameterValLong > thirdThresholdHit + parameterVal.Contains(wxT(".")))
        {
            SetColourForParameter(parameterValLabel, parameterLabelPart1, parameterLabelPart2, parameterLabelPart3, wxT(RED_STATUS_COLOUR));
        }
        else if (parameterValLong > secondThresholdHit + parameterVal.Contains(wxT(".")))
        {
            SetColourForParameter(parameterValLabel, parameterLabelPart1, parameterLabelPart2, parameterLabelPart3, wxT(YELLOW_STATUS_COLOUR));
        }
        else if (parameterValLong > firstThresholdHit + parameterVal.Contains(wxT(".")))
        {
            SetColourForParameter(parameterValLabel, parameterLabelPart1, parameterLabelPart2, parameterLabelPart3, wxT(BLUE_STATUS_COLOUR));
        }
        else
        {
            SetColourForParameter(parameterValLabel, parameterLabelPart1, parameterLabelPart2, parameterLabelPart3, wxT(GREEN_STATUS_COLOUR));
        }

        newParameterFont.SetWeight(wxFONTWEIGHT_BOLD);
    }

    parameterValLabel->SetLabel(parameterVal);
    parameterLabelPart1->SetFont(newParameterFont);
    parameterLabelPart2->SetFont(newParameterFont);
    parameterLabelPart3->SetFont(newParameterFont);
    parameterValLabel->SetFont(newParameterFont);
}

void WinAirqDialog::CallAirPollutionRequest(bool silentMode)
{
    if (!isCallAirPollutionRequestRunning)
    {
        isCallAirPollutionRequestRunning = true;
        if (wxGetApp().location.Trim().IsEmpty())
        {
            isCallAirPollutionRequestRunning = false;

            if (!silentMode)
            {
                wxMessageBox(_("You have not specified the location. Please go to the settings and specify your location."), _("Warning"), wxICON_EXCLAMATION);
            }
        }
        else
        {
            airPollutionRequestThread = new AirPollutionRequestThread(silentMode);

            airPollutionRequestThread->mainDialog = this;

            airPollutionRequestThread->Create();
            airPollutionRequestThread->Run();
        }
    }
}

void WinAirqDialog::UpdateAllDetails(wxInputStream *airPollutionInputStream, bool silentMode)
{
    wxFont newFont = LblAirQualityVal->GetFont();
    wxString newFontColour = defaultFontColour;

    wxTextInputStream airPollutionTextInputStream(*airPollutionInputStream);
    wxString unknownAirQualityReason = wxEmptyString;
    if (airPollutionInputStream != NULL && airPollutionInputStream->CanRead())
    {
        wxJSONValue jsonRoot;
        wxJSONReader jsonReader;

        int numErrors = jsonReader.Parse(airPollutionTextInputStream.ReadLine(), &jsonRoot);

        if (numErrors == 0)
        {
            wxString errorMessage = jsonRoot[wxT("message")].AsString();

            if (errorMessage == wxT("null"))
            {
                long dt = jsonRoot[wxT("list")][0][wxT("dt")].AsLong();
                wxDateTime dtDt = wxDateTime(dt);
                LblDateTimeVal->SetLabel(dtDt.FormatISODate() + ' ' + dtDt.FormatISOTime());
                wxString airQualityVal = wxEmptyString;

                int aqi = jsonRoot[wxT("list")][0][wxT("main")][wxT("aqi")].AsInt();
                switch (aqi)
                {
                    case 1:
                        airQualityVal = _("Good");

                        taskbarIcon->SetIcon(wxIcon(wxT(GOOD_QUALITY_ICON_NAME)), _("WinAirq - Air quality: ") + airQualityVal);

                        newFont.SetWeight(wxFONTWEIGHT_BOLD);
                        newFontColour = wxT(GREEN_STATUS_COLOUR);
                        break;
                    case 2:
                        airQualityVal = _("Fair");

                        taskbarIcon->SetIcon(wxIcon(wxT(FAIR_QUALITY_ICON_NAME)), _("WinAirq - Air quality: ") + airQualityVal);

                        newFont.SetWeight(wxFONTWEIGHT_BOLD);
                        newFontColour = wxT(BLUE_STATUS_COLOUR);
                        break;
                    case 3:
                        airQualityVal = _("Moderate");

                        taskbarIcon->SetIcon(wxIcon(wxT(MODERATE_QUALITY_ICON_NAME)), _("WinAirq - Air quality: ") + airQualityVal);

                        newFont.SetWeight(wxFONTWEIGHT_BOLD);
                        newFontColour = wxT(YELLOW_STATUS_COLOUR);
                        break;
                    case 4:
                        airQualityVal = _("Poor");

                        taskbarIcon->SetIcon(wxIcon(wxT(POOR_QUALITY_ICON_NAME)), _("WinAirq - Air quality: ") + airQualityVal);

                        newFont.SetWeight(wxFONTWEIGHT_BOLD);
                        newFontColour = wxT(RED_STATUS_COLOUR);
                        break;
                    case 5:
                        airQualityVal = _("Very poor");

                        taskbarIcon->SetIcon(wxIcon(wxT(VERY_POOR_QUALITY_ICON_NAME)), _("WinAirq - Air quality: ") + airQualityVal);

                        newFont.SetWeight(wxFONTWEIGHT_BOLD);
                        newFontColour = wxT(GREY_STATUS_COLOUR);
                        break;
                    default:
                        airQualityVal = _("Unknown");

                        taskbarIcon->SetIcon(wxIcon(wxT(UNKNOWN_QUALITY_ICON_NAME)), _("WinAirq - Air quality: ") + airQualityVal);

                        newFont.SetWeight(wxFONTWEIGHT_NORMAL);
                        break;
                }
                LblAirQualityVal->SetLabel(airQualityVal);
                LblAirQuality->SetFont(newFont);
                LblAirQualityVal->SetFont(newFont);
                LblAirQuality->SetForegroundColour(wxColour(newFontColour));
                LblAirQualityVal->SetForegroundColour(wxColour(newFontColour));

                UpdateMeasureParameter(jsonRoot, wxT("co"), LblCOVal);
                UpdateMeasureParameter(jsonRoot, wxT("no"), LblNOVal);
                UpdateMeasureParameter(jsonRoot, wxT("no2"), LblNO2Val, LblNO2_1, LblNO2_2, LblNO2_3, 50, 100, 200, 400);
                UpdateMeasureParameter(jsonRoot, wxT("o3"), LblO3Val, LblO3_1, LblO3_2, LblO3_3, 60, 120, 180, 240);
                UpdateMeasureParameter(jsonRoot, wxT("so2"), LblSO2Val);
                UpdateMeasureParameter(jsonRoot, wxT("pm2_5"), LblPM25Val, LblPM25_1, LblPM25_2, LblPM25_3, 15, 30, 55, 110);
                UpdateMeasureParameter(jsonRoot, wxT("pm10"), LblPM10Val, LblPM10_1, LblPM10_2, LblPM10_3, 25, 50, 90, 180);
                UpdateMeasureParameter(jsonRoot, wxT("nh3"), LblNH3Val);

                Refresh();
            }
            else if (!silentMode)
            {
                wxMessageBox(_("Unable to read data for the specified location. Please change the location or try again."), _("Error"), wxICON_HAND);
            }
            else
            {
                unknownAirQualityReason = _("Unknown (read error)");
            }
        }
        else if (!silentMode)
        {
            wxMessageBox(_("Unable to read data. Please try again later."), _("Error"), wxICON_HAND);
        }
        else
        {
            unknownAirQualityReason = _("Unknown (parse error)");
        }
    }
    else if (!silentMode)
    {
        wxMessageBox(_("Could not connect to the website. Please check your Internet connection and try again later."), _("Error"), wxICON_HAND);
    }
    else
    {
        unknownAirQualityReason = _("Unknown (connection error)");
    }

    if (!unknownAirQualityReason.IsEmpty())
    {
        taskbarIcon->SetIcon(wxIcon(wxT(UNKNOWN_QUALITY_ICON_NAME)));

        LblAirQualityVal->SetLabel(unknownAirQualityReason);

        newFont.SetWeight(wxFONTWEIGHT_NORMAL);
        LblAirQuality->SetFont(newFont);
        LblAirQualityVal->SetFont(newFont);
        LblAirQuality->SetForegroundColour(wxColour(newFontColour));
        LblAirQualityVal->SetForegroundColour(wxColour(newFontColour));
    }

    if (airPollutionRequestThread)
    {
        airPollutionRequestThread->mainDialog = NULL;
    }
    isCallAirPollutionRequestRunning = false;
}

void WinAirqDialog::StartUpdatingEvery15Minutes()
{
    if (!isTimerRunning)
    {
        unsigned int totalAmountOfSeconds = 900; // 900 secs = 15 mins
        StartScheduledTasks(totalAmountOfSeconds);
    }
}

void WinAirqDialog::TerminateUpdatingEvery15Minutes()
{
    if (isTimerRunning)
    {
        StopScheduledTasks();
    }
}

void WinAirqDialog::OnTimer(wxTimerEvent& event)
{
    CallAirPollutionRequest(true);
}

void WinAirqDialog::OnTaskbarMenuRightClick(wxCommandEvent& event)
{
    taskbarIcon->PopupMenu(&TaskbarMenu);
}

void WinAirqDialog::OnDetails(wxCommandEvent& event)
{
    Show();
    SetFocus();
}

void WinAirqDialog::OnUpdate(wxCommandEvent& event)
{
    CallAirPollutionRequest();
}

void WinAirqDialog::OnSettings(wxCommandEvent& event)
{
    SettingsDialog *settingsDialog = new SettingsDialog(GetParent(), -1);
    if (settingsDialog->ShowModal() == wxID_OK)
    {
        RefreshLocationValLabel();

        if (wxGetApp().updateEvery15Minutes)
        {
            StartUpdatingEvery15Minutes();
        }
        else
        {
            TerminateUpdatingEvery15Minutes();
        }
    }
    wxDELETE(settingsDialog);
}

void WinAirqDialog::OnAQILegend(wxCommandEvent& event)
{
    if (aqiLegendDialog != NULL)
    {
        wxDELETE(aqiLegendDialog);
    }

    aqiLegendDialog = new AQILegendDialog(GetParent(), -1);
    aqiLegendDialog->Show();
}

void WinAirqDialog::OnAbout(wxCommandEvent& event)
{
    wxAboutDialogInfo info;
    info.SetIcon(wxIcon(wxT(ICON_NAME)));
    info.SetName(_("WinAirq"));
    info.SetVersion(wxT("1.0"));
    info.SetCopyright(wxT("Copyright (C) PeCeT_full 2022 <me@pecetfull.pl>"));
    info.SetDescription(_("A current air quality reading program for vintage computers connected to the Internet\nfrom the data retrieved from OpenWeatherMap's API.\n\nBuild info: ") + wxBuildInfo(long_f) + _(".\nBuild date: ") +  __TDATE__ + wxT(", ") __TTIME__ + '.');
    info.SetWebSite(_("https://www.pecetfull.pl"));
    info.SetLicence(_("This program is published under The MIT License. For more information, please refer to the Licence.txt file included with the application."));

    wxAboutBox(info);
}

void WinAirqDialog::OnQuit(wxCommandEvent& event)
{
    wxGetApp().Exit();
}

void WinAirqDialog::OnBtnUpdateClick(wxCommandEvent& event)
{
    CallAirPollutionRequest();
}
