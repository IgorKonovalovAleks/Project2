#pragma once
#include "Musician.h"
class Conductor :
    public Musician
{
	Conductor();
	Conductor(std::string name);
	Conductor(const Musician& m);
	void play() const;
};

