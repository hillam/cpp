#include "FileReader.h"
#include "Set.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> joinFiles(FileReader& f1,FileReader& f2){
	Set s1;
	Set s2;

	while(!f1.endOfFile())
		s1.add(f1.readLine());
	while(!f2.endOfFile())
		s2.add(f2.readLine());

	return (s1+s2).getItems();
}

vector<string> intersectFiles(FileReader& f1,FileReader& f2){
	Set s1;
	Set s2;

	while(!f1.endOfFile())
		s1.add(f1.readLine());
	while(!f2.endOfFile())
		s2.add(f2.readLine());

	return (s1*s2).getItems();
}

int main(){
	{
		FileReader f1("names1.txt");
		FileReader f2("names2.txt");

		vector<string> v1;
		v1 = joinFiles(f1,f2);
		cout << "Union: " << endl;
		for(string s : v1)
			cout << s << " ";
		cout << endl;
	}

	{
		FileReader f1("names1.txt");
		FileReader f2("names2.txt");

		vector<string> v2;
		v2 = intersectFiles(f1,f2);
		cout << "Intersection: " << endl;
		for(string s : v2)
			cout << s << " ";
		cout << endl;
	}
}