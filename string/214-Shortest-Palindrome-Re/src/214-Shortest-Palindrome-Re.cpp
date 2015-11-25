//============================================================================
// Name        : 214-Shortest-Palindrome-Re.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
    	int n = this->longestPalindromeFromBegin(s);

    	cout << n << endl;

    	string res;
    	for (int i = s.size()-1; i >= n; --i) {
			res.push_back(s[i]);
		}
    	for(int i = 0; i < s.size(); i++)
    		res.push_back(s[i]);

    	return res;
    }
private:
    int longestPalindromeFromBegin(string s) {
    		//check
    		string evens;
    		init(s, evens);
    		vector<int> dp(evens.size(), 0);

    		int farIdx = 1;
    		int farCenter = 0;
    		dp[0] = 1;
    		for (unsigned i = 1; i < evens.size(); i++) {
    			//search to fill dp

    			if (i < farIdx) {
    				if ( (int)((2*farCenter-i) - (dp[2*farCenter-i]))
    						> farCenter - (farIdx - farCenter)  ){
    					dp[i] = dp[2 * farCenter - i];
    				}
    				else {
    					int offset = farIdx - i;
    					//expand
    					dp[i] += farIdx - i + expandPalindrome(evens, i, offset);
    				}
    			}else
    				dp[i] = expandPalindrome(evens, i, 0);

    			//update
    			if (farIdx < i + dp[i]) {
    				farIdx = i + dp[i];
    				farCenter = i;
    			}
    		}

    		int i;
    		for(i = dp.size()-1; i >= 0 && dp[i] != i + 1; i--);
    		return i;
        	}

    	void init(const string &s, string &evens) {
    		for (unsigned i = 0; i < s.size(); i++){
    			evens.push_back('#');
    			evens.push_back(s[i]);
    		}
    		evens.push_back('#');

    	}

    	int expandPalindrome(const string &evens, int center, int offset) {
    		//check
    		int n = evens.size();
    		if (center < 0 || center >= n)
    			return 0;
    		//TODO: about  trickness in && operation
    		int idx = offset;
    		for (; true; idx++) {
    			if (center + idx >= n || center - idx < 0)
    				break;
    			if (evens[center + idx] != evens[center - idx])
    				break;
    		}

    		return idx - offset;
    	}
};

int main() {
	Solution s;
	string res = s.shortestPalindrome("abbacd");
	cout << res << endl;
	cout << "over" << endl;
	return 0;
}
