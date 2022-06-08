#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "ActionData.h"
#include "Deck.h"
#include "config.h"

int blackjack(ActionData& ad) {
	// I don't need your project guides!
	// I'll make my own project! With blackjack! And hookers!

	int result = 0;
	ad.getOS() << "Place your bets!" << std::endl;
	ad.getOS() << "Your balance is " << ad.getBalance() << "." << std::endl;
	
	int bet = getInteger(ad, "Bet: ");
	while (bet < 0 && bet > ad.getBalance()) {
		ad.getOS() << "Please enter a valid bet." << std::endl;
		ad.getOS() << "Your balance is " << ad.getBalance() << "." << std::endl;
		bet = getInteger(ad, "Bet: ");
	}
	std::vector<std::string> dealerHand = ad.getDeck().drawMultiple(2);
	std::vector<std::string> playerHand = ad.getDeck().drawMultiple(2);
	
	ad.getOS() << "Dealer shows: " << ad.getDeck().expandString(dealerHand[0]) << std::endl;
	
	if (bjHandValue(ad, dealerHand) == 21) {
		ad.getOS() << "Dealer's hand starts at 21. You lose." << std::endl;
		result = -bet;
	}

	ad.getOS() << "---------------------" << std::endl;
	ad.getOS() << "Your hand: " << ad.getDeck().expandString(playerHand[0]) << ", " << ad.getDeck().expandString(playerHand[1]) << std::endl;

	if (bjHandValue(ad, playerHand) == 21) {
		ad.getOS() << "You got a 21! Congratulations!" << std::endl;
		result = bet;
	}
	std::string choice = "";
	std::string newCard = "";	// only necessary if neither the dealer or the player hits
	while (choice != "stay" && bjHandValue(ad, playerHand) <= 21) {
		choice = getString(ad, "Hit or stay? ");
		while (choice != "hit" && choice != "stay") {
			ad.getOS() << "Please enter a valid option." << std::endl;
			choice = getString(ad, "Hit or stay? ");
		}
		if (choice == "hit") {
			newCard = ad.getDeck().draw();
			ad.getOS() << "You're dealt a " << ad.getDeck().expandString(newCard) << "." << std::endl;
			playerHand.push_back(newCard);
		}
	}

	// dealer stays on 17 or more
	while (bjHandValue(ad, dealerHand) < 17) {
		newCard = ad.getDeck().draw();
		dealerHand.push_back(newCard);
	}

	// game results
	
	ad.getOS() << "---------------------" << std::endl;
	ad.getOS() << "Dealer hand: " << ad.getDeck().expandHand(dealerHand) << "." << std::endl;
	ad.getOS() << "Player hand: " << ad.getDeck().expandHand(playerHand) << "." << std::endl;

	if (bjHandValue(ad, dealerHand) > 21) {
		ad.getOS() << "Dealer bust! You win!" << std::endl;
		result = bet;
	}else if (bjHandValue(ad, dealerHand) < bjHandValue(ad, playerHand)) {
		ad.getOS() << "Higher hand value than the dealer! You win!" << std::endl;
		result = bet;
	}else if (bjHandValue(ad, dealerHand) == bjHandValue(ad, playerHand)) {
		ad.getOS() << "Push." << std::endl;
		result = 0;
	}else if (bjHandValue(ad, playerHand) > 21) {
		ad.getOS() << "Bust, you lose." << std::endl;
		result = -bet;
	}else if (bjHandValue(ad, dealerHand) > bjHandValue(ad, playerHand)) {
		ad.getOS() << "The dealer has a higher hand value, you lose." << std::endl;
		result = -bet;
	}
	return result;
}

int bjHandValue(ActionData& ad, const std::vector<std::string>& hand) {
	unsigned int i;
	int total = 0;
	for (i = 0; i < hand.size(); i++) {
		total += ad.getDeck().blackjackValue(hand[i]);
	}
	return total;
}
