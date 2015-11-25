//============================================================================
// Name        : 65-Valid-Number-Re.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		init(s);
		vector<bool> flags(2, false); // . e
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.')
				flags[0] = true;
			if (s[i] == 'e')
				flags[1] = true;
		}
		if (flags[1]) {
			getNext();
			if(E() == false) return false;

		} else if (flags[0] && !flags[1]) {
			getNext();
			if(floatPoint1() == false) return false;
		} else if (!flags[0] && !flags[1]) {
			getNext();
			if(integer() == false)
				return false;
		}

		if(this->next == '\0') return true;
		else return false;
	}

private:
	char next;
	int idx;
	string str;

	void init(const string& s) {
		int b, e;
		for (b = 0; s[b] == ' ' && b < s.size(); b++)
			;
		for (e = s.size() - 1; s[e] == ' ' && e >= 0; e--)
			;
		for (int i = b; i < e + 1; i++)
			this->str.push_back(s[i]);
		this->str.push_back('\0');
		this->idx = -1;
	}

	bool isNum(char ch) {
		return ch >= '0' && ch <= '9';
	}

	void getNext() {
//    	cout << this->idx << endl;
//    	cout << this->str.size() - 1 << endl;
//    	if(this->idx < (this->str.size() - 1)){
		this->idx += 1;
		this->next = this->str[this->idx];
//    	}else {
//    		cout <<"read out of boundary" << endl;
//    	}

//    	cout << "ret" << endl;
	}

	char peekNextOne() {
		char ch = this->str[this->idx + 1];
		return ch;
	}
	bool unsigNum() {
		if (!isNum(this->next))
			return false;

		while (isNum(this->next)) {
			getNext();
		}
		return true;
	}

	bool integer() {
		if (this->next == '+' || this->next == '-') {
			getNext();
			if (unsigNum() == false)
				return false;
			return true;
		}

		return this->unsigNum();
	}

	bool floatPoint() {
		if (this->next == '+' || this->next == '-') {
			getNext();
			if (isNum(this->next)) {
				if (this->unsigNum() == false)
					return false;
				if (this->next != '.')
					return false;
				getNext();
				if (this->next != '\0' || isNum(this->next) == false)
					return false;
				if (isNum(this->next)) {
					return this->unsigNum();

				}
				if (this->next == '\0')
					return true;

			} else if (this->next == '.') {
				getNext();
				return this->unsigNum();

			} else if (isNum(this->next)) {
				if (this->unsigNum() == false)
					return false;
				if (this->next != '.')
					return false;
				getNext();
				if (this->next != '\0' || isNum(this->next) == false)
					return false;
				if (isNum(this->next)) {
					return this->unsigNum();
				}
				if (this->next == '\0')
					return true;
			} else {

				cout << "error1" << endl;
				return false;
			}
		}
	}

	bool floatPoint1() {
		if (((this->next == '+' || this->next == '-') && isNum(peekNextOne()))
				|| isNum(this->next)) {
			if (integer() == false)
				return false;
			if (this->next != '.')
				return false;
			getNext();
			if (this->next == '\0') {
				return true;
			} else if (isNum(this->next)) {
				return this->unsigNum();
			} else {
				cout << "error2" << endl;
				return false;
			}

		} else if (((this->next == '+' || this->next == '-')
				&& peekNextOne() == '.')) {
			getNext();
			getNext();
			return this->unsigNum();
		} else if (this->next == '.') {
			getNext();
			return this->unsigNum();
		} else {
			cout << "error3" << endl;
			return false;
		}
	}

	bool E() {
		if (((this->next == '+' || this->next == '-')
				&& isNum(this->peekNextOne())) || isNum(this->next)) {
			if (this->integer() == false)
				return false;
			if (this->next == 'e') {

			} else if (this->next == '.' && this->peekNextOne() == 'e') {
				getNext();
			} else if (this->next == '.' && isNum(this->peekNextOne())) {
				getNext();
				if (this->unsigNum() == false)
					return false;
			} else {
				cout << "error4" << endl;
				return false;
			}

		} else if ((this->next == '+' || this->next == '-')
				&& peekNextOne() == '.') {
			getNext();
			getNext();
			if (unsigNum() == false)
				return false;
		} else if (this->next == '.') {
			getNext();
			if (unsigNum() == false)
				return false;
		} else {
			cout << "error5" << endl;
			return false;
		}

		if (this->next != 'e')
			return false;
		getNext();
		if (integer() == false)
			return false;
		return true;
	}

};

int main() {
	Solution s;
	bool res = s.isNumber("1 4");
	cout << res << endl;
	cout << "over" << endl;
	return 0;
	return 0;
}
