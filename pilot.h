#include <string> 
#include "crewmember.h"
using namespace std;

class pilot: public crewmember {
    
    public:
        pilot(string m_name, int id, string m_type, string s, string rcode, int fh);
        void setRatingCode(string rc);
        string getRatingCode();
        void setFlightHours(int fh);
        int getFlightHours();
        void printInfo();
        void editPilot();

    protected: 
        string ratingcode;
        int pflighthours;

};