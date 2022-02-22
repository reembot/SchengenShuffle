#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "Country.h"
using namespace std;


class CountryMap {

    private:
        map<Country, unsigned> Map;
        unsigned MAX_DAYS = 90;
        //unsigned usedDays;
        void     populateMap( map<Country,unsigned>, string fileName );
    
    public:
        CountryMap();
        bool     inSchengen(string name) const;
        unsigned getUsedDays() const;
        void     setUsedDays(unsigned newDayCount);
        void     setCountryDays(string name, unsigned days);
        unsigned getCountryDays(string name) const;
        unsigned getMaxDays() const;
        void     showMap();


};


// Default Constructor
    CountryMap::CountryMap() {
        //usedDays = 0;
        populateMap(Map, "SchengenCountries.txt");
    }

// Populate map with country list
    void CountryMap::populateMap( map<Country,unsigned>, string fileName ) {
        
        cout << "populating map..." << endl;
        ifstream fileStream;                       // file stream buffer
        string   countryName;

        fileStream.open(fileName);
        if (!fileStream.is_open()) {                 // output error message if open fails
            cout << "Could not open " << fileName;
        }
        
        getline( fileStream, countryName );          // read first line of country file
        
        while (!fileStream.fail()) {
            Country country(countryName);
            Map.insert( make_pair(country,0) );      // insert each country into map with 0 days
            getline( fileStream, countryName );      // get next line
        }
        cout << "map size: " << Map.size() << endl;
        fileStream.close();                          // close file
    }


// List Countries and Days in order of days
    void CountryMap::showMap() {
        
        //cout << "Current Country List:" << endl;

        for (auto it= Map.begin(); it != Map.end(); it++) {   
            cout << it->first.getName() << ": " << it->second << endl;
        }

        cout << endl << "Total days used: " << getUsedDays() << "/" << MAX_DAYS << endl;
    }


// Check if country inquiry is within the Schengen region
    bool CountryMap::inSchengen(string name) const {
        
        if (Map.count(name) > 0) {  // or find?
            return true;
        } else {
            return false;
        }
    }

// How many days have been used
    unsigned CountryMap::getUsedDays() const {
        
        unsigned usedDays= 0;
        for (auto it= Map.begin(); it != Map.end(); it++) {   
            usedDays += it->second;
        }
        return usedDays;
    }

// Fetch Country object from map
    unsigned CountryMap::getCountryDays(string name) const {
        
        return Map.find(name)->second;
    }

// // Update used day count
//     void CountryMap::setUsedDays(unsigned newDayCount) {
//         usedDays = newDayCount;
//     }

// Set days in Country
    void CountryMap::setCountryDays(string name, unsigned days) {
        Map.find(name)->second = days;
    }

// Get MAX_DAYS value
    unsigned CountryMap::getMaxDays() const {
        return MAX_DAYS;
    }