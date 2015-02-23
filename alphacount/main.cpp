#include "FileReader.h"
#include <iostream>
#include <vector>

using namespace std;

void countWords(vector<int>& vector);

int main(){
	vector<int> count(26,0);
	string upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	countWords(count);

	while(true){
		string inpt;
		cout << "Enter an uppercase letter [A-Z] or 'q' to quit: ";
		(cin >> inpt).get();
		if(inpt[0] == 'q'){
			cout << "Kbye.." << endl;
			return 0;
		}
		else if(upper.find(inpt[0]) != string::npos)
			cout << "There are " << count[upper.find(inpt[0])] << 
				" words in the file that begin with " << inpt[0] << "." << endl;
	}
}

void countWords(vector<int>& vector){
	FileReader file("wordlist.txt");
	string lower("abcdefghijklmnopqrstuvwxyz");

	while(!file.endOfFile()){
		int index;
		index = lower.find(file.readLine()[0]);
		if(index >= 0)
			vector[index] ++;
	}
}