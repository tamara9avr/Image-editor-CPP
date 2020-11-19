#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Pixel.h"

class PAM
{
	int height = 0;;
	int width=0;
	int depth=0;
	int maxval = 0;
	int tuple_type = 0;
	std::vector<Pixel> arr;

public:
	PAM(const char*);
	~PAM();
};

