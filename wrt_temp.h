#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;


void print_gensugzesful() {
    Sleep(500);
    std::cout << R"(
     .___________. _______ .___  ___. .______    __          ___   .___________. _______                                     
     |           ||   ____||   \/   | |   _  \  |  |        /   \  |           ||   ____|                                    
     `---|  |----`|  |__   |  \  /  | |  |_)  | |  |       /  ^  \ `---|  |----`|  |__                                       
         |  |     |   __|  |  |\/|  | |   ___/  |  |      /  /_\  \    |  |     |   __|                                      
         |  |     |  |____ |  |  |  | |  |      |  `----./  _____  \   |  |     |  |____                                     
         |__|     |_______||__|  |__| | _|      |_______/__/     \__\  |__|     |_______|                                    
    )" << '\n';
    Sleep(500);
    std::cout << R"(
     ____    __    ____ .______       __  .___________. __  .__   __.   _______    ____    __    ____  ___           _______.
     \   \  /  \  /   / |   _  \     |  | |           ||  | |  \ |  |  /  _____|   \   \  /  \  /   / /   \         /       |
      \   \/    \/   /  |  |_)  |    |  | `---|  |----`|  | |   \|  | |  |  __      \   \/    \/   / /  ^  \       |   (----`
       \            /   |      /     |  |     |  |     |  | |  . `  | |  | |_ |      \            / /  /_\  \       \   \    
        \    /\    /    |  |\  \----.|  |     |  |     |  | |  |\   | |  |__| |       \    /\    / /  _____  \  .----)   |   
         \__/  \__/     | _| `._____||__|     |__|     |__| |__| \__|  \______|        \__/  \__/ /__/     \__\ |_______/    
    )" << '\n';
    Sleep(500);
     std::cout << R"(
          _______. __    __    ______   ______  _______     _______.     _______. _______  __    __   __                     
         /       ||  |  |  |  /      | /      ||   ____|   /       |    /       ||   ____||  |  |  | |  |                    
        |   (----`|  |  |  | |  ,----'|  ,----'|  |__     |   (----`   |   (----`|  |__   |  |  |  | |  |                    
         \   \    |  |  |  | |  |     |  |     |   __|     \   \        \   \    |   __|  |  |  |  | |  |                    
     .----)   |   |  `--'  | |  `----.|  `----.|  |____.----)   |   .----)   |   |  |     |  `--'  | |  `----.               
     |_______/     \______/   \______| \______||_______|_______/    |_______/    |__|      \______/  |_______|               
    )" << '\n';
    Sleep(3000);
    std::cout << R"(      
            The program returns to the Main menu after 5 seconds.
    )" << '\n';
}


void write_file() {

    string path = (filesystem::current_path()).path::string();
    string filename = "\\input.txt";

    cout << path + filename;

    Sleep(10);

    ofstream tmp(path + filename);
    tmp << R"(/*--------------------------------------------------------------------------------------------------------------------*\
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
\*--------------------------------------------------------------------------------------------------------------------*/

// Parameters:

year = 2025;
month = 5;
day = 21;
hour = 12;
minute = 0;
second = 0;
time_zone = -5;
latitude = 47.49150169;
longitude = 19.0606723;

//----------------------------------------------------END-OF-FILE-----------------------------------------------------//
)" << '\n';
    tmp.close();


}


int write_template() {
    system("cls");

    write_file();
    print_gensugzesful();

    Sleep(5000);
    return 0;
}