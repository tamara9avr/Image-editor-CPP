#include "Image.h"



Image::Image(const char * fname, int t)
{
	Formater f(fname);
	Layer l(f.Arr(), f.Width(), f.Height(), t);
	std::pair<Layer, bool> par(l, true);
	height = f.Height();
	width = f.Width();
	arr.push_back(par);
}


Image::~Image()
{
}

void Image::addLayer(const char * fname, int t)
{
	Formater f(fname);
	Layer l(f.Arr(), f.Width(), f.Height(),t);
	
	if (f.Width() < width || f.Height() < height) {
		l.resize(width, height);
	}
	if (f.Width() > width || f.Height() > height) {
	/*	for (std::vector<std::pair<Layer, bool>>::iterator it : arr) {
			// za svakiu layer uradimo resize()
		} */
		height = f.Height();
		width = f.Width();
		//promeniti heder
	}
	std::pair<Layer, bool> par(l, true);
	arr.push_back(par);
}

void Image::saveAs(const char * fname)
{
	Formater f(imageCalculate(), heder);
	f.write(fname);
}

std::vector<Pixel> Image::imageCalculate()
{
	std::vector<Pixel> ret;
	/*for(std::vector<std::pair<Layer,bool>>::iterator it : arr){
		if(arr.bool[it] == true) {
			ret[it] 
	*/
	return ret;
}

