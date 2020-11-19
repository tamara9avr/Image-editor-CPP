#include "Pixel.h"



Pixel::Pixel(uint32_t elem)
{
	red = elem && 0x000000ff;
	green = elem && 0x0000ff00;
	blue = elem && 0x00ff0000;
	alpha = elem && 0xff000000;

}



Pixel::~Pixel()
{
}
