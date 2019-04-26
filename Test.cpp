/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */
#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};


		testcase.setname("Check Constant Choosers right creation")
		.CHECK_OUTPUT(c1234.choose(4), "1234")												//"1234", "1234"
		.CHECK_OUTPUT(c12345.choose(5), "12345")											//"12345", "12345"
		.CHECK_OUTPUT(c9999.choose(4), "9999")												//"9999", "9999"
		;

		testcase.setname("Check Constant Guessers right creation")
		.CHECK_OUTPUT(g1234.guess(), "1234")													//"1234", "1234"
		.CHECK_OUTPUT(g12345.guess(), "12345")												//"12345", "12345"
		.CHECK_OUTPUT(g9999.guess(), "9999")													//"9999", "9999"
		;

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1111"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("4321","1111"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9988","8899"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12321","32123"), "2,2")    // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12345","54321"), "1,4")    // 1 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12333","33321"), "1,4")    // 1 bull, 4 pgia	
		.CHECK_OUTPUT(calculateBullAndPgia("12345","67890"), "0,0")    // 0 bull, 0 pgia		
		;

		g1234.learn("2,2");																						 //set bull = 2, pgia = 2
		testcase.setname("Set bull and pgia for g1234")								 //
		.CHECK_EQUAL(g1234.bull, 2)																		 //2, 2
		.CHECK_EQUAL(g1234.pgia, 2)																		 //2, 2
		;

		g12345.learn("1,4");																					 //set bull = 1, pgia = 4
		testcase.setname("Learn bull and pgia for g12345")						 //
		.CHECK_EQUAL(g12345.bull, 1)																	 //1, 1
		.CHECK_EQUAL(g12345.pgia, 4)																	 //4, 4
		;

		g9999.learn("0,3");																						 //set bull = 1, pgia = 3
		testcase.setname("Learn bull and pgia for g9999")							 //
		.CHECK_EQUAL(g9999.bull, 0)																		 //1, 1
		.CHECK_EQUAL(g9999.pgia, 3)																		 //3, 3
		;

		testcase.setname("Catch exception - sum of bull and pgia more than length of chossen number")
		.CHECK_THROWS(g1234.learn("5,5"))															 //length=4, bull+pgia=10
		.CHECK_THROWS(g12345.learn("3,3"))														 //length=5, bull+pgia=6
		.CHECK_THROWS(g9999.learn("4,1"))															 //length=4, bull+pgia=5
		;

		g1234.startNewGame(4);																				 //g1234 new game
		testcase.setname("Start new game for g1234")									 //
		.CHECK_EQUAL(g1234.length, 4)																	 //4, 4
		.CHECK_EQUAL(g1234.bull, 0)																		 //0, 0
		.CHECK_EQUAL(g1234.pgia, 0)																		 //0, 0
		;

		g12345.startNewGame(5);																				 //g12345 new game
		testcase.setname("Start new game for g1234")									 //
		.CHECK_EQUAL(g12345.length, 5)																 //5, 5
		.CHECK_EQUAL(g12345.bull, 0)																   //0, 0
		.CHECK_EQUAL(g12345.pgia, 0)																	 //0, 0
		;

		g9999.startNewGame(4);																				 //g9999 new game
		testcase.setname("Start new game for g1234")                   //
		.CHECK_EQUAL(g9999.length, 4)																	 //4, 4
		.CHECK_EQUAL(g9999.bull, 0)																		 //0, 0
		.CHECK_EQUAL(g9999.pgia, 0)																		 //0, 0
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long)
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long)
		.CHECK_EQUAL(play(c12345, g12345, 4, 100), 1)    // guesser wins in one turn
		.CHECK_EQUAL(play(c9999, g9999, 4, 100), 1)      // guesser wins in one turn
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
