//============================================================================
// Name        : 151-Reverse-Words-in-a-String.cpp
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
	void reverseWords(string &s) {
		//check
		this->reverse(s, 0, s.size());

		//TODO: string s, end of the string.
		int b, e, i;
		for (i = 0; true;) {
			for (; this->isWhite(s[i]); i++)
				;
			if (s[i] == '\0')
				break;
			b = i;
			for (; !isWhite(s[i]) && s[i] != '\0'; i++)
				;
			e = i;
			reverse(s, b, e);
			if (s[i] == '\0')
				break;
		}

		int idx;
		//eliminate the leading whites
		for (idx = 0; isWhite(s[idx]) && idx < s.size(); idx++)
			;
		s = s.substr(idx, s.size() - idx);
		//elimin the trailing whites
		for(idx = s.size() - 1; isWhite(s[idx]) && idx >= 0; idx--);
		s.resize(idx+1);

//		cout << s << endl;

		for (int i = 0, j = 0; true;) {
			for (; !isWhite(s[i]) && i < s.size();) {
				s[j++] = s[i++];
			}

			if (i >= s.size()) {
				s.resize(j);
				break;
			}

			//must have white, end must be a char not end of string or white
			for (; isWhite(s[i]); i++);
			s[j++] = ' ';

		}
	}

private:
	bool isWhite(char ch) {
		//TODO: \0 is a white?
		return ch == ' ' || ch == '\t' || ch == '\n';
	}

	void reverse(string& s, int b, int e) {
		for (int i = b, j = e - 1; i < j; i++, j--) {
			std::swap(s[i], s[j]);
		}
	}
};

int main() {
	Solution s;
	string str(" ");
	s.reverseWords(str);
	cout << str << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
