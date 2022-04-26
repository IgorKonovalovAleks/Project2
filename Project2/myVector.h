#pragma once
#include <cstdio>

const double CAPACITY_FACTOR = 2;

class MyVector {
private:

	double* d = nullptr;
	int n = 0;
	int capacity = 0;

public:

	MyVector();
	MyVector(int len);
	MyVector(const MyVector& v);
	~MyVector();
	MyVector& operator=(const MyVector& v);

	int getLength() const;
	void resize(int nSize);

	void pushBack(double a);
	double popBack();

	double& operator[](int i);
	double operator[](int i) const;


	void print() const;

};