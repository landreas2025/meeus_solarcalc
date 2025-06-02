#pragma once

#include <windows.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include<array>




void print_write_results() {
    Sleep(500);
    std::cout << R"(
     .______       _______     _______. __    __   __      .___________.    _______  __   __       _______    
     |   _  \     |   ____|   /       ||  |  |  | |  |     |           |   |   ____||  | |  |     |   ____|   
     |  |_)  |    |  |__     |   (----`|  |  |  | |  |     `---|  |----`   |  |__   |  | |  |     |  |__      
     |      /     |   __|     \   \    |  |  |  | |  |         |  |        |   __|  |  | |  |     |   __|     
     |  |\  \----.|  |____.----)   |   |  `--'  | |  `----.    |  |        |  |     |  | |  `----.|  |____    
     | _| `._____||_______|_______/     \______/  |_______|    |__|        |__|     |__| |_______||_______|                                   
    )" << '\n';
    Sleep(500);
    std::cout << R"(
      __       _______.   ____    __    ____ .______       __  .___________.___________. _______ .__   __.    
     |  |     /       |   \   \  /  \  /   / |   _  \     |  | |           |           ||   ____||  \ |  |    
     |  |    |   (----`    \   \/    \/   /  |  |_)  |    |  | `---|  |----`---|  |----`|  |__   |   \|  |    
     |  |     \   \         \            /   |      /     |  |     |  |        |  |     |   __|  |  . `  |    
     |  | .----)   |         \    /\    /    |  |\  \----.|  |     |  |        |  |     |  |____ |  |\   |    
     |__| |_______/           \__/  \__/     | _| `._____||__|     |__|        |__|     |_______||__| \__|     
    )" << '\n';
}


int eval_lines() {
    
    ifstream file("input.txt");

    if (!file.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    int maxDashN=0;

    char ReadedCharacter;

    while (file.get(ReadedCharacter)) {
        if (ReadedCharacter =='\n') {
            maxDashN = maxDashN + 1;

        }

    }

    cout << "Number of lines : " << maxDashN << endl;

    return maxDashN;

}


int write_results() {
    system("cls");

    string path = (filesystem::current_path()).path::string();
    string filename = "\\input.txt";

    //cout << path + filename << endl;


    if (filesystem::exists(path + filename) == 1) {
        cout << path + filename << endl;
        Sleep(500);
        cout << "Input file exist!" << endl;
        Sleep(500);
    }
    else
    {
        Sleep(500);
        error_print();
        Sleep(500);
        cout << "Error: " << path + filename << " not exist!" << endl;
        Sleep(500);
        cout << "Generate an Input file from the Main menu" << endl;
        Sleep(5000);
        return 0;
    }

    int maxDashN = eval_lines();

    ifstream file("input.txt");
    
    char ReadedCharacter;

    if (!file.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    // Thats a string array, will be converted to Double or Int according to the element
    string readedParameters[9];

    // This variable counts the \n charaters (where the reading actually is)
    int actDashN=0;

    // This variable will be the readed charaters
    ReadedCharacter = 0;

    // This variable counts the decimal point a specific element of the array 
    int pointCounter = 0;

    //This var. drive the row of the readedParameters[] array
    int innerDashNCounter = -1;

    //Decimal validity which ensure that the number has only one decimal point
    int decimVal = 0;
       
    while (file.get(ReadedCharacter)) {
        if (ReadedCharacter == '\n') {
            actDashN = actDashN + 1;
        }
        
        if ((29< actDashN) && (actDashN < 40)) {
            if ((ReadedCharacter == '0') || (ReadedCharacter == '1') || (ReadedCharacter == '2') || (ReadedCharacter == '3') || (ReadedCharacter == '4') || (ReadedCharacter == '5') ||
                (ReadedCharacter == '6') || (ReadedCharacter == '7') || (ReadedCharacter == '8') || (ReadedCharacter == '9') || (ReadedCharacter == '.') || (ReadedCharacter == '-') || (ReadedCharacter == '\n')){
                if (ReadedCharacter == '\n'){
                    decimVal = 0;
                    innerDashNCounter = innerDashNCounter + 1;
                }
                else
                {
                    if (ReadedCharacter == '.') {
                        decimVal = decimVal + 1;
                        if (decimVal == 2) {
                            cout << "\nERROR: The one of the number has two decimal point char= '.'";
                            readedParameters[0] = "0";
                            readedParameters[1] = "0";
                            readedParameters[2] = "0";
                            readedParameters[3] = "0";
                            readedParameters[4] = "0";
                            readedParameters[5] = "0";
                            readedParameters[6] = "0";
                            readedParameters[7] = "0";
                            readedParameters[8] = "0";
                            Sleep(5000);
                            break;
                        }
                    }
                    readedParameters[innerDashNCounter] = readedParameters[innerDashNCounter] + ReadedCharacter;
                    //cout << ReadedCharacter;
                    Sleep(50);
                }

            }

        }

    }

    file.close();

    double latitude, longitude;
    int year, month, day;
    int hour, minute, second, time_zone;

    //Readed strings convert to int and double type numbers
   
    year = stoi(readedParameters[0]);
    month = stoi(readedParameters[1]);
    day = stoi(readedParameters[2]);
    hour = stoi(readedParameters[3]);
    minute = stoi(readedParameters[4]);
    second = stoi(readedParameters[5]);
    time_zone = stoi(readedParameters[6]);

    latitude = stod(readedParameters[7]);
    longitude = stod(readedParameters[8]);
       
    //Check that the converted variables is in application range

    if ((year > 2099) || (year < 1901)) {
        system("cls");
        cout << "The year is out of range!" << endl;
        cout << "Return to the Main Menu" << endl;
        Sleep(5000);
        return 0;
    }

    if ((month > 12) || (month < 1)) {
        system("cls");
        cout << "The month is out of range!" << endl;
        cout << "Return to the Main Menu" << endl;
        Sleep(5000);
        return 0;
    }

    if ((day > 31) || (day < 1)) {
        system("cls");
        cout << "The day is out of range!" << endl;
        cout << "Return to the Main Menu" << endl;
        Sleep(5000);
        return 0;
    }

    if ((hour > 24) || (hour < 1)) {
        system("cls");
        cout << "The hour is out of range!" << endl;
        cout << "Return to the Main Menu" << endl;
        Sleep(5000);
        return 0;
    }

    if ((minute > 60) || (minute < 0)) {
        system("cls");
        cout << "The minute is out of range!" << endl;
        cout << "Return to the Main Menu" << endl;
        Sleep(5000);
        return 0;
    }

    if ((second > 60) || (second < 0)) {
        system("cls");
        cout << "The second is out of range!" << endl;
        cout << "Return to the Main Menu" << endl;
        Sleep(5000);
        return 0;
    }

    if ((time_zone > 14) || (time_zone < -11)) {
        system("cls");
        cout << "The time_zone is out of range!" << endl;
        cout << "Return to the Main Menu" << endl;
        Sleep(5000);
        return 0;
    }

    if ((latitude > 90) || (latitude < -90)) {
        system("cls");
        cout << "The latitude is out of range!";
        cout << "Return to the Main Menu" << endl;
        Sleep(5000);
        return 0;
    }

    if ((longitude>180)||(longitude<-180)) {
        system("cls");
        cout << "The longitude is out of range!";
        cout << "Return to the Main Menu" << endl;
        Sleep(5000);
        return 0;
    }

     
    years_to_day(year,month,day);

    double timeInNumber = timeToSingleNumber(hour, minute, second);
    double julianCentury = JulianCenturyCalc(daysSince, time_zone, timeInNumber);

    // To this line it should be run on a single thread

    double geomMeanLongSun=GeomMeanLongSunCalc(julianCentury);
    double geomMeanAnomSun = geomMeanAnomSunCalc(julianCentury);
    double eccentEarthOrbit = eccentEarthOrbitCalc(julianCentury);
    double sunEqOfCtrl = sunEqOfCtrlCalc(julianCentury, geomMeanAnomSun);
    double sunTrueLong = sunTrueLongCalc(sunEqOfCtrl, geomMeanLongSun);
    double sunTrueAnom = sunTrueAnomCalc(sunEqOfCtrl, geomMeanAnomSun);
    double sunRadVector = sunRadVectorCalc(eccentEarthOrbit, sunTrueAnom);
    double sunAppLong = sunAppLongCalc(julianCentury, sunTrueLong);
    double meanObliqEcliptic = meanObliqEclipticCalc(julianCentury);
    double obliqCorr = obliqCorrCalc(julianCentury, meanObliqEcliptic);
    double sunRtAscen = sunRtAscenCalc(sunAppLong, obliqCorr);
    double sunDeclin = sunDeclinCalc(obliqCorr, sunAppLong);
    double varY = varYCalc(obliqCorr);
    double EQOfTime = EQOfTimeCalc(varY, geomMeanLongSun, geomMeanAnomSun, eccentEarthOrbit);
    double HASunrise = HASunriseCalc(latitude, sunDeclin);
    double solarNoon = solarNoonCalc(longitude, time_zone, EQOfTime);
    double sunriseTime = sunriseTimeCalc(solarNoon, HASunrise);
    double sunsetTime = sunsetTimeCalc(solarNoon, HASunrise);
    double sunlightDuration = sunlightDurationCalc(HASunrise);
    double trueSolarTime = trueSolarTimeCalc(timeInNumber, EQOfTime, longitude, time_zone);
    double hourAngle = hourAngleCalc(trueSolarTime);
    double solarZenithAngle = solarZenithAngleCalc(sunDeclin, latitude, hourAngle);
    double solarElevationAngle = solarElevationAngleCalc(solarZenithAngle);
    double approxAtmosphericRefraction = approxAtmosphericRefractionCalc(solarElevationAngle);
    double solarElevationCorrForATMRefraction = solarElevationCorrForATMRefractionCalc(approxAtmosphericRefraction, solarElevationAngle);
    double solarAzimuthAngle = solarAzimuthAngleCalc(hourAngle, solarZenithAngle, sunDeclin, latitude);

    std::array<double, 3> directionVector;
    directionVector = directionVectorCalc(solarAzimuthAngle, solarElevationCorrForATMRefraction);

    int timeSeq = 100;

    system("cls");
    Sleep(timeSeq);
    cout << "Calculated data:" << endl;
    Sleep(timeSeq);
    cout << "\n     Days since 1900:                                   " << daysSince << endl;
    Sleep(timeSeq);
    cout << "     Time as single number:                             " << timeInNumber << endl;
    Sleep(timeSeq);
    cout << "     Julian Century:                                    " << julianCentury << endl;
    Sleep(timeSeq);
    cout << "     Geom Mean Long Sun in [rad]:                       " << geomMeanLongSun << " and in [deg]: " << geomMeanLongSun*(180/M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Geom Mean Anom Sun in [rad]:                       " << geomMeanAnomSun << " and in [deg]: " << geomMeanAnomSun * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Eccent Earth Orbit [-]:                            " << eccentEarthOrbit << endl;
    Sleep(timeSeq);
    cout << "     Sun Eq of Ctrl [-]:                                " << sunEqOfCtrl << endl;
    Sleep(timeSeq);
    cout << "     Sun True Long [rad]:                               " << sunTrueLong << " and in [deg]: " << sunTrueLong * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Sun True Anom [rad]:                               " << sunTrueAnom << " and in [deg]: " << sunTrueAnom * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Sun Rad Vector [rad]:                              " << sunRadVector << " and in [deg]: " << sunRadVector * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Sun App Long [rad]:                                " << sunAppLong << " and in [deg]: " << sunAppLong * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Mean Obliq Ecliptic [rad]:                         " << meanObliqEcliptic << " and in [deg]: " << meanObliqEcliptic * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Obliq Corr [rad]:                                  " << obliqCorr << " and in [deg]: " << obliqCorr * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Sun Rt Ascen [rad]:                                " << sunRtAscen << " and in [deg]: " << sunRtAscen * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Sun Declin [rad]:                                  " << sunDeclin << " and in [deg]: " << sunDeclin * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Var Y:                                             " << varY  << endl;
    Sleep(timeSeq);
    cout << "     EQOfTime [min]:                                    " << EQOfTime << endl;
    Sleep(timeSeq);
    cout << "     HA Sunrise [rad]:                                  " << HASunrise << " and in [deg]: " << HASunrise * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Solar Noon [LST]:                                  " << solarNoon << endl;
    Sleep(timeSeq);
    cout << "     Sunriserise Time [LST]:                            " << sunriseTime << endl;
    Sleep(timeSeq);
    cout << "     Sunset Time [LST]:                                 " << sunsetTime << endl;
    Sleep(timeSeq);
    cout << "     Sunlight Duration [min]:                           " << sunlightDuration << endl;
    Sleep(timeSeq);
    cout << "     True Solar Time [min]:                             " << trueSolarTime << endl; 
    Sleep(timeSeq);
    cout << "     Hour Angle [rad]:                                  " << hourAngle << " and in [deg]: " << hourAngle * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Solar Zenith Angle [rad]:                          " << solarZenithAngle << " and in [deg]: " << solarZenithAngle * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Solar Elevation Angle [rad]:                       " << solarElevationAngle << " and in [deg]: " << solarElevationAngle * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Approx Atmospheric Refraction [rad]:               " << approxAtmosphericRefraction << " and in [deg]: " << approxAtmosphericRefraction * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Solar Elevatio Corrected for ATM refraction [rad]: " << solarElevationCorrForATMRefraction << " and in [deg]: " << solarElevationCorrForATMRefraction * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "     Solar Azimuth Angle (ClockWise from N) [rad]:      " << solarAzimuthAngle << " and in [deg]: " << solarAzimuthAngle * (180 / M_PI) << endl;
    Sleep(timeSeq);
    cout << "\n\n";
    Sleep(timeSeq);
    cout << "     The direction vector which points to the sun:  " << endl;
    Sleep(timeSeq);
    cout << "     Direction Vector X component: " << directionVector[0] << endl;
    Sleep(timeSeq);
    cout << "     Direction Vector Y component: " << directionVector[1] << endl;
    Sleep(timeSeq);
    cout << "     Direction Vector Z component: " << directionVector[2] << endl;


    //Write to file
    ofstream fileTowrite("results.txt");

    fileTowrite << R"(/*--------------------------------------------------------------------------------------------------------------------*\
|  .___  ___.  _______  _______  __    __       _______.        _______.  ______    __          ___      .______       |
|  |   \/   | |   ____||   ____||  |  |  |     /       |       /       | /  __  \  |  |        /   \     |   _  \      |
|  |  \  /  | |  |__   |  |__   |  |  |  |    |   (----`      |   (----`|  |  |  | |  |       /  ^  \    |  |_)  |     |
|  |  |\/|  | |   __|  |   __|  |  |  |  |     \   \           \   \    |  |  |  | |  |      /  /_\  \   |      /      |
|  |  |  |  | |  |____ |  |____ |  `--'  | .----)   |      .----)   |   |  `--'  | |  `----./  _____  \  |  |\  \----. |
|  |__|  |__| |_______||_______| \______/  |_______/       |_______/     \______/  |_______/__/     \__\ | _| `._____| |
|                                                                                                                      |
|    ______     ___       __        ______  __    __   __          ___   .___________.  ______   .______               |
|   /      |   /   \     |  |      /      ||  |  |  | |  |        /   \  |           | /  __  \  |   _  \              |
|  |  ,----'  /  ^  \    |  |     |  ,----'|  |  |  | |  |       /  ^  \ `---|  |----`|  |  |  | |  |_)  |             |
|  |  |      /  /_\  \   |  |     |  |     |  |  |  | |  |      /  /_\  \    |  |     |  |  |  | |      /              |
|  |  `----./  _____  \  |  `----.|  `----.|  `--'  | |  `----./  _____  \   |  |     |  `--'  | |  |\  \----.         |
|   \______/__/     \__\ |_______| \______| \______/  |_______/__/     \__\  |__|      \______/  | _| `._____|         |
|                                                                                                                      |
|----------------------------------------------------------------------------------------------------------------------|
|                                                                                                                      |
| The calculations in the NOAA Sunrise/Sunset and Solar Position Calculators are based on equations  from Astronomical |
| Algorithms, by Jean Meeus. The sunrise and sunset results are theoretically accurate to within a minute for          |
| locations between +/- 72° latitude, and within 10 minutes outside of those latitudes. However, due to variations in  |
| atmospheric composition, temperature, pressure and conditions, observed values may vary from calculations.           |
|                                                                                                                      |
| Please note that calculations in the spreadsheets are only valid for dates between 1901 and 2099, due to an          |
| approximation used in the Julian Day calculation. The web calculator does not use this approximation, and can        |
| report values between the years -2000 and +3000.                                                                     |
|                                                                                                                      |
\*--------------------------------------------------------------------------------------------------------------------*/)" << '\n';

    fileTowrite << "\nCalculated data:" << endl;
    fileTowrite << "\n     Days since 1900:                                   " << daysSince << endl;
    fileTowrite << "     Time as single number:                             " << timeInNumber << endl;
    fileTowrite << "     Julian Century:                                    " << julianCentury << endl;
    fileTowrite << "     Geom Mean Long Sun in [rad]:                       " << geomMeanLongSun << " and in [deg]: " << geomMeanLongSun * (180 / M_PI) << endl;
    fileTowrite << "     Geom Mean Anom Sun in [rad]:                       " << geomMeanAnomSun << " and in [deg]: " << geomMeanAnomSun * (180 / M_PI) << endl;
    fileTowrite << "     Eccent Earth Orbit [-]:                            " << eccentEarthOrbit << endl;
    fileTowrite << "     Sun Eq of Ctrl [-]:                                " << sunEqOfCtrl << endl;
    fileTowrite << "     Sun True Long [rad]:                               " << sunTrueLong << " and in [deg]: " << sunTrueLong * (180 / M_PI) << endl;
    fileTowrite << "     Sun True Anom [rad]:                               " << sunTrueAnom << " and in [deg]: " << sunTrueAnom * (180 / M_PI) << endl;
    fileTowrite << "     Sun Rad Vector [rad]:                              " << sunRadVector << " and in [deg]: " << sunRadVector * (180 / M_PI) << endl;
    fileTowrite << "     Sun App Long [rad]:                                " << sunAppLong << " and in [deg]: " << sunAppLong * (180 / M_PI) << endl;
    fileTowrite << "     Mean Obliq Ecliptic [rad]:                         " << meanObliqEcliptic << " and in [deg]: " << meanObliqEcliptic * (180 / M_PI) << endl;
    fileTowrite << "     Obliq Corr [rad]:                                  " << obliqCorr << " and in [deg]: " << obliqCorr * (180 / M_PI) << endl;
    fileTowrite << "     Sun Rt Ascen [rad]:                                " << sunRtAscen << " and in [deg]: " << sunRtAscen * (180 / M_PI) << endl;
    fileTowrite << "     Sun Declin [rad]:                                  " << sunDeclin << " and in [deg]: " << sunDeclin * (180 / M_PI) << endl;
    fileTowrite << "     Var Y:                                             " << varY << endl;
    fileTowrite << "     EQOfTime [min]:                                    " << EQOfTime << endl;
    fileTowrite << "     HA Sunrise [rad]:                                  " << HASunrise << " and in [deg]: " << HASunrise * (180 / M_PI) << endl;
    fileTowrite << "     Solar Noon [LST]:                                  " << solarNoon << endl;
    fileTowrite << "     Sunriserise Time [LST]:                            " << sunriseTime << endl;
    fileTowrite << "     Sunset Time [LST]:                                 " << sunsetTime << endl;
    fileTowrite << "     Sunlight Duration [min]:                           " << sunlightDuration << endl;
    fileTowrite << "     True Solar Time [min]:                             " << trueSolarTime << endl;
    fileTowrite << "     Hour Angle [rad]:                                  " << hourAngle << " and in [deg]: " << hourAngle * (180 / M_PI) << endl;
    fileTowrite << "     Solar Zenith Angle [rad]:                          " << solarZenithAngle << " and in [deg]: " << solarZenithAngle * (180 / M_PI) << endl;
    fileTowrite << "     Solar Elevation Angle [rad]:                       " << solarElevationAngle << " and in [deg]: " << solarElevationAngle * (180 / M_PI) << endl;
    fileTowrite << "     Approx Atmospheric Refraction [rad]:               " << approxAtmosphericRefraction << " and in [deg]: " << approxAtmosphericRefraction * (180 / M_PI) << endl;
    fileTowrite << "     Solar Elevatio Corrected for ATM refraction [rad]: " << solarElevationCorrForATMRefraction << " and in [deg]: " << solarElevationCorrForATMRefraction * (180 / M_PI) << endl;
    fileTowrite << "     Solar Azimuth Angle (ClockWise from N) [rad]:      " << solarAzimuthAngle << " and in [deg]: " << solarAzimuthAngle * (180 / M_PI) << endl;

    fileTowrite << "\n\n";
    fileTowrite << "     The direction vector which points to the sun (If the North direction and the Y axis are same): " << endl;
    fileTowrite << "     Direction Vector X component: " << directionVector[0] << endl;
    fileTowrite << "     Direction Vector Y component: " << directionVector[1] << endl;
    fileTowrite << "     Direction Vector Z component: " << directionVector[2] << endl;


    fileTowrite.close();

    //print_write_results();
    Sleep(5000);



    return 0;
}