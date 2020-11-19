#include "Formater.h"


Formater::Formater(const char * fname)
{
	// regex = "[^.]*\.(.*)"    // Cita sve do prve tacke. Posle te tacke se nalazi ekstenzija
	// Ako je ekstenzija = bmp zove se konstruktor za bmp i citaju se visina i sirina ... 
	// data iz bmp/pam/mog formata se stavljaju u arr formatera
	BMP image(fname);
	for (int i = 0; i < image.arr.size(); i++) {
		Pixel pix(image.arr[i]);
		arr.push_back(pix);
	}

}

void Formater::write(const char* fname) {
	std::vector<uint32_t> pom;
	for (int i = 0; i < arr.size(); i++) {
		pom.push_back(arr[i].calc());
	}
	//ponovo regex, pozivamo odgovarajucu write funkciju sa hederom
}


Formater::~Formater()
{
}