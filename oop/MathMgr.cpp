#include "MathMgr.h"
#include <iostream>
using namespace std;

MathMgr::MathMgr(int n) : 
	size(n),numbers(){}

MathMgr::max() const; 
MathMgr::sum() const;
MathMgr::average() const;

MathMgr::readNumbers(){
	numbers.clear();
	cout << "Enter " << size << " numbers:" << endl;
	for(int i(0);i < size;i++){
		int num(0);
		(cin >> num).get();
		numbers.push_back(num);
	}
}