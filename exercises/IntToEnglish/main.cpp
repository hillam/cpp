#include <iostream>

using namespace std;

int main(){
	cout << "Enter a positive integer: ";
	int num(0);
	(cin >> num).get();

	for(int i(10);i / num < 10;i*=10)
		cout << (num % i) / (i/10) << " * " << i/10 << endl;
}