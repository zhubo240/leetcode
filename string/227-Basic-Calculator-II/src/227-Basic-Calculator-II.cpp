//============================================================================
// Name        : 227-Basic-Calculator-II.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		int res = E();
		return res;
	}
private:
	enum Type {
		Int, AddOp, MulOp, End
	};
	typedef struct {
		enum Type type;
		int v;
	} Token;

	vector<Token> tokens;
	Token cur;
	int idx;
	void init(const string& s) {
		string news;
		for (int i = 0; true;) {
			for (; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; i++)
				;

			//num
			int num = 0;
			for (; i >= '0' || i <= '9'; i++)
				num = s[i] - '0' + num * 10;
			//create
			Token token;
			token.type = Int;
			token.v = num;
			this->tokens.push_back(token);

			for (; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; i++)
				;
			// +|-
			if (s[i] == '+' || '-') {
				//create
				Token token;
				token.type = AddOp;
				token.v = s[i];
				this->tokens.push_back(token);
				i++;
			}

			// *|/
			if (s[i] == '*' || '/') {
				//create
				Token token;
				token.type = MulOp;
				token.v = s[i];
				this->tokens.push_back(token);
				i++;
			}
			if (s[i] == '#') {
				//create
				Token token;
				token.type = End;
				this->tokens.push_back(token);
				break;
			}
		}
		this->idx = 0;
		cur = this->tokens[0];
	}

	void getNext() {
		this->idx++;
		if (idx >= tokens.size()) {
			cerr << "out of upper boundary" << endl;
			exit(1);
		}
		this->cur = this->tokens[this->idx];
	}

	void pushBack() {
		this->idx--;
		if (idx < 0) {
			cerr << "out of lower boundary" << endl;
			exit(1);
		}
		this->cur = this->tokens[this->idx];
	}

	int E() {
		int res;
		int left, right;

		if (cur.type != Int) {
			cerr << " error 1" << endl;
			exit(1);
		}

		getNext();
		if (cur.type == End) {
			pushBack();
			res = F();

			return res;
		} else {
			pushBack();
			left = E();
			if (cur.type != AddOp) {
				cerr << " error 2" << endl;
				exit(1);
			}
			Token op = cur;
			getNext();
			right = E();
			if (cur.type != End) {
				cerr << " error 2" << endl;
				exit(1);
			}
			if (op.v == '+')
				res = left + right;
			if (op.v == '-')
				res = left - right;
		}

		return res;
	}

	int F() {
		int res, left, right;

		if (cur.type != Int) {
			cerr << "error 3" << endl;
			exit(1);
		}
		getNext();
		if (cur.type == End) {
			pushBack();
			res = cur.v;
			getNext();
			return res;
		}
		pushBack();
		left = F();
		getNext();

		if (cur.type != MulOp) {
			cerr << "error 4" << endl;
			exit(1);
		}
		Token op = cur;
		getNext();

		right = F();
		if (op.v == '*')
			res = left * right;
		if (op.v == '/')
			res = left / right;

		return res;
	}
};

int main() {

	return 0;
}
