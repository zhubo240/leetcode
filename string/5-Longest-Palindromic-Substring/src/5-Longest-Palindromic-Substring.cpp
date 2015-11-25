//============================================================================
// Name        : 5-Longest-Palindromic-Substring.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
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

//			 std::copy (dp.begin(), dp.end(), ostream_iterator<int> (cout, ","));
//			 cout << endl;

			//update
			if (farIdx < i + dp[i]) {
				farIdx = i + dp[i];
				farCenter = i;
			}
		}
		int maxidx = 0;
		for(unsigned i = 0; i < dp.size(); i++){
			if(dp[maxidx] < dp[i]) maxidx = i;
		}


		string res;
		for(int b = maxidx+1 - dp[maxidx], i = 0;
				i < dp[maxidx]*2 -1; i++)
			if(evens[b+i] != '#')
				res.push_back(evens[b+i]);
		return res;
	}
private:
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

int main(int argc, char **argv) {
	Solution s;
	string res = s.longestPalindrome("aaaa");
	cout << res << endl;
	std::cout << "main over" << std::endl;
	return 0;
}

