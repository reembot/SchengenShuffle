#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "Country.h"
using namespace std;


class CountryMap {

    private:
        map<Country,unsigned> Map;
        unsigned MAX_DAYS = 90;
        unsigned usedDays;
        void     populateMap( map<Country,unsigned>, string fileName );
    
    public:
        CountryMap();
        bool     inSchengen(string name);
        unsigned getUsedDays();
        void     setUsedDays(unsigned newDayCount);
        unsigned getCountryDays(string name);
        void     showMap();

};


// Default Constructor
    CountryMap::CountryMap() {
        usedDays = 0;
        populateMap(Map, "SchengenCountries.txt");
    }

// Populate map with country list
    void CountryMap::populateMap( map<Country,unsigned>, string fileName ) {
        
        ifstream fileStream;                       // file stream buffer
        string   countries;

        fileStream.open(fileName);
        if (!fileStream.is_open()) {               // output error message if open fails
            cout << "Could not open " << fileName;
        }
        
        getline( fileStream, countries );          // read first line of country file
        
        while (!fileStream.fail()) {
            Map.insert( make_pair(countries,0) );  // insert each country into map with 0 days
            getline( fileStream, countries );      // get next line
        }
        fileStream.close();                        // close file
    }

// List Countries and Days in order of days
    void CountryMap::showMap() {
        
        cout << "Current Country List:" << endl;

        for (auto it= Map.begin(); it != Map.end(); it++) {
            Country country = it->first;
            cout << country.getName() << ": " << it->second << endl;
        }
    }


// Check if country inquiry is within the Schengen region
    bool CountryMap::inSchengen(string name) {
        
        if (Map.count(name) > 0) {
            return true;
        } else {
            return false;
        }
    }

// How many days have been used
    unsigned CountryMap::getUsedDays() {
        return usedDays;
    }

// Fetch Country object from map
    unsigned CountryMap::getCountryDays(string name) {
        return Map[name];
    }




// Update used day count
    void CountryMap::setUsedDays(unsigned newDayCount) {
        usedDays = newDayCount;
    }