EXE = Schuffle
CXXFLAGS = 
LDLIBS =
CXX = g++

.PHONY: all
all: $(EXE)

schuffle: schuffle.cc
	$(CXX) $(CXXFLAGS) Schuffle.cc $(LDLIBS) -o schuffle

.PHONY: clean
clean:
	rm -f $(EXE)