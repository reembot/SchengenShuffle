#include <iostream>
#include <iomanip>
#include <map>
#include <locale>
#include "CountryMap.h"
using namespace std;


// Convert first letter to Uppercase and remaining letters to lower case
void convertCase(string &countryName) {

    countryName[0] = toupper(countryName[0]);
    for (unsigned i= 1; i< countryName.length(); i++) {
       
        if (countryName[i] == ' ') {    // for Czech Republic
            i++;
            countryName[i] = toupper(countryName[i]);
            continue;
        }
        countryName[i] = tolower(countryName[i]);
    }
}


int main() {

    string     countryName;
    unsigned   days;
    CountryMap myMap;
    unsigned   MAX_DAYS = myMap.getMaxDays();
    
    cout << "Welcome to Schengen Shuffle!" << endl << endl;
    cout << "You have " << MAX_DAYS << " days to move between these " << myMap.getMapSize() << " countries:" << endl << endl;

    myMap.showMap();

    cout << "Which country days would you like to edit? (enter 'quit' to exit)" << endl;
    getline(cin, countryName);
    convertCase(countryName);

    while ( countryName != "Quit" ) {

        // check if country exists in Schengen map
        if (myMap.inSchengen(countryName)) {
            cout << endl << "How many days would you like to stay in " << countryName << "?" << endl;
            cin >> days;
            if ( cin.fail() ) {
                cin.clear();
                cout << "Please enter a number between 0 and 90" << endl;
                continue;
            }
            // cin.sync();     // flush cin buffer

            if (days >= 0 && days < MAX_DAYS+1) {   // check for valid day input

                // if days entered exceeds the MAX_DAYS threshold
                if ( (myMap.getUsedDays()+days) > MAX_DAYS ) {  
                    cout << endl << "Oh no! That's " << (myMap.getUsedDays()+days) - MAX_DAYS << " days(s) over the " << MAX_DAYS << " day maximum." << endl;
                    cout << "You have " << MAX_DAYS - myMap.getUsedDays() << " left to work with." << endl;
                    continue;

                }
                myMap.setCountryDays(countryName, days);    // update day value for country entered

            } else {    // if days entered outside of range
                cout << "Please enter a number between 0 and 90" << endl;
                continue;
            }

        } else {    // input is not recognized
            cout << endl << "Sorry, '" << countryName << "' is not in the Schengen region or is not recognized." << endl << endl;
        }

        cout << endl << "<<<< Your Current Journey >>>>" << endl << endl;
        myMap.showMap();

        // if update reaches MAX_DAY threshold
        if (myMap.getUsedDays() == MAX_DAYS) {      
            cout << endl << "Congratulations, you've planned for the whole " << MAX_DAYS << " days!" << endl;
        }

        cout << "Which country days would you like to edit? (enter 'quit' to exit)" << endl;
        getline(cin, countryName);
        convertCase(countryName);
    }

    // if 'quit' - end of program
    cout << endl << "Bon Voyage! Alvederzein! Byeeeeeeeeeeeeeeeeeee" << endl << endl;

    return 0;
}