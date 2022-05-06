#variables
#variable name := tags
#used with $(VARNAME)
CXXFLAGS := -Wall -Wextra -Werror -Wpedantic

#executable programs

all: casino

casino: casino.o ActionData.o config.o MenuData.o user_io.o Deck.o
	g++ $(CXXFLAGS) -o casino $^



#object files

casino.o: casino.cpp
	g++ $(CXXFLAGS) -c -o casino.o casino.cpp

ActionData.o: ActionData.cpp ActionData.h
	g++ $(CXXFLAGS) -c -o ActionData.o ActionData.cpp

config.o: config.cpp config.h
	g++ $(CXXFLAGS) -c -o config.o config.cpp

MenuData.o: MenuData.cpp MenuData.h
	g++ $(CXXFLAGS) -c -o MenuData.o MenuData.cpp

user_io.o: user_io.cpp config.h
	g++ $(CXXFLAGS) -c -o user_io.o user_io.cpp

Deck.o: Deck.cpp Deck.h
	g++ $(CXXFLAGS) -c -o Deck.o Deck.cpp



clean:
	rm -f *.o
	rm casino
