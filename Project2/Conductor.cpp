#include "Conductor.h"


Conductor::Conductor() {
	name = "";
	spec = "Conductor";
}


Conductor::Conductor(std::string name) {
	this->name = name;
	spec = "Conductor";

}


Conductor::Conductor(const Musician& m) {
	name = m.getName();
	spec = "Conductor";

}

void Conductor::play() const {
	std::cout << " Conductor starts ruling the orchestra\n";
}

