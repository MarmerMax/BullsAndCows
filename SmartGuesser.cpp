#include <string>
#include "SmartGuesser.hpp"
#include <string>
using namespace std;

string SmartGuesser::guess(){


	return "";
}

void SmartGuesser::startNewGame(uint length){
    this->bull_arr = new int[length];
    this->pgia_arr = new int[length];

    for(int i =0; i < length; i++){
        this->bull_arr[i] = -1;
        this->pgia_arr[i] = -1;
    }
}

string parseIntegerToString(int num){
    return to_string(num);
}

int parseStringToInteger(string str){
    int ans = atoi(str.c_str());
    return ans;
}

int firstableTry(int last, int length){
    return 0;
}

int generateTry(int length){
    return 0;
}
