#include "BMP.h"

BMP::BMP(const char* fname) {
	std::ifstream image(fname, std::ios::binary);
	if (image) {
		uint16_t id;
		image.read((char *)&id, 2);
		if (id != 0x4D42) std::cout << "Greska" << std::endl;
		image.read((char*)&size_file, 4);
		uint32_t res;
		image.read((char*)&res, 4);
		uint32_t off;
		image.read((char*)&off, 4);
		uint32_t dib;
		image.read((char*)&dib, 4);
		image.read((char*)&width, 4);
		image.read((char*)&height, 4);
		uint16_t res1;
		image.read((char*)&res1, 2);
		image.read((char*)&bpp, 2);
		image.seekg(off, image.beg);
		if (bpp == 32) {
			while (!0) {
				uint32_t pom;
				image.read((char*)&pom, 4);
				arr.push_back(pom);
			}
		}
		else {
			if (bpp == 24) {
				while (!0) {
					for (int i = 0; i < width; i++) {
						uint32_t pom = 0;
						uint8_t elem;
						image.read((char*)&elem, 1);
						pom += (elem << 2);
						image.read((char*)&elem, 1);
						pom += (elem << 1);
						image.read((char*)&elem, 1);
						pom += elem;
						arr.push_back(pom);
					}
					if (width % 4 != 0) {
						for (int j = 0; j < (width % 4); j++) {
							uint8_t padd;
							image.read((char*)&padd, 1);
						}
					}
				}
			}
		}
	}
}


void BMP::write(const char* fname) {
	std::ofstream image(fname, std::ios::binary);
	uint16_t id = 0x4D42;
	image.write((char*)&id, 2);
	image.write((char*)&size_file, 4);
	uint32_t res = 0x00;
	image.write((char*)&res, 4);
	image.write((char*)&off, 4);
	uint32_t dib = 40;
	image.write((char*)&dib, 4);
	image.write((char*)&width, 4);
	image.write((char*)height, 4);
	uint16_t res1 = 1;
	image.write((char*)&res1, 2);
	image.write((char*)&bpp, 2);
	uint32_t res2 = 0;
	image.write((char*)&res2, 4);
	image.write((char*)&size_image, 4);
	uint32_t res3 = 2835;
	image.write((char*)&res3, 4);
	image.write((char*)&res3, 4);
	res3 = 0;
	image.write((char*)&res3, 4);
	image.write((char*)&res3, 4);
	if (bpp == 32) {
		for (int i = 0; i < arr.size(); i++) {
			image.write((char*)&arr[i].alpha, 1);
			image.write((char*)&arr[i].blue, 1);
			image.write((char*)&arr[i].green, 1);
			image.write((char*)&arr[i].red, 1);
		}
	}
	else {
		if (bpp == 24) {
			for (int i = 0; i < arr.size(); i++) {
				image.write((char*)&arr[i].blue, 1);
				image.write((char*)&arr[i].green, 1);
				image.write((char*)&arr[i].red, 1);
			}
			if (width % 4 != 0) {
				for (int j = 0; j < (width % 4); j++) {
					uint8_t padd;
					image.write((char*)&padd, 1);
				}
			}
		}
	}
}