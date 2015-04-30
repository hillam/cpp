#ifndef ANIMALBASE_H
#define ANIMALBASE_H

#include <iostream>

using namespace std;

class AnimalBase{
public:
	AnimalBase(){}
	virtual void speak(){
		cout << "Greetings" << endl;
	}
};

#endif