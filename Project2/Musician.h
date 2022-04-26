#pragma once
#include <string>
#include <iostream>

class Musician
{
protected:
	std::string name;
	std::string spec;

public:

	Musician();
	Musician(std::string name);
	Musician(const Musician& m);
	~Musician();

	std::string getName() const;
	std::string getSpec() const;
	void play() const;
	void takePlace() const;
};

