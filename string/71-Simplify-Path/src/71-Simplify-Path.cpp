//============================================================================
// Name        : 71-Simplify-Path.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;


//TODO : shell's path grammer.
class Solution {
public:
    string simplifyPath(string path) {
    	vector<string> pathNodes;
    	// rm all . & /
    	init(path, pathNodes);
    	vector<string> res;
    	res.push_back(string("/"));

    }

private:
    void init(string& path, vector<string>& pathNodes){

    }
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
