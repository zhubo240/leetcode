//============================================================================
// Name        : 273-Integer-to-English-Words.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


class Solution {
public:
    string numberToWords(int num) {
    	//check
    	if(num == 0) return "zero";

    	string s;
    	num2str(num, s);

    	init();
    	for(unsigned i = 0; i < s.size(); i += 3){
    		readSection(s.substr(i, 3));
    	}
    	int n = s.size() % 3;
    	if(n != 0){
    		readSection(s.substr(s.size()-n, n));
    	}
    }
private:
    map<string, string> digits;
    map<string, string> tens;
    vector<string> base;

    string num2str(int num, string& s){
    	for(;num; num = num / 10){
    		s.push_back(num % 10 + '0');
    	}
    }

    void init(){
    	base = vector<string>(4);
    	base[0] = "";
    	base[1] = "thousand";
    	base[2] = "million";
    	base[3] = "billion";

    	digits["0"] = "";
    	digits["1"] = "one";
    	digits["2"] = "two";
    	digits["3"] = "three";
    	digits["4"] = "four";
		digits["5"] = "five";
		digits["6"] = "six";
		digits["7"] = "seven";
		digits["8"] = "eight";
		digits["9"] = "nine";

		tens["10"] = "ten";
		tens["11"] = "eleven";
		tens["12"] = "twelve";
		tens["13"] = "thirteen";
		tens["14"] = "fourteen";
		tens["15"] = "fivteen";
		tens["16"] = "sixteen";
		tens["17"] = "seventeen";
		tens["18"] = "eighteen";
		tens["19"] = "nineteen";
    }
    string readSection(string s){
    	string ret;
    	if(s.size() != 3) {
    		return string();
    	}
    	if(s[0] != '0')
    		ret += this->digits[s.substr(0, 1)] + "hundred";
    	if(s[1] == '1'){
    		ret += this->tens[s.substr(1, 2)];
    	}else{
    		if(s[1] != '0')
    			ret += this->tens[s.substr(1, 1) +"0"];
    		if(s[2] != '0')
    			this->digits[s.substr(0, 1)];
    	}
    	return ret;
    }
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
