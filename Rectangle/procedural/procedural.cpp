#include "procedural.h"
#include <iostream>
using namespace std;

void printRectangle(char ch,int x,int y,int w,int h){
	for(int i(0);i<y;i++)
		cout << endl;
	for(int i(0);i<h;i++){
		for(int j(0);j<x;j++)
			cout << " ";
		for(int k(0);k<w;k++)
			cout << ch;
		cout << endl;
	}
}

int area(int w,int h){
	return w * h;
}

int perimeter(int w,int h){
	return (2*w) + (2*h);
}

bool contains(int x1,int y1,int w1,int h1,
			  int x2,int y2,int w2,int h2){
	return (x2 > x1 && y2 > y1 && 
			w2 < w1 && h2 < h1 &&
			(x2 + w2) < (x1 + w1) &&
			(y2 + h2) < (y1 + h1));
}