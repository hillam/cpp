#include "Set.h"
#include <iostream>

Set::Set() : m_items(){ 
}
int Set::size() const{
	return m_items.size();
}
string Set::get(int index) const{
	return m_items[index];
}
bool Set::contains(const string& item) const{
	for(vector<string>::iterator it=m_items.begin();it<m_items.end();i++)
		if(*it == item)
			return true;
	return false;
}
bool Set::add(const string& item){
	if(this.contains(item))
		return false;
	else
		m_items.push_back(item);
}
bool Set::remove(const string& item){
	if(!this.contains(item))
		return false;
	else
		for(int i(0);i<this.size();i++)
			if(m_items[i] == item)
				m_items.erase(i);
		return true;
}
void Set::removeAll(){
	m_items.clear();
}
void Set::operator!();

friend Set operator*(const Set& lhs, const Set& rhs); // intersection
friend Set operator-(const Set& lhs, const Set& rhs); // difference
friend Set operator+(const Set& lhs, const Set& rhs); // union
friend std::ostream& operator<<(std::ostream& os, const Set& s);