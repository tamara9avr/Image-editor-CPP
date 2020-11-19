#include <iostream>
class Pixel
{
	int red;
	int blue;
	int green;
	int alpha;
public:
	Pixel(uint32_t elem);
	~Pixel();
	int Red() const { return red; }
	int Blue() const { return blue; }
	int Green() const { return green; }
	void setRed(int r) { red = r; }
	void setGreen(int g) { green=g; }
	void setBlue(int b) { blue=b; }
	uint32_t calc() {
		uint32_t ret = 0;
		ret += (blue << 2);
		ret += (green << 1);
		ret += red;
		return ret;
	}
};
