#include "calculate.hpp"
#include <string>
using namespace std;

string calculateBullAndPgia(const string& choise, const string& guess){

    int bull = 0;
    int pgia = 0;
    int length = choise.length();

    int * checked1 = new int[length];//array of checked chars in choise
    int * checked2 = new int[length];//array of checked chars in guess

    for(int i = 0; i < length; i++) { //initialization
        checked1[i] = 0;
        checked2[i] = 0;
    }

    for(int i = 0; i < length; i++){ //find bull
        if(choise.at(i) == guess.at(i)){
            bull++;
            checked1[i] = 1;
            checked2[i] = 1;
        }
    }

    if(bull == length){//all bull
        return to_string(bull) + "," + to_string(pgia);
    }
    else{
        for(int i = 0; i < length; i++){//find pgia
            if(checked1[i] == 0){
                for(int j = 0; j < length; j++){
                    if(checked2[j] == 0){
                        if(i != j && choise.at(i) == guess.at(j)){
                            pgia++;
                            checked2[j] = 1;
                            break;
                        }
                    }
                }
            }
        }
        free(checked1);
        free(checked2);
        return to_string(bull) + "," + to_string(pgia);
    }
}