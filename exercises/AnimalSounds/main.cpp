#include "AnimalBase.h"
#include "Animals.h"

void talk(AnimalBase * animal)
{
	animal->speak();
}

int main()
{
	Dog dog;
	Frog frog;
	Duck duck;

	talk(&dog);
	talk(&frog);
	talk(&duck); 
}