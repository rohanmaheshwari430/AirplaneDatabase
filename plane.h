#include <string>

using namespace std;


class plane {   //this class contains all attributes of a single plane

    public:
        void setMake(string m);
        string getMake();
        void setModelNumber(int m_number);
        int getModelNumber();
        void setTailNumber(string t_number);
        string getTailNumber();
        void setNumSeats(int n_seats);
        int getNumSeats();
        void setRange(int s_range);
        int getRange();
        void setMinCCrew(int min_crew);
        int getMinCCrew();
        void editPlane();

    private:
        string make;
        int modelnumber;
        string tailnumber;
        int numseats;
        int range;
        int minCCrew;

};
