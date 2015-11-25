//============================================================================
// Name        : 224-Basic-Calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
    	//check
    	string tmp;
    	for(int i = 0; i < s.size(); i++)
    		if(s[i] != ' ')
    			tmp.push_back(s[i]);
    	s = tmp;
    	s.push_back('#');

    	int i = 0;
    	i += parseInt(s, i);
    	int left = this->num;
    	char op = s[i];

    	for(;s[i] != '#';){
    		int len = parseInt(s, i);


    		if(LT(op, s[i+len] )){
    			i += parseTerm(s, i);
    		}else if(EQ(op, s[i+len])){
    			i += parseInt(s, i);
    		}
    		if(op == '+') left += this->num;
    		if(op == '-') left -= this->num;
    		op = s[i];
    	}
    }

private:
    int num;
	//return len
    int parseInt(const string& s, int b){
    	int res = 0;
    	int i;
    	for(i = b; s[i] >= '0' && s[i] <= '9'; i++){
    		res = res*10 + s[i] - '0';
    	}
    	this->num = res;
    	return i - b;
    }

    int parseTerm(const string& s, int b){

    }

    bool LT(char left, char right){

    }

    bool EQ(char left, char right){

    }
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
