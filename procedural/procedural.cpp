#include "procedural.h"
#include <iostream>
#include <climits>
using namespace std;

void readNumbers(int ary[],int size){
	cout << "Enter " << size << " numbers:" << endl;
	for(int i(0);i < size;i++){
		(cin >> ary[i]).get();
	}
}

void printNumbers(int ary[],int size){
	cout << "Numbers: " << endl;
	for(int i(0);i < size;i++){
		cout << ary[i] << " ";
	}
	cout << endl;
}

int sum(int ary[],int size){
	int total(0);
	for(int i(0);i < size;i++){
		total = total + ary[i];
	}
	return total;
}

double average(int ary[],int size){
	return size / (double) sum(ary,size);
}

int max(int ary[],int size){
	int max(INT_MIN);
	for(int i(0);i < size;i++){
		if(ary[i] > max){
			max = ary[i];
		}
	}
	return max;
}