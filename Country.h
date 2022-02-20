#include <string>
using namespace std;


class Country {

    private:
        string   Name;
        //unsigned Days;
    
    public:
        Country();
        Country( string name, unsigned days= 0 );
        
        void setName(string name);
        //void setDays(unsigned days);

        string getName();
        //unsigned getDays();


};

    Country::Country() : Days(0) {
    }

    Country::Country(string name, unsigned days= 0) {
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