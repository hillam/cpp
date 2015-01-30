#include "MathMgr.h"
#include <iostream>
#include <climits>
using namespace std;

MathMgr::MathMgr(int n) : 
	size(n),numbers(){}

int MathMgr::max() const{
	int max(INT_MIN);
	for(std::vector<int>::const_iterator it = numbers.begin();
			it != numbers.end();it++)
		if(*it > max)
			max = *it;
	return max;
}

int MathMgr::sum() const{
	int total(0);
	for(std::vector<int>::const_iterator it = numbers.begin();
			it != numbers.end();it++)
		total += *it;
	return total;
}

double MathMgr::average() const{
	double average = 0.0;
	if(numbers.size() > 0)
		average = sum() / numbers.size();
	return average;
}

void MathMgr::readNumbers(){
	numbers.clear();
	cout << "Enter " << size << " numbers:" << endl;
	for(int i(0);i < size;i++){
		int num(0);
		(cin >> num).get();
		numbers.push_back(num);
	}
}

ostream& operator<<(ostream& os,const MathMgr& mgr){
	os << "Numbers: ";
	for(std::vector<int>::const_iterator it = mgr.numbers.begin();
			it != mgr.numbers.end();it++)
		os << *it << " ";
	os << endl;
	return os;
}