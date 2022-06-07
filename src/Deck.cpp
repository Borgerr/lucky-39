#include <cstdlib>
#include <string>
#include "Deck.h"

Deck::Deck() {
	shuffle();
	// initialize valueInitials keys and values
	valueInitials['A'] = "Ace";
	valueInitials['2'] = "Two";
	valueInitials['3'] = "Three";
	valueInitials['4'] = "Four";
	valueInitials['5'] = "Five";
	valueInitials['6'] = "Six";
	valueInitials['7'] = "Seven";
	valueInitials['8'] = "Eight";
	valueInitials['9'] = "Nine";
	valueInitials['T'] = "Ten";
	valueInitials['J'] = "Jack";
	valueInitials['Q'] = "Queen";
	valueInitials['K'] = "King";
	
	// initialize blackjackValues keys and values
	blackjackValues['A'] = 11;
	blackjackValues['2'] = 2;
	blackjackValues['3'] = 3;
	blackjackValues['4'] = 4;
	blackjackValues['5'] = 5;
	blackjackValues['6'] = 6;
	blackjackValues['7'] = 7;
	blackjackValues['8'] = 8;
	blackjackValues['9'] = 9;
	blackjackValues['T'] = 10;
	blackjackValues['J'] = 10;
	blackjackValues['Q'] = 10;
	blackjackValues['K'] = 10;
}

Deck::~Deck() {

}

std::string Deck::draw() {
	std::string returned = "";	// indicates empty deck
	if (!mDeckList.empty()) {
		returned = getTop();
		mDeckList.pop_back();
	}
	return returned;
}

std::string Deck::getTop() const {
	std::string returned = "";	// indicates empty deck
	if (!mDeckList.empty()) {
		returned = mDeckList.back();
	}
	return returned;
}

std::vector<std::string> Deck::drawMultiple(const int& size) {
	int i;
	std::vector<std::string> returned;
	//returned.resize(size);	// vector::push_back() method resizes the vector with the next iterated number anyway.
	std::string tempCard;
	for (i = 0; i < size; i++) {
		tempCard = draw();
		returned.push_back(tempCard);
	}
	return returned;
}

void Deck::shuffle() {
	int i, cardNum;
	std::string cardName;
	mDeckList.resize(52);
	for (i = 0; i < 52; i++) {
		cardNum = std::rand() % 52 + 1;	// generate random number between 1 and 52
		cardName = intToCard(cardNum);
		mDeckList.push_back(cardName);
	}
}

std::string Deck::intToCard(const int& value) const {
	// this was to curb having to copy these cases everywhere.
	std::string cardName = "";
		switch (value) {
			// each card in a standard deck of cards is assigned a number
			// between 1 and 52.
			// card values are interpreted with two characters at the beginning of the string,
			// and then the full name of the card's suit is followed afterward.
			case 1: // ace
				cardName = "AClubs";
				break;
			case 2: // 2
				cardName = "2Clubs";
				break;
			case 3: // 3
				cardName = "3Clubs";
				break;
			case 4: // 4
				cardName = "4Clubs";
				break;
			case 5: // 5
				cardName = "5Clubs";
				break;
			case 6: // 6
				cardName = "6Clubs";
				break;
			case 7: // 7
				cardName = "7Clubs";
				break;
			case 8: // 8
				cardName = "8Clubs";
				break;
			case 9: // 9
				cardName = "9Clubs";
				break;
			case 10:// 10
				cardName = "TClubs";
				break;
			case 11:// jack
				cardName = "JClubs";
				break;
			case 12:// queen
				cardName = "QClubs";
				break;
			case 13:// king
				cardName = "KClubs";
				break;
			case 14:
				cardName = "ASpades";
				break;
			case 15:
				cardName = "2Spades";
				break;
			case 16:
				cardName = "3Spades";
				break;
			case 17:
				cardName = "4Spades";
				break;
			case 18:
				cardName = "5Spades";
				break;
			case 19:
				cardName = "6Spades";
				break;
			case 20:
				cardName = "7Spades";
				break;
			case 21:
				cardName = "8Spades";
				break;
			case 22:
				cardName = "9Spades";
				break;
			case 23:
				cardName = "TSpades";
				break;
			case 24:
				cardName = "JSpades";
				break;
			case 25:
				cardName = "QSpades";
				break;
			case 26:
				cardName = "KSpades";
				break;
			case 27:
				cardName = "AHearts";
				break;
			case 28:
				cardName = "2Hearts";
				break;
			case 29:
				cardName = "3Hearts";
				break;
			case 30:
				cardName = "4Hearts";
				break;
			case 31:
				cardName = "5Hearts";
				break;
			case 32:
				cardName = "6Hearts";
				break;
			case 33:
				cardName = "7Hearts";
				break;
			case 34:
				cardName = "8Hearts";
				break;
			case 35:
				cardName = "9Hearts";
				break;
			case 36:
				cardName = "THearts";
				break;
			case 37:
				cardName = "JHearts";
				break;
			case 38:
				cardName = "QHearts";
				break;
			case 39:
				cardName = "KHearts";
				break;
			case 40:
				cardName = "ADiamonds";
				break;
			case 41:
				cardName = "2Diamonds";
				break;
			case 42:
				cardName = "3Diamonds";
				break;
			case 43:
				cardName = "4Diamonds";
				break;
			case 44:
				cardName = "5Diamonds";
				break;
			case 45:
				cardName = "6Diamonds";
				break;
			case 46:
				cardName = "7Diamonds";
				break;
			case 47:
				cardName = "8Diamonds";
				break;
			case 48:
				cardName = "9Diamonds";
				break;
			case 49:
				cardName = "TDiamonds";
				break;
			case 50:
				cardName = "JDiamonds";
				break;
			case 51:
				cardName = "QDiamonds";
				break;
			case 52:
				cardName = "KDiamonds";
				break;
		}
	return cardName;
}

std::string Deck::expandString(const std::string& value) {
	// Value string should be given as the same kind of output given by intToCard.
	// Function aims to return a more expanded version of the input value string,
	// making interpretation and output easier in the long run.
	char firstChar = value[0];			// gives first character in value string
	std::string returned = "";			// added onto and returned
	returned += valueInitials[firstChar];
	returned += (" of " + value.substr(1, (value.length() - 1)));
	return returned;
}

int Deck::blackjackValue(const std::string& value) {
	char firstChar = value[0];
	return blackjackValues[firstChar];
}
