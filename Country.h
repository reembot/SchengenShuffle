#include <string>
using namespace std;


class Country {

    private:
        string   Name;
        //unsigned Days;
    
    public:
        Country();
        Country( string name );
        Country(const Country& copyC);
        
        void setName(string name);

        string getName() const;
        
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


// Copy Constructor
    Country::Country(const Country& copyC) {
    Name = copyC.Name;
    }

    void Country::setName(string name) {
        Name = name;
    }


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