#include "FileReader.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> count(26,0);
	FileReader file("wordlist.txt");
	string upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string lower("abcdefghijklmnopqrstuvwxyz");

	while(!file.endOfFile()){
		int index;
		index = lower.find(file.readLine()[0]);
		if(index >= 0)
			count[index] ++;
	}

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