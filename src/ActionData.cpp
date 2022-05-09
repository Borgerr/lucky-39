#include <iostream>
#include "ActionData.h"

ActionData::ActionData(std::istream& is, std::ostream& os) 
	: mIs(is), mOs(os), done(false), mDeck(0) {
}

std::istream& ActionData::getIS() {
	return mIs;
}

std::ostream& ActionData::getOS() {
	return mOs;
}

bool ActionData::getDone() const {
	return done;
}

void ActionData::setDone() {
	done = true;
}

ActionData::~ActionData() {
	if (mDeck != 0) {
		delete mDeck;
	}
}

Deck& ActionData::getDeck() {
	return *mDeck;
}

void ActionData::setDeck(Deck* deck) {
	if (mDeck != 0) {
		delete mDeck;
	}
	mDeck = deck;
}
