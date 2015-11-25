//============================================================================
// Name        : 12-Integer-to-Roman.cpp
// Name        : 12-Integer-to-Roman.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : #include <iostream>
// Description : #include <iostream>
// Description : #include <iostream>

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	string res;
    	init();
    	int thousand = num / 1000;
    	int handred = (num % 1000) / 100;
    	int ten = (num % 100) / 10;
    	int one = num % 10;

    	res = this->thousands[thousand] + this->handreds[handred] + this->tens[ten] + this->ones[one];
    	return res;
    }
private:
    map<int, string> ones;
    map<int, string> tens;
    map<int, string> handreds;
    map<int, string> thousands;

    void init(){
    	ones[1] = "I";
    	ones[2] = "II";
    	ones[3] = "III";
    	ones[4] = "IV";
    	ones[5] = "V";
    	ones[6] = "VI";
    	ones[7] = "VII";
    	ones[8] = "VIII";
    	ones[9] = "IX";

    	tens[1] = "X";
    	tens[2] = "XX";
    	tens[3] = "XXX";
    	tens[4] = "XL";
    	tens[5] = "L";
    	tens[6] = "LX";
    	tens[7] = "LXX";
    	tens[8] = "LXXX";
    	tens[9] = "XC";

    	handreds[1] = "C";
    	handreds[2] = "CC";
    	handreds[3] = "CCC";
    	handreds[4] = "CD";
    	handreds[5] = "D";
    	handreds[6] = "DC";
    	handreds[7] = "DCC";
    	handreds[8] = "DCCC";
    	handreds[9] = "CM";

    	thousands[1] = "M";
    	thousands[2] = "MM";
    	thousands[3] = "MMM";
    }
};

int main() {
	Solution s;
	cout << s.intToRoman(101) << endl;
	cout << "over" << endl;
	return 0;
}
