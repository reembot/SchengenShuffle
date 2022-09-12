#ifndef COUNTRYMAP_H
#define COUNTRYMAP_H
#include "Country.h"
#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


class CountryMap {

    private:
        map<string, Country> Map;
        unsigned MAX_DAYS = 90;
        //unsigned entryDate;
        //unsigned exitDate;
    
    public:
        CountryMap();
        CountryMap( const CountryMap& copy);
        ~CountryMap();
        
        void     showMap() const;
        bool     inSchengen(string name) const;
        unsigned getUsedDays() const;
        unsigned getCountryDays(string name) const;
        void     setUsedDays(unsigned newDayCount);
        unsigned getMaxDays() const;
        unsigned getMapSize() const;
        void     setCountryDays(string name, unsigned days);
};

#endif