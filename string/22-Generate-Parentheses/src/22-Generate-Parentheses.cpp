//============================================================================
// Name        : 22-Generate-Parentheses.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		n = n * 2;
		//check

		if(n <= 0) return vector<string>(1, "");
		this->n = n;
		dfs();
		std::reverse(this->res.begin(), this->res.end());
		return this->res;
	}

private:
	int n;
	vector<string> res;
	void dfs() {
		//search the every section length.
		//at most n/2 sections.
		int step = 0;
		int maxSect = this->n / 2;

		//store the every sect's len
		int left = this->n;
		vector<int> stack(maxSect, 0);
		while (step >= 0) {
			if (left == 0) {
				//create res;
				string s(this->n, '#');
				for (int i = 0, b = 0; stack[i] > 0 && i < stack.size(); i++) {
					this->genSection(s, b, stack[i]);
					b += stack[i];
				}
				this->res.push_back(s);
				step--;
				if (step >= 0) {
					left += stack[step];
				}

				continue;
			}

		int sectLen;
		int tmp = left;
		for (sectLen = stack[step] + 2; sectLen <= left; sectLen += 2) {
			stack[step] = sectLen;
			left -= sectLen;
			step++;
			break;

		}

		if (sectLen > tmp) {
			stack[step] = 0;
			step--;
			left += stack[step];
			continue;
		}
	}

}
void genSection(string& v, int b, int len) {
	int i;
	for (i = 0; i < len / 2; i++)
		v[b + i] = '(';
	for (; i < len; i++)
			v[b + i] = ')';
}
};

int main() {
Solution s;
vector<string> res = s.generateParenthesis(2);
cout << res.size() << endl;
std::copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));
cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
return 0;
}
