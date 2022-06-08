#ifndef __DECK_H_
#define __DECK_H_
#include <string>	// std::string
#include <vector>	// std::vector
#include <map>		// std::map

class Deck {
public:
	Deck();
	std::string draw();		// returns empty string if decklist empty
	std::string getTop() const;	// returns empty string if decklist empty
	std::vector<std::string> drawMultiple(const int& size);
	void shuffle();			// also resets entire deck to be max size
	std::string intToCard(const int& value) const;
	std::string expandString(const std::string& value);
	// given shortened string value, returns a lengthened string interpretation
	std::string expandHand(const std::vector<std::string>& hand);
	// does the same thing but for the entire hand, or list of condensed strings.
	~Deck();

	// card game conversion methods
	int blackjackValue(const std::string& value);
private:
	std::vector<std::string> mDeckList;
	std::map<char, std::string> valueInitials;
	std::map<char, int> blackjackValues;
	// values for cards disregarding suites for games like blackjack
};

#endif //__DECK_H_
