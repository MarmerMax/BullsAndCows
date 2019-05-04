#include "SmartGuesser.hpp"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

//this function return simple string like '000', '1111', '3333'
//argumnents: length of string, digit of this string
string createSimpleGuess(uint size, char a); 

//generate final answer
string generateAnswer(int * arr, int size);

string SmartGuesser::guess(){
    if(this->count_try == 0){//if first try return '0' * length
        this->count_try++;
        return createSimpleGuess(this->length, '0');
    }
    else{
        checkPgiot(); //check pgiot of learn function to usedNums array
        if(this->already_finded < this->length){ //if already we didn't find all used numbers
            if(this->count_try >= 1 && this->count_try <= 9){ //only if we between 1-9 steps
                this->count_try++; //try ++
                switch (this->count_try - 1){
                    case 1: return createSimpleGuess(this->length, '1');
                    case 2: return createSimpleGuess(this->length, '2');;
                    case 3: return createSimpleGuess(this->length, '3');;
                    case 4: return createSimpleGuess(this->length, '4');;
                    case 5: return createSimpleGuess(this->length, '5');;
                    case 6: return createSimpleGuess(this->length, '6');;
                    case 7: return createSimpleGuess(this->length, '7');;
                    case 8: return createSimpleGuess(this->length, '8');;
                    case 9: return createSimpleGuess(this->length, '9');;
                }
            }
        }
        else{
            if(this->current_index < this->length){ //if index not equal to length so try again
                return createSmartGuess();          
            }
            else{
                return generateAnswer(this->answerArray, this->length);
            }
        }
    }
}

void SmartGuesser::startNewGame(uint length){
    // delete[] answerArray;
    this->length = length;
    this->pgia = 0;
    this->bull = 0;
    this->answerArray = new int(length); 
    this->count_try = 0;
    this->current_index= 0;
    this->last_try_index = -1;
    this->already_finded = 0;
    for(int i = 0; i < length; i++){
        answerArray[i] = 0;
    }
    for(int i = 0; i < 10; i++){
        usedNums[i] = 0;
    }
}

string SmartGuesser::createSmartGuess(){
    //create string from used number
    string temp = "";
    char ch = '*';
    for(int i = 0; i < this->current_index; i++){ //start to fill string by not used number
        temp += ch;
    }
    for(int i = 0; i < 10; i++){ //add used number to string
        if(usedNums[i] > 0 && i > this->last_try_index){
            temp += to_string(i);     //add this number to string
            this->last_try_index = i; //init last tried index
            break;
        }
    }
    for(int i = 0; i < this->length - this->current_index - 1; i++){ //fill untill end string by not used number
        temp += ch;
    }
    return temp;
}

void SmartGuesser::checkPgiot(){//check last guess
    if(this->already_finded < this->length){ //because '0000', 1111', '2222' ...                     
        int count = this->bull + this->pgia;
        if(count > 0){
            this->usedNums[count_try - 1] += count; //add in usesNum array appears of this number
            this->already_finded += count; //add to sum of all finded numbers
        }
    }
    else{
        int count = this->bull;
        if(count > 0){
            //put in answer array in current index the last try index 
            this->answerArray[this->current_index] = this->last_try_index;

            //-- count of used number on array of usedNum
            this->usedNums[this->last_try_index]--; 

            this->last_try_index = -1; //start from -1
            this->current_index++; //go to next index
        }
    }
}

//this function return simple string like '000', '1111', '3333'
//argumnents: length of string, digit of this string
string createSimpleGuess(uint size, char a){ 
    string temp = "";
    for(int i = 0; i < size; i++){
        temp += a;
    }
    return temp;
}

string generateAnswer(int * arr, int size){ //
    string temp = "";
    for(int i = 0; i < size; i++){
        temp += to_string(arr[i]);
    }
    return temp;
}

char findNotUsedNumber(int * arr, int size){ // this number is not exist in choose number
    for(int i = 1; i < size; i++){ //start from 1 for exactly change him
        if(arr[i] == 0){
            return i;
        }
    }
    return '*';
}


