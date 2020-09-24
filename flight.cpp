#include <iostream>
#include <ctime>

#include "flight.h"

using namespace std;

void flight::setTailNumber(string t_number) {
    tailnumber = t_number;
}
        string flight::getTailNumber() {
            return tailnumber;
        }
        void flight::setNumPilots(int n_pilots) {
            numpilots = n_pilots;
        }
        int flight::getNumPilots() {
            return numpilots;
        }
        void flight::setNumCabins(int n_cabins) {
            numcabins = n_cabins;
        }
        int flight::getNumCabins() {
            return numcabins;
        }
        void flight::setStartairportcode(string s_code) {
            startacode = s_code;
        }
        string flight::getStartairportcode() {
            return startacode;
        }
        void flight::setEndairportcode(string e_code) {
            endacode = e_code;
        }
        string flight::getEndairportcode() {
            return endacode;
        }
        void flight::setNumpassengers(int n_passengers) {
            numpassengers = n_passengers;
        }
        int flight::getNumpassengers() {
            return numpassengers;
        }
        void flight::setFlightstatus(string f_status) {
            flightstatus = f_status;
        }
        string flight::getFlightstatus() {
            return flightstatus;
        }
        void flight::setCrewrestriction(bool c_restriction) {
            crewrestriction = c_restriction;
        }
        bool flight::getCrewrestriction() {
            return crewrestriction;
        }
        void flight::setFlightID(int f_id) {
            flightid = f_id;
        }
        int flight::getFlightID() {
            return flightid;
        }

        void flight::setPilots(vector <int> Pilots) {
            pilots = Pilots;
        }
        vector <int> flight::getPilots() {
            for(int i = 0; i < pilots.size(); i++) {
                cout << pilots.at(i) << endl;
            }
            return pilots;
        }

        void flight::setCabinCrew(vector <int> Crew) {
            cabinCrew = Crew;
        }
        vector <int> flight::getCabinCrew() {
            for(int i = 0; i < cabinCrew.size(); i++) {
                cout << cabinCrew.at(i) << endl;
            }
            return cabinCrew;
        }

        void flight::setStarttime(string start_time) {
            starttime = start_time;
        }
        string flight::getStarttime() {
            return starttime;
        }

        void flight::setEndtime(string end_time) {
            endtime = end_time;
        }
        string flight::getEndtime() {
            return endtime;
        }

        void flight::setflightlength(double f_length) {
            flightlength = f_length;
        }
        double flight::getflightlength() {
            return flightlength;
        }

        void flight::setstarttimenumber(int s_time) {
            starttimenumber = s_time;
        }
        int flight::getstarttimenumber() {
            return starttimenumber;
        }

        void flight::setendtimenumber(int e_time) {
            endtimenumber = e_time;
        }
        int flight::getendtimenumber() {
            return endtimenumber;
        }


