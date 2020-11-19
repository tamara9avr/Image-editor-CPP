#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CImg.h"

using namespace cimg_library;
using namespace std;

class test
{
	vector<uint32_t> arr_pix;
public:
	test(const char* fname){
		CImg<uint32_t> image = CImg<>(fname);
		cimg_for(image, ptr, uint32_t) {
			arr_pix.push_back(*ptr);
		}
	/*	for (vector<uint32_t>::iterator i = arr_pix.begin(); i < arr_pix.end(); i++) {
			 *i = 0;
		}

		int i = 0;

		cimg_for(image, ptr, uint32_t) {
			
			*ptr = arr_pix[i++];
		}*/
		cout << image.height() << endl;
		uint32_t red = (uint32_t) 0x000000ff & arr_pix[1];
		uint32_t green = (uint32_t)0x0000ff00 & arr_pix[1];
		uint32_t blue = (uint32_t)0x00ff0000 & arr_pix[1];
		cout << red << endl << green << endl << blue << endl;
		
		//image.save("C:\\Users\\Avramovic\\Pictures\\Proba03_copy.bmp", -1, 6U);
		
	}
	//~test();
	
};

