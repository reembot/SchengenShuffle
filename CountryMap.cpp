#include "CountryMap.h"

// Default Constructor
    CountryMap::CountryMap() {

        ifstream fileStream;                         // file stream buffer
        string fileName = "SchengenCountries.txt";

        fileStream.open( fileName );

        if (!fileStream.is_open()) {                 // close program if file load fails
            cout << "Could not open " << fileName << endl;
            exit(0);
        }

        string   countryName;      
        while ( !getline(fileStream, countryName).eof() ) {

            Country newCountry( countryName, 0 );
            
            // conver to lowercase for Map key
            for ( int i= 0; i< countryName.length(); i++ ) {
                countryName[i] = tolower(countryName[i]);
            }

            Map.insert( make_pair(countryName, newCountry) );      // insert each country into map with 0 days
        }
        fileStream.close();
    }

// Copy Constructor
    CountryMap::CountryMap( const CountryMap& copy) : Map(copy.Map), MAX_DAYS(copy.MAX_DAYS) {
    }

// Destructor
    CountryMap::~CountryMap() {
    }

// List Countries Alphabetically
    void CountryMap::showMap() const {

        cout << endl << "<<<< Your Current Journey >>>>" << endl << endl;
        cout << left << setw(20) << "SCHENGEN" << "DAYS" << endl << endl;

        for ( auto it= Map.begin(); it != Map.end(); it++ ) {   
            cout << left << setw(20) << it->second.getName() << it->second.getDays() << endl;
        }

        cout << endl << left << setw(20) << "TOTAL DAYS USED: " << getUsedDays() << "/" << MAX_DAYS << endl << endl;
    }


// Check if country inquiry is within the Schengen region
    bool CountryMap::inSchengen(string name) const {
        
        if ( Map.find(name) != Map.end() ) {
            return true;
        } else {
            return false;
        }     
    }

// How many days have been used
    unsigned CountryMap::getUsedDays() const {
        
        unsigned usedDays= 0;

        for (auto it= Map.begin(); it != Map.end(); it++) {   
            usedDays += it->second.getDays();
        }
        return usedDays;
    }

// Fetch Country Days
    unsigned CountryMap::getCountryDays(string name) const {
        
        auto requestedCountry = Map.find(name)->second;
        return requestedCountry.getDays();
    }

// Get MAX_DAYS value
    unsigned CountryMap::getMaxDays() const {
        return MAX_DAYS;
    }


// Get number of countries in Schengen
    unsigned CountryMap::getMapSize() const {
        return Map.size();
    }

// Edit days per country
    void CountryMap::setCountryDays(string name, unsigned days) {

           
        // if days entered exceeds the MAX_DAYS threshold
        if ( (getUsedDays()+days) > MAX_DAYS ) {

            cout << endl << "Oh no! That's " << (getUsedDays()+days) - MAX_DAYS <<
                " days(s) over the " << MAX_DAYS << " day maximum." << endl;
            cout << "You only have " << MAX_DAYS - getUsedDays() << " left to work with." << endl;
        
        } else {
            Map.find(name)->second.setDays( days );
            //Map[name].setDays( days );    // does not work?
        }

        // if update reaches MAX_DAY threshold
        if (getUsedDays() == MAX_DAYS) {      
            cout << endl << "Wunderbar! You've planned for the whole " << MAX_DAYS << " days!" << endl;
        }       
    }
