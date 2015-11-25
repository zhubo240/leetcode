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

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		Elem tmp = { -1, 0 };
		vector<Elem> table(26, tmp);

		int maxb, maxe;
		for (unsigned i = 0; i < s.size(); ++i) {
			int idx = s[i] - 'a';
			if (table[idx].freq == 0) {
				table[idx].freq = 1;
				table[idx].pos = i;
			}
			if (table[idx].freq == 1) {
				//record the b & e
				int b, e;
				b = idx;
				e = idx;
				for (int i = 0; i < 26; i++) {
					if (table[i].freq == 1) {
						b = b < table[i].pos ? b : table[i].pos;
						e = e > table[i].pos ? e : table[i].pos;
					}
				}
				if (e - b > maxe - maxb) {
					e = maxe;
					b = maxb;
				}

				//update the table
				for (int i = 0; i < 26; i++) {
					int pos = table[idx].pos;

					if (table[i].freq == 1) {
						if (table[i].pos <= pos) {
							table[i].pos = -1;
							table[i].freq = 0;
						}
					}
				}
				table[idx].pos = i;
				table[idx].freq = 1;

			}
		}
		return maxe-maxb;
	}

private:
	typedef struct T {
		int pos, freq;
	} Elem;

};

int main(int argc, char **argv) {
	Solution s;
	int res;
	res = s.lengthOfLongestSubstring("abcabcbb");
	cout << res << endl;
	std::cout << "main over" << std::endl;
	return 0;
}

