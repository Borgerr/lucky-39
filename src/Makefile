#variables
#variable name := tags
#used with $(VARNAME)
CXX := $(CXX)
CXXFLAGS := -Wall -Wextra -Werror -Wpedantic

#executable programs

all: casino

casino: casino.o ActionData.o config.o MenuData.o user_io.o Deck.o options.o
	$(CXX)  -o casino $^



#object files

casino.o: casino.cpp
	$(CXX)  -c -o casino.o casino.cpp

ActionData.o: ActionData.cpp ActionData.h
	$(CXX)  -c -o ActionData.o ActionData.cpp

config.o: config.cpp config.h
	$(CXX)  -c -o config.o config.cpp

MenuData.o: MenuData.cpp MenuData.h
	$(CXX)  -c -o MenuData.o MenuData.cpp

user_io.o: user_io.cpp config.h
	$(CXX)  -c -o user_io.o user_io.cpp

Deck.o: Deck.cpp Deck.h
	$(CXX)  -c -o Deck.o Deck.cpp

options.o: options.cpp config.h
	$(CXX)  -c -o options.o options.cpp



clean:
	rm -f *.o
	rm -f casino
