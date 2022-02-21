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
            cout << "How many days?" << endl;
            cin >> days;
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


    return 0;
}