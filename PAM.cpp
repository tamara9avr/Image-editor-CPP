#include "PAM.h"



PAM::PAM(const char * fname)
{
	std::ifstream image(fname, std::ios::binary);
	if (image) {
		uint16_t id;
		image.read((char*)&id, 2);
		if (id != 0x5037) std::cout << "Greska" << std::endl;
		uint8_t dot;
		image.read((char*)&dot, 1);
		uint32_t res1;
		image.read((char*)&res1, 4);
		uint16_t res2;
		image.read((char*)&res2, 2);
		uint8_t wd;
		std::vector<uint8_t> pom;
		do {
			image.read((char*)&wd, 1);
			if (wd != dot) {
				pom.push_back(wd);
			}
		} while (wd != dot);
		for (int i = pom.size() - 1, j = 0; i >= 0; i--, j++) {
			width += pom[i] << j;
		}
		image.read((char*)&res1, 4);
		image.read((char*)&res2, 2);
		uint8_t res3;
		image.read((char*)&res3, 1);
		uint8_t hg;
		pom.clear();
		do {
			image.read((char*)&hg, 1);
			if (hg != dot) {
				pom.push_back(hg);
			}
		} while (hg != dot);
		for (int i = pom.size() - 1, j = 0; i >= 0; i--, j++) {
			height += pom[i] << j;
		}
		image.read((char*)&res1, 4);
		image.read((char*)&res2, 2);
		uint8_t dp;
		pom.clear();
		do {
			image.read((char*)&dp, 1);
			if (dp != dot) {
				pom.push_back(dp);
			}
		} while (dp != dot);
		for (int i = pom.size() - 1, j = 0; i >= 0; i--, j++) {
			depth += pom[i] << j;
		}
		image.read((char*)&res1, 4);
		image.read((char*)&res2, 2);
		image.read((char*)&res3, 1);
		uint8_t mv;
		pom.empty();
		do {
			image.read((char*)&mv, 1);
			if (mv != dot) {
				pom.push_back(mv);
			}
		} while (mv != dot);
		for (int i = pom.size() - 1, j = 0; i >= 0; i--, j++) {
			maxval += pom[i] << j;
		}
		image.read((char*)&res1, 4);
		image.read((char*)&res1, 4);
		image.read((char*)&res3, 1);
		uint8_t tt;
		pom.empty();
		do {
			image.read((char*)&tt, 1);
			if (tt != dot) {
				pom.push_back(tt);
			}
		} while (tt != dot);
		for (int i = pom.size() - 1, j = 0; i >= 0; i--, j++) {
			tuple_type += pom[i] << j;
		}
		image.read((char*)&res1, 4);
		image.read((char*)&res2, 2);
		image.read((char*)&res3, 1);
		if(depth==4){
			while (!image.eof()) {
				uint8_t alpha;
				uint8_t red;
				uint8_t green;
				uint8_t blue;
				image.read((char*)&alpha, 1);
				image.read((char*)&red, 1);
				image.read((char*)&green, 1);
				image.read((char*)&blue, 1);
				Pixel p(red,green,blue,alpha);
				arr.push_back(p);
			}
		}
		else {
			if (depth == 3) {
				uint8_t red;
				uint8_t green;
				uint8_t blue;
				image.read((char*)&red, 1);
				image.read((char*)&green, 1);
				image.read((char*)&blue, 1);
				Pixel p(red, green, blue, 0);
				arr.push_back(p);
			}
		}
	}

}


PAM::~PAM()
{
}
