#include <iostream>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <fstream>
#include "flights.h"
#include "crewmembers.h"
#include "planes.h"

extern crewmembers crew;
extern flights flightplan;
extern planes aircrafts;


using namespace std;

    
    int flights::flightCount() {
        int flight_count = flight_list.size();
        return flight_count;
    }   

    void flights::setflightlist(vector <flight> flist) {
        flight_list = flist;
    }

    vector <flight>  flights::getflightlist() {
        return flight_list;
    }

    void flights::addFlight() {
        tm startTime, endTime;
        flight flight;
        string tail_number;
        int num_pilots;
        int num_cabins;
        vector <int> pilots;
        vector <int> cabinCrew;
        //flight start time
        string start_time;
        //flight end time 
        string end_time;
        string start_acode;
        string end_acode;
        int num_passengers;
        int flight_id;
        int year;
        string flight_status;
        bool crewrestriction = false; 
        int num_copilots;
       
            //asking for flight times
        
            cout << "enter flight start time " << endl;
            cout << "enter month (0-11): "; cin >> startTime.tm_mon;
            while(startTime.tm_mon < 0 || startTime.tm_mon > 11) {
                cout << "invalid. try again: "; cin >> startTime.tm_mon;
            }

            cout << "enter days since sunday (0-6): "; cin >> startTime.tm_wday;
            while(startTime.tm_wday < 0 || startTime.tm_wday > 6) {
                cout << "invalid. try again: "; cin >> startTime.tm_wday;
            }

            cout << "enter date (1-31): "; cin >> startTime.tm_mday;
            while(startTime.tm_mday < 0 || startTime.tm_mday > 31) {
                cout << "invalid. try again: "; cin >> startTime.tm_mday;
            }
            cout << "enter year: "; cin >> year; startTime.tm_year = year - 1900;

            cout << "enter hour (0-24): "; cin >> startTime.tm_hour;
            while(startTime.tm_hour < 0 || startTime.tm_hour > 24) {
                cout << "invalid. try again: "; cin >> startTime.tm_year;
            }

            cout << "enter minutes (0-59): "; cin >> startTime.tm_min;
            while(startTime.tm_min < 0 || startTime.tm_min > 59) {
                cout << "invalid. try again: "; cin >> startTime.tm_min;
            }

            startTime.tm_sec = 0;

            
            start_time = asctime(&startTime);

            //asking for flight end time

            cout << "enter flight end time " << endl;
            cout << "enter month (0-11): "; cin >> endTime.tm_mon;
            while(endTime.tm_mon < 0 || endTime.tm_mon > 11) {
                cout << "invalid. try again: "; cin >> endTime.tm_mon;
            }

            cout << "enter days since sunday (0-6): "; cin >> endTime.tm_wday;
            while(endTime.tm_wday < 0 || endTime.tm_wday > 6) {
                cout << "invalid. try again: "; cin >> endTime.tm_wday;
            }

            cout << "enter date (1-31): "; cin >> endTime.tm_mday;
            while(endTime.tm_mday < 0 || endTime.tm_mday > 31) {
                cout << "invalid. try again: "; cin >> endTime.tm_mday;
            }

            cout << "enter year: "; cin >> year; endTime.tm_year = year - 1900;

            cout << "enter hour (0-24): "; cin >> endTime.tm_hour;
             while(endTime.tm_hour < 0 || endTime.tm_hour > 24) {
                cout << "invalid. try again: "; cin >> endTime.tm_hour;
            }
            cout << "enter minutes (0-59): "; cin >> endTime.tm_min;
             while(endTime.tm_min < 0 || endTime.tm_min > 59) {
                cout << "invalid. try again: "; cin >> endTime.tm_min;
            }
            endTime.tm_sec = 0;
            
            end_time = asctime(&endTime);
                        
            time_t uStartTime = mktime(&startTime); 
            time_t uEndTime = mktime(&endTime);

            int stime = uStartTime;
            int etime = uEndTime;
    
            
            //finding flight length
            double flightlength = difftime(uEndTime, uStartTime) / 3600;

            if(flightlength > 8) {
                crewrestriction = true;
            }

            //asking for rest of flight information
            cout << "flight id: "; cin >> flight_id; cin.ignore();
            cout << "plane tail number: " ; getline(cin, tail_number);

            int passval = 0;

            for(int i= 0; i < aircrafts.gettailnumber().size(); i++) {
                if(tail_number == aircrafts.gettailnumber().at(i)) {
                    passval = 1;
                    break;
                }
            }
        
                while(passval == 0) {
                cout << "tail number does not exist. try again: "; getline(cin, tail_number);

                    for(int i= 0; i < aircrafts.gettailnumber().size(); i++) {
                        if(tail_number == aircrafts.gettailnumber().at(i)) {
                            cout << "found" << endl;
                            passval = 1;
                            
                        }
                    }
                }
    


            cout << "number of pilots and copilots: " ; cin >> num_pilots; 
            
            
            while(crewrestriction == true && num_pilots < 4) {
                cout << "not enough pilots and copilots for this trip. try again: ";cin >> num_pilots;
                
            }

            pilots.resize(num_pilots);

            cout << "number of cabin crew: " ; cin >> num_cabins; 
            cabinCrew.resize(num_cabins);   
            
            
            
            cout << "number of passengers: "; cin >> num_passengers; 
            
        

            //asking for crew member information
            cout << "enter pilot ids: "; 
                for (int a = 0; a < num_pilots; a++) {
                    passval = 0;
                    cout << "pilot/copilot " << a+1 << endl;
                    cin >> pilots.at(a);

                    for(int b = 0; b < crew.getmembers().size(); b++) {
                        if(pilots.at(a) == crew.getmembers().at(b)->getMemberID()) {
                            passval = 1;
                        }
                    }

                    while(passval == 0) {
                        cout << "pilot does not exist. try again: "; cin >> pilots.at(a);
                        
                        for(int b = 0; b < crew.getpilotID().size() + crew.getcopilotID().size(); b++) {
                            if(pilots.at(a) == crew.getmembers().at(b)->getMemberID()) {
                                passval = 1;
                             }
                        }
                    }
                }
            
                if(num_cabins != 0) {
                    cout << "enter cabin crew ids: ";  cout << endl;
                }
                for (int a = 0; a < num_cabins; a++) {
                    passval = 0;
                    cout << "cabin member " << a+1 << endl;
                    cin >> cabinCrew.at(a);

                    for(int b = 0; b < crew.getcabinID().size(); b++) {
                        if(cabinCrew.at(a) == crew.getcabinID().at(b)) {
                            passval = 1;
                        }
                    }

                    while(passval == 0) {
                        cout << "cabin member does not exist. try again: "; cin >> cabinCrew.at(a);
                        
                        for(int b = 0; b < crew.getcabinID().size(); b++) {
                            if(cabinCrew.at(a) == crew.getcabinID().at(b)) {
                                passval = 1;
                            }
                        }
                    }


                }  

            cout << cin.ignore();
            cout << "enter starting airport code: "; getline(cin, start_acode); 
            cout << "enter ending airport code: "; getline(cin, end_acode);
        
            //still have to set flight status

            flight_list.push_back(flight);

            int last_index = flight_list.size() - 1;

            
            flight_list.at(last_index).setFlightID(flight_id);
            flight_list.at(last_index).setTailNumber(tail_number);
            flight_list.at(last_index).setNumPilots(num_pilots);
            flight_list.at(last_index).setNumCabins(num_cabins);
            flight_list.at(last_index).setPilots(pilots);
            flight_list.at(last_index).setCabinCrew(cabinCrew);
            flight_list.at(last_index).setStartairportcode(start_acode);
            flight_list.at(last_index).setEndairportcode(end_acode);
            flight_list.at(last_index).setNumpassengers(num_passengers);
            flight_list.at(last_index).setStarttime(start_time);
            flight_list.at(last_index).setEndtime(end_time);
            flight_list.at(last_index).setflightlength(flightlength);
            flight_list.at(last_index).setstarttimenumber(stime);
            flight_list.at(last_index).setendtimenumber(etime);
            flight_list.at(last_index).setFlightstatus("on time");



    }

        void flights::deleteFlight() {
            int flight_id; int i; bool flightFound = false;

            cout << "enter the flight id: "; cin >> flight_id;

            for(i = 0; i < flight_list.size(); i++) {
                if(flight_id == flight_list.at(i).getFlightID()) {
                    flightFound = true;
                     break;
                }        
            }

            if(flightFound == true) {
                flight_list.erase(flight_list.begin() + i);
                cout << "flight has been deleted" << endl;
            }
            else {
                cout << "flight not found." << endl;

            }
        }
       
        void flights::editFlight() { //range checking needed
            int i, flight_id; bool flightFound = false;

            cout << "enter the flight id: "; cin >> flight_id;

            for(i = 0; i < flight_list.size(); i++) {
                if(flight_id == flight_list.at(i).getFlightID()) {
                    flightFound = true;
                     break;
                }        
            }

            if(flightFound == true) {

                    string start_acode;
                    string end_acode;
                    int num_passengers;
                    int userChoice;

                cout << "1 - starting airport code" << endl;
                cout << "2 - ending airport code" << endl;
                cout << "3 - number of passengers" << endl;
                cout << "enter choice: "; cin >> userChoice;

                if(userChoice == 1) {
                    cin.ignore(); cout << "enter new starting airport code: "; getline(cin, start_acode);
                    flight_list.at(i).setStartairportcode(start_acode);
                }
                else if(userChoice == 2) {
                    cin.ignore(); cout << "enter new starting airport code: "; getline(cin, end_acode);
                    flight_list.at(i).setEndairportcode(end_acode);  
                }
                else if(userChoice == 3) {
                    cout << "enter new amount of passengers: "; cin >> num_passengers;
                    flight_list.at(i).setNumpassengers(num_passengers); //have not figured out range checking for numseats == numpassengers
                }
            }
        }
        void flights::printFlights() {
            for(int i = 0; i < flight_list.size(); i++) {
            //printing all data for every flightt
            cout << "flight id: " << flight_list.at(i).getFlightID() << endl;
            cout << "plane tail number: " << flight_list.at(i).getTailNumber() << endl;
            cout << "number of pilots: " << flight_list.at(i).getNumPilots() << endl;
            cout << "number of cabin crew: " << flight_list.at(i).getNumCabins() << endl;
            cout << "number of passengers: " << flight_list.at(i).getNumpassengers() << endl;
            cout << "pilot ids: "; flight_list.at(i).getPilots(); cout << endl; //different print method, watch for error
            cout << "cabin crew ids: "; flight_list.at(i).getCabinCrew(); cout << endl;
            cout << "starting airport code: " << flight_list.at(i).getStartairportcode() << endl;
            cout << "ending airport code: " << flight_list.at(i).getEndairportcode() << endl;
            cout << "start time: " << flight_list.at(i).getStarttime() << endl;
            cout << "end time: " << flight_list.at(i).getEndtime() << endl;
            cout << "flight length: " << flight_list.at(i).getflightlength() << endl;
            cout << "flight status: " << flight_list.at(i).getFlightstatus() << endl;
    
            }

        }
        void flights::printAFlight() {
            int flight_id; bool flightFound = false;

            cout << "enter the flight id: "; cin >> flight_id;
            //finding the flight associated with the entered id
            for(int i = 0; i < flight_list.size();i++) {
                if(flight_id == flight_list.at(i).getFlightID()) {
                    flightFound = true;
                    cout << "flight id: " << flight_list.at(i).getFlightID() << endl;
                    cout << "plane tail number: " << flight_list.at(i).getTailNumber() << endl;
                    cout << "number of pilots: " << flight_list.at(i).getNumPilots() << endl;
                    cout << "number of cabin crew: " << flight_list.at(i).getNumCabins() << endl;
                    cout << "number of passengers: " << flight_list.at(i).getNumpassengers() << endl;
                    cout << "pilot ids:  "; flight_list.at(i).getPilots(); cout << endl; //different print method, watch for error
                    cout << "cabin crew ids: "; flight_list.at(i).getCabinCrew(); cout << endl;
                    cout << "starting airport code: " << flight_list.at(i).getStartairportcode() << endl;
                    cout << "ending airport code: " << flight_list.at(i).getEndairportcode() << endl;
                    cout << "start time: " << flight_list.at(i).getStarttime() << endl;
                    cout << "end time: " << flight_list.at(i).getEndtime() << endl;
                    cout << "flight length: " << flight_list.at(i).getflightlength() << endl;
                    cout << "flight status: " << flight_list.at(i).getFlightstatus() << endl;
                }
            }
            
            if(flightFound == false) {
                cout << "flight not found." << endl;
            }
        }

        void flights::updateflightstatus() {
            time_t now = time(0);
        //updating flight status 
            for(int i = 0; i < flight_list.size(); i++) {
                if(now > flight_list.at(i).getendtimenumber()) {
                    flight_list.at(i).setFlightstatus("completed");
                }
            }
        }

        void flights::printAPlaneSchedule() {
            int j; string tail_number;
             cout << "enter plane tail number: "; getline(cin.ignore(), tail_number);
            //printing all flights that include the plane with entered tail number 
            for(j = 0; j < flight_list.size(); j++) {
                if(flight_list.at(j).getTailNumber() == tail_number) {
                    cout << "flight " << j+1 << endl;
                    cout << "start time: " << flight_list.at(j).getStarttime() << endl;
                    cout << "end time: " << flight_list.at(j).getEndtime() << endl;
                    cout << "starting airport: " << flight_list.at(j).getStartairportcode() << endl;
                    cout << "ending airport: " << flight_list.at(j).getEndairportcode() << endl;
                    cout << "flight status: " << flight_list.at(j).getFlightstatus() << endl;

                    
                }
            }
        }

        void flights::printAMemberSchedule() { //prinitng all flights associated with member id
            int m_id; int choice;
            cout << "is the member a pilot (1) or crew member (2): "; cin >> choice;
            while(choice != 1 && choice != 2) {
                cout << "invalid option. try again: "; cin >> choice;
            }
            cout << "enter member id: "; cin >> m_id;

            if(choice == 1) {
                for(int i = 0; i < flight_list.size();i++) {
                    for(int a = 0; a < flight_list.at(i).getPilots().size(); a++) {
                        if(m_id == flight_list.at(i).getPilots().at(a)) {
                            cout << "flight " << a+1 << endl;
                            cout << "start time: " << flight_list.at(i).getStarttime() << endl;
                            cout << "end time: " << flight_list.at(i).getEndtime() << endl;
                            cout << "starting airport: " << flight_list.at(i).getStartairportcode() << endl;
                            cout << "ending airport: " << flight_list.at(i).getEndairportcode() << endl;
                            cout << "flight status: " << flight_list.at(i).getFlightstatus() << endl;
                            
                        }
                    }   
                }  
            }
            else if(choice == 2) {
                for(int i = 0; i < flight_list.size();i++) {
                    for(int a = 0; a < flight_list.at(i).getCabinCrew().size(); a++) {
                        if(m_id == flight_list.at(i).getCabinCrew().at(a)) {
                            cout << "start time: " << flight_list.at(i).getStarttime() << endl;
                            cout << "end time: " << flight_list.at(i).getEndtime() << endl;
                            cout << "starting airport: " << flight_list.at(i).getStartairportcode() << endl;
                            cout << "ending airport: " << flight_list.at(i).getEndairportcode() << endl;
                            cout << "flight status: " << flight_list.at(i).getFlightstatus() << endl;
                            cout << "flight " << a+1 << endl;
                        }
                    }   
                }  
            }

           
        }

        void flights::deleteExpiredFlights() {  //searching for flight with certain status and deleting them
            
            for(int i = 0; i < flight_list.size(); i++) {
                if(flight_list.at(i).getFlightstatus() == "cancelled" || flight_list.at(i).getFlightstatus() == "completed") {
                    flight_list.erase(flight_list.begin() + i);
                }
            }

        }



        void flights::savedata() {
            ofstream fout;
            fout.open("flights.out");
            fout << flight_list.size() << endl;

            for(int i = 0; i < flight_list.size(); i++) {
                fout << flight_list.at(i).getFlightID() << endl;
                fout << flight_list.at(i).getTailNumber() << endl;
                fout << flight_list.at(i).getNumPilots() << endl;
                fout << flight_list.at(i).getNumCabins() <<  endl;
                fout << flight_list.at(i).getNumpassengers() << endl;
                for(int j = 0; j < flight_list.at(i).getPilots().size(); j++) {     //Saving all data of a flight
                    fout << flight_list.at(i).getPilots().at(j) << endl;
                }
                for(int a = 0; a < flight_list.at(i).getCabinCrew().size(); a++) {
                    fout << flight_list.at(i).getCabinCrew().at(a) << endl;
                }
                fout << flight_list.at(i).getStartairportcode() << endl;
                fout << flight_list.at(i).getEndairportcode() << endl;
                
                fout << flight_list.at(i).getstarttimenumber() << endl;
                fout << flight_list.at(i).getendtimenumber() << endl;
                fout << flight_list.at(i).getflightlength() << endl;
                fout << flight_list.at(i).getFlightstatus() << endl;
            }
            fout.close();
        }

        void flights::loaddata() {
            ifstream fin;
            string tail_number;
            int num_pilots;
            int num_cabins;
            vector <int> pilots;
            vector <int> cabinCrew;
            //flight start time
            int start_time;
            //flight end time
            int end_time;
            string start_acode;
            string end_acode;
            int num_passengers;
            string flight_status;
            int flight_id;
            int flight_count;
            double flightlength;

            fin.open("flights.out");
                                                    //FIXME: Abort Trap 6 issue "out of range vector". I can save but I cannot load back in data
            fin >> flight_count;

            flight_list.resize(flight_count);
        
            for(int i = 0; i < flight_count; ++i) {

                fin >> flight_id >> tail_number >> num_pilots >> num_cabins >> num_passengers;

                flight_list.at(i).setFlightID(flight_id);
                flight_list.at(i).setTailNumber(tail_number);
                flight_list.at(i).setNumPilots(num_pilots);
                flight_list.at(i).setNumCabins(num_cabins);
                flight_list.at(i).setNumpassengers(num_passengers);
                
                flight_list.at(i).getPilots().resize(num_pilots);
                
                for(int j = 0; j < num_pilots; ++j) {
                    fin >> pilots.at(j); 
                }
                flight_list.at(i).setPilots(pilots);
                
                flight_list.at(i).getCabinCrew().resize(num_cabins);
                
                for(int a = 0; a < num_cabins; ++a) {
                    fin >> cabinCrew.at(a);
                
                }
                flight_list.at(i).setCabinCrew(cabinCrew);
                fin >> start_acode >> end_acode >> start_time >> end_time >> flightlength >> flight_status;
               
                flight_list.at(i).setCabinCrew(cabinCrew);
                flight_list.at(i).setStartairportcode(start_acode);
                flight_list.at(i).setEndairportcode(end_acode);
                flight_list.at(i).setstarttimenumber(start_time);
                flight_list.at(i).setendtimenumber(end_time);
                flight_list.at(i).setflightlength(flightlength);
                flight_list.at(i).setFlightstatus(flight_status);

            }



        }