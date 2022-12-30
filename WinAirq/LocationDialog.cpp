#include "LocationDialog.h"
#include "WinAirqApp.h"
#include <wx/url.h>
#include <wx/txtstrm.h>
#include <wx/msgdlg.h>
#include <wx/busyinfo.h>
#include <wx/regex.h>

//(*InternalHeaders(LocationDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(LocationDialog)
const long LocationDialog::ID_TXTLOCATION = wxNewId();
const long LocationDialog::ID_BTNSEARCH = wxNewId();
const long LocationDialog::ID_CHKTRANSLATETOWNNAMES = wxNewId();
const long LocationDialog::ID_LTCLOCATIONS = wxNewId();
//*)

BEGIN_EVENT_TABLE(LocationDialog,wxDialog)
	//(*EventTable(LocationDialog)
	//*)
END_EVENT_TABLE()

LocationDialog::LocationDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	//(*Initialize(LocationDialog)
	wxFlexGridSizer* FgsSearch;
	wxFlexGridSizer* FgsMain;

	Create(parent, id, _("Search for location..."), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FgsMain = new wxFlexGridSizer(3, 1, 0, 0);
	FgsSearch = new wxFlexGridSizer(1, 2, 0, 0);
	FgsSearch->AddGrowableCol(0);
	FgsSearch->AddGrowableRow(0);
	TxtLocation = new wxTextCtrl(this, ID_TXTLOCATION, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TXTLOCATION"));
	FgsSearch->Add(TxtLocation, 1, wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BtnSearch = new wxButton(this, ID_BTNSEARCH, _("Search"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNSEARCH"));
	FgsSearch->Add(BtnSearch, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FgsMain->Add(FgsSearch, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ChkTranslateTownNames = new wxCheckBox(this, ID_CHKTRANSLATETOWNNAMES, _("Translate town names"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKTRANSLATETOWNNAMES"));
	ChkTranslateTownNames->SetValue(true);
	FgsMain->Add(ChkTranslateTownNames, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	LtcLocations = new wxListCtrl(this, ID_LTCLOCATIONS, wxDefaultPosition, wxSize(500,172), wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LTCLOCATIONS"));
	LtcLocations->SetMinSize(wxSize(500,120));
	FgsMain->Add(LtcLocations, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FgsMain);
	FgsMain->Fit(this);
	FgsMain->SetSizeHints(this);
	Center();

	Connect(ID_BTNSEARCH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LocationDialog::OnBtnSearchClick);
	//*)

    TxtLocation->SetMaxLength(200);
    TxtLocation->Connect(wxID_ANY, wxEVT_KEY_DOWN, wxKeyEventHandler(LocationDialog::OnTxtLocationKeyDown), NULL, this);

    LtcLocations->InsertColumn(0, _("Town"));
    LtcLocations->InsertColumn(1, _("State/Province"));
    LtcLocations->InsertColumn(2, _("Country"));
    LtcLocations->InsertColumn(3, _("Latitude"));
    LtcLocations->InsertColumn(4, _("Longitude"));
    LtcLocations->SetColumnWidth(0, 170);
    LtcLocations->SetColumnWidth(1, 160);
    LtcLocations->SetColumnWidth(2, 30);
    LtcLocations->SetColumnWidth(3, 65);
    LtcLocations->SetColumnWidth(4, 65);
    LtcLocations->Connect(wxID_ANY, wxEVT_KEY_DOWN, wxKeyEventHandler(LocationDialog::OnLtcLocationsKeyDown), NULL, this);
    LtcLocations->Connect(wxEVT_LEFT_DCLICK, (wxObjectEventFunction)&LocationDialog::OnLtcLocationsDoubleLeftClick, NULL, this);

    ChkTranslateTownNames->Connect(wxID_ANY, wxEVT_KEY_DOWN, wxKeyEventHandler(LocationDialog::OnKeyDown), NULL, this);
    BtnSearch->Connect(wxID_ANY, wxEVT_KEY_DOWN, wxKeyEventHandler(LocationDialog::OnKeyDown), NULL, this);
    Connect(wxID_ANY, wxEVT_KEY_DOWN, wxKeyEventHandler(LocationDialog::OnKeyDown), NULL, this);
}

LocationDialog::~LocationDialog()
{
	//(*Destroy(LocationDialog)
	//*)
}

wxString LocationDialog::GetSelectedLocation()
{
    return selectedLocation;
}

wxString LocationDialog::GetSelectedLongitude()
{
    return selectedLongitude;
}

wxString LocationDialog::GetSelectedLatitude()
{
    return selectedLatitude;
}

void LocationDialog::OnBtnSearchClick(wxCommandEvent& event)
{
    HandleSearch();
}

wxString LocationDialog::GetLocationParameterValue(wxJSONValue &jsonValue, int i, wxString parameter)
{
    wxString valueStr = jsonValue[wxT("results")][i][parameter].AsString();

    if (valueStr == wxT("null"))
    {
        valueStr = wxT('-');
    }
    else if (parameter == wxT("state") && valueStr.Contains(wxT("Voivodeship")))
    {
        valueStr = wxGetTranslation(valueStr);
    }

    return valueStr;
}

wxString LocationDialog::GetISO3166CountryCode()
{
    switch (wxGetApp().languageID)
    {
        case wxLANGUAGE_GERMAN:
            return wxT("de");
        case wxLANGUAGE_POLISH:
            return wxT("pl");
        case wxLANGUAGE_ENGLISH_CANADA:
        default:
            return wxT("en");
    }
}

wxString LocationDialog::GetTranslatedTownName(wxJSONValue &jsonValue, int i)
{
    wxString countryCode = GetISO3166CountryCode();
    wxString valueStr = jsonValue[wxT("results")][i][wxT("local_names")][countryCode].AsString();

    if (valueStr == wxT("null"))
    {
        valueStr = GetLocationParameterValue(jsonValue, i, wxT("name"));
    }

    return valueStr;
}

wxString LocationDialog::ParsePhraseForURL(wxString phrase)
{
    return wxString(phrase.mb_str(wxConvUTF8), wxConvISO8859_1);
}

wxString LocationDialog::GetCoordinatesSeparatorBasedOnProgramLocale()
{
    wxString decimalFractionChar = _("DEC_FRACTION_DOT");
    if (decimalFractionChar == wxT("DEC_FRACTION_COMMA"))
    {
        return wxT(";");
    }
    else
    {
        return wxT(",");
    }
}

void LocationDialog::OnLtcLocationsDoubleLeftClick(wxMouseEvent& event)
{
    HandleLocationConfirmation();
}

void LocationDialog::HandleLocationConfirmation()
{
    if (!isBusy)
    {
        long itemIndex = -1;

        while((itemIndex = LtcLocations->GetNextItem(itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != wxNOT_FOUND)
        {
            wxListItem *listItem = new wxListItem();
            listItem->SetId(itemIndex);
            listItem->SetMask(wxLIST_MASK_TEXT);

            listItem->SetColumn(0);
            LtcLocations->GetItem(*listItem);
            wxString town = listItem->GetText();

            listItem->SetColumn(1);
            LtcLocations->GetItem(*listItem);
            wxString state = listItem->GetText();
            if (state != wxT('-'))
            {
                town = wxString::Format(wxT("%s, %s"), town.c_str(), state.c_str());
            }

            listItem->SetColumn(2);
            LtcLocations->GetItem(*listItem);
            wxString country = listItem->GetText();

            listItem->SetColumn(3);
            LtcLocations->GetItem(*listItem);
            selectedLatitude = listItem->GetText();

            listItem->SetColumn(4);
            LtcLocations->GetItem(*listItem);
            selectedLongitude = listItem->GetText();

            wxString coordSeparator = GetCoordinatesSeparatorBasedOnProgramLocale();

            selectedLocation = wxString::Format(wxT("%s, %s (%s%s %s)"), town.c_str(), country.c_str(), selectedLatitude.c_str(), coordSeparator.c_str(), selectedLongitude.c_str());

            Close();
            SetReturnCode(wxID_OK);
        }
    }
}

void LocationDialog::HandleSearch()
{
    if (!isBusy)
    {
        isBusy = true;

        wxBusyInfo wait(_("Searching, please wait..."));
        wxRegEx regexSpecialURLChars(wxT("[^?&=]*$"));

        if (TxtLocation->GetValue().Trim().IsEmpty())
        {
            wxMessageBox(_("You need to enter the desired location in order to proceed."), _("Warning"), wxICON_EXCLAMATION);
        }
        else if (regexSpecialURLChars.Matches(TxtLocation->GetValue()) && TxtLocation->GetValue() == regexSpecialURLChars.GetMatch(TxtLocation->GetValue()))
        {
            wxString locationPhrase = ParsePhraseForURL(TxtLocation->GetValue());
            wxString strUrl(wxT("http://api.openweathermap.org/geo/1.0/direct?q=") + locationPhrase + wxT("&limit=5&appid=") + wxT(OPENWEATHERMAP_APIKEY));
            wxURI uri(strUrl);
            wxString strEncodedUrl = uri.BuildURI();
            wxURL directURL(strEncodedUrl);
            wxInputStream *directInputStream = directURL.GetInputStream();

            wxTextInputStream directTextInputStream(*directInputStream);
            if (directInputStream != NULL && directInputStream->CanRead())
            {
                wxJSONValue jsonRoot;
                wxJSONReader jsonReader;

                int numErrors = jsonReader.Parse(wxT("{\"results\":") + directTextInputStream.ReadLine() + wxT("}"), &jsonRoot);

                if (numErrors == 0)
                {
                    wxString errorMessage = jsonRoot[wxT("message")].AsString();

                    if (errorMessage == wxT("null"))
                    {
                        this->Freeze();
                        LtcLocations->DeleteAllItems();

                        for (int i = 0; i < jsonRoot[wxT("results")].Size(); i++)
                        {
                            wxString townName;
                            if (ChkTranslateTownNames->IsChecked())
                            {
                                townName = GetTranslatedTownName(jsonRoot, i);
                            }
                            else
                            {
                                townName = GetLocationParameterValue(jsonRoot, i, wxT("name"));
                            }

                            long locationItem = LtcLocations->InsertItem(i, townName);
                            LtcLocations->SetItem(locationItem, 1, GetLocationParameterValue(jsonRoot, i, wxT("state")));
                            LtcLocations->SetItem(locationItem, 2, GetLocationParameterValue(jsonRoot, i, wxT("country")));
                            LtcLocations->SetItem(locationItem, 3, GetLocationParameterValue(jsonRoot, i, wxT("lat")));
                            LtcLocations->SetItem(locationItem, 4, GetLocationParameterValue(jsonRoot, i, wxT("lon")));
                        }

                        this->Thaw();
                    }
                    else
                    {
                        wxMessageBox(_("Unable to read data for the specified search phrase. Please change the location or try again."), _("Error"), wxICON_HAND);
                    }
                }
                else
                {
                    wxMessageBox(_("Unable to read data. Please try again later."), _("Error"), wxICON_HAND);
                }
            }
            else
            {
                wxMessageBox(_("Could not connect to the website. Please check your Internet connection and try again later."), _("Error"), wxICON_HAND);
            }

            delete directInputStream;
        }
        else
        {
            wxMessageBox(_("The search phrase contains invalid characters, such as ^, ?, &, or =. Please remove them and try again."), _("Warning"), wxICON_EXCLAMATION);
        }

        isBusy = false;
    }
}

void LocationDialog::OnKeyDown(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
        case WXK_ESCAPE:
            Close();
            break;
        default:
            event.Skip();
            break;
    }
}

void LocationDialog::OnLtcLocationsKeyDown(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
        case 13:
            HandleLocationConfirmation();
            break;
        case WXK_ESCAPE:
            Close();
            break;
        default:
            event.Skip();
            break;
    }
}

void LocationDialog::OnTxtLocationKeyDown(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
        case 13:
            HandleSearch();
            break;
        case WXK_ESCAPE:
            Close();
            break;
        default:
            event.Skip();
            break;
    }
}
