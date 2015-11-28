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
#include <iterator>
using namespace std;


//TODO : shell's path grammer.
class Solution {
public:
    string simplifyPath(string path) {
    	//check
    	if(path.size() == 0) return path;

    	vector<string> pathNodes;
    	init(path, pathNodes);

//    	std::copy(pathNodes.begin(), pathNodes.end(), ostream_iterator<string> (cout, "\n"));
    	vector<string> names;
    	for(int i = 0; i < pathNodes.size(); i++){
    		if(pathNodes[i].compare("..") == 0){
    			//TODO: could not pop when empty
    			if(names.size() > 0)
    				names.pop_back();
    		}else if(pathNodes[i].compare(".") == 0  || pathNodes[i].compare("") == 0){
    			//empty
    		}else{
    			names.push_back(pathNodes[i]);
    		}
    	}

    	string res;
    	if(names.size() == 0) res = "/";
    	for(int i = 0; i < names.size(); i++){
    		res.push_back('/');
    		res.append(names[i].begin(), names[i].end());
    	}

    	return res;
    }


private:
    void init(const string& path, vector<string>& pathNodes){
    	for(int i = 0; true;){
    		//skip '/'
    		i++;
    		if(i == path.size()) break;
    		string name;
    		for(;i < path.size(); i++)
    			if(path[i] != '/')
    				name.push_back(path[i]);
    			else break;
    		pathNodes.push_back(name);
    		if(i == path.size()) break;
    	}
    }
};

int main() {
	string path = "/..";
	Solution s;
	string res = s.simplifyPath(path);
	cout << res << endl;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
