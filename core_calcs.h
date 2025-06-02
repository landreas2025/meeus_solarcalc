#pragma once

#include <iostream>
#include<array>
using namespace std;

//This function calculates the number of days since 1900 january 1
int years_to_day(int year, int month, int day)
{
    int yearsToCheck = 1900;
    int numberOfLeapyears = 0;
    bool  isDeclaredYearLeap = 0;
    int daysSinceBasedonYear = 0;

    // Days of the month which will be modified based on that the declared year leap or not
    int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    //--------------------------This part of the code calculates the number of days since 1900 january 1 but in just year based -------------------- 
    // 
    // The while loop count those years which are leap in the numberOfLeapyears variable
    while (yearsToCheck < year) {
        if ((((yearsToCheck % 4) == 0) && ((yearsToCheck % 100) != 0)) || ((yearsToCheck % 400) == 0)) {
            numberOfLeapyears++;
            //cout << numberOfLeapyears << endl;
            //cout << yearsToCheck << endl;
            yearsToCheck++;
        }
        else
        {
            //cout << yearsToCheck << endl;
            yearsToCheck++;
        }
    }

    daysSinceBasedonYear = numberOfLeapyears * 366 + (((year)-1900) - numberOfLeapyears) * 365;

    //cout << "Days based on year: " << daysSinceBasedonYear << endl;

    //--------------------------------This part of the code calculates the year of the day but in just month based----------------------------------
    //
    // Is the declared year leap or not?
    if (((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0))) {
        daysPerMonth[1] = 29;
    }

    int daysSinceBasedonMonth = 0;

    for (int i = 0; (i < month - 1); i++)
    {
        daysSinceBasedonMonth = daysSinceBasedonMonth + daysPerMonth[i];
        //cout << daysSinceBasedonMonth << endl;
    }

    //cout << "Days based on month: " << daysSinceBasedonMonth << endl;

    //--------------------------------This part of the code calculates the year of the day based on the results of the code above----------------------------------

    //cout << "Days based on day: " << day << endl;

    // +1 day shift because of the Year 1900 bug of the Excel: https://en.wikipedia.org/wiki/Year_1900_problem

    daysSince = daysSinceBasedonYear + daysSinceBasedonMonth + (day)+1;
    //cout << "Days since 1900:   " << daysSince << endl;
    return daysSince;
}

double timeToSingleNumber(int hour, int minute, int second) {
    return ((1 * static_cast<double>(hour)) / (24)) + ((1 * static_cast<double>(minute)) / (24 * 60)) + ((1 * static_cast<double>(second)) / (24 * 60 * 60));
}

double JulianCenturyCalc(int daysSince, int time_zone, double timeInNumber) {
    double JulianDay;

    JulianDay = static_cast<double>(daysSince) + 2415018.5 + static_cast<double>(timeInNumber) - (static_cast<double>(time_zone) / 24);

    return (JulianDay - 2451545) / 36525;

}

double GeomMeanLongSunCalc(double julianCentury) {
    return fmod(280.46646 + julianCentury * (36000.76983 + (julianCentury * 0.0003032)), 360) * (M_PI / 180);
}

double geomMeanAnomSunCalc(double julianCentury) {
    return (357.52911 + julianCentury * (35999.05029 - 0.0001537 * julianCentury)) * (M_PI / 180);
}

double eccentEarthOrbitCalc(double julianCentury) {
    return 0.016708634 - julianCentury * (0.000042037 + 0.0000001267 * julianCentury);
}

double sunEqOfCtrlCalc(double julianCentury, double geomMeanAnomSun) {
    return (sin(geomMeanAnomSun) * (1.914602 - julianCentury * (0.004817 + 0.000014 * julianCentury)) + sin(2 * geomMeanAnomSun) * (0.019993 - 0.000101 * julianCentury) + sin(3 * geomMeanAnomSun) * 0.000289);
}

double sunTrueLongCalc(double sunEqOfCtrlCalc, double GeomMeanLongSun) {
    return (sunEqOfCtrlCalc + GeomMeanLongSun * (180 / M_PI)) * (M_PI / 180);
}

double sunTrueAnomCalc(double sunEqOfCtrlCalc, double geomMeanAnomSun) {
    return (sunEqOfCtrlCalc + geomMeanAnomSun * (180 / M_PI)) * (M_PI / 180);
}

double sunRadVectorCalc(double eccentEarthOrbit, double sunTrueAnom) {
    return (1.000001018 * (1 - eccentEarthOrbit * eccentEarthOrbit)) / (1 + eccentEarthOrbit * cos(sunTrueAnom));
}

double sunAppLongCalc(double julianCentury, double sunTrueLong) {
    return (sunTrueLong * (180 / M_PI) - 0.00569 - 0.00478 * sin((125.04 - 1934.136 * julianCentury) * ((M_PI / 180)))) * (M_PI / 180);
}

double meanObliqEclipticCalc(double julianCentury) {
    return (23 + (26 + ((21.448 - julianCentury * (46.815 + julianCentury * (0.00059 - julianCentury * 0.001813)))) / 60) / 60) * (M_PI / 180);
}

double obliqCorrCalc(double julianCentury, double meanObliqEcliptic) {
    return (meanObliqEcliptic * (180 / M_PI) + 0.00256 * cos((125.04 - 1934.136 * julianCentury) * (M_PI / 180))) * (M_PI / 180);
}

