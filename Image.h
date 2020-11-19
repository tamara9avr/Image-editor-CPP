#include "Formater.h"
#include "Layer.h"
#include <regex>

class Image
{
	std::vector<int> heder;
	int height;
	int width;
	std::vector<std::pair<Layer, bool>> arr;

public:
	Image(const char *fname,int t);
	Image(int w, int h) :width(w), height(h) {
		Layer l(w,h);
		std::pair<Layer, bool> par(l, true);
		arr.push_back(par);
	}
	~Image();
	void addLayer(const char *fname, int t);
	void addLayer() { 
		Layer l(width, height);
		std::pair<Layer, bool> par(l, true);
		arr.push_back(par);
	}
	void activate(int i) {
		//arr[i].bool=true;
	}
	void deactivate(int i) {
		//arr[i].bool = false;
	}
	int Visina()const { return height; }
	int Sirina()const { return width; }
	void saveAs(const char *fname);
	std::vector<Pixel> imageCalculate();
	void deleteLayer() { arr.erase(arr.end() - 1); }
};

