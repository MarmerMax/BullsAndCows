#include <string>
#include "SmartGuesser.hpp"
#include <string>
using namespace std;

string SmartGuesser::guess(){
	return "";
}

void SmartGuesser::startNewGame(uint length){
   
}

string parseIntegerToString(int num){
    return to_string(num);
}

int parseStringToInteger(string str){
    int ans = atoi(str.c_str());
    return ans;
}
