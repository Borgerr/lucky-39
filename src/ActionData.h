#ifndef __ACTIONDATA_
#define __ACTIONDATA_

#include <iostream>

class ActionData {
public:
	ActionData(std::istream& is, std::ostream& os);
	std::istream& getIS();
	std::ostream& getOS();
	bool getDone() const;
	void setDone();
	~ActionData();
protected:
	std::istream& mIs;
	std::ostream& mOs;
	bool done;
};

#endif //__ACTIONDATA_
