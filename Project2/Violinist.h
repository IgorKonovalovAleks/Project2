#pragma once
#include "Musician.h"
class Violinist :
    public Musician
{
	Violinist();
	Violinist(std::string name);
	Violinist(const Musician& m);
	void play() const;
};

