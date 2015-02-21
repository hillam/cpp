#include "FileReader.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	FileReader file("wordlist.txt");

	vector<std::string> words;
	while(!file.endOfFile())
		words.push_back(file.readLine());


	for (vector<string>::iterator it = words.end()-1; it != words.begin()-1; --it)
		cout << *it << endl;
}