#ifndef AQILEGENDDIALOG_H
#define AQILEGENDDIALOG_H

//(*Headers(AQILegendDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/dialog.h>
//*)

class AQILegendDialog: public wxDialog
{
	public:

		AQILegendDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AQILegendDialog();

		//(*Declarations(AQILegendDialog)
		wxStaticText* LblModerate;
		wxStaticText* LblPM10_1;
		wxStaticText* LblValues4;
		wxStaticText* LblValues13;
		wxStaticText* LblValues7;
		wxStaticText* LblValues6;
		wxStaticText* LblPM10_2;
		wxStaticText* LblQualitativeName;
		wxStaticText* LblPM25_2;
		wxStaticText* LblPollutantConcentration_1;
		wxStaticText* LblGood;
		wxStaticText* LblValues17;
		wxStaticText* LblValues14;
		wxStaticText* LblPollutantConcentration_2;
		wxStaticText* LblValues8;
		wxStaticText* LblValues19;
		wxStaticText* LblVeryPoor;
		wxStaticText* LblValues15;
		wxStaticText* LblValues1;
		wxPanel* PnlHeader;
		wxStaticText* LblValues16;
		wxStaticText* LblValues20;
		wxStaticText* LblValues11;
		wxStaticText* LblFair;
		wxStaticText* LblPM25_3;
		wxStaticText* LblValues5;
		wxStaticText* LblValues10;
		wxStaticText* LblNO2_2;
		wxStaticText* LblO3_2;
		wxStaticText* LblValues3;
		wxStaticText* LblNO2_1;
		wxStaticText* LblValues9;
		wxPanel* PnlValues;
		wxStaticText* LblPM25_1;
		wxStaticText* StaticText4;
		wxStaticText* LblValues18;
		wxStaticText* LblValues2;
		wxStaticText* LblPoor;
		wxStaticText* LblValues12;
		wxStaticText* LblO3_1;
		//*)

	protected:

		//(*Identifiers(AQILegendDialog)
		static const long ID_LBLQUALITATIVENAME;
		static const long ID_LBLPOLLUTANTCONCENTRATION_1;
		static const long ID_LBLPOLLUTANTCONCENTRATION_2;
		static const long ID_PNLHEADER;
		static const long ID_STATICTEXT4;
		static const long ID_LBLNO2_1;
		static const long ID_LBLNO2_2;
		static const long ID_LBLPM10_1;
		static const long ID_LBLPM10_2;
		static const long ID_LBLO3_1;
		static const long ID_LBLO3_2;
		static const long ID_LBLPM25_1;
		static const long ID_LBLPM25_2;
		static const long ID_LBLPM25_3;
		static const long ID_LBLGOOD;
		static const long ID_LBLVALUES1;
		static const long ID_LBLVALUES2;
		static const long ID_LBLVALUES3;
		static const long ID_LBLVALUES4;
		static const long ID_LBLFAIR;
		static const long ID_LBLVALUES5;
		static const long ID_LBLVALUES6;
		static const long ID_LBLVALUES7;
		static const long ID_LBLVALUES8;
		static const long ID_LBLMODERATE;
		static const long ID_LBLVALUES9;
		static const long ID_LBLVALUES10;
		static const long ID_LBLVALUES11;
		static const long ID_LBLVALUES12;
		static const long ID_LBLPOOR;
		static const long ID_LBLVALUES13;
		static const long ID_LBLVALUES14;
		static const long ID_LBLVALUES15;
		static const long ID_LBLVALUES16;
		static const long ID_LBLVERYPOOR;
		static const long ID_LBLVALUES17;
		static const long ID_LBLVALUES18;
		static const long ID_LBLVALUES19;
		static const long ID_LBLVALUES20;
		static const long ID_PNLVALUES;
		//*)

	private:

		//(*Handlers(AQILegendDialog)
		void OnKeyDown(wxKeyEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
