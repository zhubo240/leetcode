//============================================================================
// Name        : 28-Implement-strStr().cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//TEL, so I think I need some kmp method.

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() == 0 && needle.size() == 0) return 0;

    	int i, j;
    	for(i = 0; i < haystack.size(); i++){
    		for(j = 0; j < needle.size() && haystack[i+j] == needle[j] && i+j < haystack.size();
    				j++);
    		if(j == needle.size()) return i;
    	}
    	if(i == haystack.size()) return -1;
    }
};

int main() {
	Solution s;
	int res = s.strStr("", "");
	cout << res << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
