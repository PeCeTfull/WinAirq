#ifndef LOCATIONDIALOG_H
#define LOCATIONDIALOG_H

#include "include/wx/jsonreader.h"

//(*Headers(LocationDialog)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class LocationDialog: public wxDialog
{
	public:

		LocationDialog(wxWindow* parent, wxWindowID id=wxID_ANY, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize);
		virtual ~LocationDialog();
		wxString GetSelectedLocation();
		wxString GetSelectedLongitude();
		wxString GetSelectedLatitude();

		//(*Declarations(LocationDialog)
		wxTextCtrl* TxtLocation;
		wxButton* BtnSearch;
		wxListCtrl* LtcLocations;
		wxCheckBox* ChkTranslateTownNames;
		//*)

	protected:

		//(*Identifiers(LocationDialog)
		static const long ID_TXTLOCATION;
		static const long ID_BTNSEARCH;
		static const long ID_CHKTRANSLATETOWNNAMES;
		static const long ID_LTCLOCATIONS;
		//*)

	private:

        wxString GetLocationParameterValue(wxJSONValue &jsonValue, int i, wxString parameter);
        wxString GetISO3166CountryCode();
        wxString GetTranslatedTownName(wxJSONValue &jsonValue, int i);
        wxString ParsePhraseForURL(wxString phrase);
        wxString GetCoordinatesSeparatorBasedOnProgramLocale();
        void OnLtcLocationsDoubleLeftClick(wxMouseEvent& event);
        void HandleLocationConfirmation();
        void HandleSearch();
        void OnKeyDown(wxKeyEvent& event);
        void OnLtcLocationsKeyDown(wxKeyEvent& event);
        void OnTxtLocationKeyDown(wxKeyEvent& event);
        wxString selectedLocation;
        wxString selectedLongitude;
        wxString selectedLatitude;

        bool isBusy = false;

		//(*Handlers(LocationDialog)
		void OnBtnSearchClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
