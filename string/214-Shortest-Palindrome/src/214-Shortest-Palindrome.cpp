//============================================================================
// Name        : 214-Shortest-Palindrome.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
    	if (s.size() == 0) return string();
    	string::iterator palindromeEnd;
    	for(string::iterator iter = s.begin(); iter != s.end(); ++iter){
    		if(isPalindrome(s.begin(), iter)){
    			palindromeEnd = iter;
    		}
    	}
//    	cout << string(palindromeEnd+1, s.end()) << endl;
    	string res(s);
    	//if you do not create a new res, instead you use res
    	//the terator is still valid there ?
    	string tmp(palindromeEnd+1, s.end());
    	reverse(tmp.begin(), tmp.end());
    	res.insert(res.begin(), tmp.begin(), tmp.end());
    	return res;
    }

private:
    bool isPalindrome(string::const_iterator begin, string::const_iterator end) const {
    	// TODO : if you pass const iterator, this iter could not use -- / ++
    	// so, you need const_iterator
    	for(;begin <= end && *begin == *end ; begin++, end--);
    	if(begin > end)
    		return true;
    	return false;
    }
};



int main() {
	Solution s;
	string res;
	res = s.shortestPalindrome("sdag");
	cout << res << endl;
	cout << "over" << endl;
	return 0;

}
