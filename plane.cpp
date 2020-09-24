#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <cmath>
#include <ctime>
#include <ios>
#include <iomanip>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>

#include "plane.h"

using namespace std;

    void plane::setMake(string m) {
        make = m;
    }
    string plane::getMake() {
        return make;
    }
    void plane::setModelNumber(int m_number) {
        modelnumber = m_number;
    }
    int plane::getModelNumber() {
        return modelnumber;
    }
    void plane::setTailNumber(string t_number) {
        tailnumber = t_number;
    }
    string plane::getTailNumber() {
        return tailnumber;
    }
    void plane::setNumSeats(int n_seats) {
        numseats = n_seats;
    }
    int plane::getNumSeats() {
        return numseats;
    }
    void plane::setRange(int s_range) {
        range = s_range;
    }
    int plane::getRange() {
        return range;
    }
    void plane::setMinCCrew(int min_crew) {
        minCCrew = min_crew;
    }
    int plane::getMinCCrew() {
        return minCCrew;
    }

    void plane::editPlane() {

        int userChoice;
        string planemake;
        int model_number;
        int num_seats;
        int flight_range;
        int min_CCrew;

    //perfoming edit function by asking user what to edit
    cout << "What property would you like to edit?" << endl;
    cout << "1 - model number" << endl;
    cout << "2 - number of seats" << endl;
    cout << "3 - flight range" << endl;
    cout << "4 - mininum number of cabin members" << endl;
    cout << "5- make" << endl;

    cout << "Enter option: "; cin >> userChoice;

    //range checking for proper input
    while(userChoice != 1 && userChoice != 2 &&  userChoice != 3 && userChoice != 4 && userChoice != 5) {
        cout << "Invalid option. Try again." << endl;
        cin >> userChoice;
    }
    
    //prompting for desired property to edit
    if(userChoice == 1) {
        cout << "Enter new model number: "; cin >> model_number;
        modelnumber = model_number;
    }
    else if(userChoice == 2) {
        cout << "Enter new seat capacity: "; cin >> num_seats;
        numseats = num_seats;
    }
    else if(userChoice == 3) {
        cout << "Enter new flight range: "; cin >> flight_range;
        range = flight_range;
    } 
    else if(userChoice == 4) {
        cout << "Enter new minimum number of cabin members: "; cin >> min_CCrew;
        minCCrew = min_CCrew;
    } 
    else if(userChoice == 5) {
        cout << "Enter new make: "; getline(cin, planemake);
        make = planemake;
    }
}
    