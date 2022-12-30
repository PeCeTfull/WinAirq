#ifndef AIRPOLLUTIONREQUESTTHREAD_H
#define AIRPOLLUTIONREQUESTTHREAD_H

#include "../WinAirqApp.h"
#include "../WinAirqMain.h"
#include <wx/thread.h>
#include <wx/txtstrm.h>

class AirPollutionRequestThread: public wxThread
{
    public:
        AirPollutionRequestThread(bool silentMode);
        virtual ~AirPollutionRequestThread();
        void *Entry();
        WinAirqDialog *mainDialog;
    protected:
    private:
        bool isSilent;
        wxInputStream *airPollutionInputStream = NULL;
};

#endif // AIRPOLLUTIONREQUESTTHREAD_H
