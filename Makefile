EXE = Schuffle
CXXFLAGS = 
LDLIBS =
CXX = g++

.PHONY: all
all: $(EXE)

schuffle: schuffle.cc
	$(CXX) $(CXXFLAGS) Schuffle.cc CountryMap.h Country.h $(LDLIBS) -o schuffle

.PHONY: clean
clean:
	rm -f $(EXE)