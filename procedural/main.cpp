#include "procedural.h"
#include <iostream>
using namespace std;

const int SIZE(5);

int main(int argc,char * argv[]){
	int numbers[SIZE];
	readNumbers(numbers,SIZE);
	printNumbers(numbers,SIZE);
	cout << sum(numbers,SIZE);
	cout << average(numbers,SIZE);
	cout << max(numbers,SIZE);
}