//============================================================================
// Name        : 6-ZigZag-Conversion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		//check
		//numRows >= 1
		if (numRows == 1)
			return s;

		vector<vector<char> > res(numRows,
				vector<char>((int) ceil(s.size() / 2 + 1), ' '));

		int i = 0, j = 0;
		int k = 0;
		int line;
		for (line = 0; line < s.size() / (numRows - 1); line++) {
			for (int num = 0; num < numRows - 1; num++) {
				//sleep(1);
				if (line % 2 == 0) {
					res[i++][j] = s[k++];
				} else {
					res[i--][j++] = s[k++];
				}
				if (k >= s.size())
					break;
			}

			if (k >= s.size())
				break;
		}

		int left = s.size() % (numRows - 1);
		for (int num = 0; num < left; num++) {
			if (line % 2 == 0) {
				res[i++][j] = s[k++];
			} else {
				res[i--][j++] = s[k++];
			}
		}

		string str;
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++) {
				if (res[i][j] != ' ') {
					str.push_back(res[i][j]);
				}
//				cout << res[i][j];
			}
//			cout << endl;
		}

		return str;
	}
};

int main() {
	Solution s;
	string res = s.convert("PAHNAPLSIIGYIR", 15);
	cout << res << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
