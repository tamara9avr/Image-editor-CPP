#include <fstream>
#include <iostream>
#include <vector>

class BMP
{
protected:
	uint32_t size_file;
	uint32_t width;
	uint32_t height;
	uint16_t bpp;
	uint32_t size_image;
	uint32_t off;
	std::vector<uint32_t> arr;

	friend class Formater;
public:
	BMP(const char *);
	void write(const char*);
	BMP();

};