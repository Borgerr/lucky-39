#include <iostream>
#include <string>
#include "ActionData.h"
#include "Deck.h"
#include "config.h"

void shuffleDeck(ActionData& ad) {
	ad.getDeck().shuffle();
}

void topCard(ActionData& ad) {
	std::string topVal = ad.getDeck().getTop();
	ad.getOS() << "The " << ad.getDeck().expandString(topVal) << " is at the top of the deck." << std::endl;
}

void drawCard(ActionData& ad) {
	std::string topVal = ad.getDeck().draw();
	if (topVal == "") {
		ad.getOS() << "Deck empty. Shuffling..." << std::endl;
		ad.getDeck().shuffle();
		ad.getOS() << std::endl;
	}
	ad.getOS() << "You drew the " << ad.getDeck().expandString(ad.getDeck().draw()) << "." << std::endl;
}
