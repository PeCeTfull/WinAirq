# WinAirq #

WinAirq is a current air quality reading program for vintage computers connected to the Web from the data retrieved from OpenWeatherMap's API. It was written in C++ and uses wxWidgets GUI library.

### Getting to work in Windows 95 ###

In order to make the software work properly on your Windows 95 computer, you must have Microsoft Internet Explorer 5.0 or 5.5 installed there. The Internet Explorer installers of those particular versions update some essential system files so that the search for location window can be faultlessly presented on the screen.

### Handling the program ###

The program is loaded into the system tray - by default, you should find it in the bottom right corner of your computer screen. If you are launching WinAirq for the first time, an icon representing a grey question mark on a white background should appear. If you cannot see it there, try to expand the system tray by clicking the arrow(s).

On the application's icon, press the right mouse button and go to Settings as it is one of the necessary steps to start watching the air quality of your location. Click on the star button and use the search bar to find it. You may be given a variety of options. After selecting your desired location, click OK and then apply settings. Now you are ready to read the data - just click twice on the tray icon using the left mouse button to display the main window and hit Update. If everything went successfully, you should be able to see the current air quality with all the details.

### Program options ###

The following options can be adjusted: 

* location, 

* show main window on program launch, 

* update data on program launch, 

* update data every 15 minutes, 

* UI language.

After switching to another UI language, it is necessary to restart the application in order to reflect all the changes.

### Recommended programming setup ###

Source and target OS: Windows

IDE: Code::Blocks Release 13.12 rev 9501 (2013/12/25 19:25:45) gcc 4.7.1 Windows/unicode - 32 bit

wxWidgets version: 2.8.12 (SHARED=0 MONOLITHIC=1 UNICODE=1 MSLU=1)

Additional info: 

* The post-build script for Release contains the line that launches UPX (if it exists) in order to compress the executable file. Please change UPX directory to your desired one or simply remove the line if you do not have the program, otherwise the files from the "common" directory may not be successfully copied after compiling.

* Please replace the value of `OPENWEATHERMAP_APIKEY` in DevConfig.h with your active API key.

### Program licence ###

WinAirq is published under The MIT License. Please refer to the LICENSE.txt file of this repository for more information regarding it.

This program also includes libraries and source codes that are necessary to successfully compile and launch the software. The licensing information regarding those are located in the Licenses directory.

### Screenshots ###

<img width="444" height="365" alt="The main window of WinAirq" src="https://github.com/user-attachments/assets/d511bcd4-a829-4f06-b230-98608a27ca0c" />

<img width="129" height="44" alt="WinAirq hidden in the system tray" src="https://github.com/user-attachments/assets/ffac8abf-1035-4046-ae8d-7e83838370c7" />

### Videos ###

[![WinAirq — Demonstration](https://img.youtube.com/vi/Xsg3tNwJG80/0.jpg)](https://www.youtube.com/watch?v=Xsg3tNwJG80)
