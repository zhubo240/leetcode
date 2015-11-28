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
		//check
		this->stats = getFreqMap(t);
		int min;
		if (!this->greatEq(s)){
			return "";
		}
		else
			min = s.size();

		int minLower = 0, minUpper = 0;
		int lower, upper;
		for (lower = 0, upper = 1; lower < upper && upper <= s.size();) {
			string cover = s.substr(lower, upper);
//			cout << cover << endl;

			if (greatEq(cover)) {
				//exactly a cover

				if (upper - lower <= min) {
					minLower = lower;
					minUpper = upper;
					min = minUpper - minLower;
				}
				lower++;
			} else if (lessEq(cover)) {
				upper++;
			}
		}

		return s.substr(minLower, minUpper);
	}

private:
	map<char, int> stats;

	map<char, int> getFreqMap(const string& s) {
		map<char, int> m;
		for (int i = 0; i < s.size(); i++)
			if (m.find(s[i]) != m.end())
				m[s[i]]++;
			else
				m[s[i]] = 1;
		return m;
	}

	//s >= stats
	bool greatEq(const string& s) {
		map<char, int> freq = getFreqMap(s);
		for (map<char, int>::iterator iter = stats.begin(); iter != stats.end();
				iter++) {
			char key = iter->first;
			if (freq.find(key) != freq.end()) {
				if (iter->second > freq[key])
					return false;
			} else
				return false;
		}

		return true;
	}

	// s <= stats
	bool lessEq(const string& s) {
		map<char, int> freq = getFreqMap(s);
		for (map<char, int>::iterator iter = stats.begin(); iter != stats.end();
				iter++) {
			char key = iter->first;
			if (freq.find(key) != freq.end()) {
				if (iter->second > freq[key])
					return true;
			} else
				return true;
		}

		return false;
	}

};

int main(int argc, char **argv) {

	Solution s;
	string res = s.minWindow("swmvvzytpzovapzemeooshbchunsuyuowijrjhkbiawkrxrdcfrwpvawpnqlnmbjwkagtmheofqfchjgpccexccopsbchcndopjkbsqpxgxcqgifknlkppahjclqgzuxqfjsyzjxfgzxokezxrloglxspliwmevcmeukdejkmlkbvoasgnioyggqrrodxjfjncvsiheusovndxhlkrzlxibqbpvyydknfffnojjgyfvdecopwnctxdmyuhzskjhrqogfzqlzxhcblqqhgudfxperydlloueeiljidxhaembreubmoesovyfvbtgrnnvyyfgbepdkdgbiacuriofdmmzphhgxuevujdxpsczwjaglfacnrjtdyuvhdbeahzwqcuhxwgvhjbtodxdujyahsvqyyvygwuybqgypmtwxwrlzpruypuhkr", "xkpuixtewux");
	//find none?..
	cout << res << endl;

	std::cout << "main over" << std::endl;

	return 0;
}
