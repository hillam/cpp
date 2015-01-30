#include "MathMgr.h"
#include <iostream>
using namespace std;

int main(){
	MathMgr math(5);
	math.readNumbers();
	cout << math;
}