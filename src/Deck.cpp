#include <cstdlib>
#include <string>
#include "Deck.h"

Deck::Deck() {
	shuffle();
}

Deck::~Deck() {

}

std::string Deck::draw() {
	if (!mDeckList.empty()) {
		return mDeckList.pop_back();
	}
	return "";	// indicates empty deck
}

std::string& Deck::getTop() const {
	if (!.MdeckList.empty()) {
		return mDeckList.back();
	}
	return "";	// indicates empty deck
}

std::vector<std::string> Deck::drawMultiple(const int& size) {
	int i;
	std::vector<std::string> returned;
	returned.resize(size);
	for (i = 0; i < size; i++) {
		returned.push_back(mDeckList[i]);
	}
}

void Deck::shuffle() {
	int i, cardNum;
	std::string cardName;
	mDeckList.resize(52);
	for (i = 0; i < 52; i++) {
		cardNum = std::rand() % 52 + 1;	// generate random number between 1 and 52
		cardName = intToCard(cardNum);
		mDeckList.pop_back(cardName);
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
			case 2: // 2
				cardName = "02Clubs";
			case 3: // 3
				cardName = "03Clubs";
			case 4: // 4
				cardName = "04Clubs";
			case 5: // 5
				cardName = "05Clubs";
			case 6: // 6
				cardName = "06Clubs";
			case 7: // 7
				cardName = "07Clubs";
			case 8: // 8
				cardName = "08Clubs";
			case 9: // 9
				cardName = "09Clubs";
			case 10:// 10
				cardName = "10Clubs";
			case 11:// jack
				cardName = "JaClubs";
			case 12:// queen
				cardName = "QuClubs";
			case 13:// king
				cardName = "KiClubs";
			case 14:
				cardName = "AcSpades";
			case 15:
				cardName = "02Spades";
			case 16:
				cardName = "03Spades";
			case 17:
				cardName = "04Spades";
			case 18:
				cardName = "05Spades";
			case 19:
				cardName = "06Spades";
			case 20:
				cardName = "07Spades";
			case 21:
				cardName = "08Spades";
			case 22:
				cardName = "09Spades";
			case 23:
				cardName = "10Spades";
			case 24:
				cardName = "JaSpades";
			case 25:
				cardName = "QuSpades";
			case 26:
				cardName = "KiSpades";
			case 27:
				cardName = "AcHearts";
			case 28:
				cardName = "02Hearts";
			case 29:
				cardName = "03Hearts";
			case 30:
				cardName = "04Hearts";
			case 31:
				cardName = "05Hearts";
			case 32:
				cardName = "06Hearts";
			case 33:
				cardName = "07Hearts";
			case 34:
				cardName = "08Hearts";
			case 35:
				cardName = "09Hearts";
			case 36:
				cardName = "10Hearts";
			case 37:
				cardName = "JaHearts";
			case 38:
				cardName = "QuHearts";
			case 39:
				cardName = "KiHearts";
			case 40:
				cardName = "AcDiamonds";
			case 41:
				cardName = "02Diamonds";
			case 42:
				cardName = "03Diamonds";
			case 43:
				cardName = "04Diamonds";
			case 44:
				cardName = "05Diamonds";
			case 45:
				cardName = "06Diamonds";
			case 46:
				cardName = "07Diamonds";
			case 47:
				cardName = "08Diamonds";
			case 48:
				cardName = "09Diamonds";
			case 49:
				cardName = "10Diamonds";
			case 50:
				cardName = "JaDiamonds";
			case 51:
				cardName = "QuDiamonds";
			case 52:
				cardName = "KiDiamonds";
		}
	return cardName;
}
