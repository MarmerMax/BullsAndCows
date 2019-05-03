#include <string>
#include "SmartGuesser.hpp"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

string RemainsOfZero(int,string);
string concat_n_times(string,int);
string concat_arr_elements(int[],int);


int firstIn = 0;
int i = 0;
int j = 0;
int l = 0;
int countbull = 0;
int bull_in_arr;
string firstguess = "";
int nextguess = 0;


string SmartGuesser::guess(){
    firstIn++;
    if(firstIn == 1){
        bull_arr = new int[this->length];
        return firstguess = concat_n_times("1",this->length);
    }
    else if(this->length < 10){
        for(; i<this->length ; i++){
            while(j<10 && l<10){
                // cout << "i=" << i << ",j=" << j << ",l=" << l << endl;
                if(this->bull > 0){
                    string str = concat_n_times(to_string(l),i) + to_string(j) + concat_n_times(to_string(l),length-i-1);
                    countbull++;
                    l++;
                    if(countbull==10 && l==10){
                        bull_arr[i] = j;
                        bull_in_arr++;
                        if(bull_in_arr == this->length){
                            return concat_arr_elements(bull_arr,this->length);
                        }
                        // cout << bull_arr[0] << " " << bull_arr[1] << " " << bull_arr[2] << " " << endl;
                        countbull=0;
                    }
                    if(l==10 && j<10){
                        j++;
                        l=0;
                    }
                    return str;
                }
                if(this->bull == 0){
                    countbull=0;
                    l = 0;
                    j++;
                    if(j==10){
                        j=0;
                        break;
                    }
                    string str = concat_n_times(to_string(l),i) + to_string(j) + concat_n_times(to_string(l),length-i-1);
                    return str;
                }
            }
        }
    }
    else{
        for(; i<pow(10,this->length) ; i++){
            nextguess++;
            string s_nextguess = to_string(nextguess);
            int diffLen = this->length - s_nextguess.length();
            if(diffLen == 0){
                return s_nextguess;
            }
            else if(diffLen > 0){
                s_nextguess= RemainsOfZero(diffLen,s_nextguess);
                return s_nextguess;
            }
        }
    }
    return "";
}
// string SmartGuesser::guess(){
//     for(; i<this->length*100 ; i++){
//         nextguess++;
//         string s_nextguess = to_string(nextguess);
//         int diffLen = this->length - s_nextguess.length();
//         if(diffLen == 0){
//             return s_nextguess;
//         }
//         else if(diffLen > 0){
//             s_nextguess= RemainsOfZero(diffLen,s_nextguess);
//             return s_nextguess;
//         }
//     }
// 	return "";
// }


string RemainsOfZero(int amount, string str){
    for(int k=0 ; k<amount ; k++){
        str = "0"+str;
    }
    return str;
}

string concat_n_times(string str,int n){
    string ans = "";
    for(int t=0 ; t<n ; t++){
        ans += str;
    }
    return ans;
}

string concat_arr_elements(int* arr, int len){
    string ans = "";
    for(int x=0 ; x<len ; x++){
        ans += to_string(arr[x]);
    }
    return ans;
}
string parseIntegerToString(int num){
    return to_string(num);
}

int parseStringToInteger(string str){
    int ans = atoi(str.c_str());
    return ans;
}
