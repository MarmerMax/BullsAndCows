#pragma once
#include <string>
#include <vector>
#include "Guesser.hpp"
#include "calculate.hpp"
#include <iostream>
using namespace std;

class SmartGuesser: public bullpgia::Guesser{
    public:
    int already_finded = 0;   //all pgia finded
    int * usedNums;           //[0: 0, 1: 1, 2: 0, 3: 0, 4: 0, 5: 1, 6: 1, 7: 0, 8: 0, 9: 1]
    int * answerArray;        //[0, 0, 0, 0]
    string last_try = "";
    int count_try = 0;       //all tries
    int current_index = 0;   //index of next place in final array
    int last_try_index = -1; //number in used numbers array

    SmartGuesser(): usedNums(new int [10]){
    };
    ~SmartGuesser(){
        delete[] answerArray;
        delete[] usedNums;
    };
    string guess() override;
    void startNewGame(uint length) override;  
    string createSmartGuess();
    void checkPgiot();  
};