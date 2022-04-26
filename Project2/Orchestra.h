#pragma once
#include "Conductor.h"
#include "Violinist.h"
#include <vector>


class Orchestra
{
private:
	std::vector <Musician*> orc;

public:

	Orchestra();
	Orchestra(std::string name);
	Orchestra(const Musician& m);
	~Orchestra();

	void play() const;


};

