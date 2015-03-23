#include "utils.h"
#include "FileReader.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	const string prefix ("Pesky");
	const int num_photos = 9;

	image pics[num_photos];

	cout << "Reading images.." << endl;
	//read file
	for(int i(0);i<num_photos;i++){
		char name[50];
		sprintf(name,"%s%d.ppm",prefix.c_str(),(i+1));
		FileReader in_pic(name);
		
		//ignore first four lines
		in_pic.readLine();
		in_pic.readLine();
		in_pic.readLine();
		in_pic.readLine();

		for(int j(0);j<num_pixels;j++){
			int r=0;
			int g=0;
			int b=0;
			if(!in_pic.endOfFile())
				r = atoi(in_pic.readLine().c_str());
			if(!in_pic.endOfFile())
				g = atoi(in_pic.readLine().c_str());
			if(!in_pic.endOfFile())
				b = atoi(in_pic.readLine().c_str());
			pics[i].pixels[j] = {r,g,b};
		}
	}

	cout << "Filtering.." << endl;
	//populate median image
	image result;
	for(int i(0);i<num_pixels;i++){
		//cout << i << endl;
		pixel p[num_photos];
		for(int j(0);j<num_photos;j++){
			p[j] = pics[j].pixels[i];
			result.pixels[i] = median(p,num_photos);
		}
	}

	cout << "Creating " << prefix << ".ppm.." << endl;
	//write to file
	ofstream ppmFile;
	ppmFile.open(prefix+".ppm");
	ppmFile << "P3" << endl 
			<< "# CREATOR: median.o" << endl 
			<< width << " " <<  height << endl 
			<< "255" << endl;
	for (int i(0);i<num_pixels;i++)
	{
		ppmFile << result.pixels[i].r << endl <<
			result.pixels[i].g << endl <<
			result.pixels[i].b << endl;
	}
	ppmFile.close();
}