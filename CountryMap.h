#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include "Country.h"
using namespace std;


class CountryMap {

    private:
        set<Country> Map;
        unsigned MAX_DAYS = 90;
        unsigned usedDays;
        void     populateMap( set<Country>, string fileName );
    
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
    void CountryMap::populateMap( set<Country>, string fileName ) {
        
        ifstream fileStream;                       // file stream buffer
        string   countryName;

        fileStream.open(fileName);
        if (!fileStream.is_open()) {               // output error message if open fails
            cout << "Could not open " << fileName;
        }
        
        getline( fileStream, countryName );          // read first line of country file
        
        while (!fileStream.fail()) {
            Country country(countryName, 0);
            Map.insert( country );  // insert each country into map with 0 days
            getline( fileStream, countryName );      // get next line
        }
        fileStream.close();                        // close file
    }

// List Countries and Days in order of days
    void CountryMap::showMap() {
        
        cout << "Current Country List:" << endl;

        for (auto it= Map.begin(); it != Map.end(); it++) {
            Country country = it;
            cout << it->getName() << ": " << it->second << endl;
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
        auto it = Map.find(name);
    
        return it->getDays();
    }




// Update used day count
    void CountryMap::setUsedDays(unsigned newDayCount) {
        usedDays = newDayCount;
    }