#pragma once
#include <string>
using namespace std;

namespace bullpgia{
    class Guesser{
        public:
        uint length;
        int bull = 0;
        int pgia = 0;
        virtual string guess() = 0;
        virtual void startNewGame(uint length);
        void learn(string reply);
    };
}
