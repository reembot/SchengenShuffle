#include <string>
using namespace std;


class Country {

    private:
        string   Name;
        unsigned Days;
    
    public:
        Country();
        Country( string name, unsigned days );
        
        void setName(string name);
        void setDays(unsigned days);

        string getName();
        unsigned getDays();
        
        friend bool operator<( const Country& lhs , const Country& rhs );
        friend bool operator>( const Country& lhs , const Country& rhs );
        friend bool operator==( const Country& lhs , const Country& rhs );
        friend bool operator!=( const Country& lhs , const Country& rhs );

};

    Country::Country() {
    }

    Country::Country(string name, unsigned days) {
        Name = name;
        Days = days;
    }

    void Country::setName(string name) {
        Name = name;
    }

    void Country::setDays(unsigned days) {
        Days = days;
    }

    unsigned Country::getDays() {
        return Days;
    }

    string Country::getName() {
        return Name;
    }



    // Overload operators for vertex ordering
    bool operator<( const Country& lhs , const Country& rhs ) {
        
        return lhs.getDays() < rhs.getDays();
    }

    bool operator>(  const Country& lhs , const Country& rhs ) {
        
        return rhs < lhs;   //return counterpart overload
    }

// Overload operators for vertex identification
    bool operator==( const Country& lhs , const Country& rhs ) {

        return lhs.getDays() == rhs.getDays();
    }

    bool operator!=( const Country& lhs , const Country& rhs ) {

        return !(lhs.getDays() == rhs.getDays());
    }