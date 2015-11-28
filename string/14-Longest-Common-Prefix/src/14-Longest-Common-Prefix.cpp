//============================================================================
// Name        : 14-Longest-Common-Prefix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	//check
    	if(strs.size() == 0) return "";
    	if(strs.size() == 1) return strs[0];

    	string prefix = strs[0];
    	for(int i = 1; i < strs.size(); i++){
    		int j = 0;
    		for(; j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]; j++);
    		prefix.resize(j);
    	}

    	return prefix;
    }
};

int main() {
	Solution s;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
