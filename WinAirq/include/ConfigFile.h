#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/fileconf.h>


class ConfigFile
{
    public:
        ConfigFile();
        void SaveConfiguration();
        void SaveConfiguration(short languageID, wxString location, wxString longitude, wxString latitude, bool showMainWindowOnProgramLaunch, bool updateOnProgramLaunch, bool updateEvery15Minutes);
        void LoadConfiguration();
        virtual ~ConfigFile();
        const wxString configFileName = wxT("config.ini");
    protected:
    private:
        wxFileConfig *m_Config;
};

#endif // CONFIGFILE_H
