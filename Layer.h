#include "Pixel.h"
#include <vector>

class Layer
{
	std::vector<Pixel> sloj;
	int visina;
	int sirina;
	int trancparency;
public:
	Layer(int v, int s) :visina(v), sirina(s),trancparency(0) {};
	Layer(std::vector<Pixel> arr, int w, int h, int t):sloj(arr),sirina(w),visina(h),trancparency(t) {};
	~Layer();
	void resize(int w, int h) {
	}
};

