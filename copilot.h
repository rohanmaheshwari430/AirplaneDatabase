#include <string> 
#include "crewmember.h"

class copilot: public crewmember {

    public: 
        copilot(string m_name, int id, string m_type, string s, string rcode, int fh); 
        void setRatingCode(string rc);
        string getRatingCode();
        void setFlightHours(int fh);
        int getFlightHours();
        void printInfo();
        void editCopilot();

    protected: 
        string ratingcode;
        int coflighthours;


};