#include <iostream>
#include "ActionData.h"

ActionData::ActionData(std::istream& is, std::ostream& os) 
	: mIs(is), mOs(os), done(false) {
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

}
