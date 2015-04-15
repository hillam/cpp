#ifndef MAXMINFINDER_H
#define MAXMINFINDER_H

#include <vector>

using namespace std;

template <class T>
class MaxMinFinder{
public:
	MaxMinFinder(const T m) : m_max(m),m_min(m) {}
	void test(T m){
		if(m > m_max)
			m_max = m;
		if(m < m_min)
			m_min = m;
	}
	void test(const vector<T> v){
		for(T m : v)
			test(m);
	}
	T max() const {return m_max;}
	T min() const {return m_min;}
private:
	T m_max;
	T m_min;
};

#endif