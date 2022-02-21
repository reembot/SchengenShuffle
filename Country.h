#include <string>
using namespace std;


class Country {

    private:
        string   Name;
        //unsigned Days;
    
    public:
        Country();
        Country( string name );
        //Country( string name, unsigned days );
        Country(const Country& copyC);
        
        void setName(string name);
        //void setDays(unsigned days);

        string getName() const;
        //unsigned getDays() const;
        
        friend bool operator<( const Country& lhs , const Country& rhs );
        friend bool operator>( const Country& lhs , const Country& rhs );
        friend bool operator==( const Country& lhs , const Country& rhs );
        friend bool operator!=( const Country& lhs , const Country& rhs );

};

    Country::Country() {
    }

    Country::Country( string name ) {
        Name = name;
    }

    // Country::Country(string name, unsigned days) {
    //     Name = name;
    //     Days = days;
    // }

// Copy Constructor
    Country::Country(const Country& copyC) {
    Name = copyC.Name;
    //Days = copyC.Days;
    }

    void Country::setName(string name) {
        Name = name;
    }

    // void Country::setDays(unsigned days) {
    //     Days = days;
    // }

    // unsigned Country::getDays() const {
    //     return Days;
    // }

    string Country::getName() const {
        return Name;
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