#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(char ch,int x,int y,int w,int h) : 
	m_ch(ch), m_x(x), m_y(y), m_h(h), m_w(w){}

int Rectangle::area() const{
	return m_w * m_h;
}

int Rectangle::perimeter() const{
	return (2*m_w) + (2*m_h);
}

double Rectangle::contains(const Rectangle& other) const{
	return (other.m_x > m_x && other.m_y > m_y &&
			other.m_w < m_w && other.m_h < m_h &&
			(other.m_x + other.m_w) < (m_x + m_w) &&
			(other.m_y + other.m_h) < (m_y + m_h));
}

Rectangle Rectangle::container(const Rectangle& other) const{
	int  ch,x,y,w,h;
	if(m_x < other.m_x)
		x = m_x;
	else
		x = other.m_x;
	if(m_y < other.m_y)
		y = m_y;
	else
		y = other.m_y;
	
	if((m_x + m_w) > (other.m_x + other.m_w))
		w = (m_x + m_w) - x;
	else
		w = (other.m_x + other.m_w) - x;
	if((m_y + m_h) > (other.m_y + other.m_h))
		h = (m_y + m_h) - y;
	else
		h = (other.m_y + other.m_h) - y;
}

ostream& operator<<(ostream& os, const Rectangle& r){
	for(int i(0);i<r.m_y;i++)
		os << endl;
	for(int i(0);i<r.m_h;i++){
		for(int j(0);j<r.m_x;j++)
			os << " ";
		for(int k(0);k<r.m_w;k++)
			os << r.m_ch;
		os << endl;
	}
	return os;
}