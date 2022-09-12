#include "Country.h"


// Default Constructor
    Country::Country( string name, unsigned days ) : name(name), days(days) {
    }

// Copy Constructor
    Country::Country(const Country& copy) : name(copy.name), days(copy.days) {
    }

// Destructor
    Country::~Country() {
    }

// Get Country name
    string Country::getName() const {
        return name;
    }

// Get Country Days
    unsigned Country::getDays() const {
        return days;
    }

// Set Days in Country
    void Country::setDays(unsigned days) {
        days = days;
    }


// Overload operators for vertex ordering
    bool operator<( const Country& lhs , const Country& rhs ) {
        
        return lhs.getName() < rhs.getName();
    }

    bool operator>(  const Country& lhs , const Country& rhs ) {
        
        return rhs < lhs;   //return counterpart overload
    }

// Overload operators for vertex identification
    bool operator==( const Country& lhs , const Country& rhs ) {

        return lhs.getName() == rhs.getName();
    }

    bool operator!=( const Country& lhs , const Country& rhs ) {

        return !(lhs.getName() == rhs.getName());
    }