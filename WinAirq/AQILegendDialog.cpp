#include "AQILegendDialog.h"
#include "WinAirqApp.h"

//(*InternalHeaders(AQILegendDialog)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(AQILegendDialog)
const long AQILegendDialog::ID_LBLQUALITATIVENAME = wxNewId();
const long AQILegendDialog::ID_LBLPOLLUTANTCONCENTRATION_1 = wxNewId();
const long AQILegendDialog::ID_LBLPOLLUTANTCONCENTRATION_2 = wxNewId();
const long AQILegendDialog::ID_PNLHEADER = wxNewId();
const long AQILegendDialog::ID_STATICTEXT4 = wxNewId();
const long AQILegendDialog::ID_LBLSO2_1 = wxNewId();
const long AQILegendDialog::ID_LBLSO2_2 = wxNewId();
const long AQILegendDialog::ID_LBLNO2_1 = wxNewId();
const long AQILegendDialog::ID_LBLNO2_2 = wxNewId();
const long AQILegendDialog::ID_LBLPM10_1 = wxNewId();
const long AQILegendDialog::ID_LBLPM10_2 = wxNewId();
const long AQILegendDialog::ID_LBLPM25_1 = wxNewId();
const long AQILegendDialog::ID_LBLPM25_2 = wxNewId();
const long AQILegendDialog::ID_STATICTEXT1 = wxNewId();
const long AQILegendDialog::ID_STATICTEXT2 = wxNewId();
const long AQILegendDialog::ID_LBLCO = wxNewId();
const long AQILegendDialog::ID_LBLGOOD = wxNewId();
const long AQILegendDialog::ID_LBLVALUES1 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES2 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES3 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES4 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES5 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES6 = wxNewId();
const long AQILegendDialog::ID_LBLFAIR = wxNewId();
const long AQILegendDialog::ID_LBLVALUES7 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES8 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES9 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES10 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES11 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES12 = wxNewId();
const long AQILegendDialog::ID_LBLMODERATE = wxNewId();
const long AQILegendDialog::ID_LBLVALUES13 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES14 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES15 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES16 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES17 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES18 = wxNewId();
const long AQILegendDialog::ID_LBLPOOR = wxNewId();
const long AQILegendDialog::ID_LBLVALUES19 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES20 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES21 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES22 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES23 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES24 = wxNewId();
const long AQILegendDialog::ID_LBLVERYPOOR = wxNewId();
const long AQILegendDialog::ID_LBLVALUES25 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES26 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES27 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES28 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES29 = wxNewId();
const long AQILegendDialog::ID_LBLVALUES30 = wxNewId();
const long AQILegendDialog::ID_PNLVALUES = wxNewId();
//*)

BEGIN_EVENT_TABLE(AQILegendDialog,wxDialog)
	//(*EventTable(AQILegendDialog)
	//*)
END_EVENT_TABLE()

