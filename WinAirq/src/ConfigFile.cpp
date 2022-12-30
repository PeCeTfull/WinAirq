#include "ConfigFile.h"
#include "../WinAirqApp.h"
#include <wx/wfstream.h>
#include <wx/sstream.h>
#include <wx/intl.h>

ConfigFile::ConfigFile()
{
    //ctor
    m_Config = new wxFileConfig(wxT("WinAirq"), wxEmptyString, wxGetCwd() + '\\' + configFileName, wxEmptyString, wxCONFIG_USE_LOCAL_FILE);
}

void ConfigFile::SaveConfiguration()
{
    m_Config->Write(wxT("/WinAirq/LanguageID"), wxLANGUAGE_ENGLISH_CANADA);
    m_Config->Write(wxT("/WinAirq/Location"), wxEmptyString);
    m_Config->Write(wxT("/WinAirq/Longitude"), wxT("0"));
    m_Config->Write(wxT("/WinAirq/Latitude"), wxT("0"));
    m_Config->Write(wxT("/WinAirq/ShowMainWindowOnProgramLaunch"), false);
    m_Config->Write(wxT("/WinAirq/UpdateOnProgramLaunch"), false);
    m_Config->Write(wxT("/WinAirq/UpdateEvery15Minutes"), false);

    m_Config->Flush();
}

void ConfigFile::SaveConfiguration(short languageID, wxString location, wxString longitude, wxString latitude, bool showMainWindowOnProgramLaunch, bool updateOnProgramLaunch, bool updateEvery15Minutes)
{
    m_Config->Write(wxT("/WinAirq/LanguageID"), languageID);
    m_Config->Write(wxT("/WinAirq/Location"), location);
    m_Config->Write(wxT("/WinAirq/Longitude"), longitude);
    m_Config->Write(wxT("/WinAirq/Latitude"), latitude);
    m_Config->Write(wxT("/WinAirq/ShowMainWindowOnProgramLaunch"), showMainWindowOnProgramLaunch);
    m_Config->Write(wxT("/WinAirq/UpdateOnProgramLaunch"), updateOnProgramLaunch);
    m_Config->Write(wxT("/WinAirq/UpdateEvery15Minutes"), updateEvery15Minutes);

    m_Config->Flush();
}

void ConfigFile::LoadConfiguration()
{
    wxGetApp().languageID = m_Config->Read(wxT("/WinAirq/LanguageID"), wxLANGUAGE_ENGLISH_CANADA);
    wxGetApp().location = m_Config->Read(wxT("/WinAirq/Location"), wxEmptyString);
    wxGetApp().longitude = m_Config->Read(wxT("/WinAirq/Longitude"), wxT("0"));
    wxGetApp().latitude = m_Config->Read(wxT("/WinAirq/Latitude"), wxT("0"));
    wxString showMainWindowOnProgramLaunchStr = m_Config->Read(wxT("/WinAirq/ShowMainWindowOnProgramLaunch"), wxT("0"));
    wxGetApp().showMainWindowOnProgramLaunch = showMainWindowOnProgramLaunchStr.Trim() == wxT("1");
    wxString updateOnProgramLaunchStr = m_Config->Read(wxT("/WinAirq/UpdateOnProgramLaunch"), wxT("0"));
    wxGetApp().updateOnProgramLaunch = updateOnProgramLaunchStr.Trim() == wxT("1");
    wxString updateEvery15MinutesStr = m_Config->Read(wxT("/WinAirq/UpdateEvery15Minutes"), wxT("0"));
    wxGetApp().updateEvery15Minutes = updateEvery15MinutesStr.Trim() == wxT("1");
}

ConfigFile::~ConfigFile()
{
    //dtor
}
