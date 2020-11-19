#include "BMP.h"
#include "Pixel.h"
#include <algorithm>


class Formater
{
	struct BMPHeader {
		int width;
		int height;
		int size_of_file;
		int bpp;
		int size_of_image;
	};
	std::vector<Pixel> arr;
	BMPHeader header;

public:
	Formater(const char *);
	Formater(std::vector<Pixel> pom, std::vector<int> hed) :arr(pom) {};
	void write(const char*);	//u odnosu na ekstenziju prosledjujem heder i pozivam prikladnu write metodu
	~Formater();
	int Height()const { return header.height; }
	int Width()const { return header.width; }
	std::vector<Pixel> Arr() { return arr; }
};



