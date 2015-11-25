//============================================================================
// Name        : 65-Valid-Number.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		init(s);
		getNext();

		if ((isNum(this->next) || this->next == '+' || this->next == '-' )&& peekNextOne() != '.') {
			if (integer() == false)
				return false;

			if (next == '\0')
				return true;
			else if (next == 'e') {
				getNext();
				if (integer() == true) {
					if (next == '\0')
						return true;
					else
						return false;
				} else
					return false;

			} else if (next == '.') {
				cout << "here" << endl;
				getNext();
				if (next == '\0')
					return true;
				if (unsigNum() == false)
					return false;
				if (next == '\0')
					return true;
				else if (next == 'e') {
					getNext();
					if (integer() == true) {
						if (next == '\0')
							return true;
						else
							return false;
					} else
						return false;
				} else
					return false;
			} else
				return false;
		} else if (this->next == '.' || this->next == '+' || this->next == '-' ) {
			if(this->next == '+' || this->next == '-'){
				getNext();
				if(this->next != '.') return false;
			}
			getNext();
			if (unsigNum() == true) {
				if (this->next == '\0')
					return true;
				else if (this->next == 'e') {
					getNext();
					if (integer() == true) {
						if (this->next == '\0')
							return true;
						else
							return false;
					} else
						return false;
				} else {
					return false;
				}
			} else
				return false;
		} else
			return false;
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

	char peekNextOne(){
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
		if (unsigNum() == false)
			return false;
		else
			return true;

	}
//    bool pointfloat(){
//
//    }
//    bool efloat(){
//
//    }
};

int main() {
	Solution s;
	bool res = s.isNumber("3.");
	cout << res << endl;
	cout << "over" << endl;
	return 0;
}
