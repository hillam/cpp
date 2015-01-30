#include "procedural.h"
#include <iostream>

int main()
{
	int x1 = 1, y1 = 1, w1 = 10, h1 = 5;
	int x2 = 2, y2 = 3, w2 = 4, h2 = 2;
	int x3 = 2, y3 = 2, w3 = 4, h3 = 5;

	printRectangle('*', x1, y1, w1, h1);
	printRectangle('-', x2, y2, w2, h2);
	printRectangle('+', x3, y3, w3, h3);

	std::cout << std::endl;
	std::cout << "r1 area: " << area(w1, h1) << std::endl;
	std::cout << "r2 area: " << area(w2, h2) << std::endl;
	std::cout << "r3 area: " << area(w3, h3) << std::endl;

	std::cout << "r1 perimeter: " << perimeter(w1, h1) << std::endl;
	std::cout << "r2 perimeter: " << perimeter(w2, h2) << std::endl;
	std::cout << "r3 perimeter: " << perimeter(w3, h3) << std::endl;

	std::cout << "Does r1 contain r2? " 
		<< contains(x1, y1, w1, h1,
					x2, y2, w2, h2) << std::endl;

	std::cout << "Does r1 contain r3? " 
		<< contains(x1, y1, w1, h1,
					x3, y3, w3, h3) << std::endl;

}