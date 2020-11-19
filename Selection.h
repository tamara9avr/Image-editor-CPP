#include <string>
#include "Rectangle.h"
#include <map>


class Selection
{
	std::string name;
	std::vector<Rectangle> arr;
	std::map<std::pair<int, int>, bool> ap;			//active pixels in selection
	bool active = false;

public:
	Selection(std::string n, std::vector<Rectangle> r) :name(n), arr(r) { 
		active = true;
		for (Rectangle r : arr) {
			ap[r.Position()] = true;
		}
	};
	void deactivate() { active = false; }
	~Selection();
	std::vector<Rectangle>::iterator begin() { return arr.begin(); }
	std::vector<Rectangle>::iterator end() { return arr.end(); }
	std::map<std::pair<int, int>, bool> Map() { return ap; }
};

