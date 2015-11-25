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

		string T(53, '#');
		int cnt = 0;
		for (int i = 0; i < t.size() && cnt < T.size(); i++) {
			if (T.find(t[i]) == -1) {
				T[cnt++] = t[i];
			}
		}

		T.resize(cnt);
		cout << T << endl;
		map<char, int> counts;
		for (int i = 0; i < T.size(); ++i) {
			counts[T[i]] = 0;
		}
		//init
		string minWin;
		int lower, upper;
		for (lower = 0; T.find(s[lower]) == -1 && lower < s.size(); lower++)
			;
		if (lower == s.size())
			return minWin;
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
				return minWin;

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

					int size = upper + 1 - lower;
					if (minWin.size() == 0)
						minWin = s.substr(lower, size);
					else {
						if (size < minWin.size())
							minWin = s.substr(lower, size);
					}
				}

				if (isACoverWithoutOne(counts)) {
					//TODO: what if there are only one
					for (; T.find(s[lower]) == -1; lower++)
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
	bool isACover(const map<char, int>& counts) {
		map<char, int>::const_iterator iter;
		for (iter = counts.begin(); iter->second != 0 && iter != counts.end();
				iter++)
			;
		if (iter == counts.end())
			return true;
		else
			return false;
	}

	bool isACoverWithoutOne(const map<char, int>& counts) {
		map<char, int>::const_iterator iter;
		int num;
		for (num = 0, iter = counts.begin(); iter != counts.end(); iter++) {
			if (iter->second == 0)
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
	string res = s.minWindow("A", "ACAA");
	//find none?..
	cout << res << endl;

	std::cout << "main over" << std::endl;

	return 0;
}