double sunRtAscenCalc(double sunAppLong, double obliqCorr) {
    return atan2(cos(obliqCorr) * sin(sunAppLong), cos(sunAppLong));
}

double sunDeclinCalc(double obliqCorr, double sunAppLong) {
    return asin(sin(obliqCorr) * sin(sunAppLong));
}

double varYCalc(double obliqCorr) {
    return tan(obliqCorr / 2) * tan(obliqCorr / 2);
}

double EQOfTimeCalc(double varY, double geomMeanLongSun, double geomMeanAnomSun, double eccentEarthOrbit) {
    return 4 * (180 / M_PI) * (varY * sin(2 * geomMeanLongSun) - 2 * eccentEarthOrbit * sin(geomMeanAnomSun) + 4 * eccentEarthOrbit * varY * sin(geomMeanAnomSun) *
        cos(2 * geomMeanLongSun) - 0.5 * varY * varY * sin(4 * geomMeanLongSun) - 1.25 * eccentEarthOrbit * eccentEarthOrbit * sin(2 * geomMeanAnomSun));
}

double HASunriseCalc(double latitude, double sunDeclin) {
    return acos(cos(90.833 * (M_PI / 180)) / (cos(latitude * (M_PI / 180)) * cos(sunDeclin)) - tan(latitude * (M_PI / 180)) * tan(sunDeclin));
}

double solarNoonCalc(double longitude, int  time_zone, double EQOfTime) {
    return (720 - 4 * longitude - EQOfTime + time_zone * 60) / 1440;
}

double sunriseTimeCalc(double solarNoon, double HASunrise) {
    return (solarNoon - HASunrise * (180 / M_PI) * 4 / 1440);
}

double sunsetTimeCalc(double solarNoon, double HASunrise) {
    return solarNoon + HASunrise * (180 / M_PI) * 4 / 1440;
}

double sunlightDurationCalc(double HASunrise) {
    return 8 * HASunrise * (180 / M_PI);
}

double trueSolarTimeCalc(double timeInNumber, double EQOfTime, double longitude, int time_zone) {
    return fmod(timeInNumber * 1440 + EQOfTime + 4 * longitude - 60 * time_zone, 1440);
}

double hourAngleCalc(double trueSolarTime) {
    return ((trueSolarTime / 4 < 0) ? trueSolarTime / 4 + 180 : trueSolarTime / 4 - 180) * (M_PI / 180);
}

double solarZenithAngleCalc(double sunDeclin, double latitude, double hourAngle) {
    return acos(sin(latitude * (M_PI / 180)) * sin(sunDeclin) + cos(latitude * (M_PI / 180)) * cos(sunDeclin) * cos(hourAngle));
}

double solarElevationAngleCalc(double solarZenithAngle) {
    return (90 * (M_PI / 180)) - solarZenithAngle;
}

double approxAtmosphericRefractionCalc(double solarElevationAngle) {
    return (((solarElevationAngle > (85 * (M_PI / 180))) ? 0 :
        ((solarElevationAngle > 5 * (M_PI / 180)) ? 58.1 / tan(solarElevationAngle) - 0.07 / pow(tan(solarElevationAngle), 3) + 0.000086 / pow(tan(solarElevationAngle), 5) :
            ((solarElevationAngle > -0.575 * (M_PI / 180)) ? 1735 + solarElevationAngle * (-518.2 + solarElevationAngle * (103.4 + solarElevationAngle * (-12.79 + solarElevationAngle * 0.711))) : -20.772 / tan(solarElevationAngle)))) / 3600) * (M_PI / 180);
}

double solarElevationCorrForATMRefractionCalc(double approxAtmosphericRefraction, double solarElevationAngle) {
    return approxAtmosphericRefraction + solarElevationAngle;
}

double solarAzimuthAngleCalc(double hourAngle, double solarZenithAngle, double sunDeclin, double latitude) {
    return ((hourAngle > 0) ? fmod((180 / M_PI) * (acos(((sin(latitude * (M_PI / 180)) * cos(solarZenithAngle)) - sin(sunDeclin)) / (cos(latitude * (M_PI / 180)) * sin(solarZenithAngle)))) + 180, 360) : fmod(540 - (180 / M_PI) * (acos(((sin(latitude * (M_PI / 180)) * cos(solarZenithAngle)) - sin(sunDeclin)) / (cos(latitude * (M_PI / 180)) * sin(solarZenithAngle)))), 360)) * (M_PI / 180);
}

std::array<double, 3> directionVectorCalc(double solarAzimuthAngle, double solarElevationAngle) {

    double signEval = floor(solarAzimuthAngle / (M_PI / 2));

    std::array<double, 3> directionVector;
    double r = 100;

    // x direction sign
    if ((signEval == 2) || (signEval == 3)) {
        directionVector[0] = cos(solarAzimuthAngle - (signEval * (M_PI / 2)))*r*-1;
    }
    else {
        directionVector[0] = cos(solarAzimuthAngle - (signEval * (M_PI / 2))) * r * 1;
    }

    if ((signEval == 1) || (signEval == 2)) {
        directionVector[1] = sin(solarAzimuthAngle - (signEval * (M_PI / 2))) * r * -1;
    }
    else {
        directionVector[1] = sin(solarAzimuthAngle - (signEval * (M_PI / 2))) * r * 1;
    }

    directionVector[2] = sin(solarElevationAngle)*r;

    return directionVector;


}
