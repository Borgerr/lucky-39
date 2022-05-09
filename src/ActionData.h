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
protected:
	std::istream& mIs;
	std::ostream& mOs;
	bool done;
	Deck* mDeck;
};

#endif //__ACTIONDATA_
