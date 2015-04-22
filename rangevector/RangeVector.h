#ifndef RANGEVECTOR_H
#define RANGEVECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class RangeVector{
public:
	RangeVector(T min,T max) : m_min(min), m_max(max){}
	void add(const T& item){
		if(!contains(item) && inrange(item))
			m_items.push_back(item);
	}
	bool contains(const T& item) const {
		return find(m_items.begin(), m_items.end(), item) != m_items.end();
	}
	bool inrange(const T& item) const {
		return item >= m_min && item <= m_max;
	}
	void merge(const RangeVector<T>& other){
		for(T x : other.m_items)
			add(x);
	}
	friend std::ostream& operator<<(std::ostream& os, const RangeVector<T>& r){
		for(T x : r.m_items)
			os << x << " ";
		return os;
	}
private:
	T m_min;
	T m_max;
	vector<T> m_items;
};

#endif