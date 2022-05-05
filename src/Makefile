#variables
#variable name := tags
#used with $(VARNAME)
CXXFLAGS := -Wall -Wextra -Werror -Wpedantic

#executable programs

all: casino

casino: casino.o
	g++ $(CXXFLAGS) -o casino casino.o



#object files

casino.o: casino.cpp
	g++ $(CXXFLAGS) -c -o casino.o casino.cpp



clean:
	rm -f *.o
	rm casino
