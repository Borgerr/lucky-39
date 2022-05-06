#ifndef __DECK_H_
#define __DECK_H_
#include <string>	// std::string
#include <vector>	// std::vector

class Deck {
public:
	Deck();
	std::string draw();		// returns empty string if decklist empty
	std::string& getTop() const;	// returns empty string if decklist empty
	std::vector<std::string> drawMultiple(const int& size);
	void shuffle();
	std::string intToCard(const int& value) const;
	~Deck();
private:
	std::vector<std::string> mDeckList;
};

#endif //__DECK_H_
