/***************************************************************
 * Name:      WinAirqApp.h
 * Purpose:   Defines Application Class
 * Author:    PeCeT_full (me@pecetfull.pl)
 * Created:   2022-03-08
 * Copyright: PeCeT_full (https://www.pecetfull.pl/)
 * License:   The MIT License
 **************************************************************/

#ifndef WINAIRQAPP_H
#define WINAIRQAPP_H

#include "DevConfig.h"
#include "include/wxTranslationHelper.h"
#include <wx/app.h>

class WinAirqApp : public wxApp
{
    wxTranslationHelper *m_TranslationHelper;
    public:
        virtual bool OnInit();
        virtual int OnExit();
        void OnSetLanguage(short languageID);
        short SelectLanguage();
        bool DoesLangsFolderExist();

        short languageID;
        wxString location;
        wxString longitude;
        wxString latitude;
        bool showMainWindowOnProgramLaunch;
        bool updateOnProgramLaunch;
        bool updateEvery15Minutes;
    private:
        bool ValidateOpenWeatherMapApiKey();
};

DECLARE_APP(WinAirqApp);

#endif // WINAIRQAPP_H
