// meeus_solarcalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Libraries
#define _USE_MATH_DEFINES
#include <iostream>
#include <ctime>
#include <vector>
#include <windows.h>
//#include <unistd.h> for Linux theoritically need to be testing
#include <math.h>

// Namesspaces
using namespace std;

// Global Parameters:


int daysSince;



// Custom headers
#include "core_calcs.h"
#include "graphics.h"
#include "wrt_temp.h"
#include "wrt_result.h"




int main()
{
    //cout << fixed;
    
    cout.precision(10);
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    
    
    while (1) {
    system("cls");
    print_intro();
    char chosenOption = 0;
    cin >> chosenOption;

    switch (chosenOption){
        case '1':
            write_template();
            break;
        case '2':
            write_results();
            break;
        default:
        exit(0);
        }
        
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
