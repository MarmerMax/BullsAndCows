#pragma once
#include "Guesser.hpp"
using std::string;

/**
 * ConstantGuesser is a guesser that always guesses the same string. 
 */
class ConstantGuesser: public bullpgia::Guesser {
	string myConstantString;
	public:
	ConstantGuesser(const string& constantString) {
		myConstantString = constantString; 
		this->length = constantString.length();
	}
	string guess() override {
		return myConstantString;
	}
};

/**
 * RandomGuesser is a guesser that guesses a random string.
 */
class RandomGuesser: public bullpgia::Guesser {
	public:
	string guess() override;
};

// /**
//  * SmartGuesser is a guesser that guesses a random string by smart technic.
//  */
// class SmartGuesser: public bullpgia::Guesser{
// 	public:
// 	string guess() override;
// };
