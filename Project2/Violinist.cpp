#include "Violinist.h"


Violinist::Violinist() {
	name = "";
	spec = "violinist";
}


Violinist::Violinist(std::string name) {
	this->name = name;
	spec = "violinist";

}


Violinist::Violinist(const Musician& m) {
	name = m.getName();
	spec = "violinist";

}

void Violinist::play() const {
	std::cout << " violin music starts\n";
}


