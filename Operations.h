#include "Pixel.h"
#include<math.h>

class Operations 
{
	int elem;

public:
	Operations() ;
	~Operations();
};


class Subtraction {
	int elem;
public:
	Subtraction(Pixel& pix, int el) :elem(el) {
		int red = pix.Red() - el;
		int green = pix.Green() - el;
		int blue = pix.Blue() - el;
		pix.setRed(red);
		pix.setBlue(blue);
		pix.setGreen(green);
	}
	~Subtraction() {};
};

class InvSubtraction {
	int elem;
public:
	InvSubtraction(Pixel& pix, int el) :elem(el) {
		int red = el - pix.Red() ;
		int green = el - pix.Green();
		int blue = el - pix.Blue();
		pix.setRed(red);
		pix.setBlue(blue);
		pix.setGreen(green);
	}
	~InvSubtraction() {};
};

class Addition {
	int elem;
public:
	Addition(Pixel& pix, int el) :elem(el) {
		int red = pix.Red() + el;
		int green = pix.Green() + el;
		int blue = pix.Blue() + el;
		pix.setRed(red);
		pix.setBlue(blue);
		pix.setGreen(green);
	}
	~Addition() {};
};

class Multiplication {
	int elem;
public:
	Multiplication(Pixel& pix, int el) :elem(el) {
		int red = pix.Red() * el;
		int green = pix.Green() * el;
		int blue = pix.Blue() * el;
		pix.setRed(red);
		pix.setBlue(blue);
		pix.setGreen(green);
	}
	~Multiplication() {};
};

class Division {
	int elem;
public:
	Division(Pixel& pix, int el) :elem(el) {
		if (elem == 0) { }
		int red = pix.Red() / el;
		int green = pix.Green() / el;
		int blue = pix.Blue() / el;
		pix.setRed(red);
		pix.setBlue(blue);
		pix.setGreen(green);
	}
	~Division() {};
};

class InvDivision {
	int elem;
public:
	InvDivision(Pixel& pix, int el) :elem(el) {
		if (elem == 0) {}
		if (pix.Red() != 0) {
			int red = el / pix.Red();
			pix.setRed(red);
		}
		if (pix.Green() != 0) {
			int green = el / pix.Green();
			pix.setGreen(green);
		}
		if (pix.Blue() != 0) {
			int blue = el / pix.Blue();
			pix.setBlue(blue);
		}
		
	}
	~InvDivision() {};
};

class Power {
	int elem;
public:
	Power(Pixel& pix, int el) :elem(el) {
		pix.setRed(pow(pix.Red(), elem));
		pix.setBlue(pow(pix.Blue(), elem));
		pix.setGreen(pow(pix.Green(), elem));
	}
	~Power() {};
};

class Logarithm {
	int elem;
public:
	Logarithm(Pixel& pix, int el) :elem(el) {
		pix.setRed(log(pix.Red()));
		pix.setGreen(log(pix.Green()));
		pix.setBlue(log(pix.Blue()));
	}
	~Logarithm() {};
};

//class Abs??

class Minimum {
	int elem;
public:
	Minimum(Pixel& pix, int el):elem(el) {
		if (pix.Red() > elem) pix.setRed(elem);
		if (pix.Green() > elem) pix.setGreen(elem);
		if (pix.Blue() > elem) pix.setBlue(elem);
	}
	~Minimum() {};
};

class Maximum {
	int elem;
public:
	Maximum(Pixel& pix, int el) :elem(el) {
		if (pix.Red() < elem) pix.setRed(elem);
		if (pix.Green() < elem) pix.setGreen(elem);
		if (pix.Blue() < elem) pix.setBlue(elem);
	}
	~Maximum() {};
};

class Inversion {
public:
	Inversion(Pixel& pix) {
		InvSubtraction inv(pix, 255);
	}
	~Inversion() {};
};

class Gray {
public:
	Gray(Pixel& pix) {
		int ars = (pix.Red() + pix.Blue() + pix.Green()) / 3;
		pix.setRed(ars);
		pix.setGreen(ars);
		pix.setBlue(ars);
	}
	~Gray() {};
};

class BlackWhite {
public:
	BlackWhite(Pixel& pix) {
		int ars = (pix.Red() + pix.Blue() + pix.Green()) / 3;
		if (ars < 127) {
			pix.setRed(0);
			pix.setGreen(0);
			pix.setBlue(0);
		}
		else {
			pix.setRed(255);
			pix.setGreen(255);
			pix.setBlue(255);
		}
	}
	~BlackWhite() {};
};


//Medijana?