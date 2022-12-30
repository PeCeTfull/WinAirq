#include "AirPollutionRequestThread.h"
#include <wx/url.h>

AirPollutionRequestThread::AirPollutionRequestThread(bool silentMode)
{
    //ctor

    isSilent = silentMode;
    wxSocketBase::Initialize();
}

AirPollutionRequestThread::~AirPollutionRequestThread()
{
    //dtor

    delete airPollutionInputStream;
}

void *AirPollutionRequestThread::Entry()
{
    wxURL airPollutionURL(wxT("http://api.openweathermap.org/data/2.5/air_pollution?lat=") + wxGetApp().latitude + wxT("&lon=") + wxGetApp().longitude + wxT("&appid=") + wxT(OPENWEATHERMAP_APIKEY));
    airPollutionInputStream = airPollutionURL.GetInputStream();
    if (mainDialog != NULL)
    {
        mainDialog->UpdateAllDetails(airPollutionInputStream, isSilent);
    }
}
