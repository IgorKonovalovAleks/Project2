#include "Musician.h"

Musician::Musician() {
	name = "";
	spec = "musician";
}


Musician::Musician(std::string name) {
	this->name = name;
	spec = "musician";

}


Musician::Musician(const Musician& m) {
	name = m.name;
	spec = "musician";

}

Musician::~Musician() {

}

std::string Musician::getName() const {
	return name;
}


std::string Musician::getSpec() const {
	return spec;
}

void Musician::takePlace() const {
	std::cout << " " << spec << " \n";
}

void Musician::play() const {
	std::cout << "music starts\n";
}

