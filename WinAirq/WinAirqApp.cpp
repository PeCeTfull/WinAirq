/***************************************************************
 * Name:      WinAirqApp.cpp
 * Purpose:   Code for Application Class
 * Author:    PeCeT_full (me@pecetfull.pl)
 * Created:   2022-03-08
 * Copyright: PeCeT_full (https://www.pecetfull.pl/)
 * License:   The MIT License
 **************************************************************/

#include "WinAirqApp.h"
#include "ConfigFile.h"
#include <wx/filename.h>
#include <wx/dir.h>

//(*AppHeaders
#include "WinAirqMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(WinAirqApp);

bool WinAirqApp::OnInit()
{
    m_TranslationHelper = new wxTranslationHelper(*this);

    ConfigFile *configFile = new ConfigFile();
    if(!wxFileName::FileExists(configFile->configFileName))
    {
        configFile->SaveConfiguration();
    }
    configFile->LoadConfiguration();
    wxDELETE(configFile);

    if (DoesLangsFolderExist())
    {
        m_TranslationHelper->Load(languageID);
    }

    //(*AppInitialize
    bool wxsOK = ValidateOpenWeatherMapApiKey();
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	WinAirqDialog* Dialog = new WinAirqDialog(0);
    	if (showMainWindowOnProgramLaunch)
        {
            Dialog->Show();
        }
    	SetTopWindow(Dialog);
    }
    //*)
    return wxsOK;

}

int WinAirqApp::OnExit()
{
    if(m_TranslationHelper)
    {
        wxDELETE(m_TranslationHelper);
    }

    return 0;
}

void WinAirqApp::OnSetLanguage(short languageID)
{
    m_TranslationHelper->SetLanguage(languageID);
}

short WinAirqApp::SelectLanguage()
{
    wxArrayString names;
    wxArrayShort identifiers;
    m_TranslationHelper->GetInstalledLanguages(names, identifiers);
    return m_TranslationHelper->AskUserForLanguage(names, identifiers);
}

bool WinAirqApp::DoesLangsFolderExist()
{
    return wxDir::Exists(m_TranslationHelper->languagesPath) ? true : false;
}

bool WinAirqApp::ValidateOpenWeatherMapApiKey()
{
    bool result = true;

    if (OPENWEATHERMAP_APIKEY == "CHANGE_ME")
    {
        wxMessageBox(_("You are using a version of WinAirq that has an invalid API key for OpenWeatherMap services. Please contact your software provider and ask for a valid build.\n\nThe application will terminate now."), _("Error"), wxICON_HAND);
        result = false;
    }

    return result;
}
