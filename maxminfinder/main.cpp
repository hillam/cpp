#include "MaxMinFinder.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//find the min, print it and remove it..

int main(){
	vector<string> v;
	v.push_back("bat");
	v.push_back("snake");
	v.push_back("ant");
	v.push_back("leopard");

	int size = v.size();
	for(int i(0);i<size;i++){
		MaxMinFinder<string> finder(v[0]);
		finder.test(v);
		auto it = find(v.begin(),v.end(),finder.min());
		cout << *it << endl;
		v.erase(it);
	}
}