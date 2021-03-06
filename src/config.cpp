#include <iostream>
#include "config.h"
#include "MenuData.h"
#include "ActionData.h"
#include "Deck.h"

void showMenu(MenuData& md, ActionData& ad) {
	std::vector<std::string> commands = md.getNames();
	unsigned int i;				// iterator
	unsigned int len = commands.size();	// iterated
	std::string name;
	for (i=0; i < len; i++) {
		name = commands[i];
		ad.getOS() << name << ") " << md.getDescription(name) << std::endl;
	}
}

void takeAction(const std::string& choice, MenuData& md, ActionData& ad) {
	ActionFunctionType func = md.getFunction(choice);
	if (func != 0) {
		func(ad);
	}else if (choice == "menu") {
		showMenu(md, ad);
	}else {
		ad.getOS() << "Unknown action '" << choice << "'." << std::endl;
	}
}

int casinoMenu(std::istream& is, std::ostream& os) {
	ActionData ad(is, os);
	MenuData md;
	Deck *ptr;
	ptr = new Deck;
	ad.setDeck(ptr);
	configureMenu(md);
	std::string choice;

	while ((!ad.getDone()) && (ad.getIS().good())) {
		choice = getChoice(ad);
		takeAction(choice, md, ad);
	}
	return 0;
}

void configureMenu(MenuData& md) {
	//USE THE FOLLOWING TEMPLATE:
	//md.addAction("name", function, "Long description.");
	md.addAction("shuffle", shuffleDeck, "Shuffle the current deck.");
	md.addAction("balance", getBalance, "View your current balance at the Lucky-39 casino.");
	md.addAction("top-card", topCard, "Look at the top card in the deck without drawing it.");
	md.addAction("draw-card", drawCard, "Draw a card from the top of the deck.");
	md.addAction("draw-multiple", drawMultiple, "Draw multiple cards from the deck and show them all.");

	md.addAction("blackjack", playBlackjack, "Play a round of blackjack with the Lucky-39 dealer.");

	//try to retain some kind of organization in this menu. Quit should be at the bottom of the list.
	md.addAction("quit", quit, "Exit the program.");
}
