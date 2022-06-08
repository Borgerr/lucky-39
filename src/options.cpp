#include <iostream>
#include <string>
#include <vector>
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
	std::string topVal = ad.getDeck().getTop();
	if (topVal == "") {
		ad.getOS() << "Deck empty. Shuffling..." << std::endl;
		ad.getDeck().shuffle();
		ad.getOS() << std::endl;
	}
	ad.getOS() << "You drew the " << ad.getDeck().expandString(ad.getDeck().draw()) << "." << std::endl;
}

void drawMultiple(ActionData& ad) {
	unsigned int handSize = getInteger(ad, "How many cards would you like to draw? ");
	std::vector<std::string> hand = ad.getDeck().drawMultiple(handSize);

	ad.getOS() << "Current hand: " << std::endl;
	unsigned int i;
	for (i = 0; i < handSize; i++) {
		ad.getOS() << "     " << i+1 << ": " << ad.getDeck().expandString(hand[i]) << std::endl;
	}
}

void getBalance(ActionData& ad) {
	ad.getOS() << "Current balance: " << ad.getBalance() << std::endl;
}

void playBlackjack(ActionData& ad) {
	ad.setBalance(ad.getBalance() + blackjack(ad));
	ad.getOS() << "Your current balance is now: " << ad.getBalance() << std::endl;
}