AQILegendDialog::AQILegendDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(AQILegendDialog)
	wxFlexGridSizer* FgsPM10;
	wxFlexGridSizer* FgsNO2;
	wxFlexGridSizer* FgsCO;
	wxFlexGridSizer* FgsHeader;
	wxFlexGridSizer* FgsPollutantConcentration;
	wxFlexGridSizer* FgsSO2;
	wxFlexGridSizer* FgsPM25;
	wxFlexGridSizer* FgsMain;
	wxFlexGridSizer* FgsValues;
	wxFlexGridSizer* FgsO3;

	Create(parent, wxID_ANY, _("Air quality index - Legend"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FgsMain = new wxFlexGridSizer(2, 1, 0, 0);
	PnlHeader = new wxPanel(this, ID_PNLHEADER, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLHEADER"));
	PnlHeader->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	FgsHeader = new wxFlexGridSizer(1, 2, 0, 0);
	LblQualitativeName = new wxStaticText(PnlHeader, ID_LBLQUALITATIVENAME, _("Qualitative name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLQUALITATIVENAME"));
	LblQualitativeName->SetMinSize(wxSize(130,-1));
	LblQualitativeName->SetMaxSize(wxSize(130,-1));
	wxFont LblQualitativeNameFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblQualitativeName->SetFont(LblQualitativeNameFont);
	FgsHeader->Add(LblQualitativeName, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsPollutantConcentration = new wxFlexGridSizer(1, 2, 0, 0);
	LblPollutantConcentration_1 = new wxStaticText(PnlHeader, ID_LBLPOLLUTANTCONCENTRATION_1, _("Pollutant concentration in micro-g/m "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPOLLUTANTCONCENTRATION_1"));
	wxFont LblPollutantConcentration_1Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblPollutantConcentration_1->SetFont(LblPollutantConcentration_1Font);
	FgsPollutantConcentration->Add(LblPollutantConcentration_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LblPollutantConcentration_2 = new wxStaticText(PnlHeader, ID_LBLPOLLUTANTCONCENTRATION_2, _("3"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPOLLUTANTCONCENTRATION_2"));
	wxFont LblPollutantConcentration_2Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblPollutantConcentration_2->SetFont(LblPollutantConcentration_2Font);
	FgsPollutantConcentration->Add(LblPollutantConcentration_2, 1, wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsHeader->Add(FgsPollutantConcentration, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	PnlHeader->SetSizer(FgsHeader);
	FgsHeader->Fit(PnlHeader);
	FgsHeader->SetSizeHints(PnlHeader);
	FgsMain->Add(PnlHeader, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	PnlValues = new wxPanel(this, ID_PNLVALUES, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLVALUES"));
	PnlValues->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	FgsValues = new wxFlexGridSizer(6, 7, 0, 0);
	StaticText4 = new wxStaticText(PnlValues, ID_STATICTEXT4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText4->SetMinSize(wxSize(130,-1));
	StaticText4->SetMaxSize(wxSize(130,-1));
	FgsValues->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsSO2 = new wxFlexGridSizer(1, 2, 0, 0);
	LblSO2_1 = new wxStaticText(PnlValues, ID_LBLSO2_1, _("SO "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLSO2_1"));
	wxFont LblSO2_1Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblSO2_1->SetFont(LblSO2_1Font);
	FgsSO2->Add(LblSO2_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LblSO2_2 = new wxStaticText(PnlValues, ID_LBLSO2_2, _("2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLSO2_2"));
	wxFont LblSO2_2Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblSO2_2->SetFont(LblSO2_2Font);
	FgsSO2->Add(LblSO2_2, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsValues->Add(FgsSO2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsNO2 = new wxFlexGridSizer(1, 2, 0, 0);
	LblNO2_1 = new wxStaticText(PnlValues, ID_LBLNO2_1, _("NO "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNO2_1"));
	wxFont LblNO2_1Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblNO2_1->SetFont(LblNO2_1Font);
	FgsNO2->Add(LblNO2_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LblNO2_2 = new wxStaticText(PnlValues, ID_LBLNO2_2, _("2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLNO2_2"));
	wxFont LblNO2_2Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblNO2_2->SetFont(LblNO2_2Font);
	FgsNO2->Add(LblNO2_2, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsValues->Add(FgsNO2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsPM10 = new wxFlexGridSizer(1, 2, 0, 0);
	LblPM10_1 = new wxStaticText(PnlValues, ID_LBLPM10_1, _("PM "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM10_1"));
	wxFont LblPM10_1Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblPM10_1->SetFont(LblPM10_1Font);
	FgsPM10->Add(LblPM10_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LblPM10_2 = new wxStaticText(PnlValues, ID_LBLPM10_2, _("10"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM10_2"));
	wxFont LblPM10_2Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblPM10_2->SetFont(LblPM10_2Font);
	FgsPM10->Add(LblPM10_2, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsValues->Add(FgsPM10, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsPM25 = new wxFlexGridSizer(1, 2, 0, 0);
	LblPM25_1 = new wxStaticText(PnlValues, ID_LBLPM25_1, _("PM "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM25_1"));
	wxFont LblPM25_1Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblPM25_1->SetFont(LblPM25_1Font);
	FgsPM25->Add(LblPM25_1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LblPM25_2 = new wxStaticText(PnlValues, ID_LBLPM25_2, _("2.5"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPM25_2"));
	wxFont LblPM25_2Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblPM25_2->SetFont(LblPM25_2Font);
	FgsPM25->Add(LblPM25_2, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsValues->Add(FgsPM25, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsO3 = new wxFlexGridSizer(1, 2, 0, 0);
	StaticText1 = new wxStaticText(PnlValues, ID_STATICTEXT1, _("O "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	FgsO3->Add(StaticText1, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(PnlValues, ID_STATICTEXT2, _("3"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	FgsO3->Add(StaticText2, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsValues->Add(FgsO3, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsCO = new wxFlexGridSizer(1, 2, 0, 0);
	LblCO = new wxStaticText(PnlValues, ID_LBLCO, _("CO"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLCO"));
	wxFont LblCOFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblCO->SetFont(LblCOFont);
	FgsCO->Add(LblCO, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsValues->Add(FgsCO, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LblGood = new wxStaticText(PnlValues, ID_LBLGOOD, _("Good"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLGOOD"));
	LblGood->SetForegroundColour(wxColour(0,128,0));
	wxFont LblGoodFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblGood->SetFont(LblGoodFont);
	FgsValues->Add(LblGood, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues1 = new wxStaticText(PnlValues, ID_LBLVALUES1, _("0-20"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES1"));
	LblValues1->SetForegroundColour(wxColour(0,128,0));
	FgsValues->Add(LblValues1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues2 = new wxStaticText(PnlValues, ID_LBLVALUES2, _("0-40"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES2"));
	LblValues2->SetForegroundColour(wxColour(0,128,0));
	FgsValues->Add(LblValues2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues3 = new wxStaticText(PnlValues, ID_LBLVALUES3, _("0-20"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES3"));
	LblValues3->SetForegroundColour(wxColour(0,128,0));
	FgsValues->Add(LblValues3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues4 = new wxStaticText(PnlValues, ID_LBLVALUES4, _("0-10"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES4"));
	LblValues4->SetForegroundColour(wxColour(0,128,0));
	FgsValues->Add(LblValues4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues5 = new wxStaticText(PnlValues, ID_LBLVALUES5, _("0-60"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES5"));
	LblValues5->SetForegroundColour(wxColour(0,128,0));
	FgsValues->Add(LblValues5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues6 = new wxStaticText(PnlValues, ID_LBLVALUES6, _("0-4400"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES6"));
	LblValues6->SetForegroundColour(wxColour(0,128,0));
	FgsValues->Add(LblValues6, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblFair = new wxStaticText(PnlValues, ID_LBLFAIR, _("Fair"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLFAIR"));
	LblFair->SetForegroundColour(wxColour(0,0,255));
	wxFont LblFairFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblFair->SetFont(LblFairFont);
	FgsValues->Add(LblFair, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues7 = new wxStaticText(PnlValues, ID_LBLVALUES7, _("20-80"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES7"));
	LblValues7->SetForegroundColour(wxColour(0,0,255));
	FgsValues->Add(LblValues7, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues8 = new wxStaticText(PnlValues, ID_LBLVALUES8, _("40-70"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES8"));
	LblValues8->SetForegroundColour(wxColour(0,0,255));
	FgsValues->Add(LblValues8, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues9 = new wxStaticText(PnlValues, ID_LBLVALUES9, _("20-50"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES9"));
	LblValues9->SetForegroundColour(wxColour(0,0,255));
	FgsValues->Add(LblValues9, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues10 = new wxStaticText(PnlValues, ID_LBLVALUES10, _("10-25"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES10"));
	LblValues10->SetForegroundColour(wxColour(0,0,255));
	FgsValues->Add(LblValues10, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues11 = new wxStaticText(PnlValues, ID_LBLVALUES11, _("60-100"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES11"));
	LblValues11->SetForegroundColour(wxColour(0,0,255));
	FgsValues->Add(LblValues11, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues12 = new wxStaticText(PnlValues, ID_LBLVALUES12, _("4400-9400"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES12"));
	LblValues12->SetForegroundColour(wxColour(0,0,255));
	FgsValues->Add(LblValues12, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblModerate = new wxStaticText(PnlValues, ID_LBLMODERATE, _("Moderate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLMODERATE"));
	LblModerate->SetForegroundColour(wxColour(128,128,0));
	wxFont LblModerateFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblModerate->SetFont(LblModerateFont);
	FgsValues->Add(LblModerate, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues13 = new wxStaticText(PnlValues, ID_LBLVALUES13, _("80-250"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES13"));
	LblValues13->SetForegroundColour(wxColour(128,128,0));
	FgsValues->Add(LblValues13, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues14 = new wxStaticText(PnlValues, ID_LBLVALUES14, _("70-150"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES14"));
	LblValues14->SetForegroundColour(wxColour(128,128,0));
	FgsValues->Add(LblValues14, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues15 = new wxStaticText(PnlValues, ID_LBLVALUES15, _("50-100"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES15"));
	LblValues15->SetForegroundColour(wxColour(128,128,0));
	FgsValues->Add(LblValues15, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues16 = new wxStaticText(PnlValues, ID_LBLVALUES16, _("25-50"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES16"));
	LblValues16->SetForegroundColour(wxColour(128,128,0));
	FgsValues->Add(LblValues16, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues17 = new wxStaticText(PnlValues, ID_LBLVALUES17, _("100-140"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES17"));
	LblValues17->SetForegroundColour(wxColour(128,128,0));
	FgsValues->Add(LblValues17, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues18 = new wxStaticText(PnlValues, ID_LBLVALUES18, _("9400-12400"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES18"));
	LblValues18->SetForegroundColour(wxColour(128,128,0));
	FgsValues->Add(LblValues18, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblPoor = new wxStaticText(PnlValues, ID_LBLPOOR, _("Poor"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLPOOR"));
	LblPoor->SetForegroundColour(wxColour(255,0,0));
	wxFont LblPoorFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblPoor->SetFont(LblPoorFont);
	FgsValues->Add(LblPoor, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues19 = new wxStaticText(PnlValues, ID_LBLVALUES19, _("250-350"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES19"));
	LblValues19->SetForegroundColour(wxColour(255,0,0));
	FgsValues->Add(LblValues19, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues20 = new wxStaticText(PnlValues, ID_LBLVALUES20, _("150-200"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES20"));
	LblValues20->SetForegroundColour(wxColour(255,0,0));
	FgsValues->Add(LblValues20, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues21 = new wxStaticText(PnlValues, ID_LBLVALUES21, _("100-200"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES21"));
	LblValues21->SetForegroundColour(wxColour(255,0,0));
	FgsValues->Add(LblValues21, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues22 = new wxStaticText(PnlValues, ID_LBLVALUES22, _("50-75"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES22"));
	LblValues22->SetForegroundColour(wxColour(255,0,0));
	FgsValues->Add(LblValues22, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues23 = new wxStaticText(PnlValues, ID_LBLVALUES23, _("140-180"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES23"));
	LblValues23->SetForegroundColour(wxColour(255,0,0));
	FgsValues->Add(LblValues23, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues24 = new wxStaticText(PnlValues, ID_LBLVALUES24, _("12400-15400"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES24"));
	LblValues24->SetForegroundColour(wxColour(255,0,0));
	FgsValues->Add(LblValues24, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblVeryPoor = new wxStaticText(PnlValues, ID_LBLVERYPOOR, _("Very Poor"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVERYPOOR"));
	LblVeryPoor->SetForegroundColour(wxColour(128,128,128));
	wxFont LblVeryPoorFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	LblVeryPoor->SetFont(LblVeryPoorFont);
	FgsValues->Add(LblVeryPoor, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues25 = new wxStaticText(PnlValues, ID_LBLVALUES25, _(">350"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES25"));
	LblValues25->SetForegroundColour(wxColour(128,128,128));
	FgsValues->Add(LblValues25, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues26 = new wxStaticText(PnlValues, ID_LBLVALUES26, _(">200"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES26"));
	LblValues26->SetForegroundColour(wxColour(128,128,128));
	FgsValues->Add(LblValues26, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues27 = new wxStaticText(PnlValues, ID_LBLVALUES27, _(">200"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES27"));
	LblValues27->SetForegroundColour(wxColour(128,128,128));
	FgsValues->Add(LblValues27, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues28 = new wxStaticText(PnlValues, ID_LBLVALUES28, _(">75"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES28"));
	LblValues28->SetForegroundColour(wxColour(128,128,128));
	FgsValues->Add(LblValues28, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues29 = new wxStaticText(PnlValues, ID_LBLVALUES29, _(">180"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES29"));
	LblValues29->SetForegroundColour(wxColour(128,128,128));
	FgsValues->Add(LblValues29, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LblValues30 = new wxStaticText(PnlValues, ID_LBLVALUES30, _(">15400"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBLVALUES30"));
	LblValues30->SetForegroundColour(wxColour(128,128,128));
	FgsValues->Add(LblValues30, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	PnlValues->SetSizer(FgsValues);
	FgsValues->Fit(PnlValues);
	FgsValues->SetSizeHints(PnlValues);
	FgsMain->Add(PnlValues, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FgsMain);
	FgsMain->Fit(this);
	FgsMain->SetSizeHints(this);

	PnlHeader->Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&AQILegendDialog::OnKeyDown,0,this);
	PnlValues->Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&AQILegendDialog::OnKeyDown,0,this);
	Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&AQILegendDialog::OnKeyDown);
	//*)

    if (wxGetApp().languageID == wxLANGUAGE_JAPANESE)
    {
        AdaptTableToAsianChars();
    }

	PnlHeader->SetFocus();
}

AQILegendDialog::~AQILegendDialog()
{
	//(*Destroy(AQILegendDialog)
	//*)
}

void AQILegendDialog::AdaptTableToAsianChars()
{
    wxFont boldFont = LblValues1->GetFont();
    boldFont.SetWeight(wxFONTWEIGHT_BOLD);

    LblQualitativeName->SetFont(boldFont);
    LblPollutantConcentration_1->SetFont(boldFont);
    LblPollutantConcentration_2->SetLabel(wxEmptyString);
    LblGood->SetFont(boldFont);
    LblFair->SetFont(boldFont);
    LblModerate->SetFont(boldFont);
    LblPoor->SetFont(boldFont);
    LblVeryPoor->SetFont(boldFont);
}

void AQILegendDialog::OnKeyDown(wxKeyEvent& event)
{
    if (event.GetKeyCode() == WXK_ESCAPE)
    {
        Close();
    }
}
