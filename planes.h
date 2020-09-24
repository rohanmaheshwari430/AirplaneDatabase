#include <string>
#include <vector>
#include "plane.h"

using namespace std;

class planes { //this class holds all functionalities for a single plane

    public:
        void addPlane();
        void deletePlane();
        void searchPlane();
        void findPlaneToEdit();
        void printPlane();
        void printAPlane();
        void loaddata();
        void savedata();
        void setplanes(vector <plane> plist);
        vector <plane> getplanes();
        void settailnumber(vector <string> tnumber);
        vector <string> gettailnumber();
        


    private:
        vector <plane> plane_list;
        vector <string> tailnumber;

};