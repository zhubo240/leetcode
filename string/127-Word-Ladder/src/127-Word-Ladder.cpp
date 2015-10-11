#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
namespace std {
using std::tr1::unordered_map;
using std::tr1::unordered_set;
}
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord,
			unordered_set<string> &wordList) {
		//check

		//build oneStep & endWords.
		init(wordList, beginWord, endWord);

		unordered_set<string> expanded;
		//intelligence sense does not work, when the type is State
		vector<State> Q(100000);
		int front = -1, roar = -1;

		//init
		State first = { 0, -1, beginWord };
		Q[++roar] = first;
		expanded.insert(first.s);

		++front;
		for (unordered_set<string>::iterator iter = this->beginWords.begin();
				iter != this->beginWords.end(); iter++) {
			State s = { 1, front, *iter };
			Q[++roar] = s;
			expanded.insert(s.s);
		}

		for (; front < roar;) {
			State state = Q[++front];

			if (this->endWords.find(state.s) != this->endWords.end()) {
				return state.layer + 2;
			}

			for (unsigned i = 0; i < this->oneStep[state.s].size(); i++) {
				State newState = { state.layer + 1, front,
						this->oneStep[state.s][i] };
				//cut..
				if (expanded.find(newState.s) == expanded.end()) {
					Q[++roar] = newState;
					expanded.insert(newState.s);
				}
			}
		}

		return 0;
	}
private:
	typedef struct A {
		int layer;
		int father;
		string s;

	} State;

	map<string, vector<string> > oneStep;
	unordered_set<string> endWords, beginWords;

	void init(const unordered_set<string> & wordlist, const string& beginWord,
			const string& endWord) {
		//init endWords
		for (unordered_set<string>::const_iterator iter = wordlist.begin();
				iter != wordlist.end(); ++iter) {
			if (isOneStep(endWord, *iter))
				this->endWords.insert(*iter);
		}

		//init beginWords
		for (unordered_set<string>::const_iterator iter = wordlist.begin();
				iter != wordlist.end(); ++iter) {
			if (isOneStep(beginWord, *iter))
				this->beginWords.insert(*iter);
		}

		//init oneStep
		for (unordered_set<string>::const_iterator i = wordlist.begin();
				i != wordlist.end(); ++i) {
			vector<string> tmp;
			for (unordered_set<string>::const_iterator j = wordlist.begin();
					j != wordlist.end(); ++j)
				if (isOneStep(*i, *j)) {
					tmp.push_back(*j);
				}
			this->oneStep[*i] = tmp;
		}
	}

	inline bool isOneStep(const string& s, const string& t) const {
		int diff = 0;
		for (unsigned i = 0; i < s.size(); i++) {
			if (s[i] != t[i])
				diff++;
		}

		if (diff == 1)
			return true;
		else
			return false;
	}

};

int main() {
	Solution s;
	unordered_set<string> v;
	v.insert("hot");
	v.insert("dot");
	v.insert("dog");
	v.insert("lot");
	v.insert("log");

	int res = s.ladderLength("hit", "cog", v);
	cout << res << endl;

	cout << "over" << endl;
	return 0;
}
