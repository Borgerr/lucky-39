#variables
#variable name := tags
#used with $(VARNAME)
CXX := $(CXX)
CXXFLAGS := -Wall -Wextra -Werror -Wpedantic
#CXXFLAGS := -Wall -Wextra -Werror -Wpedantic -g #debugger
#executable programs

all: casino

casino: casino.o ActionData.o config.o MenuData.o user_io.o Deck.o options.o
	$(CXX) $(CXXFLAGS) -o casino $^



#object files

casino.o: casino.cpp
	$(CXX) $(CXXFLAGS) -c -o casino.o casino.cpp

ActionData.o: ActionData.cpp ActionData.h
	$(CXX) $(CXXFLAGS) -c -o ActionData.o ActionData.cpp

config.o: config.cpp config.h
	$(CXX) $(CXXFLAGS) -c -o config.o config.cpp

MenuData.o: MenuData.cpp MenuData.h
	$(CXX) $(CXXFLAGS) -c -o MenuData.o MenuData.cpp

user_io.o: user_io.cpp config.h
	$(CXX) $(CXXFLAGS) -c -o user_io.o user_io.cpp

Deck.o: Deck.cpp Deck.h
	$(CXX) $(CXXFLAGS) -c -o Deck.o Deck.cpp

options.o: options.cpp config.h
	$(CXX) $(CXXFLAGS) -c -o options.o options.cpp

games.o: games.cpp config.h
	$(CXX) $(CXXFLAGS) -c -o games.o games.cpp





clean:
	rm -f *.o
	rm -f casino
