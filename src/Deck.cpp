#include <cstdlib>
#include <string>
#include "Deck.h"

Deck::Deck() {
	shuffle();
}

Deck::~Deck() {

}

std::string Deck::draw() {
	std::string returned = "";
	if (!mDeckList.empty()) {
		returned = mDeckList.back();
		mDeckList.pop_back();
		return returned;
	}
	return returned;	// indicates empty deck
}

std::string Deck::getTop() const {
	std::string returned = "";
	if (!mDeckList.empty()) {
		returned = mDeckList.back();
	}
	return returned;	// indicates empty deck
}

std::vector<std::string> Deck::drawMultiple(const int& size) {
	int i;
	std::vector<std::string> returned;
	returned.resize(size);
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
				cardName = "AcClubs";
				break;
			case 2: // 2
				cardName = "02Clubs";
				break;
			case 3: // 3
				cardName = "03Clubs";
				break;
			case 4: // 4
				cardName = "04Clubs";
				break;
			case 5: // 5
				cardName = "05Clubs";
				break;
			case 6: // 6
				cardName = "06Clubs";
				break;
			case 7: // 7
				cardName = "07Clubs";
				break;
			case 8: // 8
				cardName = "08Clubs";
				break;
			case 9: // 9
				cardName = "09Clubs";
				break;
			case 10:// 10
				cardName = "10Clubs";
				break;
			case 11:// jack
				cardName = "JaClubs";
				break;
			case 12:// queen
				cardName = "QuClubs";
				break;
			case 13:// king
				cardName = "KiClubs";
				break;
			case 14:
				cardName = "AcSpades";
				break;
			case 15:
				cardName = "02Spades";
				break;
			case 16:
				cardName = "03Spades";
				break;
			case 17:
				cardName = "04Spades";
				break;
			case 18:
				cardName = "05Spades";
				break;
			case 19:
				cardName = "06Spades";
				break;
			case 20:
				cardName = "07Spades";
				break;
			case 21:
				cardName = "08Spades";
				break;
			case 22:
				cardName = "09Spades";
				break;
			case 23:
				cardName = "10Spades";
				break;
			case 24:
				cardName = "JaSpades";
				break;
			case 25:
				cardName = "QuSpades";
				break;
			case 26:
				cardName = "KiSpades";
				break;
			case 27:
				cardName = "AcHearts";
				break;
			case 28:
				cardName = "02Hearts";
				break;
			case 29:
				cardName = "03Hearts";
				break;
			case 30:
				cardName = "04Hearts";
				break;
			case 31:
				cardName = "05Hearts";
				break;
			case 32:
				cardName = "06Hearts";
				break;
			case 33:
				cardName = "07Hearts";
				break;
			case 34:
				cardName = "08Hearts";
				break;
			case 35:
				cardName = "09Hearts";
				break;
			case 36:
				cardName = "10Hearts";
				break;
			case 37:
				cardName = "JaHearts";
				break;
			case 38:
				cardName = "QuHearts";
				break;
			case 39:
				cardName = "KiHearts";
				break;
			case 40:
				cardName = "AcDiamonds";
				break;
			case 41:
				cardName = "02Diamonds";
				break;
			case 42:
				cardName = "03Diamonds";
				break;
			case 43:
				cardName = "04Diamonds";
				break;
			case 44:
				cardName = "05Diamonds";
				break;
			case 45:
				cardName = "06Diamonds";
				break;
			case 46:
				cardName = "07Diamonds";
				break;
			case 47:
				cardName = "08Diamonds";
				break;
			case 48:
				cardName = "09Diamonds";
				break;
			case 49:
				cardName = "10Diamonds";
				break;
			case 50:
				cardName = "JaDiamonds";
				break;
			case 51:
				cardName = "QuDiamonds";
				break;
			case 52:
				cardName = "KiDiamonds";
				break;
		}
	return cardName;
}
