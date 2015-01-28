#ifndef MATHMGR_H
#define MATHMGR_H
using namespace std;

class MathMgr{

private:
	int size;
	vector<int> numbers;

public:
	MathMgr(int size);
	int max() const; 
	int sum() const;
	int average() const;
	void readNumbers();

};

#endif