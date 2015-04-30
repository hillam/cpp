#ifndef ANIMALS_H
#define ANIMALS_H

#include "AnimalBase.h"
#include <iostream>

using namespace std;

class Dog : public AnimalBase{
public:
	Dog(){}
	virtual void speak(){
		cout << "Woof" << endl;
	}
};

class Frog : public AnimalBase{
public:
	Frog(){}
	virtual void speak(){
		cout << "Ribbit" << endl;
	}
};

class Duck : public AnimalBase{
public:
	Duck(){}
	virtual void speak(){
		cout << "Quack" << endl;
	}
};

#endif