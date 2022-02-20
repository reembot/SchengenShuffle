#include <string>
#include <map>
#include "Country.h"
using namespace std;


class CountryMap {

    private:
        map<Country,unsigned> CountryMap;
        unsigned usedDays;
        void     populateMap();
    
    public:
        bool     inSchengen();
        unsigned getUsedDays();
        pair<Country,unsigned> getCountry();

};


    