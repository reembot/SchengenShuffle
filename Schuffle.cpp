#include <iostream>
#include <iomanip>
#include <map>
#include <locale>
#include "CountryMap.h"
using namespace std;



void convertCase(string &countryName) {
    
    countryName[0] = toupper(countryName[0]);
    for (unsigned i= 1; i< countryName.length(); i++) {
        countryName[i] = tolower(countryName[i]);
    }
}


int main() {

    string countryName;
    unsigned days;
    CountryMap myMap;
    unsigned MAX_DAYS = myMap.getMaxDays();
    
    cout << "Welcome to Schengen Shuffle!" << endl << endl;
    cout << "You have " << MAX_DAYS << " days to move between these countries:" << endl << endl;

    myMap.showMap();

    cout << "Which country days would you like to edit? (enter 'quit' to exit)" << endl;
    cin >> countryName;
    convertCase(countryName);

    while ( countryName != "quit" ) {

        // check if country exists in Schengen map
        if (myMap.inSchengen(countryName)) {
            cout << endl << "How many days would you like to stay in " << countryName << "?" << endl;
            cin >> days;

            // if days entered exceeds the MAX_DAYS threshold
            if ( (myMap.getUsedDays()+days) > MAX_DAYS ) {  
                cout << endl << "Oh no! That's " << (myMap.getUsedDays()+days) - MAX_DAYS << " days(s) over the " << MAX_DAYS << " day maximum." << endl;
                cout << "You have " << MAX_DAYS - myMap.getUsedDays() << " left to work with." << endl;
                continue;

            }
            myMap.setCountryDays(countryName, days);    // update day value for country entered

            if (myMap.getUsedDays() == MAX_DAYS) {      // if update reaches MAX_DAY threshold
                cout << endl << "Congratulations, you've planned for the whole " << MAX_DAYS << " days!" << endl;
            }

        } else {    // input is not recognized
            cout << endl << "Sorry, '" << countryName << "' is not in the Schengen region or is not recognized." << endl << endl;
        }

        cout << "Your current journey:" << endl;
        myMap.showMap();
        cout << "Which country days would you like to edit? (enter 'quit' to exit)" << endl;
        cin >> countryName;
    }

    // if 'quit' - end of program
    cout << endl << "Bon Voyage! Alvederzein! YOLO! Byeeeeeee" << endl << endl;

    return 0;
}