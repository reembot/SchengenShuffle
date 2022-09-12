schuffle: Country.o CountryMap.o schuffle.o
	g++ Country.o CountryMap.o schuffle.o -o schuffle

schuffle.o: Schuffle.cpp CountryMap.h
	g++ -Wall -pedantic -g -std=c++17 -c schuffle.cpp

CountryMap.o: CountryMap.cpp CountryMap.h Country.h
	g++ -Wall -pedantic -g -std=c++17 -c CountryMap.cpp

Country.o: Country.cpp Country.h
	g++ -Wall -pedantic -g -std=c++17 -c Country.cpp

clean: 
	rm -f *.o main