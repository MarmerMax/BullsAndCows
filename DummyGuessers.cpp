#include "DummyGuessers.hpp"
#include <stdlib.h>
#include <string>
#include <stdexcept>
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

void bullpgia::Guesser::learn(string reply){
	int index_of_comma = 0;
	//find index of comma
	while(reply.at(index_of_comma) != ','){
		index_of_comma++;
	}
	//cut strings
	string str_bull = reply.substr(0, index_of_comma);
	string str_pgia = reply.substr(index_of_comma + 1, reply.length());
	//parse strings

	int temp_bull = atoi(str_bull.c_str());
	int temp_pgia = atoi(str_pgia.c_str());

	if(temp_bull + temp_pgia > this->length){
		throw out_of_range{"Sum of bull and pgia can't be more than length..."};
	}

	this->bull = temp_bull;
	this->pgia = temp_pgia;
}

void bullpgia::Guesser::startNewGame(uint length){
	this->length = length;
	this->pgia = 0;
	this->bull = 0; 
}