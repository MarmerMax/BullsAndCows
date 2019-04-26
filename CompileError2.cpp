#pragma once
/**
 * A program that should not compile.
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "Guesser.hpp"
using namespace bullpgia;

int main() {
	Guesser g;
}
