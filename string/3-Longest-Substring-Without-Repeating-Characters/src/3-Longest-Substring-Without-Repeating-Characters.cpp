//============================================================================
// Name        : 3-Longest-Substring-Without-Repeating-Characters.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		Elem tmp = { -1, 0 };
		vector<Elem> table(26, tmp);
		map<char, Elem> newTable;


		int b = 0, e = 0;
		int longest = 0;
		for (unsigned i = 0; i < s.size(); ++i) {
//			cout << i << endl;
			e = i;

			if(newTable.find(s[i]) == newTable.end()){
				Elem elem = {i, 1};
				newTable[s[i]] = elem;
			}else{
				//exist
				if(newTable[s[i]].freq < 1){
					newTable[s[i]].freq = 1;
					newTable[s[i]].pos = i;
				}else{
					b = newTable[s[i]].pos + 1;
					//update table
					for(unsigned i = 0; i < newTable.size(); i++){
						if(newTable[i].pos < b && newTable[i].freq > 0){
							newTable[i].freq = 0;
							newTable[i].pos = -1;
						}
					}

					newTable[s[i]].freq = 1;
					newTable[s[i]].pos = i;
				}
			}
			//cout << b << ", " << e << endl;

			if( e + 1 - b > longest) longest = e+1 - b;
		}

		return longest;
	}

private:
	typedef struct T {
		int pos, freq;
	} Elem;

};

int main(int argc, char **argv) {
	Solution s;
	int res;
	res = s.lengthOfLongestSubstring("qthepvzhouiriqnqjpgwabpwwoqebcguxnankzwztgsdwgwixcexfwvemliqpomnemcolypfgikfognnktkqrhueteukvgzb");
	cout << res << endl;
	std::cout << "main over" << std::endl;
	return 0;
}

