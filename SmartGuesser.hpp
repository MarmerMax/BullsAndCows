#pragma once
#include <string>
#include "Guesser.hpp"
#include "calculate.hpp"
using namespace std;

class SmartGuesser: public bullpgia::Guesser{
    public:
    int * bull_arr;
    int * pgia_arr;
    int last_try;
    SmartGuesser(): bull_arr(nullptr), pgia_arr(nullptr), last_try(-1) {};
    ~SmartGuesser(){
        delete[] bull_arr;
        delete[] pgia_arr;
    };
    string guess() override;
    void startNewGame(uint length) override;
};