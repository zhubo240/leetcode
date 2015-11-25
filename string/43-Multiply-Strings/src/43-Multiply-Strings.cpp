//============================================================================
// Name        : 43-Multiply-Strings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	//check
    	if(num1.size() == 0 || num2.size() == 0) return "0";

    	std::reverse(num1.begin(), num1.end());
    	std::reverse(num2.begin(), num2.end());

    	string res;
    	int carry = 0;
    	int i;
    	for(i = 0; i < num1.size(); i++){
    		string product;
    		for(int j = 0; j < num2.size(); j++){
    			int left = ((num1[i]-'0') * (num2[j]-'0') + carry) % 10;
    			carry = ((num1[i]-'0') * (num2[j]-'0') + carry) / 10;
    			product.push_back(left+'0');
    		}
    		if(carry != 0)
    			product.push_back(carry + '0');
    		string shift(i, '0');
    		product.insert(product.begin(), shift.begin(), shift.end());
    		res = this->add(product, res);
    	}

    	std::reverse(res.begin(), res.end());
    	return res;
    }
private:
    // low -> high
    string add(string s1, string s2){
    	if(s1.size() < s2.size()){
    		string tmp;
    		tmp = s1, s1 = s2, s2 = tmp;
    	}

    	int carry = 0;
    	int i = 0;
    	string sum;
    	for(; i < s2.size(); i++){
    		int left = (s1[i]-'0' + s2[i]-'0' + carry) % 10;
    		carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    		sum.push_back('0' + left);
    	}

    	for(; i < s1.size(); i++){
    		int left = (s1[i] - '0' + carry) % 10;
    		carry = (s1[i] - '0' + carry) / 10;
    		sum.push_back('0' + left);
    	}

    	if(carry != 0){
    		sum.push_back('0' + carry);
    	}

    	return sum;
    }
};

int main() {
	Solution s;
	string res;
	res = s.multiply("12", "12");
	//res = s.add("", "999");
	cout << res << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
