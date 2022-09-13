#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <iostream>
using namespace std;


class Country {

    private:
        string   name;
        unsigned days;
    
    public:
        Country( string name, unsigned days );
        Country(const Country& copy);
        ~Country();

        string getName() const;
        unsigned getDays() const;

        void setDays(unsigned days);
        
        // friend bool operator<( const Country& lhs , const Country& rhs );
        // friend bool operator>( const Country& lhs , const Country& rhs );
        // friend bool operator==( const Country& lhs , const Country& rhs );
        // friend bool operator!=( const Country& lhs , const Country& rhs );

};

#endif