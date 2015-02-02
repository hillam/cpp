#include "Rectangle.h"
#include <iostream>

int main()
{
	Rectangle r1('*', 1, 1, 10, 5);
	Rectangle r2('-', 2, 3, 4, 2);
	Rectangle r3('+', 2, 2, 4, 5);

	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
	std::cout << r3 << std::endl;


	std::cout << std::endl;
	std::cout << "r1 area: " << r1.area() << std::endl;
	std::cout << "r2 area: " << r2.area() << std::endl;
	std::cout << "r3 area: " << r3.area() << std::endl;

	std::cout << "r1 perimeter: " << r1.perimeter() << std::endl;
	std::cout << "r2 perimeter: " << r2.perimeter() << std::endl;
	std::cout << "r3 perimeter: " << r3.perimeter() << std::endl;

	std::cout << "Does r1 contain r2? " << r1.contains(r2) << std::endl;
	std::cout << "Does r1 contain r3? " << r1.contains(r3) << std::endl;
}