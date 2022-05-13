#ifndef __ACTIONDATA_
#define __ACTIONDATA_

#include <iostream>
#include "Deck.h"

class ActionData {
public:
	ActionData(std::istream& is, std::ostream& os);
	std::istream& getIS();
	std::ostream& getOS();
	bool getDone() const;
	void setDone();
	Deck& getDeck();
	void setDeck(Deck* deck);
	~ActionData();
	int getBalance() const;
	void setBalance(const int& balance);
protected:
	std::istream& mIs;
	std::ostream& mOs;
	bool done;
	Deck* mDeck;
	int mBalance;
};

#endif //__ACTIONDATA_
