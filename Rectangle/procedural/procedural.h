#ifndef PROCEDURAL_H
#define PROCEDURAL_H

void printRectangle(char ch, int x, int y, int w, int h);
int area(int w, int h);
int perimeter(int w, int h);
bool contains(int x1, int y1, int w1, int h1,
	 		  int x2, int y2, int w2, int h2);

#endif