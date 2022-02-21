#include <iostream>
#include <iomanip>
#include <map>
#include "CountryMap.h"
using namespace std;


int main() {

    string countryName;
    unsigned days;
    CountryMap myMap;
    
    cout << "Welcome to Schengen Shuffle!" << endl;
    cout << "Here is a list of all the countries within the Schengen Region." << endl;
    cout << "You have " << myMap.getMaxDays() << " to move between these countries:" << endl;

    myMap.showMap();

    cout << "Which country days would you like to edit? (enter 'quit' to exit)" << endl;
    cin >> countryName;

    while ( countryName != "quit" ) {

        if (myMap.inSchengen(countryName)) {
            cout << "How many days for " << countryName << "?" << endl;
            cin >> days;
            if ( (myMap.getUsedDays()+days) > myMap.getMaxDays() ) {
                cout << "Oh no! That's " << (myMap.getUsedDays()+days) - myMap.getMaxDays() << " days(s) over the allotted 90 days." << endl;
                cout << "You have " << myMap.getMaxDays() - myMap.getUsedDays() << " left to work with." << endl;
                continue;
            }
            myMap.setCountryDays(countryName, days);

        } else {     
            cout << endl << "Sorry, " << countryName << " is not in the Schengen region or is not recognized." << endl;
            cout << "Here is your current list:" << endl;
        }
        cout << "Your current list:" << endl;
        myMap.showMap();
        cout << "Which country days would you like to edit? (enter 'quit' to exit)" << endl;
        cin >> countryName;
    }

    cout << endl << "Have a fun adventure! Byeeeeeee" << endl;

    return 0;
}