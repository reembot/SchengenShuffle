#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Country.h"
using namespace std;


class CountryMap {

    private:
        map<Country, unsigned> Map;
        unsigned MAX_DAYS = 90;
        //unsigned usedDays;
        //unsigned entryDate;
        //unsigned exitDate;
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
        fileStream.close();                          // close file
    }


// List Countries and Days in order of days
    void CountryMap::showMap() {


        multimap< unsigned,string,greater<unsigned> > sortByDayMap;
        for (auto it= Map.begin(); it != Map.end(); it++) {
            sortByDayMap.insert(make_pair(it->second,it->first.getName()));
        }
        
        cout << "SCHENGEN" << setw(20 - 6) << right << "DAYS" << endl << endl;

        for (auto it= sortByDayMap.begin(); it != sortByDayMap.end(); it++) {   
            cout  << it->second << ": " << setw(20 - it->second.length() ) << right << it->first << endl;
        }

        cout << endl << "TOTAL DAYS USED: " << setw(20-15) << right << getUsedDays() << "/" << MAX_DAYS << endl << endl;
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