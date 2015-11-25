//============================================================================
// Name        : 30-Substring-with-Concatenation-of-All-Words.cpp
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
	vector<int> findSubstring(string s, vector<string>& words) {
		//check..
		if(words.size() == 0 ) return vector<int>();
//		if(words[0].size() > s.size()) return vector<int>();

		//init wordIdxs
		vector<int> wordIdxs;
		init(s, words, wordIdxs);

		vector<int> res;

		int numWord = words.size();
		int wordLen = words[0].size();

		for (unsigned i = 0; i < wordIdxs.size(); i++) {
			vector<bool> occur(numWord, false);
			int left = numWord;
//			cout << "i = " << i << endl;

			for (int j = i; left > 0 && j < wordIdxs.size(); j += wordLen, left--) {
//				cout << "j = " << j << endl;
//				cout << wordIdxs[j] << endl;
				if(wordIdxs[j] == -1)  break;
				occur[wordIdxs[j]] = true;
			}
			//test

//			for (int i = 0; i < occur.size(); ++i) {
//				cout << occur[i] << ", ";
//			}
//			cout << endl;

			if(left == 0){
				//check whether all word in occour
				unsigned k;
				for (k = 0; k < occur.size() && occur[k]; ++k);
				if(k == occur.size()) res.push_back(i);
			}
		}

		return res;
	}

private:
	void init(const string s, const vector<string> words,
			vector<int> &wordIdxs) const{
		//convert the s -> wordIdxs
		map<string, int> wordMap;
		for (int i = 0, idx = 0; i < words.size(); ++i) {
			wordMap[words[i]] = idx++;
		}

		int wordLen = words[0].size();
		//what's the fuck !!
		for (unsigned i = 0; i < s.size() - wordLen; i++) {
			cout <<i << "  " << wordLen << "  " << s.size()<< endl;
			string word = s.substr(i, wordLen);
			if (wordMap.find(word) != wordMap.end())
				wordIdxs.push_back(wordMap[word]);
			else wordIdxs.push_back(-1);
		}

//		for (int var = 0; var < wordIdxs.size(); ++var) {
//			cout << wordIdxs[var] << ", ";
//		}
//		cout << endl;
	}
};

int main(int argc, char **argv) {
	Solution s;
	vector<int> res;

	vector<string> words;
	words.push_back("mississippis");

	res = s.findSubstring("mississippi", words);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << ", ";
	}
	cout << endl;
	std::cout << "main over" << std::endl;
	return 0;
}

