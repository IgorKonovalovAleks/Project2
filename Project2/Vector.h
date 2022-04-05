#pragma once
#include <cstdio>

class Vector {
private:

	double* d = nullptr;
	int n = 0;
	
public:

	Vector();
	Vector(int len);
	Vector(const Vector& v);
	~Vector();



	int getLength() const;
	void resize(int nSize);

	void setVal(int i, double val);

	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	
	Vector& operator=(const Vector& v);
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);

	Vector operator*(double c) const;
	Vector& operator*=(double c);
	double getNorm() const;

	double dot(const Vector& v) const;

	double& operator[](int i);
	double operator[](int i) const;

	void print() const;

};


