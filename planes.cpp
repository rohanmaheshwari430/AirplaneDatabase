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


#include "planes.h"
#include "flights.h"

extern planes aircrafts;

using namespace std;

    string planemake;
    int model_number;
    string tail_number;
    int num_seats;
    int planerange;
    int min_crew;
    
void planes::addPlane() {   //asking all information
    plane plane;
    cin.ignore(); cout << "enter plane make: "; getline(cin, planemake); 
    cout << "enter model number (enter numerical id): "; cin >> model_number; cin.ignore();
    cout << "enter tail number: "; getline(cin, tail_number); 
    cout << "enter number of seats: "; cin >> num_seats;
    cout << "enter flight range: "; cin >> planerange;
    cout << "enter minimum crew members: "; cin >> min_crew;

    plane_list.push_back(plane);

    int last_index = plane_list.size() - 1;

    plane_list.at(last_index).setMake(planemake);   //mutating the information of the plane into the list
     plane_list.at(last_index).setModelNumber(model_number);
    plane_list.at(last_index).setTailNumber(tail_number);
    plane_list.at(last_index).setNumSeats(num_seats);
    plane_list.at(last_index).setRange(planerange);
    plane_list.at(last_index).setMinCCrew(min_crew);
    cout << "hi";
    tailnumber.push_back(tail_number);
    cout << "bye";
}
void planes::deletePlane() {
    string tail_number; int i; bool planeFound = false;
    cout << "enter tail number: "; cin >> tail_number;  

    for(i = 0; i < plane_list.size(); i++) {    //finding plane to delete
        if(plane_list.at(i).getTailNumber() == tail_number) {
            planeFound = true;
            break;
        }
    }

    if(planeFound == true) {
        plane_list.erase(plane_list.begin() + i);
        cout << "plane erased." << endl;
    }
    else {
        cout << "plane not found." << endl;
    }

}

void planes::findPlaneToEdit() {
    string plane_tnumber; int i; bool planeFound = false;

    cout << "enter tail number of plane: "; getline(cin, plane_tnumber);
    for(i = 0; i < plane_list.size(); i++) {
        if(plane_tnumber == plane_list.at(i).getTailNumber()) { //finding plane to edit
            planeFound = true;
            plane_list.at(i).editPlane(); //calling edit function once found
            break;
        }
    }

    if(planeFound == false) {
        cout << "plane not found" << endl;
    }

}
void planes::printPlane() { //printing all planes in the vector list
    for(int i = 0; i < plane_list.size(); i++) {
        cout << "tail number: " << plane_list.at(i).getTailNumber() << endl;
        cout << "plane make: " << plane_list.at(i).getMake() << endl;
        cout << "model number: " << plane_list.at(i).getModelNumber() << endl;
        cout << "number of seats: " << plane_list.at(i).getNumSeats() << endl;
        cout << "flight range: " << plane_list.at(i).getRange() << endl;
        cout << "minimum cabin crew members: " << plane_list.at(i).getMinCCrew() << endl;
    }
}
void planes::printAPlane() { //asking for id and printing plane info associated with that id
    string tail_number; int i; 

    cin.ignore(); cout << "enter the tail number of the plane to view: "; getline(cin, tail_number);
    
    for(i = 0; i < plane_list.size(); i++) {
        if(tail_number == plane_list.at(i).getTailNumber()) {
            break;
        }
    }

    if(i != plane_list.size()) {

        cout << "tail number: " << plane_list.at(i).getTailNumber() << endl;
        cout << "plane make: " << plane_list.at(i).getMake() << endl;
        cout << "model number: " << plane_list.at(i).getModelNumber() << endl;
        cout << "number of seats: " << plane_list.at(i).getNumSeats() << endl;
        cout << "flight range: " << plane_list.at(i).getRange() << endl;
        cout << "minimum cabin crew members: " << plane_list.at(i).getMinCCrew() << endl;
        cout << endl;
    }
    else {
        cout << "plane does not exist." << endl;
    }

}

void planes::settailnumber(vector <string> tnumber) {
    tailnumber = tnumber;
}

vector <string> planes::gettailnumber() {
    return tailnumber;
}


void planes::savedata() { //saving all data using accessors
    ofstream fout;
    fout.open("planes.out");

    fout << plane_list.size() << endl;
    
    for(int i = 0; i < plane_list.size(); i++) {
        fout << plane_list.at(i).getTailNumber() << endl;
        fout <<  plane_list.at(i).getMake() << endl;
        fout << plane_list.at(i).getModelNumber() << endl;
        fout << plane_list.at(i).getNumSeats() << endl;
        fout << plane_list.at(i).getRange() << endl;
        fout << plane_list.at(i).getMinCCrew() << endl;
    }

    fout.close();

}

void planes::loaddata() { //loading all data using mutators
    ifstream fin;
    string planemake;
    int model_number;
    string tail_number;
    int num_seats;
    int planerange;
    int min_crew;
    int plane_count;
    fin.open("planes.out");

    fin >> plane_count; 

    plane_list.resize(plane_count);

    for(int i = 0; i < plane_count; i++) {
        fin >> tail_number >> planemake >> model_number >> num_seats >> planerange >> min_crew ;

        plane_list.at(i).setTailNumber(tail_number);
        plane_list.at(i).setMake(planemake);
        plane_list.at(i).setModelNumber(model_number);
        plane_list.at(i).setNumSeats(num_seats);
        plane_list.at(i).setRange(planerange);
        plane_list.at(i).setMinCCrew(min_crew);
    }
    
    fin.close();
}

void planes::setplanes(vector <plane> plist) { //making the plane list accessible
    plane_list = plist;

}

vector <plane> planes::getplanes() {

    return plane_list;
}