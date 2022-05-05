#include <cstdlib>
#include <ctime>
#include <iostream>
#include "config.h"
int main() {
	std::srand(std::time(0));
	return casinoMenu(std::cin, std::cout);
}
