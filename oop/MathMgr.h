#ifndef MATHMGR_H
#define MATHMGR_H

#include <iostream>
#include <vector>
using namespace std;

class MathMgr{

private:
	int size;
	vector<int> numbers;

public:
	MathMgr(int size);
	int max() const; 
	int sum() const;
	double average() const;
	void readNumbers();
	friend ostream& operator<<(ostream& os,const MathMgr& mgr);

};

#endif