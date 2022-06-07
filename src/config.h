#ifndef __CONFIG_H_
#define __CONFIG_H_

#include <iostream>		// std::istream, std::ostream
#include <string>		// std::string
#include "ActionData.h"
#include "MenuData.h"


// config.cpp declarations
void configureMenu(MenuData& md);

int casinoMenu(std::istream& is, std::ostream& os);

void showMenu(MenuData& md, ActionData& ad);

void takeAction(const std::string& choice, MenuData& md, ActionData& ad);

// user_io.cpp declarations
int getInteger(ActionData& ad, const std::string& prompt);

std::string getString(ActionData& ad, const std::string& prompt);

double getDouble(ActionData& ad, const std::string& prompt);

std::string getChoice(ActionData& ad);

void commentLine(ActionData& ad);

void quit(ActionData& ad);

// options.cpp declarations
void shuffleDeck(ActionData& ad);

void topCard(ActionData& ad);

void drawCard(ActionData& ad);

void drawMultiple(ActionData& ad);

void getBalance(ActionData& ad);

void playBlackjack(ActionData& ad);

// games.cpp declarations
int blackjack(ActionData& ad);

int bjHandValue(ActionData& ad, const std::vector<std::string>& hand);

#endif //__CONFIG_H_
