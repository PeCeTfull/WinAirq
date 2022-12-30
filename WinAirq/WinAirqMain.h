/***************************************************************
 * Name:      WinAirqMain.h
 * Purpose:   Defines Application Frame
 * Author:    PeCeT_full (me@pecetfull.pl)
 * Created:   2022-03-08
 * Copyright: PeCeT_full (https://www.pecetfull.pl/)
 * License:   The MIT License
 **************************************************************/

#ifndef WINAIRQMAIN_H
#define WINAIRQMAIN_H

#include <wx/timer.h>
#include <wx/txtstrm.h>

//(*Headers(WinAirqDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "AQILegendDialog.h"
#include "include/wx/jsonreader.h"
#include <wx/taskbar.h>

class WinAirqDialog: public wxDialog
{
    public:

        WinAirqDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~WinAirqDialog();
        void UpdateAllDetails(wxInputStream *airPollutionInputStream, bool silentMode = false);

    private:

        wxTaskBarIcon *taskbarIcon;
        wxTimer timer;
        bool isTimerRunning = false;
        bool isCallAirPollutionRequestRunning = false;
        wxString defaultFontColour;
        AQILegendDialog *aqiLegendDialog = NULL;

        void RefreshLocationValLabel();
        void StartScheduledTasks(unsigned int& totalAmountOfSeconds);
        void StopScheduledTasks();
        void UpdateMeasureParameter(wxJSONValue &jsonRoot, wxString parameterJson, wxStaticText* parameterValLabel);
        void SetColourForParameter(wxStaticText* parameterValLabel, wxStaticText* parameterLabelPart1, wxStaticText* parameterLabelPart2, wxStaticText* parameterLabelPart3, wxString colour);
        void UpdateMeasureParameter(wxJSONValue &jsonRoot, wxString parameterJson, wxStaticText* parameterValLabel, wxStaticText* parameterLabelPart1, wxStaticText* parameterLabelPart2, wxStaticText* parameterLabelPart3, int firstThresholdHit, int secondThresholdHit, int thirdThresholdHit, int fourthThresholdHit);
        void CallAirPollutionRequest(bool silentMode = false);
        void StartUpdatingEvery15Minutes();
        void TerminateUpdatingEvery15Minutes();

        //(*Handlers(WinAirqDialog)
        void OnTimer(wxTimerEvent& event);
        void OnTaskbarMenuRightClick(wxCommandEvent& event);
        void OnDetails(wxCommandEvent& event);
        void OnUpdate(wxCommandEvent& event);
        void OnSettings(wxCommandEvent& event);
        void OnAQILegend(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnBtnUpdateClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(WinAirqDialog)
        static const long ID_LBLLOCATION;
        static const long ID_LBLLOCATIONVAL;
        static const long ID_LBLDATETIME;
        static const long ID_LBLDATETIMEVAL;
        static const long ID_LBLAIRQUALITY;
        static const long ID_LBLAIRQUALITYVAL;
        static const long ID_PNLHEADER;
        static const long ID_STATICLINE1;
        static const long ID_LBLCO;
        static const long ID_LBLCOVAL;
        static const long ID_LBLNO;
        static const long ID_LBLNOVAL;
        static const long ID_LBLNO2_1;
        static const long ID_LBLNO2_2;
        static const long ID_LBLNO2_3;
        static const long ID_LBLNO2VAL;
        static const long ID_LBLO3_1;
        static const long ID_LBLO3_2;
        static const long ID_LBLO3_3;
        static const long ID_LBLO3VAL;
        static const long ID_LBLSO2_1;
        static const long ID_LBLSO2_2;
        static const long ID_LBLSO2_3;
        static const long ID_LBLSO2VAL;
        static const long ID_LBLPM25_1;
        static const long ID_LBLPM25_2;
        static const long ID_LBLPM25_3;
        static const long ID_LBLPM25VAL;
        static const long ID_LBLPM10_1;
        static const long ID_LBLPM10_2;
        static const long ID_LBLPM10_3;
        static const long ID_LBLPM10VAL;
        static const long ID_LBLNH3_1;
        static const long ID_LBLNH3_2;
        static const long ID_LBLNH3_3;
        static const long ID_LBLNH3VAL;
        static const long ID_PNLMEASURES;
        static const long ID_BTNUPDATE;
        static const long idMenuDetails;
        static const long idMenuUpdate;
        static const long idMenuSettings;
        static const long idMenuAQILegend;
        static const long idMenuAbout;
        static const long idMenuExit;
        //*)

        //(*Declarations(WinAirqDialog)
        wxStaticText* LblPM10_1;
        wxStaticText* LblAirQuality;
        wxStaticText* LblO3_3;
        wxStaticText* LblNOVal;
        wxStaticText* LblSO2_2;
        wxStaticText* LblNH3_3;
        wxStaticText* LblAirQualityVal;
        wxStaticText* LblNO;
        wxStaticText* LblPM10Val;
        wxStaticText* LblSO2Val;
        wxStaticText* LblPM10_2;
        wxStaticText* LblSO2_1;
        wxStaticText* LblPM25_2;
        wxMenuItem* MenuItem5;
        wxStaticText* LblSO2_3;
        wxMenuItem* MenuItem2;
        wxStaticText* LblPM10_3;
        wxStaticText* LblPM25Val;
        wxMenuItem* MenuItem1;
        wxMenuItem* MenuItem4;
        wxPanel* PnlHeader;
        wxStaticText* LblLocationVal;
        wxStaticText* LblNO2_3;
        wxStaticText* LblCOVal;
        wxMenuItem* MenuItem3;
        wxStaticText* LblPM25_3;
        wxStaticText* LblDateTime;
        wxButton* BtnUpdate;
        wxStaticText* LblNH3_2;
        wxMenu TaskbarMenu;
        wxMenuItem* MenuItem6;
        wxStaticLine* StaticLine1;
        wxStaticText* LblNH3Val;
        wxStaticText* LblNO2Val;
        wxStaticText* LblNO2_2;
        wxStaticText* LblO3_2;
        wxPanel* PnlMeasures;
        wxStaticText* LblNO2_1;
        wxStaticText* LblCO;
        wxStaticText* LblLocation;
        wxStaticText* LblPM25_1;
        wxStaticText* LblNH3_1;
        wxStaticText* LblDateTimeVal;
        wxStaticText* LblO3_1;
        wxStaticText* LblO3Val;
        wxButton* BtnOK;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WINAIRQMAIN_H
