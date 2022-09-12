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

            //cout << "reading in " << countryName << endl;
            Country newCountry( countryName, 0 );
            Map.insert( make_pair(countryName, newCountry) );      // insert each country into map with 0 days
            getline( fileStream, countryName );          // get next line
        }
        fileStream.close();
    }


// List Countries and Days in order of days
    void CountryMap::showMap() const {

        cout << endl << "<<<< Your Current Journey >>>>" << endl << endl;
        cout << "SCHENGEN" << setw(20 - 6) << right << "DAYS" << endl << endl;

        for ( auto it= Map.begin(); it != Map.end(); it++ ) {   
            cout  << it->first << ": " << setw(20) << right << it->second.getDays() << endl;
        }

        cout << endl << "TOTAL DAYS USED: " << setw(20-15) << right << getUsedDays() << "/" << MAX_DAYS << endl << endl;
    }


// Check if country inquiry is within the Schengen region
    bool CountryMap::inSchengen(string name) const {
        
        for ( auto it= Map.begin(); it != Map.end(); it++ ) {
            
            // Compare input name to each Country name
            if ( it->second.getName() == name ) {
                continue;
            }
        }
        return false;
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

    void CountryMap::setCountryDays(string name, unsigned days) {

           
        // if days entered exceeds the MAX_DAYS threshold
        if ( (getUsedDays()+days) > MAX_DAYS ) {

            cout << endl << "Oh no! That's " << (getUsedDays()+days) - MAX_DAYS <<
                " days(s) over the " << MAX_DAYS << " day maximum." << endl;
            cout << "You only have " << MAX_DAYS - getUsedDays() << " left to work with." << endl;
        
        } else {
            auto requestedCountry = Map.find(name)->second;
            requestedCountry.setDays(days);
        }

        // if update reaches MAX_DAY threshold
        if (getUsedDays() == MAX_DAYS) {      
            cout << endl << "Wunderbar! You've planned for the whole " << MAX_DAYS << " days!" << endl;
        }       
    }
