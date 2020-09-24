#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

#include "crewmembers.h"
#include "planes.h"
#include "flights.h"

using namespace std;

//creating an object of each collection class to store respective data
crewmembers crew;
planes aircrafts;
flights flightplan;

//declaring files for loading and saving (loading works for planes and crewmembers, saving works for all three collections)
ifstream fin;
ofstream fout;


int main() {
    
    //declaring a time_t type variable to hold the current time
    time_t now = time(0);
    
    
    //converting time_t to readable time
    char* date = ctime(&now);
    tm *gmtm = gmtime(&now);
    date = asctime(gmtm);
    
    cout<< endl;
    cout << "The UTC time and date today is " << date << endl;

    //updating flight statuses right when program is launched
    //flightplan.updateflightstatus();
    

    int choice = -1;

    while(choice != 0) {
       
        //updating flight status after every task (periodically updating)
        flightplan.updateflightstatus();

        //offering user the options
        cout << "what would you like to do?" << endl;
        cout << "0 or any other key - quit" << endl;
        cout << "1 - add flight" << endl;
        cout << "2 - edit flight" << endl;
        cout << "3 - delete flight" << endl;
        cout << "4 - print flights" << endl;
        cout << "5 - print a flight" << endl;
        cout << "6 - add crew member" << endl;
        cout << "7 - edit crew member" << endl;
        cout << "8 - delete crew member" << endl;
        cout << "9 - print crew members" << endl;
        cout << "10 - print a crew member" << endl;
        cout << "11 - add plane" << endl;
        cout << "12 - edit plane" << endl;
        cout << "13 - delete plane" << endl;
        cout << "14 - print planes" << endl;
        cout << "15 - print a plane" << endl;
        cout << "16 - print a plane schedule" << endl;
        cout << "17 - print a member schedule" << endl;
        cout << "18 - delete all cancelled and completed flights" << endl;
        cout << "19 - load data" << endl;
        cout << "20 - save data" << endl;
        cout << "enter your choice: "; cin >> choice; //reading in user choice

                    

            //executing user choice by calling respective function
            if(choice == 0) {
                 cout << "good bye." << endl; exit(0); 
            }
            else if(choice == 1) {     
            flightplan.addFlight();
            }
            else if(choice == 2) {
                flightplan.editFlight(); 
            }
            else if(choice == 3) {
                flightplan.deleteFlight(); 
            }
            else if(choice == 4) {
                flightplan.printFlights(); 
            }
            else if(choice == 5) {
                flightplan.printAFlight(); 
            }
             else if(choice == 6) {
                crew.addMember(); 
            }
             else if(choice == 7) {
                crew.findMemberToEdit(); 
            }
             else if(choice == 8) {
                 crew.deleteMember(); 
            }
             else if(choice == 9) {
                crew.printMember(); 
            }
             else if(choice == 10) {
                crew.printAMember(); 
            }
             else if(choice == 11) {
                aircrafts.addPlane(); 
            }
             else if(choice == 12) {
                 aircrafts.findPlaneToEdit(); 
            }
             else if(choice == 13) {
                 aircrafts.deletePlane();
            }
             else if(choice == 14) {
                aircrafts.printPlane(); 
            }
             else if(choice == 15) {
                 aircrafts.printAPlane(); 
            }
             else if(choice == 16) {
                flightplan.printAPlaneSchedule(); 
            }
             else if(choice == 17) {
                flightplan.printAMemberSchedule(); 
            }
             else if(choice == 18) {
                flightplan.deleteExpiredFlights();
            }
             else if(choice == 19) {
                aircrafts.loaddata(); /*flightplan.loaddata();*/ crew.loaddata();
            }
             else if(choice == 20) {
                aircrafts.savedata(); flightplan.savedata(); crew.savedata(); 
            }

        }
        return 0;
    }

















 