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
        unsigned usedDays;
        void     populateMap( map<Country,unsigned>, string fileName );
    
    public:
        CountryMap();
        bool     inSchengen(string name) const;
        unsigned getUsedDays() const;
        void     setUsedDays(unsigned newDayCount);
        unsigned getCountryDays(string name) const;
        void     showMap();


};


// Default Constructor
    CountryMap::CountryMap() {
        usedDays = 0;
        populateMap(Map, "SchengenCountries.txt");
    }

// Populate map with country list
    void CountryMap::populateMap( map<Country,unsigned>, string fileName ) {
        
        cout << "populating map..." << endl;
        ifstream fileStream;                       // file stream buffer
        string   countryName;

        fileStream.open(fileName);
        if (!fileStream.is_open()) {               // output error message if open fails
            cout << "Could not open " << fileName;
        }
        
        getline( fileStream, countryName );          // read first line of country file
        
        while (!fileStream.fail()) {
            //cout << "inserting " << countryName << endl;
            Country country(countryName);
            Map.insert( make_pair(country,0) );     // insert each country into map with 0 days
            getline( fileStream, countryName );      // get next line
        }
        cout << "map size: " << Map.size() << endl;
        fileStream.close();                        // close file
    }

// List Countries and Days in order of days
    void CountryMap::showMap() {
        
        cout << "Current Country List:" << endl;

        for (auto it= Map.begin(); it != Map.end(); it++) {
            
            // cout.flush();
            if (it->first.getName() == "Switzerland") {
                it->second = 2;
            }
            
            // cout << it->first.getName();
            // cout << "name size: " << (it->first.getName()).length() << endl;
            // cout << "Days: " << it->second << endl;

            cout << it->first.getName();
            cout.flush();
            cout << ":" << it->second << endl;
        }
    }


// Check if country inquiry is within the Schengen region
    bool CountryMap::inSchengen(string name) const {
        
        if (Map.count(name) > 0) {
            return true;
        } else {
            return false;
        }
    }

// How many days have been used
    unsigned CountryMap::getUsedDays() const {
        return usedDays;
    }

// Fetch Country object from map
    unsigned CountryMap::getCountryDays(string name) const {
        
        //unsigned days = it->getDays();
        return Map.find(name)->second;
    }

// Update used day count
    void CountryMap::setUsedDays(unsigned newDayCount) {
        usedDays = newDayCount;
    }