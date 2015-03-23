#include "utils.h"
#include <algorithm>
using namespace std;

pixel median(pixel* pixels, int size){
	int red[size];
	int green[size];
	int blue[size];

	for(int i(0);i<size;i++){
		red[i] = pixels[i].r;
		green[i] = pixels[i].g;
		blue[i] = pixels[i].b;
	}
	sort(red,red+size);
	sort(green,green+size);
	sort(blue,blue+size);

	pixel result = {red[size/2],green[size/2],blue[size/2]};
	return result;
}
