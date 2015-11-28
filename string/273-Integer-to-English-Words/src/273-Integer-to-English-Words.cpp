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
#include <algorithm>

using namespace std;


class Solution {
public:
    string numberToWords(int num) {
    	//check
    	if(num == 0) return "Zero";

    	string s;
    	num2str(num, s);
//    	cout << s << endl;
    	init();
    	string res;
    	int numSect = s.size() / 3;
    	int left = s.size() % 3;

//    	cout << numSect << left << endl;
    	if(left != 0){
    		string zeros(3 - left, '0');
//    		cout << zeros + s.substr(0, left) << endl;
    		res += readSection(zeros + s.substr(0, left));
    		res += this->base[numSect];
    		res += " ";
    	}
    	for(int i = left, j = numSect - 1; i < s.size() && j >= 0; i = i + 3, j--){

    		string tmp = readSection(s.substr(i, 3));
    		res += tmp;
    		if(tmp != ""){
    			res += this->base[j];
    			res += " ";
    		}
    	}
		int i = res.size() - 1;
		for (; i >= 0 && res[i] == ' '; i--)
			;
		res.resize(i + 1);

    	return res;
    }
private:
    map<string, string> digits;
    map<string, string> tens;
    vector<string> base;

    string num2str(int num, string& s){
    	for(;num; num = num / 10){
    		s.push_back(num % 10 + '0');
    	}
    	std::reverse(s.begin(), s.end());
    	return s;
    }

    void init(){
    	base = vector<string>(4);
    	base[0] = "";
    	base[1] = "Thousand";
    	base[2] = "Million";
    	base[3] = "Billion";

    	digits["0"] = "";
    	digits["1"] = "One";
    	digits["2"] = "Two";
    	digits["3"] = "Three";
    	digits["4"] = "Four";
		digits["5"] = "Five";
		digits["6"] = "Six";
		digits["7"] = "Seven";
		digits["8"] = "Eight";
		digits["9"] = "Nine";

		tens["10"] = "Ten";
		tens["11"] = "Eleven";
		tens["12"] = "Twelve";
		tens["13"] = "Thirteen";
		tens["14"] = "Fourteen";
		tens["15"] = "Fifteen";
		tens["16"] = "Sixteen";
		tens["17"] = "Seventeen";
		tens["18"] = "Eighteen";
		tens["19"] = "Nineteen";

		tens["20"] = "Twenty";
		tens["30"] = "Thirty";
		tens["40"] = "Forty";
		tens["50"] = "Fifty";
		tens["60"] = "Sixty";
		tens["70"] = "Seventy";
		tens["80"] = "Eighty";
		tens["90"] = "Ninety";
    }
    string readSection(string s){
//    	cout << s << endl;
    	string ret;
    	if(s.size() != 3) {
    		return string();
    	}

    	if(s[0] != '0')
    		ret += this->digits[s.substr(0, 1)] + " " + "Hundred ";

    	if(s[1] == '1'){
    		ret += this->tens[s.substr(1, 2)] + " ";
    	}else{
    		if(s[1] != '0'){
    			ret += this->tens[s.substr(1, 1) +"0"] + " ";
    		}
    		if(s[2] != '0'){
    			ret += this->digits[s.substr(2, 1)] + " ";
    		}
    	}

    	return ret;
    }
};

int main() {
	Solution s;
	string res = s.numberToWords(123);
	cout << res << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
