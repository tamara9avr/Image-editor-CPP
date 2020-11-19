#include <vector>

class Rectangle
{
	int heigth;
	int width;
	std::pair<int, int> position;

public:
	Rectangle(std::pair<int, int> p, int h, int w) :position(p), heigth(h), width(w) {};
	~Rectangle();
	std::pair<int, int> Position() { return position; }
};

