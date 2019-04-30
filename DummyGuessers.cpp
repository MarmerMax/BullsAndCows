#include "DummyGuessers.hpp"
#include <stdlib.h>
#include <string>
// #include <stdexcept>
using namespace std;
using namespace bullpgia;

string RandomGuesser::guess() {
	string r = "";
	for (uint i = 0; i < this->length; ++i) {
		char c = '0' + (rand()%10);
		r += c;
	}
	return r;
}