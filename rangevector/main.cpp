#include "RangeVector.h"
#include "FileReader.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	RangeVector<string> rv1("Carl","George");
	RangeVector<string> rv2("Brice","Lisa");
	FileReader f1("names1.txt");
	FileReader f2("names2.txt");
	
	// read files
	while(!f1.endOfFile())
		rv1.add(f1.readLine());
	while(!f2.endOfFile())
		rv2.add(f2.readLine());

	// merge and print
	rv1.merge(rv2);
	cout << rv1 << endl;
}