//============================================================================
// Name        : 67-Add-Binary.cpp
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
	string addBinary(string a, string b) {
		//check

		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());
		//a > b
		if (a.size() < b.size()) {
			string tmp;
			tmp = a, a = b, b = tmp;
		}

		string sum;
		int carry = 0;
		int i = 0;
		for (; i < b.size(); i++) {
			if (a[i] == '0' && b[i] == '0') {
				sum.push_back('0' + carry);
				carry = 0;
			} else if (a[i] == '1' && b[i] == '0'
					|| a[i] == '0' && b[i] == '1') {
				if (carry == 1) {
					sum.push_back('0');
					carry = 1;
				} else {
					sum.push_back('1');
					carry = 0;
				}
			} else {
				sum.push_back('0' + carry);
				carry = 1;
			}
		}

		for (; i < a.size(); i++) {
			if (a[i] == '0') {
				sum.push_back('0' + carry);
				carry = 0;
			} else {
				if (carry == 1) {
					sum.push_back('0');
					carry = 1;
				} else {
					sum.push_back('1');
					carry = 0;
				}
			}
		}

		if (carry == 1) {
			sum.push_back('1');
		}

		std::reverse(sum.begin(), sum.end());
		return sum;
	}
};

int main() {
	Solution s;
	string res = s.addBinary("", "");
	cout << res << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
