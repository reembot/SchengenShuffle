#include <iostream>
#include <iomanip>
#include <map>
#include <locale>
#include "CountryMap.h"
using namespace std;


int main() {

    CountryMap myMap;
    unsigned   MAX_DAYS = myMap.getMaxDays();
    
    cout << "Welcome to Schengen Shuffle!" << endl << endl;
    cout << "You have " << MAX_DAYS << " days to move between these " << myMap.getMapSize() << " countries:" << endl;
    myMap.showMap();

    int action= 0;
    string countryName;

    while ( action != 3 ) {
        
        cout << "Please make a selection:" << endl;
        cout << "1) View My Current Journey" << endl;
        cout << "2) Add or Remove Days" << endl;
        cout << "3) Quit" << endl;
        cin >> action;

        switch ( action ) {
            
            case 1:
                myMap.showMap();
                break;

            case 2:
                cout << "\nWhich country's days would you like to edit?" << endl;
                cin.ignore();
                getline(cin, countryName);

                // convert input to lower-case to match Map key
                for ( int i= 0; i< countryName.length(); i++ ) {
                    countryName[i] = tolower(countryName[i]);
                }
                // check if country exists in Schengen map
                if ( myMap.inSchengen(countryName) ) {
                    
                    unsigned days;
                    cout << "\nHow many days would you like to stay in " << countryName << "?" << endl;
                    cin >> days;

                    // check for valid day input
                    if ( days >= 0 && days <= MAX_DAYS ) {
                        
                        myMap.setCountryDays(countryName, days);    // update day value for country entered

                    } else {    // if days entered outside of range
                        cout << "Please enter a number between 0 and 90" << endl;
                    }

                } else {    // input is not recognized
                    cout << endl << "Sorry, '" << countryName << "' is not in the Schengen region or is not recognized." << endl << endl;
                }
                break;

            case 3:
                cout << endl << "Bon Voyage! Alvederzein! Byeeeeeeeeeeeeeeeeeee" << endl << endl;
                exit(0);

            default:
                cout << "Please make a selection between 1 and 3." << endl;
        }
    }
    return 0;
    
}