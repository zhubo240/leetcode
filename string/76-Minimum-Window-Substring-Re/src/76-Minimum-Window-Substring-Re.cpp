//============================================================================
// Name        : 76-Minimum-Window-Substring.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		//cout << s << " " << t << endl;
		//cout << t[0] + "" << endl;  TODO: strange . T[0] + "" != T
		//check
		if (t.size() == 1)
			if (s.find(t[0], 0) != -1)
				return t;
		if (t.size() == 0)
			return "";
		if(t.size() > s.size())
			return "";

		//init
		for(int i =0; i < s.size(); i++)
			if(this->stats.find(s[i]) != this->stats.end())
				this->stats[s[i]]++;
			else
				this->stats[s[i]] = 1;

		map<char, int> counts;
		for (int i = 0; i < t.size(); ++i) {
			counts[t[i]] = 0;
		}

		int lower, upper;
		int resLower, resUpper;
		for (lower = 0; t.find(s[lower]) == -1 && lower < s.size(); lower++)
			;
		if (lower == s.size())
			return "";
		counts[s[lower]] = 1;

		for (upper = lower; true;) {
			//TEST
//			cout << "lower = " << lower << ", upper = " << upper << endl;
//			for (map<char, int>::iterator iter = counts.begin();
//					iter != counts.end(); iter++) {
//				cout << iter->first << ", " << iter->second << endl;
//			}

			//up the upper to just find a cover
			for (upper = upper + 1; upper < s.size(); upper++) {
				if (counts.find(s[upper]) != counts.end())
					counts[s[upper]]++;
				//record ths cover
				if (isACover(counts)) {
					break;
				}
			}

			if (upper == s.size())
				return s.substr(resLower, resUpper+1);

			//up the lower to just a cover without 2 elements

			for (; lower <= upper; lower++) {
				//cout << "lower = " << lower << endl;

				if (isACover(counts)) {
					//TEST
//					cout << "find a  cover: " << "lower = " << lower
//							<< ", upper = " << upper << endl;
//					for (map<char, int>::iterator iter = counts.begin();
//							iter != counts.end(); iter++) {
//						cout << iter->first << ", " << iter->second << endl;
//					}

					resLower = lower;
					resUpper = upper+1;
				}

				if (isACoverNeedOne(counts)) {
					//TODO: what if there are only one
					for (; t.find(s[lower]) == -1; lower++)
						;
					break;
				}

				if (counts.find(s[lower]) != counts.end()) {
					counts[s[lower]]--;
				}

			}

			//TEST
//			cout << "up lower : " << "lower = " << lower << ", upper = "
//					<< upper << endl;
//			for (map<char, int>::iterator iter = counts.begin();
//					iter != counts.end(); iter++) {
//				cout << iter->first << ", " << iter->second << endl;
//			}
//
//			sleep(1);
		}
	}

private:
	map<char, int> stats;
	bool isACover(const map<char, int>& counts) {
		map<char, int>::const_iterator iter;
		for (iter = counts.begin(); iter->second <= this->stats[iter->first] && iter != counts.end();
				iter++)
			;
		if (iter == counts.end())
			return true;
		else
			return false;
	}

	bool isACoverNeedOne(const map<char, int>& counts) {
		map<char, int>::const_iterator iter;
		int num;
		for (num = 0, iter = counts.begin(); iter != counts.end(); iter++) {
			if (this->stats[iter->first] - iter->second == 1)
				num++;
		}
		if (num == 1)
			return true;
		else
			return false;
	}
};

int main(int argc, char **argv) {
	Solution s;
	string res = s.minWindow("aaaa", "aaa");
	//find none?..
	cout << res << endl;

	std::cout << "main over" << std::endl;

	return 0;
}
