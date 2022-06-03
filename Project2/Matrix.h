#pragma once
#include <cstdio>
#include "Vector.h"




class Matrix {
private:

	Vector* d = nullptr;
	int rw;
	int cl;

public:

	Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& m);
	~Matrix();

	int getRw();
	int getCl();
	void resize(int newRw, int newCl);

	Vector& operator[](int i);
	Vector operator[](int i) const;

	Matrix operator+(const Matrix& m) const;
	Matrix operator-(const Matrix& m) const;
	Matrix operator*(double c) const;
	Matrix operator*(const Matrix& m) const;

	friend Matrix operator*(double a, Matrix c);

	Matrix& operator+=(const Matrix& m);
	Matrix& operator= (const Matrix& m);
	Matrix& operator-=(const Matrix& m);
	Matrix& operator*=(double c);

	void print() const;

};


