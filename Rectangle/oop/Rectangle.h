#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle
{
public:
	Rectangle(char ch, int x, int y, int w, int h);
	int area() const;
	int perimeter() const;
	double contains(const Rectangle& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);

private:
	char m_ch;
	int m_x;
	int m_y;
	int m_h;
	int m_w;
};

#endif