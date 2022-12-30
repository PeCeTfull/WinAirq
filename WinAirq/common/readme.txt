**** Read Me - English ****

WinAirq 1.0
Author: PeCeT_full
Website: http://www.pecetfull.pl
Copyright (c) by PeCeT_full 2022. WinAirq is published under The MIT License. For more information, please refer to Licence.txt included with the application.

If there are any problems or doubts, please contact me.

-------------------
Program description
-------------------

WinAirq is a current air quality reading program for vintage computers connected to the Web from the data retrieved from OpenWeatherMap's API. It was written in C++ and uses wxWidgets GUI library.

Minimal hardware and system requirements: 133 MHz or faster processor; 16 MB of available RAM; 3 MB of free hard disk space available where the program exists; Windows 95 or newer operating system; active Internet connection.

-----------------------------
Getting to work in Windows 95
-----------------------------

In order to make the software work properly on your Windows 95 computer, you must have Microsoft Internet Explorer 5.0 or 5.5 installed there. The Internet Explorer installers of those particular versions update some essential system files so that the search for location window can be faultlessly presented on the screen.

--------------------
Handling the program
--------------------

The program is loaded into the system tray - by default, you should find it in the bottom right corner of your computer screen. If you are launching WinAirq for the first time, an icon representing a grey question mark on a white background should appear. If you cannot see it there, try to expand the system tray by clicking the arrow(s).

On the application's icon, press the right mouse button and go to Settings as it is one of the necessary steps to start watching the air quality of your location. Click on the star button and use the search bar to find it. You may be given a variety of options. After selecting your desired location, click OK and then apply settings. Now you are ready to read the data - just click twice on the tray icon using the left mouse button to display the main window and hit Update. If everything went successfully, you should be able to see the current air quality with all the details.

-----------
AQI details
-----------

Besides basic air quality index (AQI), you can find data about polluting gases, such as: 

* carbon monoxide (CO), 

* nitrogen monoxide (NO), 

* nitrogen dioxide (NO ), 
                      2
* ozone (O ), 
          3
* sulphur dioxide (SO ), 
                     2
* ammonia (NH ), 
             3
* particulates (PM    and PM  ).
                  2.5       10
                      
Here is a description of AQI levels: 

+------------------+------------------------------------------------+
|                  |                                     3          |
|                  | Pollutant concentration in micro-g/m           |
|                  |                                                |
| Qualitative name |---------+---------+---------+------------------+
|                  |         |         |         |                  |
|                  | NO      | PM      | O       | PM    (optional) |
|                  |   2     |   10    |  3      |   2.5            |
+------------------+---------+---------+---------+------------------+
| Good             | 0-50    | 0-25    | 0-60    | 0-15             |
| Fair             | 50-100  | 25-50   | 60-120  | 15-30            |
| Moderate         | 100-200 | 50-90   | 120-180 | 30-55            |
| Poor             | 200-400 | 90-180  | 180-240 | 55-110           |
| Very Poor        | >400    | >180    | >240    | >110             |
+------------------+---------+---------+---------+------------------+

The legend is also available from WinAirq's context menu and can be used for direct reference.

----------------
Program settings
----------------

The following options can be adjusted: 

* location, 

* show main window on program launch, 

* update data on program launch, 

* update data every 15 minutes, 

* UI language.

After switching to another UI language, it is necessary to restart the application in order to reflect all the changes.
