#include <string>
#include <vector>
#include <ctime>
using namespace std;

class flight {  //this class contains all the attributes of a single flight

    public:
    
        void setTailNumber(string t_number);
        string getTailNumber();
        void setNumPilots(int n_pilots);
        int getNumPilots();
        void setNumCabins(int n_cabins);
        int getNumCabins();
        void setStartairportcode(string s_code);
        string getStartairportcode();
        void setEndairportcode(string e_code);
        string getEndairportcode();
        void setNumpassengers(int n_passengers);
        int getNumpassengers();
        void setFlightstatus(string f_status);
        string getFlightstatus();
        void setCrewrestriction(bool c_restriction);
        bool getCrewrestriction();
        void setFlightID(int f_id);
        int getFlightID();
        void setPilots(vector <int> Pilots);
        vector <int> getPilots();
        void setCabinCrew(vector <int> cabinCrew);
        vector <int> getCabinCrew();
        void setStarttime(string start_time);
        string getStarttime();
        void setEndtime(string end_time);
        string getEndtime();
        void setflightlength(double f_length);
        double getflightlength();
        void setstarttimenumber(int s_time);
        int getstarttimenumber();
        void setendtimenumber(int e_time);
        int getendtimenumber();
       

        //still need accessor and mutators for flight start and end times 

    private:
        string tailnumber;
        int numpilots;
        int numcabins;
        vector <int> pilots;
        vector <int> cabinCrew;
        //flight start time
        string starttime;
        //flight end time
        string endtime;
        string startacode;
        string endacode;
        int numpassengers;
        string flightstatus;
        bool crewrestriction;
        int flightid;
        double flightlength;
        int starttimenumber;
        int endtimenumber;
        
        


 


};









